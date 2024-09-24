#include <stdio.h>

int main(void){
    /* code */
	int i = 0;
	
    for (i = 1; i <= 100; i++) {
        if ((i % 3) == 0) {
            if ((i % 5) == 0) {
                printf("Fizz Buzz, ");
            }
            else {
                printf("Fizz, ");
            }
        }
        else if ((i % 5) == 0) {
            if ((i % 3) == 0) {
                printf("Fizz Buzz, ");
            }
            else {
                printf("Buzz, ");
            }
        }
        else {
            printf("%d, ", i);        
        }
    }
  

    return 0;
}
