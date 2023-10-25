#include <stdio.h>

void insertionSort(int arr[], int length) {
    int i, j, tmpStore = 0;
    
    for (i = 1; i < length; i++) {
        int key = arr[i];
        
        for (j = 1; j < length; j++) {
            
        }
    }    
}

int main(void) {
    /* code */
    int arr[] = {8, 7, 5, 4, 3, 2, 1};
    //{7, 8, 5, 4, 3, 2, 1}; // j=1, i=1
    //{7, 5, 8, 4, 3, 2, 1} -> {5, 7, 8, 4, 3, 2, 1}; // j=1, i=2

    int i, length = sizeof(arr) / sizeof(int);

    insertionSort(arr, length);

    for (i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    

    return 0;
}
