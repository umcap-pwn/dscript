#include <stdio.h>
#include <stdlib.h>
#include "lib/stack.h"
#include <stdint.h>

/* Virtual mashine for executing .dcode sequenses. */

/* Used to bundle operator and operand together. More readable than the embedded operands variant, though may waste some memory. */
typedef struct {
	uint8_t  *opcode;
	int          arg;	
} instruction;

/* General VM state. Memory management implemented primarily through a stack. */
typedef struct {
	int                *sp;
	int                *ip;
	instruction      *prog;
	int         stack[256];
} VM;

/* Just some helpful .dcode decls. Implementation can be found in lib/dops.h */
extern int _PUSH  (VM *vm);
extern int _ADD   (VM *vm);
extern int _PRINT (VM *vm);

/* Basic auxiliary function set. Decls in lib/misc.h */
extern int step     (VM *vm, instruction *seq);
extern int parse_bc (char* file, instruction *seq);
extern int exec     (int (*op)(VM *vm));

/* Initialisation of core data structs. */
int (*ops[])(VM *) = {
	_PUSH,
	_ADD, 
	_PRINT
};
instruction seq[1024];


int main (int argc, char **argv){

	parse_bc(argv[1], seq);

	VM vm = {
		.sp = 0,
		.ip = 0,
		.prog = seq 
	};

	for(;;)
	{
		if (step(&vm, seq)) break;
	}
	
}
