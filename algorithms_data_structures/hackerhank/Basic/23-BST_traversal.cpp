#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }

    void levelOrder(Node* root)
    {
        // Base Case
        if (root == NULL)
            return;
    
        // Create an empty queue for level order traversal
        queue<Node*> q;
    
        // Enqueue Root and initialize height
        q.push(root);
    
        while (q.empty() == false) {
            // nodeCount (queue size) indicates number
            // of nodes at current level.
            int nodeCount = q.size();
    
            // Dequeue all nodes of current level and
            // Enqueue all nodes of next level
            while (nodeCount > 0) {
                Node* Node = q.front();
                cout << Node->data << " ";
                q.pop();
                if (Node->left != NULL)
                    q.push(Node->left);
                if (Node->right != NULL)
                    q.push(Node->right);
                nodeCount--;
            }
        }
    }

};

int main()
{
    Solution myTree;
    Node* root=NULL;
    int data;

    root = myTree.insert(root, 3);
    root = myTree.insert(root, 5);
    root = myTree.insert(root, 4);
    root = myTree.insert(root, 7);
    root = myTree.insert(root, 2);
    root = myTree.insert(root, 1);

    myTree.levelOrder(root);

    return 0;
}