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
 * @brief In this solution the recursive call return a linked list which is reversed from head->next to tail and it returns the head of the reversed linked list (which will be the last node of the linked list).
 * 
 * The base case is when the head is NULL or the node next to head is null in that case we just return the head.
 * 
 * In other cases we consider that the recursive call reverse the list from head->next to tail of LL. 
 * So we now just reverse the current node.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(n)
 * 
 * @param head 
 */
Node* reverseRecursive(Node *head){

    // Base cases
    if(head==NULL||head->next==NULL)
    {
        return head;
    }


    // Recursive case
    Node *restHead=reverseRecursive(head->next);
    Node *restTail=head->next;
    restTail->next=head;
    head->next=NULL;

    return restHead;
}
int main(){
    // Node *head=NULL;
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);

    traverse(head);
    head=reverseRecursive(head);
    traverse(head);

    return 0;
}