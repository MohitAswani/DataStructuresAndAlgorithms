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
 * @brief To reverse a linked list we just reverse the pointers and then make the last element as the head.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param head 
 */
void reverseItterative(Node *&head){

    Node *curr=head;
    Node *prev=NULL;

    while(curr!=NULL){    // reversing the pointers
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    head=prev;           // making the tail as the head
}
int main(){
    // Node *head=NULL;
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);

    traverse(head);
    reverseItterative(head);
    traverse(head);

    return 0;
}