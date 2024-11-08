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
    node_t *node = free_list_head;
    node_t *best = NULL;

    while (node != NULL) {
        if (node->size >= size
        && (best == NULL || node->size < best->size))
            best = node;

        node = node->next;
    }

    return best;
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

void print_free_node_list(void) {
    node_t *node = free_list_head;
    size_t counter = 0;

    printf("--- free node list ----\n");
    while (node != NULL) {
        printf("--- node #%lu ----\n", counter);
        printf("addr: %p\n", node);
        printf("size: %lu\n", node->size);
        printf("next: %p\n", node->next);
        printf("\n");

        node = node->next;
        counter++;
    }
    printf("\n\n");
    
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
    printf("elected node: %p\n", free_node);
    if (free_node == NULL) return NULL;

    /* split the node if there is space available */
    size_t new_size = free_node->size - size;
    if (new_size >= sizeof(node_t)) {
        /* get chunk limit */
        char *endptr = (char *) free_node;
        endptr += size + sizeof(node_t);

        /* check that the chunk limit doesn't pass the heap limit */
        if (endptr < (char *) heap + HEAP_SIZE - sizeof(node_t)) {
            /* create new node */
            node_t *new_node = (node_t *) endptr;
            new_node->size = new_size - sizeof(node_t);
            new_node->next = free_node->next;

            /* recover pointer from previous node in free list */
            node_t *prev_node = free_list_head;
            while (prev_node->next != NULL
                && prev_node != free_node
                && prev_node->next != free_node)
                prev_node = prev_node->next;

            if (prev_node == free_list_head)
                free_list_head = new_node;
            else if (prev_node->next == free_node)
                prev_node->next = new_node;
        }
    }

    /* if full node is used, recover pointers */
    else {
        node_t *prev_node = free_list_head;

        while (prev_node->next != NULL
            && prev_node != free_node
            && prev_node->next != free_node)
            prev_node = prev_node->next;

        if (prev_node == free_list_head)
            free_list_head = free_node->next;
        else 
            prev_node->next = free_node->next;
    }

    /* create header */
    header_t *header = (header_t *) free_node;
    header->size = size;
    header->magic = MAGIC_NUM;

    return header + 1;
}

void free(void *ptr) {
    /* get header address and size */
    header_t *header = (header_t *) ptr - 1;
    size_t size = header->size;

    /* create new node */
    node_t *node = (node_t *) header;
    node->size = size;
    node->next = free_list_head;

    /* change list head to new node */
    free_list_head = node;
}
