#ifndef CPU_H
#define CPU_H

#define OPC(i) ((i)>>12)
#define NOPS (16) // number of different instructions

enum regist {
    R0 = 0,
    R1,
    R2,
    R3,
    R4,
    R5,
    R6,
    R7,
    RPC,
    RCND,
    RCNT
};
uint16_t reg[RCNT] = {0};


typedef void (*op_ex_f)(uint16_t instruction);

// conditional branch
void br(uint16_t i);
// addition
void add(uint16_t i);

// load RPC + offset
void ld(uint16_t i);

// store
void st(uint16_t i);

// jump to subroutine
void jsr(uint16_t i);

// bitwise logical AND
void and(uint16_t i);

// load base + offset
void ldr(uint16_t i);

// store base + offset
void str(uint16_t i);

// return from interrupt
// TODO implement later
void rti(uint16_t i);

// bitwise complement
void not(uint16_t i);

// load indirect
void ldi(uint16_t i);

// store indirect
void sti(uint16_t i);

// jump/return to subroutine
void jmp(uint16_t i);

// unused opcode, reserved
void res(uint16_t i);

// load effective address
void lea(uint16_t i);

// system trap/call
void trap(uint16_t i);

op_ex_f op_ex[NOPS] = {
    br,
    add,
    ld,
    st,
    jsr,
    and,
    ldr,
    str,
    rti,
    not,
    ldi,
    sti,
    jmp,
    res,
    lea,
    trap
};
#endif