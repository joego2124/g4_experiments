#include "rcc.h"
#include "flash.h"

void rcc_init_hse() {
    // enable HSE
    RCC->CR |= (0b1 << 16);

    // wait for HSE ready
    while (!(RCC->CR & (0b1 << 17)));

    // To modify the PLL configuration, proceed as follows:
    // 1. Disable the PLL by setting PLLON to 0 in Clock control register (RCC_CR).
    RCC->CR &= ~(0b1 << 24);
    // 2. Wait until PLLRDY is cleared. The PLL is now fully stopped.
    while ((RCC->CR & (0b1 << 25)));
    // 3. Change the desired parameter.
    RCC->PLLCFGR |=  (0b11);               // HSE clock selected as PLL clock entry
    RCC->PLLCFGR |=  (0b10   << 21);       // set Q divisor to 6
    RCC->PLLCFGR &= ~(0b11   << 25);       // set R divisor to 2
    RCC->PLLCFGR &= ~(127U   << 8);        // clear N mult
    RCC->PLLCFGR |=  (24U    << 8);        // set N mult to 24
    RCC->PLLCFGR |=  (0b0001 << 4);        // set M divisor to 2
    RCC->PLLCFGR |=  (0b1    << 24);       // set PLLREN
    // 4. Enable the PLL again by setting PLLON to 1.
    RCC->CR |= (0b1 << 24);
    // 5. Enable the desired PLL outputs by configuring PLLPEN, PLLQEN, PLLREN in PLL
    //    configuration register (RCC_PLLCFGR).

    // set FLASH to use 4 wait cycles
    FLASH->ACR |= (0b0100);

    // set SW[1:0] to use PLL
    RCC->CFGR |=  (0b11);

    // wait for switch complete
    while ((RCC->CFGR & (0b11 << 2)) != (0b11 << 2));
}