#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
void traverse(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
/**
 * @brief To reverse a doubly linked list we just swap the prev and next pointer of each element in the doubly linked list.
 *
 * In case the list is empty we don't do anything and just return.
 *
 * Time complexity : O(n)
 * Auxillary space : O(1)
 *
 * @param head
 */
void reverseDLL(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        swap(curr->next, curr->prev);
        curr = curr->prev;
    }
    head = curr;
    swap(curr->next, curr->prev);
    return;
}
int main()
{
    int a;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    traverse(head);
    reverseDLL(head);
    traverse(head);

    return 0;
}