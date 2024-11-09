/*   main.c   */

#include <stdio.h>
#include "alloc.h"

int main(int argc, char *argv[]) {
    int *nums1 = (int *) alloc(10 * sizeof(int));
    print_free_node_list();
    int *nums2 = (int *) alloc(10 * sizeof(int));
    print_free_node_list();
    int *nums3 = (int *) alloc(10 * sizeof(int));
    print_free_node_list();
    free(nums2);
    print_free_node_list();
    int *nums4 = (int *) alloc(10 * sizeof(int));
    print_free_node_list();

    free(nums1);
    free(nums3);
    free(nums4);

    return 0;
}
