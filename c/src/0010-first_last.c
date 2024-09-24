#include <stdio.h>

#define SIZE 10

int main(void) {
    /* code */
    int i, first = 0, last = 0, arr[] = { 2, 4, 5, 5, 5, 5, 5, 7, 9, 9 }, arrRef[SIZE] = {0};    
    int target = 9;

    for (i = 0; i < SIZE; i++) {
        if (target == arr[i]) {
            first = i;
            break;
        }        
    }

    for (i = 0; i < SIZE; i++) {
        if (target == arr[i]) {
            arrRef[i]++;
        }        
    }

    for (i = 0; i < SIZE; i++) {
        printf("%d ", arrRef[i]);
        if (arrRef[i] == 1)
        {
            last = i;
        }        
    }
    
    printf("\nFirst: %d\n", first);
    printf("Last: %d\n", last);
    
    return 0;
}
