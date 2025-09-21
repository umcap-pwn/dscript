#include "dcore.h"
#include <stdio.h>

int _PUSH  (VM *vm) {puts("a"); return 0;}
int _ADD   (VM *vm) {puts("b"); return 0;}
int _PRINT (VM *vm) {puts("c"); return 0;}
int _RET   (VM *vm) {puts("d"); return 0;}


int (*ops[])(VM *) = {      // placed on .data
	  _RET,
          _PUSH,
          _ADD,
          _PRINT,
};



