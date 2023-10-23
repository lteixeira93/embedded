#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int arrLength);
void swap(int *x, int*y);
void binarySearch(int arr[], int elementSearch, int left, int right);

int main(void) {
    /* code */
    int arrLength, arr[] = {9, 5, 13, 3, 8, 7, 2, 12, 6, 10, 4, 11, 1};
    
    arrLength = sizeof(arr) / sizeof(int);

    printf("%d\n", arrLength);

    bubbleSort(arr, arrLength);  

    binarySearch(arr, 11, 0, arrLength - 1);
    
    return 0;
}

void swap(int *x, int*y)  {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

void bubbleSort(int arr[], int arrLength) {
    bool swapping;
    int i;

    do {
        swapping = false;

        for (i = 0; i < arrLength; i++) {
            if(arr[i] > arr[i+1]) {
                swap(&arr[i], &arr[i+1]);
                swapping = true;
            }
        }
    } while (swapping);

    for (i = 0; i < arrLength; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

/*
1 2 3 4 5 6 7 8 9 10 11 12 13
                   * ^     *
left = 0
right = 12
middle = 6
arr[middle] = 7
elementSearch = 11

left = 7
right = 12
middle = 9
arr[middle] = 10
elementSearch = 11

left = 10
right = 12
middle = 11
arr[middle] = 12
elementSearch = 11

left = 10
right = 10
middle = 10
arr[middle] = 11
elementSearch = 11

The element is at position: 10
*/
void binarySearch(int arr[], int elementSearch, int left, int right)  {
    int middle = left + ((right - left) / 2);

    if (left > right) {
        printf("The element %d is not in the array\n", elementSearch);
        return;
    }    
    
    printf("left = %d\n", left);
    printf("right = %d\n", right);
    printf("middle = %d\n", middle);
    printf("arr[middle] = %d\n", arr[middle]);
    printf("elementSearch = %d\n\n", elementSearch);

    if(arr[middle] == elementSearch) {
        printf("The element is at position: %d\n", middle);
        return;
    }
    else if(arr[middle] > elementSearch) {
        binarySearch(arr, elementSearch, left, middle - 1);
    }
    else binarySearch(arr, elementSearch, middle + 1, right);
    
}