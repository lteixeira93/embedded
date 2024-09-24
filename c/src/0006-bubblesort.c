#include <stdio.h>
#include <stdbool.h>

void swap(int *x, int *y) 
{
    *x^=*y;
    *y^=*x;
    *x^=*y;
}

void bubbleSort(int arr[], int length) {
    int i, j = 0;
    bool swapping = false;

    do {    
        swapping = false;

        for (i = 0; i < (length - 1 - j); i++) {
            if (arr[i] > arr[i+1]) {
                swap(&arr[i], &arr[i+1]);
                swapping = true;
            }        
        }  
        j++;  
         
    } while (swapping);   
}

int main(void) {
    /* code */
    int arr[] = { 6, 5, 3, 1, 8, 7, 2, 4, 15, -1, 16, 100, 98, -15, 26, 1 };
    // int arrSorted[] = { -15, -1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 15, 16, 26, 98, 100 };

    int length = sizeof(arr) / sizeof(int);

    bubbleSort(arr, length); 

    int i;
    
    for (i = 0; i < length; i++) {
        printf("%d ", arr[i]);        
    }
    printf("\n"); 

    return 0;
}