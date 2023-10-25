#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

void FindIntersection(char * strArr[], int arrLength) {  
  // code goes here  
  int i, j, k = 0;

  int fullLenght = strlen(strArr[0])+strlen(strArr[1]) + 1;
  int fullLenght0 = strlen(strArr[0]) + 1 , fullLenght1 = strlen(strArr[1]) + 1;

  printf("fullLenght0: %d\n", fullLenght0);
  printf("fullLenght1: %d\n", fullLenght1);

  char strArrRef0[strlen(strArr[0]) + 1], strArrRef1[strlen(strArr[1]) + 1];
  
  for(i = 0 ; i < fullLenght0 + 1; i++) {
    if (*strArr[0] == ' ') {
      strArr[0]++;
      i--;
      continue;
    }
    strArrRef0[i] = *strArr[0]++;
  }
  for(i = 0 ; i < fullLenght1; i++) {
    if (*strArr[1] == ' ') {
      strArr[1]++;
      i--;
      continue;
    }
    strArrRef1[i] = *strArr[1]++;
  }

  printf("strArrRef0: %s\n", strArrRef0);  
  printf("strArrRef1: %s\n", strArrRef1);  

  for(i = 0 ; i < fullLenght1; i++) {
    if (*strArr[1] == ' ') {
      strArr[1]++;
      i--;
      continue;
    }
    strArrRef1[i] = *strArr[1]++;
  }

  // char strArrRefResult[strlen(strArrRef1) + 1];

  // for(i = 0 ; i < strlen(strArrRef1); i++) {
  //   if (strArrRef1[i] == ' ') {
  //     continue;
  //   }
  //   strArrRefResult[i] = strArrRef1[i] - 48;
  // }
  
  // for(i = 0 ; i < strlen(strArrRef1); i++) {
  //   printf("strArrRefResult: %d\n", strArrRefResult[i]);
  // }
   
}

int main(void) {   
  // keep this function call here
//  char *A[] = coderbyteInternalStdinFunction(stdin);
//  int arrLength = sizeof(A) / sizeof(*A);
//
//  FindIntersection(A, arrLength);

  return 0;    
}