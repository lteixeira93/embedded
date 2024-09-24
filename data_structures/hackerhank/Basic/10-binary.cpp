#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void display_binary_format(vector <int> &binary)
{
    reverse(binary.begin(), binary.end());

    for (const auto it:binary)
    {
        cout << it;
    }
    
    cout << endl; 
}

void decimal_to_binary(int n)
{
    vector <int> binary;
    vector <int> consecutive;

    do
    {
        if(n % 2 == 0) binary.push_back(0);
        else binary.push_back(1);
        n /= 2;
    } while (n >= 1);

    display_binary_format(binary);    
}

int main(void)
{
    int n, count {0};
    cin >> n;

    decimal_to_binary(n);

    do
    {
        n &= (n << 1);
        count++;
    } while (n > 0);

    cout << count << endl;

    return 0;
}
