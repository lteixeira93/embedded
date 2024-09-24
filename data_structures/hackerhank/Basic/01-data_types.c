#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define BUFF_SIZE 100

int main() {
    int i = 4, j = 0;
    double d = 4.0, e = 0.0;
    char s[] = "HackerRank ";

    char t[BUFF_SIZE/2];

    scanf("%d %lf %[^\n]s", &j, &e, t);  
    
    printf("%d\n", i+j);
    printf("%.1lf\n", d+e);
    //strcat(s, t);    
    printf("%s%s\n", s, t);

    // Declare second integer, double, and String variables.
    
    // Read and save an integer, double, and String to your variables.
    
    // Print the sum of both integer variables on a new line.
    
    // Print the sum of the double variables on a new line.
    
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.

    return 0;
}