#include <stdlib.h>
#include "stack.h"



void push(STACK* stack, const int cell, const int jump_to) {
    STACK_NODE* n_ptr = (STACK_NODE*)malloc(sizeof(STACK_NODE));

    n_ptr->cell = cell;
    n_ptr->jump_to = jump_to;

    n_ptr->next = stack->head;

    stack->head = n_ptr;
}


void pop(STACK* stack) {
    STACK_NODE* r_node = stack->head;

    stack->head = stack->head->next;

    free(r_node);
}
