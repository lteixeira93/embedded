#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool substringExist(char check[], char onString[]);

int main(void) {
    /* code */
    char check[] = "Brasil";
    char onString[] = "o Brazil fica naamerica do sul no Brasil";

    printf("Is substring: %s\n", substringExist(check, onString) ? "True" : "False");

    return 0;
}

bool substringExist(char check[], char onString[]) {
    int i, j;

    int checkLen = strlen(check);
    int onStringLen = strlen(onString);
    int end = onStringLen - checkLen + 1;

    int firstOccur = strcspn(onString, check);

    for (i = firstOccur; i < end; i++) {
        bool isSubstring = true;

        for (j = 0; j < checkLen; j++) {
            printf("i: %d - j: %d\n", i, j);
            
            if (check[j] != onString[i + j]) {
                printf("False\n");
                isSubstring = false;
                break;
            }        

            printf("True\n");    
        }
        
        if (isSubstring) return true;
    }

    return false;
}