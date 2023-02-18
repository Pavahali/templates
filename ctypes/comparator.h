// It's licensed under MIT, btw
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

// ---
// Only sizes are compared, not the contents
//

// Is the size of `a` less or equal than the size of `b`?
int cmp_shorter(cmp_item_t a, cmp_item_t b) {
    return (a.size <= b.size);
}

// Is the size of `a` longer than the size of `b`?
int cmp_longer(cmp_item_t a, cmp_item_t b) {
    return (a.size <= b.size);
}

//
// ---

// ---
// Little-endian
//

// Is `a` less or equal to `b`? (In little-endian)
int cmp_smaller_le(cmp_item_t a, cmp_item_t b) {
    if (a.size != b.size) return cmp_shorter(a, b);

    uint8_t* aptr = (uint8_t*)a.item + a.size - 1;
    uint8_t* bptr = (uint8_t*)b.item + b.size - 1;

    while (aptr >= (uint8_t*)a.item && bptr >= (uint8_t*)b.item) {
        if (*aptr != *bptr) return *aptr <= *bptr;
        aptr++;
        bptr++;
    }
    return 1; // if a == b;
}

// Is `a` greater than `b`? (In little-endlian)
int cmp_greater_le(cmp_item_t a, cmp_item_t b) {
    if (a.size != b.size) return cmp_longer(a, b);

    uint8_t* aptr = (uint8_t*)a.item + a.size - 1;
    uint8_t* bptr = (uint8_t*)b.item + b.size - 1;

    while (aptr >= (uint8_t*)a.item && bptr >= (uint8_t*)b.item) {
        if (*aptr != *bptr) return *aptr > *bptr;
        aptr++;
        bptr++;
    }
    return 1; // if a == b;
}

//
// ---

// ---
// Big-Endian
//

// Is `a` less or equal to `b`? (In big-endian)
int cmp_smaller_be(cmp_item_t a, cmp_item_t b) {
    if (a.size != b.size) return cmp_shorter(a, b);

    
    uint8_t* aptr = (uint8_t*)a.item;
    uint8_t* bptr = (uint8_t*)b.item;

    while (aptr != (uint8_t*)(a.item + a.size) && bptr != (uint8_t*)(b.item + b.size)) {
        if (*aptr != *bptr) return *aptr <= *bptr;
        aptr++;
        bptr++;
    }
    return 1; // if a == b;
}

// Is `a` greater than `b`? (In big-endian)
int cmp_greater_be(cmp_item_t a, cmp_item_t b) {
    if (a.size != b.size) return cmp_longer(a, b);

    
    uint8_t* aptr = (uint8_t*)a.item;
    uint8_t* bptr = (uint8_t*)b.item;

    while (aptr != (uint8_t*)(a.item + a.size) && bptr != (uint8_t*)(b.item + b.size)) {
        if (*aptr != *bptr) return *aptr > *bptr;
        aptr++;
        bptr++;
    }
    return 1; // if a == b;
}

//
// ---

// ---
// Platform-dependent
//

// Is `a` less or equal to `b`?
// If it does not work, consider manually specifying endianness
int cmp_smaller(cmp_item_t a, cmp_item_t b) {
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        return cmp_smaller_le(a, b);
    #else
        return cmp_smaller_be(a, b);
    #endif
}

// Is `a` greater than `b`?
// If it does not work, consider manually specifying endianness
int cmp_bigger(cmp_item_t a, cmp_item_t b) {
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        return cmp_greater_le(a, b);
    #else
        return cmp_greater_be(a, b);
    #endif
}

//
// ---


#endif