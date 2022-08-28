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
 * @brief In this function we are simply swapping data. The issue with this solution is that in some case the data might be an object or big data. So in that case the time complexity increases.
 *
 * Time complexity : O(n)
 * Auxillary space : O(1)
 *
 * @param head
 */
void swappingData(Node *&head)
{
    Node *curr = head;

    while (curr != NULL && curr->next != NULL)
    {
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
}

/**
 * @brief So if we swap the nodes using links rather than swapping the data then we must traverse two nodes at a time and then swap the links approapriately.
 *
 * Time complexity : O(n)
 * Auxillary space : O(1)
 *
 * @param head
 */
void swappingLinks(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL && curr->next != NULL)
    {
        Node *next = curr->next->next;
        if (prev == NULL)
        {
            head = head->next;
            Node *temp = curr->next->next;
            curr->next->next = curr;
            curr->next = temp;
        }
        else
        {
            prev->next = curr->next;
            Node *temp = curr->next->next;
            curr->next->next = curr;
            curr->next = temp;
        }
        prev = curr;
        curr = next;
    }
}

int main()
{
    int a;
    Node *head = new Node(10);
    insertAtEnd(head, 11);
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);
    insertAtEnd(head, 14);
    insertAtEnd(head, 15);
    insertAtEnd(head, 16);
    insertAtEnd(head, 17);

    traverse(head);
    swappingLinks(head);
    traverse(head);

    return 0;
}