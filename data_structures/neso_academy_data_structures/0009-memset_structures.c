#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    int age;
    int roll_number;
    float marks;
};

void display_modify_structure(struct student *s)
{
    printf("==== After memset ====\n");
    printf("%s\n", s->name);
    printf("%d\n", s->age);
    printf("%d\n", s->roll_number);
    printf("%f\n", s->marks);

    strcpy(s->name, "Test");
    s->age = 20;
    s->roll_number = 2;
    s->marks = 0.01;

    printf("==== After initialization ====\n");
    printf("%s\n", s->name);
    printf("%d\n", s->age);
    printf("%d\n", s->roll_number);
    printf("%.2f\n", s->marks);
}

int main(int argc, char const *argv[])
{
    struct student s1;
    memset(&s1, 0, sizeof(s1));
 
    display_modify_structure(&s1);

    return 0;
}
