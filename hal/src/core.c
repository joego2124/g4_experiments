#include "core.h"
#include "core.h"

void exti_init(exti_port_t port, exti_pin_t pin) {
    uint32_t offset = (pin & 0b11) * 4; // (pin % 4) * 4
    SYSCFG->EXTICR[pin >> 2] &= ~(0xF << offset);
    SYSCFG->EXTICR[pin >> 2] |=  (port << offset);

    // EXTI
}