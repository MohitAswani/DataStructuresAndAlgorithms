#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void traverse(Node *&head)
{

    if (head == NULL)
    {
        return;
    }

    cout << head->data << " ";

    for (Node *curr = head->next; curr != head; curr = curr->next)
    {
        cout << curr->data << " ";
    }
    cout << endl;
}
/**
 * @brief In this solution we simply add an element after last element.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param head 
 * @param data 
 */
void insertAtEndNaive(Node *&head,ll data){
    Node *temp=new Node(data);

    if(head==NULL){
        head=temp;
        head->next=head;
    }
    else{

        Node *curr=head;

        while(curr->next!=head){
            curr=curr->next;
        }

        temp->next=curr->next;
        curr->next=temp;
    }
}

/**
 * @brief In this solution we add an element at the beginning using the previous efficient method and then we make the node next to the head as the head so the inserted node becomes the tail.
 * 
 * Time complexity : O(1)
 * Auxillary space : O(1)
 * 
 * @param head 
 * @param data 
 */
void insertAtEndEfficient(Node *&head,ll data){
    Node *temp=new Node(data);

    if(head==NULL){
        head=temp;
        head->next=head;
    }
    else{
        temp->next=head->next;
        head->next=temp;

        swap(head->data,temp->data);
        head=temp;
    }
}
int main()
{
    // Node *head=NULL;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;

    traverse(head);
    insertAtEndEfficient(head,40);
    traverse(head);

    return 0;
}