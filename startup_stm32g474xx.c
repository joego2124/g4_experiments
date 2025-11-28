#include <stdint.h>

extern int main();
extern uint32_t _estack;

void reset_handler() {
	main();
	while(1);
}

void hardfault_handler() {
	while(1);
}

typedef void (*isr_t)(void);

__attribute__((used, section(".isr_vector")))
static const isr_t vector_table[115] = {
	(isr_t)&_estack,
	reset_handler,
	0,
	hardfault_handler,
};