#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct Person {
    char name[MAX_NAME];
    int age;

    struct Person *next;
} person;

person* hash_table[TABLE_SIZE];

void init_hash_table(void) {
    int i;

    for (i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }    
}

void print_table(void) {
    int i;
    printf("START\n");
    
    for (i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        }
        else {
            printf("\t%i\t ", i);
            person *tmp = hash_table[i];

            while (tmp != NULL) {
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n", hash_table[i]);
            
        }
    }

    printf("END\n");
}

unsigned int hash(char *name) {
    int i, lenght = strlen(name);
    uint32_t hash_value = 0;

    for (i = 0; i < lenght; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % 10;
    }
    
    return hash_value;
}

bool hash_table_insert(person* p) {
    if (p == NULL) return false;

    int i, index = hash(p->name);

    p->next = hash_table[index];
    hash_table[index] = p;
    return true;      
}

person* hash_table_lookup(char* name) {
    int i, index = hash(name);
    person *tmp = hash_table[index];

    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0) {
        tmp = tmp->next;
    }
    
    return tmp;
}

person* hash_table_delete(char* name) {
    int i, index = hash(name);
    person *tmp = hash_table[index];
    person *prev = NULL;

    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }

    if(tmp == NULL) return NULL;
    if(prev == NULL) {
        // Deleting head

        hash_table[index] = tmp->next;
    }
    else {
        prev->next = tmp->next;
    }

    return tmp;
}

int main(void) {
    init_hash_table();
    print_table();

    person Jacob = {.name = "Jacob", .age = 16};
    person Kate = {.name = "Kate", .age = 27};
    person Mpho = {.name = "Mpho", .age = 14};
    person Sarah = {.name = "Sarah", .age = 14};
    person Edna = {.name = "Edna", .age = 16};
    person Maren = {.name = "Maren", .age = 11};
    person Eliza = {.name = "Eliza", .age = 15};
    person Robert = {.name = "Robert", .age = 12};

    hash_table_insert(&Jacob);
    hash_table_insert(&Kate);
    hash_table_insert(&Mpho);
    hash_table_insert(&Sarah);
    hash_table_insert(&Edna);
    hash_table_insert(&Maren);
    hash_table_insert(&Eliza);
    hash_table_insert(&Robert);

    print_table();

    person *tmp = hash_table_lookup("Jacobi");

    if(tmp == NULL) {
        printf("Person not found\n");
    } 
    else {
        printf("Person found. Name: %s\n", tmp->name);
    }

    tmp = hash_table_lookup("Jacob");

    if(tmp == NULL) {
        printf("Person not found\n");
    } 
    else {
        printf("Person found. Name: %s\n", tmp->name);
    }

    tmp = hash_table_delete("Jacob");
    if(tmp == NULL) {
        printf("Person not found\n");
    } 
    else {
        printf("Person found. Name: %s\n", tmp->name);
    }
    
    print_table();

    return 0;
}
