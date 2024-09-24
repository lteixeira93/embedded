#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

bool isListEmpty(Node *LIST);
void printList(Node *LIST);
void insertAtBeginning(Node **LIST, int data);
void insertAtEnd(Node **LIST, int data);
void insertAtGivenPosition(Node **LIST, int position, int data);
void deleteAtBeginning(Node **LIST);
void deleteAtEnd(Node **LIST);
void deleteAtGivenPosition(Node **LIST, int position);
void freeList(Node **LIST);
void getListSize(Node *LIST);

bool isListEmpty(Node *LIST) {
    if (LIST == NULL) {
        return true;
    }
    else {
        return false;
    }    
}

void printList(Node *LIST) {
    if (isListEmpty(LIST)) {
        printf("Empty List\n");
        return;
    }
    
    while (LIST != NULL) {
        printf("%d -> ", LIST->data);
        LIST = LIST->next;
    }

    printf("NULL\n");      
}

void insertAtBeginning(Node **LIST, int data) {
    Node *newNode = malloc(sizeof(Node));

    if(!newNode) {
        printf("No memory avaliable\n");
        return;
    }

    newNode->data = data;
    newNode->next = *LIST;

    *LIST = newNode;  
}

void insertAtEnd(Node **LIST, int data) {
    Node *newNode = malloc(sizeof(Node));

    if(!newNode) {
        printf("No memory avaliable\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    Node *listRef = *LIST;

    while (listRef->next != NULL) {
        listRef = listRef->next;
    }

    listRef->next = newNode;
    return;
}

void insertAtGivenPosition(Node **LIST, int position, int data) {
    int positionCounter = 1;

    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    
    Node *listRef = *LIST;
    Node *previousNode = NULL;

    while ((listRef->next != NULL) && (positionCounter < position)) {
        previousNode = listRef; // 1
        listRef = listRef->next; // 2
        positionCounter++;
    }

    newNode->next = listRef; // 8->2
    previousNode->next = newNode; // 1->8

    listRef = previousNode;
}

void deleteAtBeginning(Node **LIST) {
    Node *ListRef = *LIST;
    Node *AfterHeadRef = NULL;

    ListRef = ListRef->next;
    AfterHeadRef = ListRef; // Points to next

    ListRef = NULL;
    free(ListRef);

    *LIST = AfterHeadRef;
}

void deleteAtEnd(Node **LIST) {
    Node *lastListRef = *LIST;
    Node *nextToLastRef = NULL;

    while (lastListRef->next != NULL) {
        nextToLastRef = lastListRef; // Points to previous last
        lastListRef = lastListRef->next;
    }

    nextToLastRef->next = NULL;

    lastListRef = NULL;
    free(lastListRef);

    lastListRef = nextToLastRef;
}

void deleteAtGivenPosition(Node **LIST, int position) {
    int positionCounter = 1;
    Node *listRef = *LIST;
    Node *previous = NULL;

    while ((listRef->next != NULL) && (positionCounter < position)) {
        previous = listRef; // 1
        listRef = listRef->next; // 8
        positionCounter++;
    }

    listRef = listRef->next; // 2

    previous->next = listRef;

    listRef = previous;  
}

void freeList(Node **LIST) {
    *LIST = NULL;
    free(*LIST);
}

void getListSize(Node *LIST) {
    int listSize = 0;

    if (isListEmpty(LIST)) {
        printf("The list is empty\n");
        return;
    }
    else {
        while (LIST->next != NULL) {
            listSize++;
            LIST = LIST->next;
        }
        listSize++;

        printf("The list have %d nodes, where each node is using %ld bytes and the full list is using %ld bytes of memory\n", listSize, sizeof(Node) ,listSize*sizeof(Node));
        
    }
}

int main(void)
{
    Node *LIST = NULL;

    printList(LIST);

    insertAtBeginning(&LIST, 3);
    insertAtBeginning(&LIST, 2);  
    insertAtBeginning(&LIST, 1);
    printList(LIST);

    insertAtEnd(&LIST, 4);
    insertAtEnd(&LIST, 5);
    printList(LIST);

    deleteAtEnd(&LIST);
    deleteAtEnd(&LIST);
    printList(LIST);

    deleteAtBeginning(&LIST);
    deleteAtBeginning(&LIST);
    insertAtBeginning(&LIST, 6);
    insertAtBeginning(&LIST, 2);  
    insertAtBeginning(&LIST, 1);
    printList(LIST);

    insertAtGivenPosition(&LIST, 2, 8);
    insertAtGivenPosition(&LIST, 4, 7);
    printList(LIST);

    deleteAtGivenPosition(&LIST, 2);
    printList(LIST);

    getListSize(LIST);

    freeList(&LIST);
    printList(LIST);
    
    return 0;
}
