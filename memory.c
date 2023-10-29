#include "includes.h"
#include "memory.h"

uint16_t mr(uint16_t address) {
    return mem[address];
}

void mw(uint16_t address, uint16_t val) {
    mem[address] = val;
}