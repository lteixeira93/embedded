#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool substringExist(char s1[], char s2[]);

int main(void) {
    /* code */
    char s1[] = "Brasil";
    char c2[] = "o Brazil fica naamerica do sul no Brasil";

    printf("Is substring: %s\n", substringExist(s1, c2) ? "True" : "False");

    return 0;
}

bool substringExist(char check[], char onString[]) {
    int firstOccur, i, j;
    char s3[strlen(check)];

    firstOccur = strcspn(onString, check);

    printf("firstOccur: %d\n", firstOccur);

    for (i = firstOccur; i < strlen(check)+firstOccur; i++) {
        s3[j] = onString[i];
        j++;
    }

    j = 0;

    printf("%s\n", s3);
    
    if (strcmp(check, s3) == 0) {
        printf("Return true\n");
        return true;
    } else {        
        for (i = firstOccur; i < strlen(check)+firstOccur; i++) {
            onString[i] = '-';
        }
    }
    

    
}