#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

static std::string hash(char c);
static void display_decrypted(std::string message, std::unordered_multimap<char, std::string> &enc_unordered_multimap);
static void encrypt_message(std::string message, std::unordered_multimap<char, std::string> &enc_unordered_multimap);

int main(void)
{
    std::string message;
    std::vector <std::string> enc_values {};

    std::unordered_multimap <char, std::string> enc_unordered_multimap;
    std::cout << "[INPUT] Enter the message to be encrypted >> ";
    getline(std::cin, message);

    std::cout << "[STATUS] Encrypting..." << std::endl;
    encrypt_message(message, enc_unordered_multimap);     
    
    std::cout << "[OUTPUT] Encrypted message: " << std::endl;
    auto it = enc_unordered_multimap.begin();
    while (it != enc_unordered_multimap.end())
    {
       enc_values.push_back(it->second);
       ++it;
    }
    
    for(auto it = enc_values.rbegin(); it != enc_values.rend(); ++it)
    {
        std::cout << *it;
    }
    std::cout << std::endl;

    std::cout << "[STATUS] Decrypting..." << std::endl;
    std::cout << "[OUTPUT] Decrypted message: " << std::endl;
    display_decrypted(message, enc_unordered_multimap);

    return 0;
}

static void encrypt_message(std::string message, std::unordered_multimap<char, std::string> &enc_unordered_multimap)
{
    for(auto c:message) 
    {
        enc_unordered_multimap.insert((std::pair<char, std::string>(c, hash(c))));     
    }
}

static std::string hash(const char c)
{
    return std::to_string((c + (rand() % RAND_MAX) % 100));
}

static void display_decrypted(std::string message, std::unordered_multimap<char, std::string> &enc_unordered_multimap)
{
    std::string dec_message;

    for(auto c:message)
    {
        for(auto it = enc_unordered_multimap.find(c); it != enc_unordered_multimap.end(); it++)
        {
            dec_message += it->first;
            break;
        }
    }
    std::cout << dec_message << std::endl;    
}