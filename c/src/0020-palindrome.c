#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define DEBUG 

bool isPalindrome(char s1[], char s2[]) {
    if (strlen(s1) != strlen(s2)) {
        printf("Strings length differ\n");
        exit(1);
    }

    int i = 0, j = 0;
    bool isPalindrome = false;

#ifdef DEBUG
    printf("len(s1): %ld\n", strlen(s1));
    printf("len(s2): %ld\n", strlen(s2));
#endif // DEBUG

    j = strlen(s2)-1;

    while ((i <= strlen(s1)) && (j >= 0)) {
#ifdef DEBUG
        printf("i: %d\n", i);
        printf("j: %d\n", j);
        printf("s1[i]: %c\n", s1[i]);
        printf("s2[j]: %c\n", s2[j]);

#endif // DEBUG

        if (s1[i] == s2[j]) {
            isPalindrome = true;
        }
        else {
            isPalindrome = false;
            break;
        }

        i++;
        j--;        
    }  

    return isPalindrome;
}

int main(void) {
    char s1[] = "onibus";
    char s2[] = "subino";   

    printf("Is palindrome: %s\n", isPalindrome(s1, s2) ? "True" : "False");

    return 0;
}
