#include <iostream>

using std::string;

class Employee {
public:
    string name;
    string company;
    int age;

    void IntroduceYourself() {
        std::cout << "Name - " << this->name << std::endl;
        std::cout << "Company - " << this->company << std::endl;
        std::cout << "Age - " << this->age << std::endl;
    }

    Employee() {}
    ~Employee() {}

    Employee(string name, string company, int age)
            : name {this->name}, company {this->company}, age {this->age} {}
};

int main(void) {
    Employee employee_1("Ed", "Volvo", 21);

    employee_1.IntroduceYourself();


    return 0;
};
