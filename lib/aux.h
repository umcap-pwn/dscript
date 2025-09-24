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

extern int parse_bc (char* file, instruction *seq, int seq_len){

	FILE *fd = fopen(file, "r");
	int count, sqp = 0;
	instruction ins;
	char o, a;
	
	printf("starting to analyse bytecode. \
		writing into buffer with size %d\n", seq_len);

	while(!((o = fgetc(fd)) == EOF) && (!((a = fgetc(fd)) == EOF)))
	{
		ins.opcode = o;
		ins.arg = a;
		if(sqp < seq_len)
		{
			seq[sqp++] = ins;
			printf("Writing down to %d'th position in seq\n", sqp);
		}

	}

	fclose(fd);
	ins.arg = (ins.opcode = 0);
	seq[sqp] = (ins);
	printf("Finished parsing! got %d instructions.\n", sqp);
}

/*
int exec (VM *vm, instruction *ins, int (*ops[])(VM*)){
	return ops[ins->opcode](vm);
}
*/

#endif
