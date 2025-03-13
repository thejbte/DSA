#ifndef __MYSTACK__
#define __MYSTACK__

#include <stdbool.h>

#define MAX_SIZE_STACK (10)


//private definition in mystack.c
typedef struct Stack_t Stack_t;

#ifdef STACK_STATIC_MEM
Stack_t* stackInitialization(void);
#else
Stack_t* stackCreate(void);

void stackDestroy(Stack_t *st);
#endif



int stackSize(Stack_t * st);

bool stackIsEmpty(Stack_t *st);

bool stackIsFull(Stack_t *st);

int stackTop(Stack_t *st);

void stackPush(Stack_t *st, int value);


int stackPop(Stack_t *st);

void stackPrint(Stack_t *st);

#endif
