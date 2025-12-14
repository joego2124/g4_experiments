#include <stdint.h>

typedef struct {
    volatile uint32_t ACR;         // Access Control Register (Latency, Prefetch)
    volatile uint32_t PDKEYR;      // Power-down Key Register
    volatile uint32_t KEYR;        // Flash Key Register (Unlock CR)
    volatile uint32_t OPTKEYR;     // Option Byte Key Register
    volatile uint32_t SR;          // Status Register (Busy, Errors)
    volatile uint32_t CR;          // Control Register (Program/Erase ops)
    volatile uint32_t ECCR;        // ECC Control Register
    volatile uint32_t OPTR;        // Option Register
    volatile uint32_t PCROP1SR;    // PCROP1 Start Address
    volatile uint32_t PCROP1ER;    // PCROP1 End Address
    volatile uint32_t WRP1AR;      // WRP1 Area A Address
    volatile uint32_t WRP1BR;      // WRP1 Area B Address
} flash_t;

#define FLASH_BASE  (0x40022000UL)
#define FLASH       ((flash_t *) FLASH_BASE)