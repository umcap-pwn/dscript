#include <stdlib.h>

typedef struct {
    int bytes;
    void *next;   
} entry;

int push(int data, entry **sp){

    entry *ent = malloc(sizeof(entry));
    if(ent==NULL){return -1;}
    
    ent->bytes = data;
    ent->next = *sp;
    *sp = ent;
    
    return 0;
}

int pop(entry **sp){
    
    if (*sp==NULL){return -1;}
    
    entry *temp = *sp;
    int res = temp->bytes;
    *sp = temp->next;
    
    free(temp);
    
    return res;
}


