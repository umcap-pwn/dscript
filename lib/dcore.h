#include <stdint.h>

#ifndef CORE_H
#define CORE_H

/* Core library defining global data structures. */

/* Used to bundle operator and operand together. More readable than the embedded operands variant, though may waste some memory. */
typedef struct {
      uint8_t      opcode;
      int          arg;
} instruction;

/* General VM state. Memory management implemented primarily through a stack. */ //TODO: external stack from lib/stack.c
typedef struct {
        int                 sp;
        int                 ip;
        instruction      *prog;
        int         stack[256];
} VM;


#endif 
