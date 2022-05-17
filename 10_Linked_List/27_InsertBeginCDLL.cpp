#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
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
void insertBegin(Node *&head, ll data)
{
    Node *temp = new Node(data);

    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        head = temp;
    }
    else
    {
        head->prev->next = temp;
        head->prev = temp;
        temp->prev = head->prev;
        temp->next = head;
        head = temp;
    }
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->next = head;
    head->next->next->prev = head->next;
    head->prev = head->next->next;

    traverse(head);
    insertBegin(head,40);
    traverse(head);

    return 0;
}