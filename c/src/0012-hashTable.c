#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFFF)

typedef struct Person {
    char name[MAX_NAME];
    int age;
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
        else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t--- <DELETED>\n", i);
        }
        else printf("\t%i\t%s\n", i, hash_table[i]->name);
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

    for (i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;

        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE) {
            hash_table[try] = p;
            return true;
        }       
    }

    printf("No space left to store\n");
    return false;   
}

person* hash_table_lookup(char* name) {
    int i, index = hash(name);

    for (i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;

        if(hash_table[try] == NULL) {
            return NULL;
        }
        if (hash_table[try] == DELETED_NODE) {
            continue;        
        }

        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) {
            return hash_table[try];
        }
    }

    return NULL;
}

person* hash_table_delete(char* name) {
    int i, index = hash(name);

    for (i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;

        if(hash_table[try] == NULL) return NULL;

        if (hash_table[try] == DELETED_NODE) continue;        

        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) {
            person* tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;

            return tmp;
        }
    }

    return NULL;
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
