#include <stdio.h>

#define SIZE 9

int biggerNum(int arr[]) {
    int bigger = -100, i;

    for (i = 0; i < SIZE; i++) {
        if (arr[i] > bigger) {
            bigger = arr[i];
        }       
    }

    return bigger;
}

int main(void) {
    /* code */
    int i, j = 0, counter, bigger, arr[] = { 4, 2, 9, 7, 5, 6, 7, 1, 3 };
    int k = 6;

    int arrRef[SIZE] = { 0 };
    
    for (counter = 0; counter < k; counter++) {
        bigger = biggerNum(arr);
        
        printf("Bigger: %d\n", biggerNum(arr));
        
        for (i = 0; i < SIZE; i++) {
            if (arr[i] == bigger) {
                arrRef[j] = bigger;
                arr[i] = 0;
                j++;
            }                
        }
    }

    for (i = 0; i < SIZE; i++) {
        printf("%d\n", arrRef[i]);       
    }   

    printf("kth element: %d\n", arrRef[k-1]);

    return 0;
}
