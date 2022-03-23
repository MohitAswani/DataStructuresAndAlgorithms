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
/**
 * @brief This will traverse the pointer to the linked list until the pointer becomes NULL.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param head 
 */
void traverse(Node *head){

    Node *curr=head;

    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }

    cout<<endl;
}
int main(){
    int a;
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);

    traverse(NULL);
    traverse(head);
    traverse(head->next);
    traverse(head->next->next);
    return 0;
}