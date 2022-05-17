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
 * @brief The following function first finds the length of the linked list and then uses its length to find the required node.
 *
 * So it does 2 traversals of the linked list.
 *
 * Time complexity : O(n)
 * Auxillary space : O(1)
 *
 * @param head
 * @param n
 */
void nFromEndNaive(Node *head, int n)
{

    Node *curr = head;
    int count = 0;

    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    if (n >= count)
    {
        return;
    }

    curr = head;

    for (int i = 0; i < count - n - 1; i++)
    {
        curr = curr->next;
    }

    cout << curr->data << endl;
}

/**
 * @brief The following function uses two pointer approach to find the nth node from the end.
 *
 * So we move one pointer 'n' positions ahead of one pointer and then we move both the pointers at the same speed. If the second pointer reaches the last node then the first pointer has reached the requirred node.
 *
 * So it does 1 traversals of the linked list.
 *
 * Time complexity : O(n)
 * Auxillary space : O(1)
 *
 * @param head
 * @param n
 */
void nFromEndEfficient(Node *head, int n)
{
    Node *ptr1 = head;
    Node *ptr2 = ptr1;

    for (int i = 0; i < n; i++)
    {
        if (ptr2 == NULL)
        {
            return;
        }
        ptr2 = ptr2->next;
    }

    while (ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    cout << ptr1->data << endl;
}
int main()
{
    int a;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    nFromEndNaive(head, 8);
    nFromEndEfficient(head, 8);

    return 0;
}