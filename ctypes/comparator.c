#include "comparator.h"
#include <string.h> // memcpy()
#include <stdio.h>

void* cmp_item(cmp_item_t x) {
    return x.item;
}

cmp_item_t cmp_item_new(void* item, size_t size) {
    void* out;

    out = malloc(size);
    memcpy(out, item, size);
    return (cmp_item_t){out, size};
}


// ---
// Platform independent
//

// Is `a` equal to `b`?
int cmp_equal(cmp_item_t a, cmp_item_t b) {
    if (a.size != b.size) {
        printf("%d != %d (size)\n", a.item, b.item);
        return 0;
    }

    uint8_t* aptr = (uint8_t*)a.item + a.size - 1;
    uint8_t* bptr = (uint8_t*)b.item + b.size - 1;

    while (aptr >= (uint8_t*)a.item && bptr >= (uint8_t*)b.item) {
        if (*aptr != *bptr) {
            return 0;
            printf("%d != %d (%d-th byte)\n", a.item, b.item, aptr-(uint8_t*)a.item);
        }
        aptr--;
        bptr--;
    }
    return 1;
}

//
// ---

// ---
// Little-endian
//

// Is `a` less or equal to `b`? (In little-endian)
int cmp_smaller_le(cmp_item_t a, cmp_item_t b) {
    if (a.size != b.size) return (a.size <= b.size);

    uint8_t* aptr = (uint8_t*)a.item + a.size - 1;
    uint8_t* bptr = (uint8_t*)b.item + b.size - 1;

    while (aptr >= (uint8_t*)a.item && bptr >= (uint8_t*)b.item) {
        if (*aptr != *bptr) return *aptr <= *bptr;
        aptr--;
        bptr--;
    }
    return 1; // if a == b;
}

// Is `a` greater than `b`? (In little-endlian)
int cmp_greater_le(cmp_item_t a, cmp_item_t b) {
    if (a.size != b.size) return (a.size > b.size);

    uint8_t* aptr = (uint8_t*)a.item + a.size - 1;
    uint8_t* bptr = (uint8_t*)b.item + b.size - 1;

    while (aptr >= (uint8_t*)a.item && bptr >= (uint8_t*)b.item) {
        if (*aptr != *bptr) return *aptr > *bptr;
        aptr--;
        bptr--;
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
    if (a.size != b.size) return (a.size <= b.size);

    
    uint8_t* aptr = (uint8_t*)a.item;
    uint8_t* bptr = (uint8_t*)b.item;

    while (aptr != (uint8_t*)a.item + a.size && bptr != (uint8_t*)b.item + b.size) {
        if (*aptr != *bptr) return *aptr <= *bptr;
        aptr++;
        bptr++;
    }
    return 1; // if a == b;
}

// Is `a` greater than `b`? (In big-endian)
int cmp_greater_be(cmp_item_t a, cmp_item_t b) {
    if (a.size != b.size) return (a.size > b.size);

    
    uint8_t* aptr = (uint8_t*)a.item;
    uint8_t* bptr = (uint8_t*)b.item;

    while (aptr != (uint8_t*)a.item + a.size && bptr != (uint8_t*)b.item + b.size) {
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
