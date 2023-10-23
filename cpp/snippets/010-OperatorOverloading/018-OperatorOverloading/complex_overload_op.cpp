#include<iostream>
#include<string>

using namespace std;

class Complex
{
public:
    int a,b;

    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        this->a=v1;
        this->b=v2;
    }    
};

Complex operator+(Complex const& lhs, Complex const& rhs) {
    Complex z;
    z.a = lhs.a + rhs.a;
    z.b = lhs.b + rhs.b;
    return z;
}

std::ostream& operator<<(std::ostream &os, const Complex& rhs) {
    return os << rhs.a << "+i" << rhs.b << endl;
}

int main() {
    Complex x, y;
    string s1, s2;

    cin >> s1; // 3+i4
    cin >> s2; // 5+i6

    x.input(s1);
    y.input(s2);

    Complex z = x + y;
    cout << z << endl;
}
