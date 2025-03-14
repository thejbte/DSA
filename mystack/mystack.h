#ifndef __MYSTACK__
#define __MYSTACK__

#include <stdbool.h>


//private definition in mystack.c
typedef struct Stack_t Stack_t;

#ifdef STACK_STATIC_MEM

#define MAX_SIZE_STACK (10)
Stack_t* stackInitialization(void);

#else

Stack_t* stackCreate(int capacity);

void stackDestroy(Stack_t *st);

#endif



int stackSize(Stack_t * st);

bool stackIsEmpty(Stack_t *st);

bool stackIsFull(Stack_t *st);

int stackTop(Stack_t *st);

bool resize(Stack_t* st);

bool stackPush(Stack_t *st, int value);


bool stackPop(Stack_t *st);

void stackPrint(Stack_t *st);

#endif
