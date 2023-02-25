// It's licensed under MIT, btw
#ifndef __CTYPES_LIST_H
#define __CTYPES_LIST_H

#include "comparator.h"

#include <stddef.h> // size_t

// The item stored in the list
struct list_item_t {
    cmp_item_t item;
    //void *item;

    struct list_item_t *prev;
    struct list_item_t *next;
};


// The list itself, should be assigned the value of `list_new()` or zeroed manually
struct list_t {
    size_t size;

    struct list_item_t *tail;
    struct list_item_t *head;    
};

typedef struct list_t list_t;


// Returns `list_t` filled with zeroes
list_t list_new();

// Returns a boolean value indicating wheether or not `L` is empty
int list_empty(list_t L);

// Returns the number of elements
size_t list_size(list_t L);


// Accesses the first element
void* list_front(list_t L);

// Accesses the last element
void* list_back(list_t L);

// Inserts an element to the beginning
void list_push_front(list_t* L, void* item, size_t size);

// Inserts an element at the end
void list_push_back(list_t* L, void* item, size_t size);


// Removes the first element
void list_pop_front(list_t* L);

// Removes the last element
void list_pop_back(list_t* L);

// Inserts an element at the specified index
// (Acts as `list_push_back()` if list is too small)
void list_insert(list_t* L, int at, void* item, size_t size);

// Removes an element at the specified index
// (Does `nothing` if list is too small)
void list_remove(list_t* L, int at);

// Accesses an element at the specified index
// 0 if not found
void* list_at(list_t L, int at);

// Returns the number of elements mathing specific key
int list_count(list_t L, void* item, size_t size);

#endif