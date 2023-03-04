// It's licensed under MIT, btw
#ifndef __CTYPES_DEQUE_H
#define __CTYPES_DEQUE_H

#include "comparator.h"

#include <stddef.h> // size_t

// The item stored in the deque
struct deque_item_t {
    cmp_item_t item;
    //void *item;

    struct deque_item_t *prev;
    struct deque_item_t *next;
};


// The deque itself, should be assigned the value of `deque_new()` or zeroed manually
struct deque_t {
    size_t size;

    struct deque_item_t *tail;
    struct deque_item_t *head;    
};

typedef struct deque_t deque_t;


// Returns `deque_t` filled with zeroes
deque_t deque_new();

// Returns a boolean value indicating wheether or not `L` is empty
int deque_empty(deque_t L);

// Returns the number of elements
size_t deque_size(deque_t L);


// Accesses the first element
void* deque_front(deque_t L);

// Accesses the last element
void* deque_back(deque_t L);

// Inserts an element to the beginning
void deque_push_front(deque_t* L, void* item, size_t size);

// Inserts an element at the end
void deque_push_back(deque_t* L, void* item, size_t size);


// Removes the first element
void deque_pop_front(deque_t* L);

// Removes the last element
void deque_pop_back(deque_t* L);

// Inserts an element at the specified index
// (Acts as `deque_push_back()` if deque is too small)
void deque_insert(deque_t* L, int at, void* item, size_t size);

// Removes an element at the specified index
// (Does `nothing` if deque is too small)
void deque_remove(deque_t* L, int at);

// Accesses an element at the specified index
// 0 if not found
void* deque_at(deque_t L, int at);

// Returns the number of elements mathing specific key
int deque_count(deque_t L, void* item, size_t size);

#endif