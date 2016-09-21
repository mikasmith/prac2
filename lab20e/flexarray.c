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
    void *result = realloc(p, s);
    if (NULL == result) {
        fprintf(stderr, "Memory reallocation failed!\n");
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

void selection_sort(flexarray f) {
    /* sort into ascending order */
    int p, c, small, key, i; 

    /*For each position c in the array a except the last one.*/
    for(p=0; p < f->itemcount-1 ; p++){
        if(p == f->itemcount/2){    
            for(c=0;c < f->itemcount;c++){
                fprintf(stderr,"%d\n",f->items[c]);
            }
        }
        
        small=p;
        for(i=p; i < f->itemcount ; i++){
            /*If the current element is larger than the right element.*/
            if(f->items[i] < f->items[small]){
                /*Set d as the smallest element in p.*/
                small=i;
            }
        }
        /**If the smallest element p is not in position c.*/
        
        /*Swap the two elements in positions p and c.*/
        key = f->items[p];
            
        f->items[p]= f->items[small];
        f->items[small]=key;             
    }
}

void flexarray_free(flexarray f) {
/* free the memory associated with the flexarray */
    free(f->items);
    free(f);
}
