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

static void half_print(int *a, int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\n", a[i]);
    }
}

static void insertion_sort(int*a, int n){
    int p,c,key;

    /*For each position in a except the first.*/
    
    for(c=1;c<=n-1;c++){
        p=c;
        /**While the item to the left of p is greater than p.*/
        while(p>0&&a[p]<a[p-1]){
            /*Pull out the item at p and store in key.*/
            key=a[p];
            /*Move item to the left of p to p.*/
            a[p]=a[p-1];
            /*The new gap will be filled with key.*/
            
            a[p-1]=key;
            p--;
        }
        if(c== n){
            half_print(a, n);
        }
       
    }
   
    
}

void flexarray_sort(flexarray f) {
/* sort into ascending order */
    insertion_sort(f->items, f->itemcount);
}

void flexarray_free(flexarray f) {
/* free the memory associated with the flexarray */
    free(f->items);
    free(f);
}
