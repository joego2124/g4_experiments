#include "stdint.h"

typedef struct {
    volatile uint32_t MODER;    // 0x00 mode register
    volatile uint32_t OTYPER;   // 0x04 output type register
    volatile uint32_t OSPEEDR;  // 0x08 output speed register
    volatile uint32_t PUPDR;    // 0x0C pull-up/pull-down register
    volatile uint32_t IDR;      // 0x10 input data register
    volatile uint32_t ODR;      // 0x14 output data register
    volatile uint32_t BSRR;     // 0x18 bit set/reset register
    volatile uint32_t LCKR;     // 0x1C configuration lock register
    volatile uint32_t AFRL;     // 0x20 alternate function low register
    volatile uint32_t AFRH;     // 0x24 alternate function high register
    volatile uint32_t BRR;      // 0x28 bit reset register
} gpio_t;

#define GPIO_BASE (0x48000000UL)
#define GPIOA     ((gpio_t *) (GPIO_BASE))
#define GPIOB     ((gpio_t *) (GPIO_BASE + 0x0400UL))
#define GPIOC     ((gpio_t *) (GPIO_BASE + 0x0800UL))
#define GPIOD     ((gpio_t *) (GPIO_BASE + 0x0C00UL))
#define GPIOE     ((gpio_t *) (GPIO_BASE + 0x1000UL))
#define GPIOF     ((gpio_t *) (GPIO_BASE + 0x1400UL))
#define GPIOG     ((gpio_t *) (GPIO_BASE + 0x4800UL))