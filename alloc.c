/*   alloc.c   */

#include "alloc.h"
#include <stdint.h>
#include <stdio.h>

#define HEAP_SIZE 4096
#define MAGIC_NUM 0x55


/* --- data structures --- */

typedef struct header_t {
    size_t  size;           /* block size */
    uint8_t magic_num;      /* magic number for integrity */
} header_t;

typedef struct node_t {
    size_t          size;   /* block size */
    struct node_t   *next;  /* next node in the free list */
} node_t;


/* --- data --- */

static uint8_t heap[HEAP_SIZE];
static node_t  head = {
    .size = HEAP_SIZE - sizeof(node_t),
    .next = NULL,
};


/* --- private functions --- */

void *best_fit(size_t size) { 
    /* TO-DO */
    return NULL;
}

void *worst_fit(size_t size) {
    /* TO-DO */
    return NULL;
}

void *first_fit(size_t size) { 
    node_t *node = &head;
    while (node != NULL && node->size < size) {
        node = &(node->next);
    }

    return node;
}

void *next_fit(size_t size) { 
    /* TO-DO */
    return NULL;
}


/* --- public functions --- */

void *alloc(size_t size) {
    /* search for free space */
    void *node = first_fit(size);
    /* assert(node != NULL); */

    /*
    node_t old_node = *((node *) node);
    old_node.size = old_node.size - size;
    */
    
    /* create header */
    /*
    headet_t *header = (header_t *) node;
    header->size = size;
    header->magic_num = MAGIC_NUM;

    node = node + sizeof(header_t);
    */

    /* register node */
    /*
    *((node_t *) node + size) = old_node;
    */

    return node;
}

void free(void *ptr) {
    /* TO-DO */
}
