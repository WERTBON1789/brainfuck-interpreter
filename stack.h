#ifndef STACK_H
#define STACK_H 1

#include <stdio.h>

typedef struct STACK_NODE {
    struct STACK_NODE* next;
    int cell;
    int jump_to;
} STACK_NODE;

typedef struct STACK {
    STACK_NODE* head;
} STACK;

void push(STACK* stack, const int cell, const int jump_to);
void pop(STACK* stack);

#endif
