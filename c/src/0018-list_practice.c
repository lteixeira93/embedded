#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next_node;
} Node;

/* Prototypes */
static void showOptions(void);
static void printList(Node *head);
static void insertAtBeginning(Node **head, char data);
static void insertAtEnd(Node **head, char data);
static void deleteAtBeginning(Node **head);
static char deleteAtPosition(Node **head, char data);
static int isEmpty(Node **head);

static void printList(Node *head) {
    printf("---- Current List ----\n");
    if (head != NULL) {
        while (head->next_node != NULL) {
            printf("%c->", head->data);
            head = head->next_node;
        }        
        printf("NULL\n");
        printf("----------------------\n\n"); 
    }
    else {
        printf("List is empty\n");
        printf("----------------------\n\n"); 
    }
    
}

static void showOptions(void) {
    printf("Usage: \n"
        "1 - Insert an element at the beginning of the list \n"
        "2 - Insert an element at the end of the list \n"
        "3 - Delete from beginning \n" 
        "4 - Delete an element \n"
        "5 - Print list \n"
        "0 - Exit \n"
    );
    printf("--> ");
}

static void insertAtBeginning(Node **head, char data) {
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("No memory avaliable\n");
        exit(EXIT_FAILURE);
    }

    if (*head == NULL) { // Is list empty?    
        new_node->data = data;    
        new_node->next_node = NULL;
        *head = new_node;
    } 
    else {
        new_node->data = data;
        new_node->next_node = *head;
        *head = new_node;
    }
}

static void insertAtEnd(Node **head, char data) {
    if (*head == NULL) {
        printf("List is empty, add head first\n\n");
        printList(*head);    
        return;
    }

    Node *head_ref = *head;
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next_node = NULL;

    while (head_ref->next_node != NULL) {
        head_ref = head_ref->next_node;
    }
    
    // Add after arrive last element
    head_ref->next_node = new_node;
    *head = new_node;

    printList(*head);    
}

int main(void) {
    int choice = 0;
    char data = '\0';     

    Node *head = NULL;

    showOptions();
    scanf("%d", &choice);

    while (choice != 0) {
        switch (choice) {
        case 1:
            printf("Enter character: ");
            scanf("\n%c", &data);
            insertAtBeginning(&head, data);
            printList(head);
            break;

        case 2:
            printf("Enter character: ");
            scanf("\n%c", &data);
            insertAtEnd(&head, data);
            break;
        
        case 3:
            
            break;

        case 4:

            break;

        case 5:
            printList(head);
            break;

        case 0:
            exit(EXIT_SUCCESS);
            break;
        
        default:
            printf("\n*No such option*\n\n");                       
            break;
        }      

        showOptions();
        scanf("%d", &choice); 
    }
    
    
    return 0;
}
