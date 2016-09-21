#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec {
int capacity;
int itemcount;
int *items;
};

void *emalloc(size_t s) {
    /* implementation of emalloc goes here */
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void *erealloc(void *p, size_t s) {
    /* implementation of erealloc goes here */
    void *result = realloc(p,s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

flexarray flexarray_new() {
/* initialise flexarray structure (including items array) */
    flexarray result = emalloc(sizeof *result);
    result->capacity =2;
    result->itemcount=0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

void flexarray_append(flexarray f, int num) {
/* add an item to the flexarray, expanding as necessary */
    if (f->itemcount == f->capacity) {
        f->capacity+=f->capacity;
        f->items=erealloc(f->items, f->capacity * sizeof f->items[0]);
        /* do the old "double the capacity" trick */
    }
    f->items[f->itemcount++]=num; 
}

void flexarray_print(flexarray f) {
/* a "for" loop to print out each cell of f->items */
    int i;
    for(i=0;i<f->itemcount;i++){
        printf("%d\n",f->items[i]);
    }
}



void insertion_sort(flexarray f){
    int p, index, key, i; 

    /*For each position in a except the first.*/
    for(p=1; p < f->itemcount; p++){
        if(p== f->itemcount/2){
            for(i=0; i < f->itemcount; i++){
                fprintf(stderr, "%d\n", f->items[i])
            }
            }
        }
    
        /**While the item to the left of p is greater than p.*/
        while(index >0 && f->items[index] < f->items[index-1]){
            /*Pull out the item at p and store in key.*/
            key=f->items[index];
            /*Move item to the left of p to p.*/
            f->items[index]= f->items[index-1];
            /*The new gap will be filled with key.*/
            f->items[index-1]=key; 
            index--;
        }
    }
}

void flexarray_free(flexarray f) {
/* free the memory associated with the flexarray */
    free(f->items);
    free(f);
}
