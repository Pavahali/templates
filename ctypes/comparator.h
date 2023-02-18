// It's licensed under MIT, btw
// ! NOT TESTED !
#ifndef __CTYPES_COMPARATOR_H
#define __CTYPES_COMPARATOR_H

#include <stdlib.h> // size_t
#include <stdint.h> // uint8_t

// An element which can be compared independently of its type
struct cmp_item_t {
    void *item;
    size_t size;
};

typedef struct cmp_item_t cmp_item_t;

int cmp_shorter(cmp_item_t a, cmp_item_t b);
int cmp_longer(cmp_item_t a, cmp_item_t b);


int cmp_smaller_le(cmp_item_t a, cmp_item_t b);
int cmp_greater_le(cmp_item_t a, cmp_item_t b);

int cmp_smaller_be(cmp_item_t a, cmp_item_t b);
int cmp_greater_be(cmp_item_t a, cmp_item_t b);

int cmp_smaller(cmp_item_t a, cmp_item_t b);
int cmp_bigger(cmp_item_t a, cmp_item_t b);


#endif