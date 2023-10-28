#ifndef MEMORY
#define MEMORY
uint16_t PC_START = 0x3000;
uint16_t mem[__UINT16_MAX__+1] = {0};

static inline uint16_t mr(uint16_t address);
static inline void mw(uint16_t address, uint16_t val);
#endif