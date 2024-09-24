#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    string s, s_even, s_odd;
    int val = 0, test_cases = 0, count = 0;

    cin >> test_cases;
    getchar();

    while (count < test_cases)
    {
        getline(cin, s);

        for (auto index:s)
        {
            if (val % 2 == 0)
            {
                s_even.push_back(index);
                
            }
            else {
                s_odd.push_back(index);
            }
            
            val++;
        }
        
        cout << s_even << " " << s_odd << endl;
        
        s_even.clear();
        s_odd.clear();
        val = 0;

        count++;
    }
    
    

    return 0;
}
