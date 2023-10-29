#ifndef IO_H
#define IO_H

typedef void (*trp_ex_f)();

void tgetc();
void tout();
void tputs();
void tin();
void tputsp();
void thalt();
void tinu16();
void toutu16();

enum { trp_offset = 0x20 };
trp_ex_f trp_ex[8] = {
    tgetc, tout, tputs, tin, tputsp, thalt, tinu16, toutu16
};

#endif