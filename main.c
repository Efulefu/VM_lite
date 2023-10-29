#include "includes.h"
#include <stdio.h>
#include "memory.h"
#include "io.h"
#include "cpu.h"
#include "globals.h"

void start(uint16_t offset) {
    reg[RPC] = PC_START + offset; // set RPC
    while(running) {
        // We extract instructions from the memory location
        // pointed by RPC, and autoincrement RPC
        uint16_t i = mr(reg[RPC]++);
        // We execute each instruction
        op_ex[OPC(i)](i);
    }
}

void ld_img(char *fname, uint16_t offset) {
    // open binary containint the VM program
    FILE *in = fopen(fname, "rb");
    if (NULL == in) {
        fprintf(stderr, "Cannot open file %s.\n", fname);
        exit(1);
    }
    // The position from where we start copying the file to main memory
    uint16_t *p = mem + PC_START + offset;
    // load program into memory
    fread(p, sizeof(uint16_t), (UINT16_MAX - PC_START), in);
    // close file stream
    fclose(in);
}

int main(int argc, char *argv[]) {
    ld_img(argv[1], 0x0);
    start(0x0);
    return 0;
}