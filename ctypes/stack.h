// It's licensed under MIT, btw
// 02/2023
#ifndef _CTYPES_STACK_H
#define _CTYPES_STACK_H

#include <stddef.h> // size_t

struct stack_item_t {
    void *item;
    struct stack_item_t *prev;
};

struct stack_t {
    size_t size;
    struct stack_item_t *head;
};

typedef struct stack_t stack_t;


// Basically returns stack_t with zeroed pointers
// Can be replaced with {0, 0}
stack_t stack_new(void);

int stack_empty(stack_t S);
void *stack_top(stack_t S);

void stack_push(stack_t *S, void *item, size_t size);
void stack_pop(stack_t *S);

#endif