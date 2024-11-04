/*   main.c   */

#include <stdio.h>
#include "alloc.h"

int main(int argc, char *argv[]) {
    int *nums = (int *) alloc(500 * sizeof(int));

    int i;
    for (i = 0; i < 500; i++)
        nums[i] = i;

    char *msg = alloc(10);
    for (i = 0; i < 10; i++)
        msg[i] = 'a' + i;
    msg[9] = 0x00;

    for (i = 0; i < 500; i++)
        printf("%d ", nums[i]);
    printf("\n");
    printf("%s\n", msg);

    return 0;
}
