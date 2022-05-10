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

void deleteHeadEfficient(Node *&head)
{

    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    else
    {

        swap(head->data, head->next->data);

        Node *temp = head->next;
        head->next = head->next->next;

        delete temp;
    }
}

/**
 * @brief To delete the kth element of a linked list we first make sure the linked list is not empty. 
 * Then if k==1 we use the code to remove head in a circular linked list.
 * If if none of the above conditions are true we traverse through the linked list k-2 (so as to reach the element just before the one to be removed) or till we reach the last node.
 * If we reach the last node it means that the list is smaller than the required size.
 * If not then we just remove the node next to the curr node.
 *  
 * @param head 
 * @param k 
 */
void deleteKth(Node *&head, ll k)
{
    if (head == NULL)
    {
        return;
    }
    if (k == 1)
    {
        deleteHeadEfficient(head);
    }
    else
    {

        Node *curr = head;

        for (ll i = 0; i < k - 2 && curr->next!=head; i++)
        {
            curr = curr->next;
        }

        if(curr->next==head){  // this will make sure that k is not greater than the size of the linked list.
            return ;
        }
        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
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
    deleteKth(head, 40);
    traverse(head);

    return 0;
}