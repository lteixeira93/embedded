#include<stdio.h>

typedef struct person {
    char name;
    int age;
}__attribute__((__packed__)) person;

int main(int argc, char const *argv[])
{
    printf("%ld\n", sizeof(person));

    return 0;
}
