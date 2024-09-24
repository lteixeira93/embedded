#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

void find_phone_book_info(map <std::string, std::string> phone_book, long long int n, int queries, std::string name, std::string phone_number, std::string c_name)
{
    long long int count = 0;
    while (count < n)
    {
        cin >> name >> phone_number;
        getchar();

        phone_book.insert(make_pair(name, phone_number));

        name.clear();
        phone_number.clear();
        
        count++;
    }

    count = 0;    

    while (!cin.eof())
    {
        getline (cin, c_name);

        auto it = phone_book.find(c_name);

        if (it != phone_book.end())
        {
            cout << it->first << "=" << it->second << " " << endl;
        }
        else {
            cout << "Not found" << endl;
        }   
        
        c_name.clear();
        count++;
    }

}

int main() {
    map <string, string> phone_book;

    long long int n {0}, queries {0};
    string name, phone_number, c_name;

    cin >> n >> queries;
    getchar();

    find_phone_book_info(phone_book, n, queries, name, phone_number, c_name);
    return 0;
}