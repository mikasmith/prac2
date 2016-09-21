#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"
#define ARRAY_MAX 10


/*void insertion_sort(int *a, int n) {

}

static void array_print(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    }*/


int main(void) {
    int item;
    flexarray my_flexarray = flexarray_new();
    
    while (1 == scanf("%d", &item)) {
        flexarray_append(my_flexarray, item);
    }
    
    selection_sort(my_flexarray);
    flexarray_print(my_flexarray);
    flexarray_free(my_flexarray);
    
    return EXIT_SUCCESS;
}
