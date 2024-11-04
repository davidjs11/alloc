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

    free(nums);
    nums = NULL;

    char *msg = alloc(10);
    for (i = 0; i < 10; i++)
        msg[i] = 'a' + i;
    msg[9] = '\0';
    printf("%s\n", msg);

    return 0;
}
