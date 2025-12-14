#include "gpio.h"

void gpio_init(
    gpio_t *port,
    uint16_t pins,
    gpio_mode_t mode,
    gpio_af_t af,
    gpio_ot_t ot,
    gpio_speed_t speed,
    gpio_pupd_t pupd
) {
    for (uint8_t pin = 0; pin < 16; pin++, pins >>= 1) {
        if (!(pins & 0b1)) continue;

        port->MODER &= ~(0b11 << (pin * 2));
        port->MODER |=  (mode << (pin * 2));

        port->OTYPER &= ~(0b1 << pin);
        port->OTYPER |=  (ot  << pin);

        port->AF[pin >> 3] &= ~(0b11 << ((pin & 0b111) * 4));
        port->AF[pin >> 3] |=  (af   << ((pin & 0b111) * 4));

        port->OSPEEDR &= ~(0b11  << (pin * 2));
        port->OSPEEDR |=  (speed << (pin * 2));

        port->PUPDR &= ~(0b11 << (pin * 2));
        port->PUPDR |=  (pupd << (pin * 2));
    }
}
