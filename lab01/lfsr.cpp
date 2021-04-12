#include <iostream>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    uint16_t bit = 1 & *reg;
    bit = (1 & (*reg >> 2)) ^ bit;
    bit = (1 & (*reg >> 3)) ^ bit;
    bit = (1 & (*reg >> 5)) ^ bit;
    bit = bit << 15;
    *reg = *reg >> 1;
    *reg = *reg | bit;
    /* YOUR CODE HERE */
}

