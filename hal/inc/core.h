#include <stdint.h>

#define NVIC_BASE   (0xE000E000UL)
#define NVIC_ISER   ((volatile uint32_t *) (NVIC_BASE + 0x100))