#include <stdint.h>

typedef struct {
    volatile uint32_t CR1;      // Control register 1
    volatile uint32_t CR2;      // Control register 2
    volatile uint32_t CR3;      // Control register 3
    volatile uint32_t BRR;      // Baud rate register
    volatile uint32_t GTPR;     // Guard time and prescaler register
    volatile uint32_t RTOR;     // Receiver timeout register
    volatile uint32_t RQR;      // Request register
    volatile uint32_t ISR;      // Interrupt and status register
    volatile uint32_t ICR;      // Interrupt flag clear register
    volatile uint32_t RDR;      // Receive data register
    volatile uint32_t TDR;      // Receive data register
    volatile uint32_t PRESC;    // Prescaler register
}  usart_t;


#define USART1_BASE 0x40013800UL
#define USART2_BASE 0x40004400UL
#define USART3_BASE 0x40004800UL
#define UART4_BASE  0x40004C00UL
#define UART5_BASE  0x40005000UL

#define USART1      ((usart_t*) (USART1_BASE))
#define USART2      ((usart_t*) (USART2_BASE))
#define USART3      ((usart_t*) (USART3_BASE))
#define UART4       ((usart_t*) (UART4_BASE))
#define UART5       ((usart_t*) (UART5_BASE))

void init_vcp_uart(uint32_t baud_rate);

void transmit_byte(usart_t* handle, uint8_t b);

void transmit_str(usart_t* handle, char *str, uint32_t len);