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

void insertAtBegin(Node *&head, int data)
{
    Node *node = new Node(data);
    node->next = head;
    head = node;
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

void deleteAtBegin(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked list empty" << endl;
        return;
    }
    Node *head_ref = head;
    head = head->next;
    delete head_ref;
}

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

void reverseItterative(Node *&head)
{

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
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
 * @brief To merge two linked list a and b we just keep on comparing their values and keep on adding the smaller node to our new linked list to get the sorted list.
 * 
 * Time complexity : O(n+m)
 * Auxillary space : O(1)    // this is where its better than array.
 * 
 * @param a 
 * @param b 
 * @return Node* 
 */
Node *SortedMerge(Node *a, Node *b)
{
    Node *ptr1 = a;
    Node *ptr2 = b;

    Node *head = NULL;
    Node *tail = NULL;

    while (ptr1 != NULL || ptr2 != NULL)
    {
        if (ptr1 != NULL && ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                Node *temp = ptr2->next;
                if (tail)
                {
                    tail->next = ptr2;
                    tail = tail->next;
                    tail->next = NULL;
                }
                else
                {
                    tail = ptr2;
                    tail->next = NULL;
                }
                ptr2 = temp;
            }
            else
            {
                Node *temp = ptr1->next;
                if (tail)
                {
                    tail->next = ptr1;
                    tail = tail->next;
                    tail->next = NULL;
                }
                else
                {
                    tail = ptr1;
                    tail->next = NULL;
                }
                ptr1 = temp;
            }
        }
        else if (ptr1 != NULL)
        {
            Node *temp = ptr1->next;
            if (tail)
            {
                tail->next = ptr1;
                tail = tail->next;
                tail->next = NULL;
            }
            else
            {
                tail = ptr1;
                tail->next = NULL;
            }
            ptr1 = temp;
        }
        else if (ptr2 != NULL)
        {
            Node *temp = ptr2->next;
            if (tail)
            {
                tail->next = ptr2;
                tail = tail->next;
                tail->next = NULL;
            }
            else
            {
                tail = ptr2;
                tail->next = NULL;
            }
            ptr2 = temp;
        }

        if (head == NULL)
        {
            head = tail;
        }
    }

    return head;
}
int main()
{
    Node *h1 = new Node(5);
    insertAtEnd(h1,10);
    insertAtEnd(h1,15);
    insertAtEnd(h1,20);
    insertAtEnd(h1,25);

    Node *h2 = new Node(15);
    insertAtEnd(h2,20);
    insertAtEnd(h2,25);
    insertAtEnd(h2,30);

    traverse(h1);
    traverse(h2);

    Node *h3=SortedMerge(h1,h2);

    traverse(h3);
    return 0;
}