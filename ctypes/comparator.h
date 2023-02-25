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

void* cmp_item(cmp_item_t x);

// Initialises new comparable item
cmp_item_t cmp_item_new(void* item, size_t size);

// Is `a` equal to `b`?
int cmp_equal(cmp_item_t a, cmp_item_t b);

// Is the size of `a` less or equal than the size of `b`?
int cmp_shorter(cmp_item_t a, cmp_item_t b);

// Is the size of `a` longer than the size of `b`?
int cmp_longer(cmp_item_t a, cmp_item_t b);


// Is `a` less or equal to `b`? (In little-endian)
int cmp_smaller_le(cmp_item_t a, cmp_item_t b);

// Is `a` greater than `b`? (In little-endlian)
int cmp_greater_le(cmp_item_t a, cmp_item_t b);

// Is `a` less or equal to `b`? (In big-endian)
int cmp_smaller_be(cmp_item_t a, cmp_item_t b);

// Is `a` greater than `b`? (In big-endian)
int cmp_greater_be(cmp_item_t a, cmp_item_t b);


// Is `a` less or equal to `b`?
// If it does not work, consider manually specifying endianness
int cmp_smaller(cmp_item_t a, cmp_item_t b);

// Is `a` greater than `b`?
// If it does not work, consider manually specifying endianness
int cmp_bigger(cmp_item_t a, cmp_item_t b);


#endif