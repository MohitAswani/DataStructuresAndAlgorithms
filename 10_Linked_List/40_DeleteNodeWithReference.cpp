#include <bits/stdc++.h>
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
 * @brief This is a trick problem and to solve it we copy the data of next node to the node which is to be deleted and then we delete the next node from the linked list and put curr->next = curr->next->next.
 * 
 * Time complexity : O(1)
 * Auxillary space : O(1)
 * 
 * @param node 
 */
void deleteNodeReference(Node *node)
{

    // We assume that the given node cannot be the last node

    Node *next = node->next;
    node->data = next->data;
    node->next = next->next;
    delete next;
}
int main()
{
    int a;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    traverse(head);
    deleteNodeReference(head->next->next);
    traverse(head);

    return 0;
}