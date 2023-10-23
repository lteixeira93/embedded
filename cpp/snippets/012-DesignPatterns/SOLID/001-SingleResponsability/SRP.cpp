#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

template <typename T>
struct Journal
{
    T title;
    vector<string> entries;

    Journal(const string &title) : title {title} {};

    void add_entry(const string & entry)
    {
        static int count = 1;
        entries.push_back(lexical_cast<string>(count++) + ": " + entry);
    }

    /* Bad practice - Against single responsability */
    // // void save(const string& filename)
    // // {
    // //     ofstream ofs(filename);
    // //     for(auto& e : entries)
    // //     {
    // //         ofs << e << endl;
    // //     }
    // // }
};

// Best practice
struct PersistenceManager
{
    static void save(const Journal<string>& j, const string& filename) // Bad practice against single responsability
    {
        ofstream ofs(filename);
        for(auto& e : j.entries)
        {
            ofs << e << endl;
        }
    }
};

int main(void)
{
    Journal<string> journal {"Dear diary"};
    journal.add_entry("I ate a bug");
    journal.add_entry("I cried today");

    PersistenceManager pm;
    pm.save(journal, "diary.txt");

    getchar();

    return 0;
}
