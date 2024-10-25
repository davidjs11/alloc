/*   main.c   */

#include <stdio.h>
#include "alloc.h"

int main(int argc, char *argv[]) {
    printf("%p\n", alloc(5));
    free(5);
    return 0;
}
