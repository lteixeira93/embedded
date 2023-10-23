#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    /* code */
    char s1[] = "astha"; // nameless, salesmen | input, putin | luiz, lizu | kardek, karpet | danger, garden
    char s2[] = "thasa";

    char alphabeticTable[] = "abcdefghijklmnopqrstuvwxyz";

    if (strlen(s1) != strlen(s2))
    {
        printf("Strings lenght differ\n");
        exit(1);
    }
    
    int size_s = strlen(s1)+1;
    int size_a = strlen(alphabeticTable)+1;

    int freqTableS1[size_a]; 
    int freqTableS2[size_a];

    int i, j;
    bool isAnagram = false;

    for (i = 0; i < size_a; i++) {
        freqTableS1[i] = 0;
        freqTableS2[i] = 0;
    }    

    for (i = 0; i < size_s; i++) {
        for (j = 0; j < size_a; j++) {
            if (s1[i] == alphabeticTable[j]) {
                freqTableS1[j]++;
            }         
            if (s2[i] == alphabeticTable[j]) {
                freqTableS2[j]++;
            }       
        }        
    }

    for (i = 0; i < size_a; i++) {        
        if(freqTableS1[i] == freqTableS2[i]) {
            isAnagram = true;
        }
        else {
            isAnagram = false;
            break;
        }
    }   

    printf("S1: %s | S2: %s - Is anagram: %s\n", s1, s2, isAnagram ? "True" : "False");    
    
    return 0;
}