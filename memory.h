#ifndef MEMORY_H
#define MEMORY_H
uint16_t PC_START = 0x3000;
uint16_t mem[__UINT16_MAX__+1] = {0};

uint16_t mr(uint16_t address);
void mw(uint16_t address, uint16_t val);
#endif