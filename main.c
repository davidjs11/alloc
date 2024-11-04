/*   main.c   */

#include <stdio.h>
#include "alloc.h"

int main(int argc, char *argv[]) {
    int *nums = (int *) alloc(10 * sizeof(int));
    int i;
    for (i = 0; i < 10; i++)
        nums[i] = i;
    for (i = 0; i < 10; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}
