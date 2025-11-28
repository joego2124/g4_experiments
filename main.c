#include <stdint.h>

extern int foo ();

int main () {
    uint8_t bar = foo();
    bar++;
    return 0;
}