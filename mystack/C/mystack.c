#include "mystack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef  struct Stack_t {
    #ifdef STACK_STATIC_MEM
    int stack_array[MAX_SIZE_STACK];
    #else
    int *stack_array;
    #endif

    int size;
    int capacity;
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

Stack_t* stackCreate(int capacity) {
    Stack_t* stack = (Stack_t*)malloc(sizeof(Stack_t));
    if (stack == NULL) {
        printf("Error: bad memmory allocation\n");
        return NULL;
    }
    stack->capacity = capacity;
    stack->stack_array = (int*)calloc( sizeof(int), stack->capacity);
    stack->size = 0;

    return stack;
}

void stackDestroy(Stack_t *st) {

    #ifndef STACK_STATIC_MEM
    free(st->stack_array);
    st->stack_array = NULL;
    free(st);
    st = NULL;
    #endif

}

#endif


int stackSize(Stack_t * st) {
    if (st != NULL) {
        return st->size;
    } else {
        printf("Error:\n");
        return -1;
    }
}

bool stackIsEmpty(Stack_t *st) {
    if (st != NULL) {
        return st->size <= 0;
    } else {
        printf("Error:\n");
        return false;
    }
}


bool stackIsFull(Stack_t *st) {
    if (st != NULL) {
        #ifdef STACK_STATIC_MEM
        return st->size == MAX_SIZE_STACK;
        #else
        return st->size == st->capacity;
        #endif
    } else {
        printf("Error:\n");
        return false;
    }
}

int stackTop(Stack_t *st) {
    if (st != NULL && !stackIsEmpty(st)) {
        return st->stack_array[st->size - 1];
    } else {
        printf("Error:\n");
        return -1;
    }
}

// Resize the stack (double the capacity)
bool resize(Stack_t* st) {
    int new_capacity = st->capacity * 2;
    int* new_array = (int*)realloc(st->stack_array, new_capacity * sizeof(int));

    if (!new_array) return false;  // Memory allocation failed

    st->stack_array = new_array;
    st->capacity = new_capacity;
    return true;
}

bool stackPush(Stack_t *st, int value) {

    if(stackIsFull(st)) {
        if (!resize(st)) {
            printf("Error: stack is full\n");
            return false;  // Resize failed
        }
    }

    if (st != NULL) {
         st->stack_array[st->size++] = value;
         return true;
    } else {
        printf("Error: addresses of stack is NULL\n");
        return false;
    }
}


bool stackPop(Stack_t *st) {
    if (st != NULL && !stackIsEmpty(st)) {
        st->size--;
        return true;
    } else {
        printf("Error: Stack is Empty\n");
        return false;
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