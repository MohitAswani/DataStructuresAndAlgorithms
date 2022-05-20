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

void insertAtEnd(Node *&head, int data)
{
    Node *node = new Node(data);

    if (head == NULL)
    {
        head = node;
    }

    Node *curr = head;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = node;
}

/**
 * @brief In the below function we compare the curr node with curr->next node. If they contain the same data then we simply make the curr->next=curr->next->next else we just move the curr forward.
 * 
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param head 
 */
void removeDuplicates(Node *&head)
{
    Node *curr=head;

    while(curr!=NULL&&curr->next!=NULL)
    {
        if(curr->data==curr->next->data)
        {
            Node *temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
        else
        {
            curr=curr->next;
        }
    }
}

int main()
{
    // Node *head=NULL;
    Node *head = new Node(10);
    insertAtEnd(head,20);
    insertAtEnd(head,20);
    insertAtEnd(head,30);
    insertAtEnd(head,30);
    insertAtEnd(head,30);
    insertAtEnd(head,40);
    insertAtEnd(head,40);

    traverse(head);
    removeDuplicates(head);
    traverse(head);

    return 0;
}