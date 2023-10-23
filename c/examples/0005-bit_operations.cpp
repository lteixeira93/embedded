#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#define ARRAY_SIZE  8

using namespace std;

void count_max_repeated_bits(void);
void hex_to_dec(void);
void decimal_to_binary(void);
void hex_counter(void);

int main(void)
{
    hex_counter();
    decimal_to_binary();
    count_max_repeated_bits();
    hex_to_dec();

    return 0;
}

void count_max_repeated_bits(void)
{
    cout << __func__ << endl;
    int n {0}, count {0};
    cin >> n;
    getchar();
    do
    {
        n &= (n << 1);
        count++;
    } while (n > 0);

    cout << "Maximum repeated bits = " << count << endl;
}

void hex_to_dec(void) 
{
    cout << __func__ << endl;
    int hex_number {0};
    cin >> hex_number;
    getchar();

	char hex[ARRAY_SIZE];
    uint32_t decimal = 0, base = 1;
    int32_t i = 0, length;
    
    sprintf(hex, "%x", hex_number);
           
    length = strlen(hex);
    for(i = length--; i >= 0; i--)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f')
        {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }

    cout << "Decimal representation = " << decimal << endl;
}

void decimal_to_binary(void)
{
    cout << __func__ << endl;
    vector <int> binary;
    int n {0}, count {0};
    cin >> n;
    getchar();

    do
    {
        if(n % 2 == 0) binary.push_back(0);
        else binary.push_back(1);
        n /= 2;
    } while (n >= 1);

    reverse(binary.begin(), binary.end());

    for (const auto it:binary)
    {
        cout << it;
    }
    
    cout << endl;  
}

void hex_counter(void) {
    cout << __func__ << endl;
    int n {0};
    cin >> n;

    for (uint32_t i = 0; i < n; i++)
    {
        cout << std::hex << uppercase << "{0x" << i << ", " << std::dec << i << "}," << endl;
    }
    
    cout << endl;
}