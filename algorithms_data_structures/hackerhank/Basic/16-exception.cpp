#include <bits/stdc++.h>
#include <string>

using namespace std;

void string_to_integer(string S)
{
    string::size_type s;
    
    cout << stoi(S) << endl;        
     
}

int main()
{
    string S;
    getline(cin, S);

    try
    {
        string_to_integer(S);
    }
    catch(std::invalid_argument)
    {
        std::cout << "Bad String" << endl;
    }    

    return 0;
}
