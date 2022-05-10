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
/**
 * @brief If the head is null we don't do anything.
 * 
 * If head->next is null we make the head null and return.
 * 
 * If none of the above conditions are true we make the previous of head->next as null and make head->next as the head and delete the previous head.
 * 
 * Time complexity : O(1)
 * Auxillary space : O(1)
 * 
 * @param head 
 */
void deleteAtBegin(Node *&head){
    if(head==NULL){
        return ;
    }

    Node *temp=head;

    if(head->next==NULL){
        delete head;
        head=NULL;
        return ;
    }

    head->next->prev=NULL;
    head=head->next;
    delete temp;
}
void traverse(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    int a;
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->prev=head;
    head->next->next=new Node(30);
    head->next->next->prev=head->next;

    traverse(head);
    deleteAtBegin(head);
    traverse(head);

    return 0;
}