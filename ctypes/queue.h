// It's licensed under MIT, btw
// 02/2023
#ifndef _CTYPES_QUEUE_H
#define _CTYPES_QUEUE_H

#include <stdlib.h>

struct queue_item_t
{
    void *item;
    struct queue_item_t *next;
};

struct queue_t
{
    size_t size;
    struct queue_item_t *tail;
    struct queue_item_t *head;
};

typedef struct queue_t queue_t;

queue_t queue_new();
int queue_empty(queue_t q);

void* queue_front(queue_t q);
void* qeque_back(queue_t q);

void queue_push(queue_t* q, void* item, size_t size);
void queue_pop(queue_t* q);

#endif