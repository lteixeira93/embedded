#include <stdio.h>
#include <stdlib.h>

/* Self reference structure */
typedef struct node
{
    char data;
    struct node *nextPtr;
} node_t;

typedef node_t* ListNodePtr;

/* Prototypes */
void insertAlphabetical(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char value);
void insertAtBeginning(ListNodePtr *head, char value);
char delete(ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr *head);
void printList(ListNodePtr currentPtr);

void printList(ListNodePtr currentPtr) {   
    printf("---- Current List ----\n");

    while (currentPtr != NULL) {
        printf("%c->", currentPtr->data);

        currentPtr = currentPtr->nextPtr;
    }

    printf("NULL\n");  
    printf("----------------------\n\n"); 
    return; 
}

void insertAtBeginning(ListNodePtr *head, char value) {
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = value;
    new_node->nextPtr = *head;
    *head = new_node;
}

void insertAtEnd(ListNodePtr *head, char value) {
    ListNodePtr current = *head;

    // Checking list is not empty
    if (current != NULL) { 
        while (current->nextPtr != NULL) {
            current = current->nextPtr;
        }

        /* Now a new data can be added */
        ListNodePtr new_node = malloc(sizeof(node_t));
        new_node->data = value;
        new_node->nextPtr = NULL;

        current->nextPtr = new_node;      
    }    
    else {
        printf("List is empty, add head first\n");
        return;
    }
}

void deleteAtBeginning(ListNodePtr *head) {
    ListNodePtr current = NULL;

    // Checking list is not empty
    if (*head != NULL) {
        current = *head;
        printf("Deleting %c\n\n", current->data);

        *head = (*head)->nextPtr;

        current->nextPtr = NULL;
        free(current);         
    }
    else {
        printf("List is empty, nothing to be deleted\n\n");
        return;
    }
    
}

// void insertAlphabetical(ListNodePtr *head, char value) {
//     ListNodePtr previousPtr;
//     ListNodePtr currentPtr;
//     ListNodePtr new_node = malloc(sizeof(node_t));    

//     /* Check for space avaliable */
//     if (new_node != NULL) {
//         new_node->data = value;
//         new_node->nextPtr = NULL;
//     }    
// }

int main(void)
{
    ListNodePtr head = NULL;

    int choice = 0;
    char item = '\0';

    printf("Usage: \n"
        "1 - Insert an element into the list in alphabetical order \n"
        "2 - Insert an element at the end of the list \n"
        "3 - Insert an element at the beginning of the list \n"
        "4 - Delete an element \n"
        "5 - Delete from beginning \n"
        "6 - Exit \n"
    );
    printf("--> ");

    scanf("%d", &choice);

    while (choice != 6)
    {
        switch (choice)
        {
        case 1:
            // printf("Enter character: ");
            // scanf("\n%c", &item);
            // insertAlphabetical(&head, item);
            // printList(head);
            // break;
        case 2:
            printf("Enter character: ");
            scanf("\n%c", &item);
            insertAtEnd(&head, item);
            printList(head);
            break;
        case 3:
            printf("Enter character: ");
            scanf("\n%c", &item);
            insertAtBeginning(&head, item);
            printList(head);
            break;
        // case 4:
        //     if (!isEmpty(head))
        //     {
        //         printf("Enter character to be deleted: ");
        //         scanf("\n%c", &item);

        //         if (delete(&head, item))
        //         {
        //             printf("%c deleted\n\n");
        //             printList(head);
        //         }
        //         else 
        //         {
        //             printf("%c not found\n\n", item);
        //         }                
        //     }
        //     else{
        //         printf("List is empty\n");
        //     }
            
        //     break;
        case 5:      
            deleteAtBeginning(&head);
            printList(head);

            break;
        case 6:
            exit(0);

        default:
            printf("Invalid choice\n\n");

            break;
        }

        printf("Usage: \n"
            "1 - Insert an element into the list in alphabetical order \n"
            "2 - Insert an element at the end of the list \n"
            "3 - Insert an element at the beginning of the list \n"
            "4 - Delete an element \n"
            "5 - Delete from beginning \n"
            "6 - Exit \n"
        );
        printf("--> ");
        scanf("%d", &choice);
    }
    
    return 0;
}
