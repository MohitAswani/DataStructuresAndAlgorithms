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
 * @brief To insert element at the end of a linked list we traverse the linked list and find the element whose next is null (last element). Then we just insert our node here.
 *
 * One special case we must consider is when the list is empty , then we simply make the new node as the head.
 *
 * Time complexity : O(n)  (can be make O(1) if the last node is also given)
 * Auxillary space : O(1)
 *
 * @param head
 * @param data
 */
void insertAtEnd(Node *&head, int data)
{
    Node *node = new Node(data);
    if (head == NULL) // For an empty linked list we just make the new node as head
    {
        head = node;
        return;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = node;
    node->prev = curr;
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

    traverse(head);
    insertAtEnd(head, 50);
    traverse(head);

    return 0;
}