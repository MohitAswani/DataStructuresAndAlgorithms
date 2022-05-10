#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

void traverse(Node *head){

    Node *curr=head;

    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }

    cout<<endl;
}

/**
 * @brief To add an element at the end of linked list we find the node whose next is null (which is the last node) and we add our node next to that end node.
 * 
 * Time complexity : O(n)  (We can do it in O(1) if we store a reference to the last element of the linked list)
 * Auxillary space : O(1)
 * 
 * @param head 
 * @param data 
 */
void insertAtEnd(Node *&head,int data){
    Node *node=new Node(data);

    // Special case for when the head node is null.
    if(head==NULL){
        head=node;
    }
    
    Node * curr=head;

    while(curr->next!=NULL){
        curr=curr->next;
    }

    curr->next=node;
}
int main(){
    int a;
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);

    traverse(head);
    insertAtEnd(head,40);
    traverse(head);

    return 0;
}