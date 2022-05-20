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
 * @brief To delete element at the end we check the number of nodes, if no nodes then linked list empty, if one node we make the head as null else we find the second last node of the linked list and make its next as null and deallocate the memory allocated to that particular node.
 *
 * Time complexity : O(n)
 * Auxillary space : O(1)
 *
 * @param head
 * @param data
 */
void deleteAtEnd(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked list empty" << endl;
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
        Node *curr = head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }

        delete curr->next;
        curr->next = NULL;
        return;
    }
}
int main()
{
    int a;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    traverse(head);
    deleteAtEnd(head);
    traverse(head);

    return 0;
}