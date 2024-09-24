/*
Here we will see bubble sort. 
The bubble sort method starts at the beginning of an unsorted array and 'bubbles up' unsorted values towards the end, 
iterating through the array until it is completely sorted. It does this by comparing adjacent items and swapping them if they are out of order. 
The method continues looping through the array until no swaps occur at which point the array is sorted.

This method requires multiple iterations through the array and for average and worst cases has quadratic time complexity. 
While simple, it is usually impractical in most situations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// #define SORTED_ARRAY

void print_array(int arr[], int length);
void swap(int *x, int *y);
void bubble_sort(int arr[], int length);

int main(void) {
    /* code */    
#ifdef SORTED_ARRAY
    int arr[] = { -15, -1, 1, 1, 2, 3, 4, 5, 6 };    
#else
    int arr[] = { 6, 5, 3, 1, 8, 8, 2, -4, 15 };
#endif

    int arr_size = (sizeof(arr) / sizeof(int));

    bubble_sort(arr, arr_size);
    
    return 0;
}
void print_array(int arr[], int length) {
    printf("[ ");
    for (size_t i = 0; i < length; i++) {
        printf("%d ", arr[i]);        
    }
    printf("]\n"); 
}

void swap(int *x, int *y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

void bubble_sort(int arr[], int length) {    
    print_array(arr, length);

    bool swapping = 0, already_sorted = true;

    size_t i = 0;

    do {
        swapping = false;
        for (size_t j = 0; j < (length - 1); j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);   
                swapping = true;       
                already_sorted = false;      
                print_array(arr, length); 
            } 
        }
        i++;
        
    }while(swapping && i < length);
    
    if (already_sorted) {
        printf("Array already sorted\n");
    }
}