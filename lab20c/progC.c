#include <stdio.h>
#include <stdlib.h>


void repeats(int *array, int size){
    int i, x=0;
    int *rand_freq = malloc(size * sizeof rand_freq[0]);
    
    for (i = 0; i < size; i++) {
        rand_freq[i]+=1;
    }

    while(rand_freq[x]>1 && x < size){
        printf("%d occurs %d times\n", x, rand_freq[x]);
        x++;
    }

    free(rand_freq);

}

int main(void) {
    int array_size = 0;
    int *my_array;
    int i = 0;
    
    printf("Enter the size of the array: \n");
    scanf("%d", &array_size);
    
    my_array = malloc(array_size * sizeof my_array[0]);
    if (NULL == my_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    
    for (i = 0; i < array_size; i++) {
        my_array[i] = rand() % array_size; 
    }
    
    printf("What’s in the array:\n");
    for (i = 0; i < array_size; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");
    repeats(my_array, array_size);
    free(my_array);
    return EXIT_SUCCESS;
}
