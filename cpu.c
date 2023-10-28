#include "includes.h"
#include "cpu.h"

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

// conditional branch
static inline void br(uint16_t i) {
    // TODO
}

// addition
static inline void add(uint16_t i) {

}

// load RPC + offset
static inline void ld(uint16_t i) {

}

// store
static inline void st(uint16_t i) {

}

// jump to subroutine
static inline void jsr(uint16_t i) {

}

// bitwise logical AND
static inline void and(uint16_t i) {

}

// load base + offset
static inline void ldr(uint16_t i) {

}

// store base + offset
static inline void str(uint16_t i) {

}

// return from interrupt
// TODO implement later
static inline void rti(uint16_t i) {

}

// bitwise complement
static inline void not(uint16_t i) {

}

// load indirect
static inline void ldi(uint16_t i) {

}

// store indirect
static inline void sti(uint16_t i) {

}

// jump/return to subroutine
static inline void jmp(uint16_t i) {

}

// unused opcode, reserved
static inline void res(uint16_t i) {}

// load effective address
static inline void lea(uint16_t i) {

}

// system trap/call
static inline void trap(uint16_t i) {
    
}