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

/**
 * @brief To delete the head element we traverse to the last element and change its next pointer to point to the head->next element and then delete the head.
 *
 * Time complexity : O(n)
 * Auxillary space : O(1)
 *
 * @param head
 */
void deleteHeadNaive(Node *&head)
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
        Node *curr = head;

        while (curr->next != head)
        {
            curr = curr->next;
        }

        Node *temp = head;
        curr->next = head->next;
        head = head->next;
        delete temp;
    }
}

/**
 * @brief In this solution we swap the data of head and head->next then we make next of head point to the head->next->next and then we just delete the head->next which is equivalent to delete the head.
 *
 * Time complexity : O(1)
 * Auxillary space : O(1)
 *
 * @param head
 */
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

int main()
{
    // Node *head=NULL;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;

    traverse(head);
    deleteHeadEfficient(head);
    traverse(head);

    return 0;
}