
// C++ program to illustrate Pointer Arithmetic
// in C/C++
#include <stdio.h>
 
// Driver program
int main()
{
    // // Declare an array
    // int v[3] = {10, 100, 200};
 
    // // Declare pointer variable
    // int *ptr;
 
    // // Assign the address of v[0] to ptr
    // ptr = v;
 
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("Value of *ptr = %d\n", *ptr);
    //     printf("Value of ptr = %p\n\n", ptr);
 
    //     // Increment pointer ptr by 1
    //     ptr++;
    // }

    int var = 10;

    int *ptr = &var;
    *ptr = 20;

    int **ptrDouble = &ptr;
    **ptrDouble = 30;

    int *ptrRef = NULL;
    ptrRef = *ptrDouble;

    printf("%p\n", &var);
    printf("%p\n", &ptr);
    printf("%p\n", &ptrDouble);
    printf("%p\n", &ptrRef);

    printf("%d\n", var);
    printf("%d\n", *ptr);
    printf("%d\n", **ptrDouble);

    *ptrRef = 100; 
    printf("%d\n", **ptrDouble);

}