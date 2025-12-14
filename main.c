#include "core.h"
#include "gpio.h"
#include "rcc.h"
#include "gtim.h"
#include "usart.h"
#include "sin.h"

#define TIM_FREQ 1000000    // 1 MHz timer
#define LED_FREQ 1000       // 1 kHz
#define LED_T    1          // 1s period

#define VCP_BR   115200     // VCP USART baud rate

static uint32_t curr_sin_index = 0;

void TIM3_irq_handler() {
    if (curr_sin_index >= SIN_ENTRIES) curr_sin_index = 0;

    // set new CCR as % of #SIN_ENTRIES
    TIM2->CCR1 = SIN_TAB[curr_sin_index++] * TIM2->ARR / SIN_ENTRIES;

    // clear TIM3 UIF
    TIM3->SR &= ~(0b1);
}

int main () {
    // set SYSCLK to run at 144 MHz
    rcc_init_hse();

    // enable GPIOA RCC
    RCC->AHB2ENR |= 0x1;

    // enable TIM2 and TIM3 RCC
    RCC->APB1ENR1 |= 0b11;

    // use gpio lib to enable USART2 AF pins
    gpio_init(GPIOA, P2 | P3, ALT, AF7, PP, HIGH, NA);

    // set up USART2 to talk over VCP through nucleo board's USB
    init_vcp_uart(VCP_BR);

    // set up TIM2 for 1kHz PWM
    TIM2->PSC    = (MCU_FREQ / TIM_FREQ) - 1;   // prescaler to acheieve LED_FREQ
    TIM2->ARR    = (TIM_FREQ / LED_FREQ) - 1;   // ARR for 1ms is 1000 counts
    TIM2->CCMR1 |= (0b0110 << 4);               // PWM mode 1 - In up-counting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive
    TIM2->EGR   |= 0b1;                         // trigger update event
    TIM2->CCMR1 |= (0b1 << 3);                  // enable capture/compare 1 preload
    TIM2->CCER  |= 0b1;                         // enable capture/compare 1 output
    TIM2->CR1   |= 0b1;                         // enable timer

    // LED breath period = 1s
    // interrupt triggered every 1s / 256 = 3906us
    // set up TIM3 for interrupt
    TIM3->PSC    = (MCU_FREQ / TIM_FREQ) - 1;              // prescaler to acheieve LED_FREQ
    TIM3->ARR    = (LED_T * TIM_FREQ / SIN_ENTRIES) - 1;   // ARR for period of each interrupt
    TIM3->DIER  |= 0b1;                                    // enable update interrupt
    TIM3->EGR   |= 0b1;                                    // trigger update event
    TIM3->CR1   |= 0b1;                                    // enable timer

    // enable TIM3 IRQ
    const uint32_t TIM3_ISR_Pos = 29;
    NVIC_ISER[TIM3_ISR_Pos >> 5] |= (uint32_t)(0b1 << (TIM3_ISR_Pos & 0x1F));

    // set up A5 as timer output for led
    gpio_init(GPIOA, P5, ALT, AF1, PP, LOW, NA);

    while (1) {
        transmit_byte(USART2, 0x55);
    }
}