#include <iostream>
#include <sstream>

using namespace std;

class Student
{
public:
    Student();
    ~Student();

    /* Setters */
    void set_age(int age) {
        this->age = age;
    }
    
    void set_standard(int standard) {
        this->standard = standard;
    }
    
    void set_first_name(std::string first_name) {
        this->first_name = first_name;
    }
    
    void set_last_name(std::string last_name) {
        this->last_name = last_name;
    }

    /* Getters */
    int get_age() {
        return this->age;
    }

    int get_standard() {
        return this->standard;
    }

    std::string get_first_name() {
         return this->first_name;
    }

    std::string get_last_name() {
         return this->last_name;
    }

    std::string to_string(int age, int standard, 
        std::string first_name, std::string last_name) 
    {
        std::string ss;
        ss = std::to_string(age) + ',' + first_name + ',' + last_name + ',' + std::to_string(standard);
        return ss;
    }

private:
    int age;
    int standard;
    std::string first_name;
    std::string last_name;
};

Student::Student()
{}

Student::~Student()
{}

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    st.set_standard(standard);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string(age, standard, first_name, last_name);

    return 0;
}