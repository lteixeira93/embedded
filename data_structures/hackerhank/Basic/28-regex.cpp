#include <bits/stdc++.h>
#include <map>
#include <regex>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
7
riya riya@gmail.com
julia julia@julia.me
julia sjulia@gmail.com
julia julia@gmail.com
samantha samantha@gmail.com
tanya tanya@gmail.com
alice alice@alicegmail.com

3
alice alice@gmail.com
alice alice@alicegmail.com
alice gmail.alice@gmail.com

alice
alice

1
alice alice@alicegmail.com

alice
*/
int main()
{
    multimap <string, string> emails;
    int npos {};

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    regex rFirstName("(^[a-z]+$)");
    regex remailID("^([a-z].+)@(gmail.com)$");

    for (int N_itr = 0; N_itr < N; N_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        string firstName = first_multiple_input[0];
        string emailID = first_multiple_input[1];

        if ((firstName.size() > 20) || (emailID.size() > 50) || (!regex_match(firstName, rFirstName)) || (!regex_match(emailID, remailID))) continue;
        else emails.insert(make_pair(firstName, emailID));
    }

    for(const auto it:emails)
    {
        cout << it.first << endl;
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
