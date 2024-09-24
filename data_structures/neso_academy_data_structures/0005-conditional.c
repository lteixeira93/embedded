#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n = 0;
    //29 5 20
    do
    {
        scanf("%d", &n);
    } while (!(n>=1 && n<=100));
    
    if(((n % 3) == 0) && (n <= 20) && ((n >= 2) && (n <= 5))) 
    {
        printf("Weird\n");
    } 
    else if(((n % 2) == 0) && ((n >= 2) && (n <= 5))) 
    {
        printf("Not Weird\n");
    } 
    else if(((n % 2) == 0) && (n > 20)) 
    {
        printf("Not Weird\n");
    } 
    else if(((n % 2) == 0) && ((n >= 6) && (n <= 20))) 
    {
        printf("Weird\n");
    } 
    else printf("Weird\n");

    return 0;
}
