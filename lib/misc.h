#include "dcore.h"
#include <stdio.h>

// extern int step     (VM *vm, instruction *seq);
// extern int parse_bc (char* file, instruction *seq);

#ifndef MISC_H
#define MISC_H

int step (VM *vm, int (*ops[])(VM*)){


	instruction ins = vm->prog[vm->ip++];
	if(!ins.opcode)
	{
		printf("EOS hit! Stopping...");
		return 1;
	}

	int (*op)(VM*) = ops[ins.opcode];
	printf("executing \n");
	
	return op(vm);
	
}
	
/*
int exec (VM *vm, instruction *ins, int (*ops[])(VM*)){
	return ops[ins->opcode](vm);
}
*/

#endif
