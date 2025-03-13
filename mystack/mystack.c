#include "mystack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef  struct Stack_t {
    int stack_array[MAX_SIZE_STACK];
    int size;
    ///capacity
}Stack_t;

#ifdef STACK_STATIC_MEM
/* static memory*/

Stack_t stack;
Stack_t* stackInitialization(void) {
    memset(stack.stack_array, 0, sizeof(int)*MAX_SIZE_STACK);
    stack.size = 0;

    return &stack;
}

#else

Stack_t* stackCreate(void) {
    Stack_t* stack = malloc(sizeof(Stack_t));
    if (stack == NULL) {
        printf("Error: bad memmory allocation\n");
        return NULL;
    }
    memset(stack->stack_array, 0, sizeof(int)*MAX_SIZE_STACK);
    stack->size = 0;

    return stack;
}

void stackDestroy(Stack_t *st) {
    free(st);
    st = NULL;
}

#endif
int stackSize(Stack_t * st) {
    return st != NULL ? st->size : -1;
}

bool stackIsEmpty(Stack_t *st) {
    return st->size <= 0;
}


bool stackIsFull(Stack_t *st) {
    return st->size == MAX_SIZE_STACK;
}

int stackTop(Stack_t *st) {
    if (st != NULL && !stackIsEmpty(st)) {
        return st->stack_array[st->size - 1];
    } else {
        printf("Error:\n");
        return -1;
    }
}

void stackPush(Stack_t *st, int value) {
    if (st != NULL && !stackIsFull(st)) {
         st->stack_array[st->size++] = value;
    } else {
        printf("Error: stack is full\n");
    }
}


int stackPop(Stack_t *st) {
    if (st != NULL && !stackIsEmpty(st)) {
        return st->stack_array[st->size--];
    } else {
        printf("Error: Stack is Empty\n");
        return -1;
    }
}


void stackPrint(Stack_t *st) {
    for (size_t i = 0; i < stackSize(st); i++)
    {
        printf(" %d", st->stack_array[i] );
    }
    if (!stackSize(st)) {
        printf("Stack is empty\n");
    } else {
        printf("\n");
    }
}