#include "includes.h"
#include <stdio.h>
#include "cpu.h"
#include "io.h"
#include "memory.h"
#include "globals.h"

void tgetc() {
    reg[R0] = getchar();
}

void tout() {
    fprintf(stdout, "%c", (char)reg[R0]);
}

void tputs() {
    uint16_t *p = mem + reg[R0];
    while(*p) {
        fprintf(stdout, "%c", (char)*p);
        p++;
    }
}

void tin() {
    tgetc();
    tout();
}

void tputsp() {
    uint16_t *p = mem + reg[R0];
    char *cp = (char*)p;
    while(*cp) {
        fprintf(stdout, "%c", *p);
        cp++;
    }
}

void thalt() {
    running = false;
}

void tinu16() {
    fscanf(stdin, "%hu", &reg[R0]);
}

void toutu16() {
    fprintf(stdout, "%hu\n", reg[R0]);
}