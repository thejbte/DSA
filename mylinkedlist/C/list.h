

#ifndef __LIST_H__
#define __LIST_H__

#include <stdbool.h>

typedef struct Node_t Node_t;

Node_t* listInitialize();

void listDestroy(Node_t *head);

bool listInsertFront(Node_t **head, int value);

bool listInsertBack(Node_t **head, int value);

bool listInsertAt(Node_t **head, int index, int value);

void listPrint(Node_t *head);

void listRemoveBack(Node_t *head);

void listRemoveFront(Node_t **head);

void listRemoveAt(Node_t **head, int index);

#endif //__LIST_H__