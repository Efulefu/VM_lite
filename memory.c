#include "includes.h"
#include "memory.h"

static inline uint16_t mr(uint16_t address) {
    return mem[address];
}

static inline void mw(uint16_t address, uint16_t val) {
    mem[address] = val;
}