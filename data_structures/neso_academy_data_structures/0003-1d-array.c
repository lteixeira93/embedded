#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(int* x, int *y) 
{
    *x^=*y;
    *y^=*x;
    *x^=*y;
}

void populate_array(int *arr, int n) 
{
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n = 0, sum = 0;

    scanf("%d", &n);

    int *arr = malloc(n*sizeof(int));

    populate_array(arr, n);
    int i = 0, j = n-1;

    while (i < j)
    {
        swap(&arr[i], &arr[j]);

        i++;
        j--;
    }

    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    // 16 13 7 ----> 7 13 16 | 16 13 7 4 ----> 4 7 13 16

    return 0;
}