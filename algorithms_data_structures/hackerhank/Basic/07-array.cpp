#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int v_size = 0;

    cin >> v_size;

    vector <int> v (v_size);

    for (size_t i = 0; i < v_size; i++)
    {
        cin >> v.at(i);
    }

    for (int j = (v_size - 1); j >= 0; j--)
    {
        cout << v.at(j) << " ";
    }
    
    cout << endl;
    
    return 0;
}


