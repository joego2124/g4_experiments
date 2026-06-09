#ifndef IRQ_H
#define IRQ_H

#define STM32G4_CORE_VECTOR_COUNT 16
#define STM32G4_MAX_IRQN 101
#define STM32G4_EXTERNAL_IRQ_COUNT (STM32G4_MAX_IRQN + 1)
#define STM32G4_VECTOR_COUNT (STM32G4_CORE_VECTOR_COUNT + STM32G4_EXTERNAL_IRQ_COUNT)
#define STM32G4_VECTOR_INDEX(irqn) ((irqn) + STM32G4_CORE_VECTOR_COUNT)

typedef enum {
    WWDG_IRQn = 0,
    PVD_PVM_IRQn = 1,
    RTC_TAMP_LSECSS_IRQn = 2,
    RTC_WKUP_IRQn = 3,
    FLASH_IRQn = 4,
    RCC_IRQn = 5,
    EXTI0_IRQn = 6,
    EXTI1_IRQn = 7,
    EXTI2_IRQn = 8,
    EXTI3_IRQn = 9,
    EXTI4_IRQn = 10,
    DMA1_Channel1_IRQn = 11,
    DMA1_Channel2_IRQn = 12,
    DMA1_Channel3_IRQn = 13,
    DMA1_Channel4_IRQn = 14,
    DMA1_Channel5_IRQn = 15,
    DMA1_Channel6_IRQn = 16,
#if defined(STM32G474xx)
    DMA1_Channel7_IRQn = 17,
#endif
    ADC1_2_IRQn = 18,
    USB_HP_IRQn = 19,
    USB_LP_IRQn = 20,
    FDCAN1_IT0_IRQn = 21,
    FDCAN1_IT1_IRQn = 22,
    EXTI9_5_IRQn = 23,
    TIM1_BRK_TIM15_IRQn = 24,
    TIM1_UP_TIM16_IRQn = 25,
    TIM1_TRG_COM_TIM17_IRQn = 26,
    TIM1_CC_IRQn = 27,
    TIM2_IRQn = 28,
    TIM3_IRQn = 29,
    TIM4_IRQn = 30,
    I2C1_EV_IRQn = 31,
    I2C1_ER_IRQn = 32,
    I2C2_EV_IRQn = 33,
    I2C2_ER_IRQn = 34,
    SPI1_IRQn = 35,
    SPI2_IRQn = 36,
    USART1_IRQn = 37,
    USART2_IRQn = 38,
    USART3_IRQn = 39,
    EXTI15_10_IRQn = 40,
    RTC_Alarm_IRQn = 41,
    USBWakeUp_IRQn = 42,
    TIM8_BRK_IRQn = 43,
    TIM8_UP_IRQn = 44,
    TIM8_TRG_COM_IRQn = 45,
    TIM8_CC_IRQn = 46,
#if defined(STM32G474xx)
    ADC3_IRQn = 47,
    FMC_IRQn = 48,
#endif
    LPTIM1_IRQn = 49,
#if defined(STM32G474xx)
    TIM5_IRQn = 50,
#endif
    SPI3_IRQn = 51,
    UART4_IRQn = 52,
#if defined(STM32G474xx)
    UART5_IRQn = 53,
#endif
    TIM6_DAC_IRQn = 54,
#if defined(STM32G431xx)
    TIM7_IRQn = 55,
#elif defined(STM32G474xx)
    TIM7_DAC_IRQn = 55,
#endif
    DMA2_Channel1_IRQn = 56,
    DMA2_Channel2_IRQn = 57,
    DMA2_Channel3_IRQn = 58,
    DMA2_Channel4_IRQn = 59,
    DMA2_Channel5_IRQn = 60,
#if defined(STM32G474xx)
    ADC4_IRQn = 61,
    ADC5_IRQn = 62,
#endif
    UCPD1_IRQn = 63,
    COMP1_2_3_IRQn = 64,
#if defined(STM32G431xx)
    COMP4_IRQn = 65,
#elif defined(STM32G474xx)
    COMP4_5_6_IRQn = 65,
    COMP7_IRQn = 66,
    HRTIM1_Master_IRQn = 67,
    HRTIM1_TIMA_IRQn = 68,
    HRTIM1_TIMB_IRQn = 69,
    HRTIM1_TIMC_IRQn = 70,
    HRTIM1_TIMD_IRQn = 71,
    HRTIM1_TIME_IRQn = 72,
    HRTIM1_FLT_IRQn = 73,
    HRTIM1_TIMF_IRQn = 74,
#endif
    CRS_IRQn = 75,
    SAI1_IRQn = 76,
#if defined(STM32G474xx)
    TIM20_BRK_IRQn = 77,
    TIM20_UP_IRQn = 78,
    TIM20_TRG_COM_IRQn = 79,
    TIM20_CC_IRQn = 80,
#endif
    FPU_IRQn = 81,
#if defined(STM32G474xx)
    I2C4_EV_IRQn = 82,
    I2C4_ER_IRQn = 83,
    SPI4_IRQn = 84,
    FDCAN2_IT0_IRQn = 86,
    FDCAN2_IT1_IRQn = 87,
    FDCAN3_IT0_IRQn = 88,
    FDCAN3_IT1_IRQn = 89,
#endif
    RNG_IRQn = 90,
    LPUART1_IRQn = 91,
    I2C3_EV_IRQn = 92,
    I2C3_ER_IRQn = 93,
    DMAMUX_OVR_IRQn = 94,
#if defined(STM32G474xx)
    QUADSPI_IRQn = 95,
    DMA1_Channel8_IRQn = 96,
#endif
    DMA2_Channel6_IRQn = 97,
#if defined(STM32G474xx)
    DMA2_Channel7_IRQn = 98,
    DMA2_Channel8_IRQn = 99,
#endif
    CORDIC_IRQn = 100,
    FMAC_IRQn = 101
} stm32g4_irqn_t;

#endif
