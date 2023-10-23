#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node(int d) {
            data=d;
            next=NULL;
        }
};

class Solution 
{
    public:
        Node* removeDuplicates(Node *head)
        {   
            vector <int> v;

            Node *new_ref = NULL;

            while (head != NULL)
            {
                v.push_back(head->data);
                head = head->next;        
            }
            
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
        
            // 1 2 3 4 
            for (auto it:v)
            {
                new_ref = insert(new_ref, it);
            }
            
            return new_ref;
        }

        Node* insert(Node *head,int data)
        {
            Node* p = new Node(data);
            if(head==NULL) {
                head=p;  
            }
            else if(head->next==NULL) {
                head->next=p;
            }
            else {
                Node *start=head;
                while(start->next!=NULL){
                    start=start->next;
                }
                start->next=p;   

            }
            return head;       
        }

        void display(Node *head)
        {
            Node *start=head;
            while(start)
            {
                cout<<start->data << " ";
                start=start->next;
            }
        }
};
			
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int data;
    
    head=mylist.insert(head, 1);
    head=mylist.insert(head, 2);
    head=mylist.insert(head, 2);
    head=mylist.insert(head, 3);
    head=mylist.insert(head, 3);
    head=mylist.insert(head, 4);

    head=mylist.removeDuplicates(head);
	mylist.display(head);
}