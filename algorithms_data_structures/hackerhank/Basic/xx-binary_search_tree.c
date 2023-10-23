#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treenode
{
    int value;
    struct treenode *left, *right;
} treenode;

/* Print functions */
void printInorder(treenode* node);
void printPreorder(treenode* node);
void printPostorder(treenode* node);
void print_tree(treenode *root);
void print_tree_rec(treenode *root, int level);
void print_tabs(int num_tabs);

/* BST functions */
treenode *create_node(int value);
treenode* insert_node(treenode *root, int value);

bool find_node(treenode *root, int value)
{
    if (root == NULL) return false;
    
    if (value == root->value)
    {
        /* The value is in root */
        return true;
    }
    else if (value < root->value) 
    {
        /* Recursevely search on left */
        return find_node(root->left, value);
    }
    else if (value > root->value) 
    {
        /* Recursevely search on right */
        return find_node(root->right, value);
    } 
}

int main(void)
{
    /*
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80
    */

    treenode *root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    printf("============================\n");
    printf("In order:\n");
    printInorder(root);
    printf("\n");
    printf("In Preorder:\n");
    printPreorder(root);
    printf("\n");
    printf("In Postorder:\n");
    printPostorder(root);
    printf("\n");
    printf("============================\n");
    printf("Whole tree:\n");
    print_tree(root);
    printf("============================\n");

    printf("(%d) Exist: %s\n", 50, find_node(root, 50) ? "True" : "False");
    printf("(%d) Exist: %s\n", 30, find_node(root, 30) ? "True" : "False");
    printf("(%d) Exist: %s\n", 20, find_node(root, 20) ? "True" : "False");
    printf("(%d) Exist: %s\n", 40, find_node(root, 40) ? "True" : "False");
    printf("(%d) Exist: %s\n", 70, find_node(root, 70) ? "True" : "False");  
    printf("(%d) Exist: %s\n", 60, find_node(root, 60) ? "True" : "False");
    printf("(%d) Exist: %s\n", 80, find_node(root, 80) ? "True" : "False");
    printf("(%d) Exist: %s\n", 5, find_node(root, 5) ? "True" : "False");
    printf("(%d) Exist: %s\n", 100, find_node(root, 100) ? "True" : "False");

    free(root);
    return 0;
}

treenode *create_node(int value)
{
    treenode *root = (treenode*)malloc(sizeof(treenode));
    root->value = value;
    root->left = NULL;
    root->right = NULL;

    return root;
}

treenode* insert_node(treenode *root, int value)
{   
    if (root == NULL)
    {
        return create_node(value);
    }
    else if (value < root->value) 
    {
        /* Insert on left */
        root->left = insert_node(root->left, value);
    }
    else if (value > root->value) 
    {
        /* Insert on right */
        root->right = insert_node(root->right, value);
    }   

    /* Return unchanged root */
    return root; 
}

void inorder(treenode* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->value);
        inorder(root->right);
    }
}

void print_tabs(int num_tabs)
{
    for (size_t i = 0; i < num_tabs; i++)
    {
        printf("\t");
    }    
}

void print_tree_rec(treenode *root, int level)
{
    if (root == NULL)
    {
        print_tabs(level);
        printf("<EMPTY>\n");

        return;
    }

    print_tabs(level);
    printf("Value = %d\n", root->value);
    print_tabs(level);
    printf("Left\n");

    print_tree_rec(root->left, level + 1);
    print_tabs(level);
    printf("Right\n");

    print_tree_rec(root->right, level + 1);
    print_tabs(level);
    printf("<END>\n");
}

void print_tree(treenode *root)
{
    print_tree_rec(root, 0);
}

void printInorder(treenode* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the value of node */
    printf("%d ", node->value);
 
    /* now recur on right child */
    printInorder(node->right);
}

void printPreorder(treenode* node)
{
    if (node == NULL)
        return;
 
    /* first print value of node */
    printf("%d ", node->value);
 
    /* then recur on left subtree */
    printPreorder(node->left);
 
    /* now recur on right subtree */
    printPreorder(node->right);
}

void printPostorder(treenode* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->left);
 
    // then recur on right subtree
    printPostorder(node->right);
 
    // now deal with the node
    printf("%d ", node->value);
}