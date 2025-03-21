#include "list.h"
#include <stdio.h>
//gcc main.c list.c -g -o build/main
//valgrind --leak-check=full ./build/main
int main () {

    Node_t *list;
    list = listInitialize();
    listInsertFront(&list, 20);
    listInsertFront(&list, 30);

    listInsertBack(&list, 1);
    listInsertBack(&list, 2);
    listInsertBack(&list, 3);
    listInsertBack(&list, 4);
    listInsertFront(&list, 33);
    printf("..Node addr: %08X  \n", list);
    listInsertAt(&list, 7, 99);
    listPrint(list);
    printf("---------------------\n");
    listRemoveBack(list);
    listRemoveFront(&list);
    listPrint(list);
        printf("---------------------\n");
    listRemoveAt(&list, 0);
    listRemoveAt(&list, 2);
    listRemoveAt(&list, 3);
        printf("---------------------\n");
    listPrint(list);
    listDestroy(list);
    return 0;
}