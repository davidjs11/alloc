/*   alloc.c   */

#include "alloc.h"
#include <stdint.h>

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

node_t *best_fit(size_t size) { 
    /* TO-DO */
    return NULL;
}

node_t *worst_fit(size_t size) {
    /* TO-DO */
    return NULL;
}

node_t *first_fit(size_t size) { 
    /* TO-DO */
    return NULL;
}

node_t *next_fit(size_t size) { 
    /* TO-DO */
    return NULL;
}


/* --- public functions --- */

void *alloc(size_t size) {
    /* TO-DO */
    return NULL;
}

void free(void *ptr) {
    /* TO-DO */
}
