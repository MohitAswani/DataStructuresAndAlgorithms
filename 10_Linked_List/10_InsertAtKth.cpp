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
 * @brief To add an element at a given position do the following :
 *
 * 1) Check if the element needs to be add at the beginning.
 *
 * 2) If not then move the current by till position pos-2 (practical observation) which lands us at the position just before the position where the element is to be inserted.
 *
 * 3) If curr becomes null in this process then the linked list is too short for the required insertion.
 *
 * 4) Else insert the given element at the curr->next positon.
 *
 * Time complexity : O(n)
 * Auxillary space : O(1)
 *
 * @param head
 * @param data
 */
void insertAtGiven(Node *&head, int data, int pos)
{
    Node *temp = new Node(data);

    if (pos == 1)
    { // if the element is to be inserted at the beginning
        temp->next = head;
        head = temp;
        return;
    }

    Node *curr = head;
    for (int i = 0; i < pos - 2 && curr != NULL; i++)
    { // find the correct position for element insertion
        curr = curr->next;
    }

    if (curr == NULL)
    { // Linked list too short to insert
        return;
    }

    temp->next = curr->next; // insertion at curr->next
    curr->next = temp;
}
int main()
{
    int a;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    traverse(head);
    insertAtGiven(head, 40, 4);
    traverse(head);

    return 0;
}