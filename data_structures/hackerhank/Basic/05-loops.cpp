#include <iostream>
#include <vector>

using namespace std;

void get_multiple(int n)
{
    vector <int> v {1,2,3,4,5,6,7,8,9,10};

    for (size_t i = 0; i < 10; i++)
    {
        cout << n << " x " << v.at(i) << " = " << n*v.at(i) << endl;
    }
    
}

int main(void)
{
    int n = 0;
    cin >> n;

    get_multiple(n);

    return 0;
}
