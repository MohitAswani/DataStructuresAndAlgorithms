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
 * @brief We make a new node and if the head is null we return the new node else we add that node.
 * 
 * Time complexity : O(1)
 * Auxillary space : O(1)
 * 
 * @param head 
 * @param data 
 */
void insertAtBegin(Node *&head,int data){
    Node *node=new Node(data);

    if(head==NULL){
        head=node;
        return ;
    }

    node->next=head;
    head->prev=node;
    head=node;
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
    insertAtBegin(head,30);
    traverse(head);

    return 0;
}