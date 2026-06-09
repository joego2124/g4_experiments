#include <stdint.h>

#define NVIC_BASE   (0xE000E000UL)
#define NVIC_ISER   ((volatile uint32_t *) (NVIC_BASE + 0x100))

typedef struct {
  volatile uint32_t MEMRMP;             // memory remap register
  volatile uint32_t CFGR1;              // configuration register 1
  volatile uint32_t EXTICR[4];          // external interrupt configuration register 1-4
  volatile uint32_t SCSR;               // SRAM command and status register
  volatile uint32_t CFGR2;              // configuration register 2
  volatile uint32_t SWPR;               // SRAM Write protection register
  volatile uint32_t SKR;                // SRAM key register

} SYSCFG_TypeDef;

typedef enum {
    EXTIA, EXTIB,
    EXTIC, EXTID,
    EXTIE, EXTIF
} exti_port_t;

typedef enum {
    EXTI_P0,  EXTI_P1,  EXTI_P2,  EXTI_P3,
    EXTI_P4,  EXTI_P5,  EXTI_P6,  EXTI_P7,
    EXTI_P8,  EXTI_P9,  EXTI_P10, EXTI_P11,
    EXTI_P12, EXTI_P13, EXTI_P14, EXTI_P15,
} exti_pin_t;

typedef enum { 
    EXTI_RISING  = 0b01U,
    EXTI_FALLING = 0b10U,
} exti_edge_t;

#define SYSCFG_BASE   (0x40010000UL)
#define SYSCFG        ((SYSCFG_TypeDef *) (SYSCFG_BASE))