#include "includes.h"
#include "cpu.h"
#include "memory.h"
#include "io.h"

enum flags {
    FP = 1 << 0,
    FZ = 1 << 1,
    FN = 1 << 2
};

// UTILITIES

void uf(enum regist r) {
    if (reg[r] == 0) {
        reg[RCND] = FZ;
    } else if (reg[r] >> 15) { // checking sign bit, negative case in two's complement
        reg[RCND] = FN;
    } else {
        reg[RCND] = FP;
    }
}

#define SEXTIMM(i) sext(IMM(1), 5)
uint16_t sext(uint16_t n, int b) {
    // if the b-th bit of n is 1 (number is negative)
    return ((n >> (b-1)) & 1) ?
    // fill up remaining bits with 1s
        (n | (0xFFFF << b)) : n; // else return number as is
}

// checks the instruction flag bit
#define FIMM(i) (((i) >> 5) & 1)

// extract Destination Register index
#define DR(i) (((i) >> 9) & 0x7)
// extract Source Register 1 or 2 index
#define SR1(i) (((i) >> 6) & 0x7)
#define SR2(i) ((i) & 0x7)
// extract 11th flag bit
#define FL(i) ((i) & 0x800)
// not sure what this one is supposed to do?
#define IMM(i) ((i) & 0x1F)
// extract 9 bits of offset from i
#define POFF11(i) sext((i) & 0xFFF, 11)
#define POFF9(i) sext((i) & 0x1FF, 9) 
#define POFF6(i) sext((i) & 0x3F, 6)
// extract trap vector
#define TRP(i) ((i) & 0xFF)

// conditional branch
void br(uint16_t i) {
    if (reg[RCND] & DR(i)) { // if RCND has the instruction's flag set
        reg[RPC] += POFF9(i); // branch to offset
    }
}

// addition
void add(uint16_t i) {
    reg[DR(i)] = reg[SR1(i)] +
        (FIMM(i) ?
            SEXTIMM(i) :
            reg[SR2(i)]);
    uf(DR(i));
}

// load RPC + offset

void ld(uint16_t i) {
    reg[DR(i)] = mr(reg[RPC] + POFF9(i));
    uf(DR(i));
}

// store
void st(uint16_t i) {
    mw(reg[RPC] + POFF9(i), reg[DR(i)]);
}

// jump to subroutine
void jsr(uint16_t i) {
    reg[R7] = reg[RPC];
    reg[RPC] = (FL(i)) ?
        reg[RPC] + POFF11(i) :
        reg[SR1(i)];
}

// bitwise logical AND
void and(uint16_t i) {
    reg[DR(i)] = reg[SR1(i)] &
        (FIMM(i) ?
            SEXTIMM(i) :
            reg[SR2(i)]);
    uf(DR(i));
}

// load base + offset
void ldr(uint16_t i) {
    reg[DR(i)] = mr(reg[SR1(i)] + POFF6(i));
    uf(DR(i));
}

// store base + offset
void str(uint16_t i) {
    mw(reg[SR1(i)] + POFF6(i), reg[DR(i)]);
}

// return from interrupt
// TODO implement later
void rti(uint16_t i) {

}

// bitwise complement
void not(uint16_t i) {
    reg[DR(i)] = ~reg[SR1(i)];
    uf(DR(i));
}

// load indirect
void ldi(uint16_t i) {
    reg[DR(i)] = mr(mr(reg[RPC] + POFF9(i)));
    uf(DR(i));
}

// store indirect
void sti(uint16_t i) {
    mw(
        mr(reg[RPC] + POFF9(i)),
        reg[DR(i)]
    );
}

// jump/return to subroutine
void jmp(uint16_t i) {
    reg[RPC] = reg[SR1(i)];
}

// unused opcode, reserved
void res(uint16_t i) {}

// load effective address
void lea(uint16_t i) {
    reg[DR(i)] = reg[RPC] + POFF9(i);
    uf(DR(i));
}

// system trap/call
void trap(uint16_t i) {
    trp_ex[TRP(i) - trp_offset]();
}