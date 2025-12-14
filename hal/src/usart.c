#include "usart.h"
#include "rcc.h"

void init_vcp_uart(uint32_t baud_rate) {
    // enable USART2 RCC
    RCC->APB1ENR1 |= (0b1 << 17);

    // set USARTDIV for baud_rate, 1250 for 144 MHz
    USART2->BRR &= ~0xFF;
    USART2->BRR |= MCU_FREQ / baud_rate;

    // enable TE and UE
    USART2->CR1 |= (0b1U << 3);
    USART2->CR1 |= (0b1U);
}

void transmit_byte(usart_t* handle, uint8_t b) {
    // yield until TXE is set
    while (!(handle->ISR & (0b1 << 7)));

    // write to TDR
    handle->TDR = b;
}