#include "includes.h"
#include <stdio.h>
#include "cpu.h"
#include "io.h"
#include "memory.h"
#include "globals.h"

static inline void tgetc() {
    reg[R0] = getchar();
}

static inline void tout() {
    fprintf(stdout, "%c", (char)reg[R0]);
}

static inline void tputs() {
    uint16_t *p = mem + reg[R0];
    while(*p) {
        fprintf(stdout, "%c", (char)*p);
        p++;
    }
}

static inline void tin() {
    tgetc();
    tout();
}

static inline void thalt() {
    running = false;
}

static inline void tinu16() {
    fscanf(stdin, "%hu", &reg[R0]);
}

static inline void toutu16() {
    fprintf(stdout, "%hu\n", reg[R0]);
}