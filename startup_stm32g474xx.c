#include <stdint.h>

extern int main();

// linker symbols
extern uint32_t _estack;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _idata;
extern uint32_t _sbss;
extern uint32_t _ebss;

void reset_handler() {
	// copy static values from FLASH to .data
	for (uint32_t i = 0; i < (&_edata - &_sdata); i++)
		*(&_sdata + i) = *(&_idata + i);

	// clear values in .bss
	for (uint32_t *p = &_sbss; p < &_ebss; p++)
		*p = 0;

	main();

	while(1); // should never get here
}

void __attribute__((weak)) hardfault_handler() { while(1); }

void __attribute__((weak)) nmi_handler() { while(1); }

void __attribute__((weak)) TIM3_irq_handler() {}

// MCU's interrupt vector table
typedef void (*iv_t)(void); 			// helper type def of "void f(void)"
__attribute__((used, section(".ivt")))  // tell linker to not throw away and give it a name
static const iv_t ivt[115] = {
	[0]	 = (iv_t)&_estack,
	[1]  = reset_handler,
	[2]  = nmi_handler,
	[3]  = hardfault_handler,
	[4 ... 114] = TIM3_irq_handler,
};