#ifndef IO_H
#define IO_H

typedef void (*trp_ex_f)();

static inline void tgetc();
static inline void tout();
static inline void tputs();
static inline void tin();
static inline void tputsp();
static inline void thalt();
static inline void tinu16();
static inline void toutu16();

enum { trp_offset = 0x20 };
trp_ex_f trp_ex[8] = {
    tgetc, tout, tputs, tin, tputsp, thalt, tinu16, toutu16
};

#endif