#include <stdio.h> 
#include <stdlib.h>
#include <math.h>



int is_prime(int candidate){
    int n;
    
    for(n=2; n<candidate; n++){
        if(candidate%n == 0){
            return 0;
        }
    }
    return 1; 
}

int main(void){
    int candidate = 2;
    int num_printed = 0;
    while(num_printed < 200){
        if(is_prime(candidate)==1){
            printf("%05d  \n", candidate);
            num_printed++;
        }
        candidate++;
    }

    printf("\n");
    return EXIT_SUCCESS;
}
