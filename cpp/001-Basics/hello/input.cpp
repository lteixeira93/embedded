#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

int main() {
    float ipt {0.0};
    cout << std::setprecision(2) << std::fixed;
    cout << "Enter float input data:" << endl;
    cin >> ipt;
    cout << "Input data with two decimal points is: " << ipt << endl;

    return 0;
}
