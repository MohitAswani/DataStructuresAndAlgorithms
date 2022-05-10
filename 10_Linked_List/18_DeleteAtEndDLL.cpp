#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};
void traverse(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
/**
 * @brief If the head is null we don't do anything.
 * 
 * If head->next is null we make the head null and return.
 * 
 * If none of the above conditions are true we traverse to the last element of linked list and make the next of previous element as null and delete the last element.
 * 
 * Time complexity : O(n)  (Due to list traversal)
 * Auxillary space : O(1)
 * 
 * We can reduce time complexity of all the operations at the end by maitaining a tail pointer in the double linked list but the issue with maintaining a tail pointer is that we need to update this tail pointer with every operation we perform.
 * 
 * @param head 
 */
void deleteAtEnd(Node *&head){
    if(head==NULL){
        return ;
    }

    Node *temp=head;

    if(head->next==NULL){
        delete head;
        head=NULL;
        return ;
    }

    Node *curr=head;

    while(curr->next!=NULL){
        curr=curr->next;
    }

    curr->prev->next=NULL;
    delete curr;
}
int main(){
    int a;
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->prev=head;
    head->next->next=new Node(30);
    head->next->next->prev=head->next;

    traverse(head);
    deleteAtEnd(head);
    traverse(head);

    return 0;
}