#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdbool.h>

using namespace std;

bool is_prime(int n) 
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int test_cases {0}, n {0};

    cin >> test_cases;

    for (size_t i = 0; i < test_cases; i++)
    {
        cin >> n;
        cout << (is_prime(n) ? "Prime\n" : "Not prime\n");    
    }
    
    return 0;
}
