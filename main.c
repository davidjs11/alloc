/*   main.c   */

#include <stdio.h>
#include "alloc.h"

int main(int argc, char *argv[]) {
    free(alloc(5));
    return 0;
}
