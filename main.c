#include "core.h"
#include "gpio.h"
#include "rcc.h"
#include "gtim.h"
#include "irq.h"
#include "usart.h"
#include "sin.h"

#include <stdio.h>

#define TIM_FREQ 1000000    // 1 MHz timer
#define LED_FREQ 1000       // 1 kHz
#define LED_T    1          // 1s period

#define VCP_BR   115200     // VCP USART baud rate

static uint32_t curr_sin_index = 0;

int _write(int fd, char *buf, int nbytes) {
    if (fd != 1 && fd != 2) return -1;
    transmit_str(USART2, buf, nbytes);
    return nbytes;
}

void TIM2_irq_handler() {
    if (curr_sin_index >= SIN_ENTRIES) curr_sin_index = 0;

    // set new CCR as % of #SIN_ENTRIES
    TIM3->CCR1 = SIN_TAB[curr_sin_index++] * TIM3->ARR / SIN_ENTRIES;

    // clear TIM2 UIF
    TIM2->SR &= ~(0b1);
}

int main () {
    // set SYSCLK to run at 144 MHz
    rcc_init_hse();

    // use gpio lib to enable USART2 AF pins
    gpio_init(GPIOB, P3 | P4, ALT, AF7, PP, HIGH, NA);

    // set up USART2 to talk over VCP through nucleo board's USB
    init_vcp_uart(VCP_BR);

    // set up TIM3 for 1kHz PWM
    TIM3->PSC    = (MCU_FREQ / TIM_FREQ) - 1;   // prescaler to acheieve LED_FREQ
    TIM3->ARR    = (TIM_FREQ / LED_FREQ) - 1;   // ARR for 1ms is 1000 counts
    TIM3->CCMR1 |= (0b0110 << 4);               // PWM mode 1 - In up-counting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive
    TIM3->EGR   |= 0b1;                         // trigger update event
    TIM3->CCMR1 |= (0b1 << 3);                  // enable capture/compare 1 preload
    TIM3->CCER  |= 0b1;                         // enable capture/compare 1 output
    TIM3->CR1   |= 0b1;                         // enable timer

    // LED breath period = 1s
    // interrupt triggered every 1s / 256 = 3906us
    // set up TIM3 for interrupt
    TIM2->PSC    = (MCU_FREQ / TIM_FREQ) - 1;              // prescaler to acheieve LED_FREQ
    TIM2->ARR    = (LED_T * TIM_FREQ / SIN_ENTRIES) - 1;   // ARR for period of each interrupt
    TIM2->DIER  |= 0b1;                                    // enable update interrupt
    TIM2->EGR   |= 0b1;                                    // trigger update event
    TIM2->CR1   |= 0b1;                                    // enable timer

    // enable TIM2 IRQ
    NVIC_ISER[TIM2_IRQn >> 5] |= (uint32_t)(0b1 << (TIM2_IRQn & 0x1F));

    // set up C6 as timer output for led
    gpio_init(GPIOC, P6, ALT, AF2, PP, LOW, NA);

    while (1) {
        printf("Current sin value: %ld\n", curr_sin_index);
    }
}
