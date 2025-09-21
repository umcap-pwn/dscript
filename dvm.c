#include <stdio.h>
#include <stdlib.h>
#include "lib/stack.h"
#include "lib/dcore.h"
#include "lib/misc.h"
#include "lib/dops.c"

/* Virtual mashine for executing .dcode sequenses. */

/* Just some helpful .dcode decls. Implementation can be found in lib/dops.c */
extern int _PUSH  (VM *vm);
extern int _ADD   (VM *vm);
extern int _PRINT (VM *vm);
extern int _RET   (VM *vm);

/* Basic auxiliary function set. Decls in lib/misc.h */
extern int step     (VM *vm, int (*ops[])(VM*));
extern int parse_bc (char* file, instruction *seq);
//extern int exec     (VM *vm, int (*op)(VM *vm));

/* Initialisation of core data structs. */
extern int (*ops[])(VM*);   // defined in lib/dops.c
instruction seq[1024];      // placed on .bss 


int main (int argc, char **argv){

	//parse_bc(argv[1], seq);

	for(uint8_t i=1;i<4;i++){
		instruction o = {i, 0};
		seq[i-1] = o;
	}

	VM vm = {
		.sp = 0,
		.ip = 0,
		.prog = seq //TODO: insecure transition. len(seq) is need to be stored somwhere 
	};

	for(;;)
	{
		if (step(&vm, ops)) break; // main VM lifecycle. TODO: error handling, stack trace. 
	}
}
