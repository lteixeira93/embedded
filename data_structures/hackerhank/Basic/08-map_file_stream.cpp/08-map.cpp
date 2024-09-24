#include <iostream>
#include <map>
#include <string>
#include <fstream>
// #define DEBUG

using namespace std;

void display_phone_book(const map<std::string, std::string> &phone_book) 
{
    cout << "{";
    for (const auto &itf: phone_book)
    {
        cout << "(" << itf.first << ":" << itf.second << ")";
    }      
    cout << "}" << endl;
}

void find_phone_book_info(map <std::string, std::string> phone_book, long long int n, std::string name, std::string phone_number, std::string c_name)
{
    std::ifstream name_dat("name.dat");
    std::ifstream phone_dat("phone.dat");
    
    long long int count = 0;

    if (name_dat && phone_dat) {
        while (count < n) {
            std::getline (name_dat, name);
            std::getline (phone_dat, phone_number);
#ifdef DEBUG
            std::cout << name << endl;
            std::cout << phone_number << endl;
#endif // DEBUG
            phone_book.insert(make_pair(name, phone_number));
            name.clear();
            phone_number.clear();
#ifdef DEBUG
            display_phone_book(phone_book);
#endif // DEBUG
            count++;
        }
    }       

#ifdef DEBUG
    display_phone_book(phone_book);
#endif // DEBUG

    count = 0;
    std::ifstream check_dat("check.dat");

    if (check_dat) {
        while (!check_dat.eof()) {
            std::getline (check_dat, c_name);
#ifdef DEBUG
            std::cout << c_name << endl;
#endif // DEBUG

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
}

int main(void)
{
    map <std::string, std::string> phone_book;

    long long int n {0};
    std::string name, phone_number, c_name;

    cin >> n;
    getchar();

    find_phone_book_info(phone_book, n, name, phone_number, c_name);

    return 0;
}
