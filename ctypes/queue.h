// It's licensed under MIT, btw
#ifndef _CTYPES_QUEUE_H
#define _CTYPES_QUEUE_H

#include <stdlib.h> // size_t

// The item stored in the queue
struct queue_item_t
{
    void *item;
    struct queue_item_t *next;
};

// The queue type. should be assigned the value of queue_new() or zeroed manually
struct queue_t
{
    size_t size;
    struct queue_item_t *tail;
    struct queue_item_t *head;
};

typedef struct queue_t queue_t;


// Returns `queue_t` filled with zeroes
// Can be replaced with {0, 0, 0}
queue_t queue_new();

// Returns a boolean value indicating whether or not `Q` is empty
int queue_empty(queue_t q);

// Returns the number of elements
size_t queue_size(queue_t q);


// Accesses the first element
void* queue_front(queue_t q);

// Accesses the last element
void* qeque_back(queue_t q);


// Inserts an element at the end
void queue_push(queue_t* q, void* item, size_t size);

// Removes the last element
void queue_pop(queue_t* q);

#endif