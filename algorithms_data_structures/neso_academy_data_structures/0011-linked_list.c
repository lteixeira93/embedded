#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Node structure */
typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* create_node(int data);
Node* invert_list(Node *head);
Node* create_head(void);
void create_at_end(Node **head, int data);
void create_at_beginning(Node **head, int data);
void create_at_position(Node **head, int data, int position);
Node* delete_at_end(Node *head);
Node* delete_at_beginning(Node *head);
Node* delete_at_position(Node *head, int position);
Node* delete_list(Node* head);
Node* delete_all_at_position(Node* head, int position);
int count_nodes(Node *head);
bool is_list_empty(Node *head);
void display_list(Node* head);

int main(void)
{
    /* Create first node */
    Node *head = create_head();
    display_list(head);
    
    /* Create nodes at end */
    for (size_t i = 1; i < 5; i++)
    {
        create_at_end(&head, i);
    }
    display_list(head);

    /* Create node at beginning */
    create_at_beginning(&head, 5);
    display_list(head);

    /* Create node at given postion */
    create_at_position(&head, 10, 3);
    display_list(head);

    /* Create node at given postion */
    create_at_position(&head, 10, 15);
    display_list(head);

    /* Reverse the list */
    head = invert_list(head);
    display_list(head);
    
    /* Delete last node */
    head = delete_at_end(head);
    display_list(head); 

    /* Delete first node */
    head = delete_at_beginning(head);
    display_list(head);   

    /* Delete node at given postion */
    head = delete_at_position(head, 6);
    display_list(head);  

    /* Delete node at given postion */
    head = delete_at_position(head, 2);
    display_list(head);  

    /* Delete whole list */
    head = delete_list(head);
    display_list(head);     

    /* Create nodes at end */
    for (size_t i = 1; i < 5; i++)
    {
        create_at_end(&head, i);
    }
    display_list(head);

    /* Delete whole list at given position */
    head = delete_all_at_position(head, 3);
    display_list(head);     

    /* Delete whole list */
    head = delete_list(head);
    display_list(head);
    
    return 0;
}

/* Returns newly created node */
Node* create_node(int data)
{    
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Not enough memory to allocate on heap\n");
        exit(1);
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

/* Invert list */
Node* invert_list(Node *head) 
{
    printf("Inverting the list\n");
    Node *pprev = NULL;
    Node *pnext = NULL;
    
    while (head != NULL)
    {
        pnext = head->next;
        head->next = pprev;
        pprev = head;
        head = pnext;
    }

    head = pprev;

    return head;    
}

/* Create head node */
Node* create_head(void) {
    printf("Creating head\n");
    Node *head = create_node(0);
    return head;
}

/* Create node at end */
void create_at_end(Node **head, int data) 
{
    if (is_list_empty(*head))
    {
        *head = create_head();
    } 

    printf("Creating at end\n");
    Node *new_node = create_node(data);

    Node *head_ref = *head;

    while (head_ref->next != NULL)
    {
        head_ref = head_ref->next;
    }   

    head_ref->next = new_node;
}

/* Create node at beginning */
void create_at_beginning(Node **head, int data) 
{
    if (is_list_empty(*head))
    {
        *head = create_head();
    } 

    printf("Creating at beginning\n");
    Node *new_node = create_node(data);
    new_node->next = *head;

    *head = new_node;
}

/* Create node at given position */
void create_at_position(Node **head, int data, int position) 
{
    if (is_list_empty(*head))
    {
        *head = create_head();
    } 

    if(count_nodes(*head) < position) 
    {   
        printf("Cannot create on position %d\n", position);
        return;
    }

    if (position == 0)
    {
        create_at_beginning(head, data);
        return;
    }
    
    printf("Creating on position %d\n", position);
    Node *new_node = create_node(data); 
    Node *pprev = NULL;
    Node *pnext = NULL;
    Node *head_ref = *head;

    pprev = NULL;
    pnext = head_ref;

    size_t count = 0;

    while ((count < position) && (head_ref->next != NULL))
    {
        pprev = pnext;
        pnext = pnext->next;

        count++;
    }

    pprev->next = new_node;
    new_node->next = pnext;   

    head_ref = pprev;
}

/* Delete node at end */
Node* delete_at_end(Node *head) 
{
    if (is_list_empty(head))
    {
        printf("The list is empty\n");
        return head;
    }

    printf("Deleting at end\n");
    Node *pprev = NULL;
    Node *head_ref = head;

    while (head_ref->next != NULL)
    {
        pprev = head_ref;
        head_ref = head_ref->next;
    }

    pprev->next = NULL;
    free(head_ref);
    head_ref = NULL;

    return head;    
}

/* Delete node at beginning */
Node* delete_at_beginning(Node *head)
{
    if (is_list_empty(head))
    {
        printf("The list is empty\n");
        return head;
    } 

    printf("Deleting at beginning\n");
    Node *head_ref = head;
    head = head->next;

    free(head_ref);
    head_ref = NULL;

    return head;
}

/* Delete node at given position */
Node* delete_at_position(Node *head, int position)
{
    if (is_list_empty(head))
    {
        printf("The list is empty\n");
        return head;
    }

    size_t count = 0;

    Node *pprev = NULL;
    Node *pnext = NULL;
    Node *head_ref = head;

    if(count_nodes(head) < position)
    {
        printf("Cannot delete on position %d\n", position);
        return head;
    }

    if(count_nodes(head) == position)
    {
        return delete_at_end(head);
    }

    printf("Deleting at position %d\n", position);

    while ((count < position) && (head_ref->next != NULL))
    {
        pprev = head_ref;
        head_ref = head_ref->next;
        pnext = head_ref->next;
        count++;
    }

    pprev->next = pnext;
    free(head_ref);
    head_ref = NULL;
    head->next = pprev;

    return head;    
}

Node* delete_all_at_position(Node* head, int position)
{
    if (is_list_empty(head))
    {
        printf("The list is empty\n");
        return head;
    }

    size_t count = 0;

    Node *pprev = NULL;
    Node *head_ref = head;

    if(count_nodes(head) < position)
    {
        printf("Cannot delete on position %d\n", position);
        return head;
    }

    if(count_nodes(head) == position)
    {
        return delete_at_end(head);
    }

    printf("Deleting all before position %d\n", position);

    while ((count < position) && (head_ref->next != NULL))
    {
        pprev = head_ref;
        head_ref = head_ref->next;
        free(pprev);
        pprev = NULL;
        count++;
    }

    head = head_ref;

    return head; 
}

Node* delete_list(Node* head)
{
    printf("Deleting the whole list\n");
    Node* head_ref = head;
    Node* pprev = NULL;

    while (head_ref->next != NULL)
    {
        pprev = head_ref;
        head_ref = head_ref->next;
        free(pprev);
        pprev = NULL;
    }

    free(head_ref);
    head_ref = NULL;

    head = head_ref;

    return head;
    
}

/* Count the number of nodes */
int count_nodes(Node *head)
{
    size_t count = 1;

    while (head->next != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

/* Check if list is empty */
bool is_list_empty(Node *head) 
{
    return (head == NULL) ? true : false;
}

/* Display list */
void display_list(Node* head) 
{
    if (is_list_empty(head))
    {
        printf("[ ]\n");
        return;
    }

    printf("[ ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        //printf("%p ", head->next);
        head = head->next;
    }
    printf("]\n");
}