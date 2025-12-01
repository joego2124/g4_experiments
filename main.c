#include "gpio.h"
#include "rcc.h"


int main () {
    // enable GPIOA RCC
    RCC->AHB2ENR |= 0x1;

    // set up A5 as high output for led
    GPIOA->MODER &= ~(0b11 << (5 * 2));
    GPIOA->MODER |=  (0b01 << (5 * 2));
    GPIOA->ODR   |=  (0b01 << 5);

    while (1);
}