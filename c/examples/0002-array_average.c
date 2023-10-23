#include <stdio.h>

int main (void){
    /* code */
    int arr[] = { 2, -2 };
    
    int i, sumElements = 0, length = sizeof(arr) / sizeof(int);

    for (i = 0; i < length; i++) {
        sumElements += arr[i];
    }

    printf("Average is: %.4f\n", (float)sumElements/length);

    return 0;
}

