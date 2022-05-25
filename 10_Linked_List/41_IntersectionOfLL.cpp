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
 * @brief In this problem we are given 2 LL's and those two LL's might contain some common nodes so we need to find the point of intersection of these two nodes.
 *
 * One way of doing this is hashing, so we store all the nodes of 1 LL in a hashset and traverse the 2nd LL finding the nodes in the hashset, the first node to be found is the point of intersection.
 *
 * The above solution requires O(m+n) extra space.
 *
 * To do it in O(1) extra space we first take the length of two LL's , find their different and then move the bigger LL by the amount. And then we move the linked lists at the same speed and first node which is common between the two is the point of intersection.
 *
 * The mathematical reasoning behind this is that when we move the bigger LL by the amount the difference between length is eliminated and the two list becomes of the same length and now the intersection can be found at same distance from their current positions.
 *
 * Time complexity : O(m+n)
 * Auxillary space : O(1)
 *
 * @param h1
 * @param h2
 * @return Node*
 */
Node *intersectionOfLL(Node *h1, Node *h2)
{
    ll l1 = 0, l2 = 0;
    Node *curr1 = h1;
    Node *curr2 = h2;

    while (curr1 != NULL)
    {
        l1++;
        curr1 = curr1->next;
    }

    while (curr2 != NULL)
    {
        l2++;
        curr2 = curr2->next;
    }

    ll diff = abs(l1 - l2);

    curr1 = h1;
    curr2 = h2;

    if (l1 > l2)
    {
        while (diff != 0 && curr1 != NULL)
        {
            diff--;
            curr1 = curr1->next;
        }
    }
    else
    {
        while (diff != 0 && curr2 != NULL)
        {
            diff--;
            curr2 = curr2->next;
        }
    }

    while (curr1 != NULL && curr2 != NULL )
    {
        if(curr1 == curr2)
        {
            return curr1;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return NULL;
}

int main()
{
    int a;
    Node *h1 = new Node(5);
    insertAtEnd(h1, 8);
    insertAtEnd(h1, 7);
    insertAtEnd(h1, 10);
    insertAtEnd(h1, 12);
    insertAtEnd(h1, 15);

    Node *h2 = new Node(9);
    h2->next = h1->next->next->next;

    Node *poi = intersectionOfLL(h1, h2);
    if (poi != NULL)
        cout << poi->data << endl;

    return 0;
}