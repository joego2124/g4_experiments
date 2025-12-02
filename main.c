#include "gpio.h"
#include "rcc.h"
#include "gtim.h"
#include "sin.h"

#define MCU_FREQ 16000000   // 16 MHz by default
#define TIM_FREQ 1000000    // 1 MHz timer
#define LED_FREQ 1000       // 1 kHz

int main () {
    // enable GPIOA RCC
    RCC->AHB2ENR |= 0x1;

    // enable TIM2 RCC
    RCC->APB1ENR1 |= 0x1;

    // set up TIM2 for 1kHz PWM
    TIM2->PSC    = (MCU_FREQ / TIM_FREQ) - 1;   // prescaler to acheieve LED_FREQ
    TIM2->ARR    = (TIM_FREQ / LED_FREQ) - 1;   // ARR default 0xFFFF -> 65535
    TIM2->CCMR1 |= (0b0110 << 4);               // PWM mode 1 - In up-counting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive
    TIM2->EGR   |= 0x1;                         // enable upddate generation
    TIM2->CCMR1 |= (0b1 << 3);                  // enable capture/compare 1 preload
    TIM2->CCER  |= 0x1;                         // enable capture/compare 1 output
    TIM2->CR1   |= 0x1;                         // enable timer

    // set up A5 as timer output for led
    GPIOA->MODER &= ~(0b11 << (5 * 2)); // clear reset value bits
    GPIOA->MODER |=  (0b10 << (5 * 2)); // set to AF mode
    GPIOA->AFRL  |=  (0b01 << (5 * 4)); // set to AF1 for TIM2

    uint32_t sin_index = 0;

    while (1){
        if (sin_index > SIN_ENTRIES) sin_index = 0;

        TIM2->CCR1 = SIN_TAB[sin_index] * TIM2->ARR / SIN_ENTRIES;

        for (uint32_t i = 0; i < 0xFFF; i++) {}

        sin_index++;
    };
}