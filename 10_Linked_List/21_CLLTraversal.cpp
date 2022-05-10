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

/**
 * @brief We keep on traversing until we come back to the same node.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param head 
 */
void traversalFor(Node *&head)
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
 * @brief We keep on traversing until we come back to the same node.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param head 
 */
void traversalDoWhile(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *curr = head;

    do{
        cout << curr->data << " ";
        curr = curr->next;
    }while (curr != head);

    cout<<endl;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;

    traversalFor(head);
    traversalDoWhile(head);

    return 0;
}