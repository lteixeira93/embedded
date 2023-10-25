#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    tuple <char, int, float> geek;

    geek = make_tuple('a', 10, 15.5);

    cout << "The initial values of the tuple are: ";
    cout << get<0>(geek) << " " << get<1>(geek);
    cout << " " << get<2>(geek) << endl;

    get<0>(geek) = 'b';

    cout << get<0>(geek) << endl;
    
    // Vector of tuples
    vector<tuple<char, int, float>> v;
    v.push_back({'c', 11, 16.5});
    v.push_back({'d', 12, 17.5});

    cout << get<0>(v.at(0)) << endl;

    return 0;
}
