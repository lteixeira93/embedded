#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// #define DEBUG

/* Calculates the maximum of and, or, xor operations that is less than k*/
void calculate_the_maximum(int n, int k) 
{
    int S [n], n_comb = 0, count = 0, b_and = 0, b_or = 0, b_xor = 0;

    for (size_t i = 0; i < n; i++) 
    {
        // Creating S array related to values from 1 to n
        S[i] = i+1;
#ifdef DEBUG
        printf("%d ", S[i]); // 1 2 3 4 5
#endif // DEBUG
    }

#ifdef DEBUG
    printf("\n");
#endif // DEBUG

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (i >= j) continue;
#ifdef DEBUG
        printf("{%d %d} ", S[i], S[j]); 
#endif // DEBUG
            n_comb++;
        }
    }

#ifdef DEBUG
    printf("\n");
#endif // DEBUG

    int s_and [n_comb], s_or [n_comb], s_xor [n_comb];

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (i >= j) continue;

            s_and[count] = (S[i] & S[j]);
            s_or[count]  = (S[i] | S[j]);
            s_xor[count] = (S[i] ^ S[j]);

#ifdef DEBUG
            //printf("%d & %d = %d\n", S[i], S[j], s_and[count]); 
            printf("%d | %d = %d\n", S[i], S[j], s_or[count]); 
            //printf("%d ^ %d = %d\n", S[i], S[j], s_xor[count]); 
#endif // DEBUG
            count++;
        }
    }

    for (size_t i = 0; i < count; i++)
    {
        if ((s_and[i] > b_and) && (s_and[i] < k)) b_and = s_and[i];
        if ((s_or[i] > b_or) && (s_or[i] < k))  b_or = s_or[i];
        if ((s_xor[i] > b_xor) && (s_xor[i] < k))  b_xor = s_xor[i];
    }

    printf("%d\n", b_and); 
    printf("%d\n", b_or); 
    printf("%d\n", b_xor);     
}

int main(void)
{
    int n = 0, k = 0;
  
    scanf("%d %d", &n, &k);

    if (k > n) {
        printf("k must be less or equal than n\n");
        main();
    }

    calculate_the_maximum(n, k);
 
    return 0;
}
