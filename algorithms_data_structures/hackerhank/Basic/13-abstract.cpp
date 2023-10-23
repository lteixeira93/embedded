#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Book{
    protected:
        string title;
        string author;
    public:
        Book(string t,string a){
            title=t;
            author=a;
        }
        /* 
            Pure virtual function - Make class abstract 
            Don't have implementation
            The derived classes define the behavior
            Abstract classes cannot be instantiated directly
            example: Book *p1 = new Book() -> Error
        */
        virtual void display()=0;
};

class MyBook : public Book
{
public:
    int book_price;
    //   Class Constructor
    //   
    //   Parameters:
    //   title - The book's title.
    //   author - The book's author.
    //   price - The book's price.
    //
    // Write your constructor here
    MyBook(string title, string author, int price) :
    Book {title, author}, book_price {price}
    {}

    //   Function Name: display
    //   Print the title, author, and price in the specified format.
    //
    // Write your method here

    /* override makes the derived to be a concrete class */
    virtual void display() override 
    {
        cout << "Title: " << this->title << "\n" << "Author: " << this->author << "\n" << "Price: " << book_price << endl;
    }

};

int main() {
    string title,author;
    int price;
    getline(cin,title);
    getline(cin,author);
    cin>>price;
    MyBook novel(title,author,price);
    novel.display();
    return 0;
}
