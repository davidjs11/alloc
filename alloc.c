/*   alloc.c   */

#include "alloc.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define HEAP_SIZE 4096
#define MAGIC_NUM 0x55


/* --- data structures --- */

typedef struct header_t {
    size_t  size;           /* block size */
    uint8_t magic;          /* magic number for integrity */
} header_t;

typedef struct node_t {
    size_t          size;   /* block size */
    struct node_t   *next;  /* next node in the free list */
} node_t;


/* --- data --- */

static uint8_t heap[HEAP_SIZE];
static node_t *free_list_head = NULL;


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
    node_t *node = free_list_head;
    while (node != NULL && node->size < size) {
        node = node->next;
    }

    return node;
}

void *next_fit(size_t size) { 
    /* TO-DO */
    return NULL;
}


/* --- public functions --- */

void *alloc(size_t size) {
    /* check free list hasn't been initialized */
    if (free_list_head == NULL) {
        free_list_head = (node_t *) heap;
        free_list_head->size = HEAP_SIZE - sizeof(node_t);
        free_list_head->next = NULL;
    }

    /* search for free node */
    node_t *free_node = (node_t *) first_fit(size);

    /* create new node */
    size_t new_size = free_node->size - size - sizeof(node_t);
    if (new_size > 0) {
        /* get address of new node */
        char *end = (char *) free_node;
        end += free_node->size + sizeof(node_t);
        node_t *new_node = (node_t *) end;

        /* check that the end doesn't pass the heap limit */
        if (end < (char *) heap + HEAP_SIZE - sizeof(node_t)) {
            new_node->size = new_size;
            new_node->next = free_node->next;

            /* recover pointer from previous node in free list */
            node_t *node = free_list_head;
            while (node->next != NULL && node->next != free_node)
                node = node->next;
            if (node->next == free_node)
                node->next = new_node;
        }
    }

    /* create header */
    header_t *header = (header_t *) free_node;
    header->size = size;
    header->magic = MAGIC_NUM;

    return header + 1;
}

void free(void *ptr) {
    /* TO-DO */
}
