// It's licensed under MIT, btw
#include "comparator.h"
#include "list.h"

#include <stdlib.h> // malloc() and free()
#include <string.h> // memcpy()

list_t list_new() {
    return (list_t){0, 0, 0};
}

int list_empty(list_t L) {
    return !(L.tail);
}

size_t list_size(list_t L) {
    return L.size;
}

void* list_front(list_t L) {
    if (list_empty(L)) return 0;
    else return cmp_item(L.tail->item);
}

void* list_back(list_t L) {
    if (list_empty(L)) return 0;
    else return cmp_item(L.head->item);
}

void list_push_front(list_t* L, void* item, size_t size) {
    struct list_item_t* newi = (struct list_item_t*)malloc(sizeof(struct list_item_t));
    
    newi->prev = 0;
    newi->item = cmp_item_new(item, size);
    
    if (list_empty(*L)) {
        L->tail = newi;
        L->head = L->tail;
    } else {
        newi->next = L->tail;
        L->tail->prev  = newi;
        L->tail = newi;
    }
    L->size++;
}

void list_push_back(list_t* L, void* item, size_t size) {
    struct list_item_t* newi = (struct list_item_t*)malloc(sizeof(struct list_item_t));
    
    newi->next = 0;
    newi->item = cmp_item_new(item, size);

    if (list_empty(*L)) {
        L->head = newi;
        L->tail = L->head;
    } else {
        newi->prev = L->head;
        L->head->next = newi;
        L->head = newi;
    }
    L->size++;
}

void list_pop_front(list_t *L) {
    if (list_empty(*L)) return;
    struct list_item_t* oldi = L->tail;

    if (L->head == L->tail) {
        L->head = 0;
        L->tail = 0;
    } else {
        L->tail = L->tail->next;
    }

    free(cmp_item(oldi->item));
    free(oldi);
    L->size--;
}

void list_pop_back(list_t *L) {
    if (list_empty(*L)) return;
    struct list_item_t* oldi = L->head;

    if (L->head == L->tail) {
        L->head = 0;
        L->tail = 0;
    } else {
        L->head = L->head->prev;
    }

    free(cmp_item(oldi->item));
    free(oldi);
    L->size--;
}

static struct list_item_t* __list_at(list_t L, int at) {
    if (list_empty(L)) return 0;
    struct list_item_t* p = L.tail;
    while (at--) {
        p = p->next;
        if (!p) return 0;
    }
    return p;
}

void* list_at(list_t L, int at) {
    if (list_empty(L)) return 0;
    struct list_item_t* p = L.tail;
    while (at--) {
        p = p->next;
        if (!p) return 0;
    }
    return cmp_item(p->item);
}


void list_insert(list_t* L, int at, void* item, size_t size) {
    struct list_item_t* p;
    struct list_item_t* newi;

    if (list_empty(*L)) list_push_back(L, item, size);
    else if (at == 0) list_push_front(L, item, size);
    else if (at >= L->size) list_push_back(L, item, size);
    else {
        newi = (struct list_item_t*)malloc(sizeof(struct list_item_t));
        newi->item = cmp_item_new(item, size);

        p = __list_at(*L, at-1);
        
        newi->prev = p;
        newi->next = p->next;
        newi->next->prev = newi;
        newi->prev->next = newi;

        L->size++;
    }
}

void list_remove(list_t* L, int at) {
    struct list_item_t* oldi;
    struct list_item_t* p;

    if (list_empty(*L)) return;
    else if (at == 0) list_pop_front(L);
    else if (at == L->size-1) list_pop_back(L);
    else if (at >= L->size) return;
    else {
        struct list_item_t* p = __list_at(*L, at-1);
        oldi = p->next;

        p->next = p->next->next;
        p->next->prev = p;
        
        free(cmp_item(oldi->item));
        free(oldi);
        L->size--;
    }
}

int list_count(list_t L, void* item, size_t size) {
    struct list_item_t *p = L.tail;
    cmp_item_t x = {item, size};

    int out = 0;
    while (p != 0) {
        if (cmp_equal(x, p->item)) out++;
        p = p->next;
    }
    return out;
}