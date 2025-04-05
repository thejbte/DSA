#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t {
    int data;
    Node_t* next;
} Node_t;

Node_t* list;

Node_t* listInitialize(){
    list = NULL;
    return list;
}

void listDestroy(Node_t *head) {
    Node_t *tmp;
        while(head->next != NULL) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    free(head);
}

bool listInsertFront(Node_t **head, int value) {
    Node_t* tmpHead = *head;
    Node_t * newNode = malloc(sizeof(Node_t));
    if (newNode == NULL) {
        printf("Error: bad memory allocation");
        return false;
    }
    newNode->data = value;
    newNode->next = tmpHead;
    *head = newNode;
}

//append
bool listInsertBack(Node_t **head, int value) {
    Node_t * tmp = *head;
    Node_t * newNode;
    bool retVal = false;
    newNode = malloc(sizeof(Node_t));
    if (newNode == NULL) {
        printf("Error: bad memory allocation");
        return false;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return true;
    }

    while(tmp->next != NULL) {

        tmp = tmp->next;
    }

    tmp->next = newNode;

    return true;
}

bool listInsertAt(Node_t **head, int index, int value) {
    Node_t * current = *head;
    Node_t*  newNode;
    int counter = 0;
    Node_t * prevNode;

    if (head != NULL){
        newNode = malloc(sizeof(Node_t));
        if (newNode == NULL) {
            printf("Error: bad memory allocation");
            return false;
        }
        newNode->data = value;
        newNode->next = NULL;

        if (index  == 0) {
            newNode->next = *head;
            *head = newNode;
            return true;
        }




        while(counter != index && current->next != NULL) {

            ++counter;
            prevNode = current;
            current = current->next;
        }
        prevNode->next = newNode;
        newNode->next = current;
        return true;
    } else
        return false;
}

void listPrint(Node_t *head) {
    Node_t * tmp = head;
    while(tmp->next != NULL) {
        printf("Node addr: %08X, value: %d  next:%08X\n", tmp, tmp->data, tmp->next);
        tmp = tmp->next;
    }
    printf("Node addr: %08X, value: %d next:%08X\n", tmp, tmp->data,  tmp->next);
}


void listRemoveBack(Node_t *head) {
    Node_t * tmp = head;
    Node_t* prev = NULL;

    while(tmp->next != NULL) {
        prev = tmp;
        tmp = tmp->next;
    }
    free(tmp);
    tmp = NULL;
    prev->next = NULL;
}

void listRemoveFront(Node_t **head) {
    Node_t * tmp = *head;
    *head = tmp->next;
    free(tmp);

}

void listRemoveAt(Node_t **head, int index) {
    Node_t * current = *head;
    Node_t* prev = NULL;
    int counter = 0;

    if (index == 0) {
        *head = current->next;
        free(current);
        return;
    }


    while(counter != index && current->next != NULL) {

        ++counter;
        prev = current;
        current = current->next;
    }


    prev->next = current->next;
    free(current);
    current = NULL;
}