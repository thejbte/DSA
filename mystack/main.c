#include "mystack.h"
#include <stdio.h>

//gcc main.c mystack.c -g -Wall -o main
//valgrind  --leak-check=full ./main

//gcc main.c mystack.c -g -Wall -D STACK_STATIC_MEM -o main

int main() {

    #ifdef STACK_STATIC_MEM
    Stack_t *my_stack = stackInitialization();
    #else
    Stack_t *my_stack = stackCreate(5);
    #endif

    stackPrint(my_stack);

    stackPush(my_stack, 10);
    stackPush(my_stack, 20);
    stackPush(my_stack, 30);
    stackPush(my_stack, 40);
    stackPush(my_stack, 50);
    //to resize
    stackPush(my_stack, 10);
    stackPush(my_stack, 20);
    stackPush(my_stack, 30);
    stackPush(my_stack, 40);
    stackPush(my_stack, 50);


    stackPrint(my_stack);
    printf("top: %d\n",stackTop(my_stack));

    stackPop(my_stack);
    stackPop(my_stack);
    stackPop(my_stack);



    stackPrint(my_stack);
    printf("top: %d\n",stackTop(my_stack));


    #ifndef STACK_STATIC_MEM
    stackDestroy(my_stack);
    #endif


    return 0;
}