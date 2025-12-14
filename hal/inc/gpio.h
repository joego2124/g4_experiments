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
    volatile uint32_t AF[2];    // 0x20 - 0x24 alternate function low/high register
    volatile uint32_t BRR;      // 0x28 bit reset register
} gpio_t;

typedef enum {
    P0  = (1U << 0),
    P1  = (1U << 1),
    P2  = (1U << 2),
    P3  = (1U << 3),
    P4  = (1U << 4),
    P5  = (1U << 5),
    P6  = (1U << 6),
    P7  = (1U << 7),
    P8  = (1U << 8),
    P9  = (1U << 9),
    P10 = (1U << 10),
    P11 = (1U << 11),
    P12 = (1U << 12),
    P13 = (1U << 13),
    P14 = (1U << 14),
    P15 = (1U << 15),
} gpio_pin_t;

typedef enum { IN, OUT, ALT, RST } gpio_mode_t;

typedef enum {
    AF0,  AF1,  AF2,  AF3,
    AF4,  AF5,  AF6,  AF7,
    AF8,  AF9,  AF10, AF11,
    AF12, AF13, AF14, AF15
} gpio_af_t;

typedef enum { PP, OD } gpio_ot_t;

typedef enum { LOW, MED, HIGH, VHIGH } gpio_speed_t;

typedef enum { NA, PU, PD } gpio_pupd_t;



#define GPIO_BASE (0x48000000UL)
#define GPIOA     ((gpio_t *) (GPIO_BASE))
#define GPIOB     ((gpio_t *) (GPIO_BASE + 0x0400UL))
#define GPIOC     ((gpio_t *) (GPIO_BASE + 0x0800UL))
#define GPIOD     ((gpio_t *) (GPIO_BASE + 0x0C00UL))
#define GPIOE     ((gpio_t *) (GPIO_BASE + 0x1000UL))
#define GPIOF     ((gpio_t *) (GPIO_BASE + 0x1400UL))
#define GPIOG     ((gpio_t *) (GPIO_BASE + 0x4800UL))

void gpio_init(
    gpio_t *port,
    uint16_t pins,
    gpio_mode_t mode,
    gpio_af_t af,
    gpio_ot_t ot,
    gpio_speed_t speed,
    gpio_pupd_t pupd
);

void init_vcp_uart(uint32_t baud_rate);