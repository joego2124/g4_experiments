#include "stdint.h"

typedef struct {
    volatile uint32_t CR1;      // Control register 1
    volatile uint32_t CR2;      // Control register 2
    volatile uint32_t SMCR;     // Slave mode control
    volatile uint32_t DIER;     // DMA/interrupt enable
    volatile uint32_t SR;       // Status register
    volatile uint32_t EGR;      // Event generation
    volatile uint32_t CCMR1;    // Capture/compare mode 1
    volatile uint32_t CCMR2;    // Capture/compare mode 2 (if timer has CH3/4)
    volatile uint32_t CCER;     // Capture/compare enable
    volatile uint32_t CNT;      // Counter value
    volatile uint32_t PSC;      // Prescaler
    volatile uint32_t ARR;      // Auto-reload (period)
    volatile uint32_t RCR;      // Repetition counter (present only on TIM15/16/17)
    volatile uint32_t CCR1;     // Capture/compare register 1
    volatile uint32_t CCR2;     // Capture/compare register 2
    volatile uint32_t CCR3;     // Capture/compare register 3
    volatile uint32_t CCR4;     // Capture/compare register 4
    volatile uint32_t BDTR;     // Break/dead-time (only valid on TIM15)
    volatile uint32_t DCR;      // DMA control
    volatile uint32_t DMAR;     // DMA address
} gtim_t;

#define TIM2  ((gtim_t *) (0x40000000UL))
#define TIM3  ((gtim_t *) (0x40000400UL))
#define TIM4  ((gtim_t *) (0x40000800UL))
#define TIM5  ((gtim_t *) (0x40000C00UL))
#define TIM15 ((gtim_t *) (0x40014000UL))
#define TIM16 ((gtim_t *) (0x40014400UL))
#define TIM17 ((gtim_t *) (0x4001C800UL))