// It's licensed under MIT, btw
#ifndef _CTYPES_STACK_H
#define _CTYPES_STACK_H

#include <stddef.h> // size_t


// The item stored in the stack
struct stack_item_t {
    void *item;
    struct stack_item_t *prev;
};

// The stack itself. Should be assingned the value of `stack_new()` or zeroed manually
struct stack_t {
    size_t size;
    struct stack_item_t *head;
};

typedef struct stack_t stack_t;


// Returns `stack_t` filled with zeroes
// Can be replaced with {0, 0}
stack_t stack_new(void);

// Returns a boolean value indicating whether or not `S` is empty 
int stack_empty(stack_t S);

// Accesses the top element
void *stack_top(stack_t S);


// Inserts `item` (its first `N` bytes) at the top
void stack_push(stack_t *S, void *item, size_t size);

// Removes the top element
void stack_pop(stack_t *S);

#endif