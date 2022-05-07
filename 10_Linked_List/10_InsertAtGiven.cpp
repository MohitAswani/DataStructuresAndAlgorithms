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

void traverse(Node *head)
{

    Node *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
}

/**
 * @brief To add an element at the end of linked list we find the node whose next is null (which is the last node) and we add our node next to that end node.
 *
 * Time complexity : O(n)
 * Auxillary space : O(1)
 *
 * @param head
 * @param data
 */
void insertAtGiven(Node *&head, int data, int pos)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr->next != NULL && pos != 1)
    {
        prev=curr;
        curr=curr->next;
        pos--;
    }

    if(prev==NULL){   // Case when the linked list is empty
        Node *temp=new Node(data);
        temp->next=head;
        head=temp;
    }
    else if(curr->next==NULL&&pos==2)  // Case when the element is to be inserted at the end and list is non-empty 
    {
        Node *temp=new Node(data);
        curr->next=temp;
        temp->next=NULL;   
    }
    else if(curr->next==NULL&&pos>2)  // Case when the list doesn't have enough elements.
    {
        cout<<"NOT ENOUGH ELEMENTS IN THE LINKED LIST"<<endl;
    }
    else{     // Case when element is to insert in the middle somewhere
        Node *temp=new Node(data);
        prev->next=temp;
        temp->next=curr;
    }
}
int main()
{
    int a;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    traverse(head);
    insertAtGiven(head, 40,4);
    traverse(head);

    return 0;
}