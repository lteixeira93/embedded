#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    int n;
    int array[10];
    int *restrict restar = (int*)malloc(10*sizeof(int));
    int *par = array;

    for (n = 0; n < 10; n++)
    {
        par[n] += 5;
        restar[n] += 5;
        array[n] *= 5;
        par[n] +=3;
        restar[n] += 3;
    }
    
    return 0;
}
