#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MARKS 6

class Person
{
protected:
    std::string name;
    int age;
public:
    virtual void getdata() {};
    virtual void putdata() {};
};

class Professor : public Person
{
private:
    int publications;
    static int cur_id;
    int id;
public:
    /* gets the input from the user: the name, age and publications of the professor */
    void getdata() override
    {
        id = ++cur_id;
        cin >> this->name >> this->age >> this->publications;
    }

    /* prints the name, age, publications and the cur_id of the professor. */
    void putdata() override
    {
        cout << this->name << " " << this->age << " " << this->publications << " " << this->id << endl;
    }
};

class Student : public Person
{
private:
    int marks[MARKS];
    static int cur_id;
    int id;
public:
    /* gets the input from the user: the name, age, and the marks of the student in 6 subjects */
    void getdata() override
    {
        id = ++cur_id;
        cin >> this->name >> this->age;

        for(int i=0;i<MARKS;i++)
        {
            cin >> this->marks[i];
        }
    }

    /* prints the name, age, sum of the marks and the cur_id of the student. */
    void putdata() override
    {
        cout << this->name << " " << this->age << " " << markSum(this->marks) << " " << this->id << endl;
    }

    int markSum(int arrMarks[])
    {
        int markSum {0};
        for (size_t i = 0; i < MARKS; i++) markSum += arrMarks[i];        
        return markSum;        
    }
};

int Professor::cur_id = 0;
int Student::cur_id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
