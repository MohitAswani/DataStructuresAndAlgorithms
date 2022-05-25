#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int d)
    {
        data = d;
        next = NULL;
        random = NULL;
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
 * @brief In this problem we are given a linked list where every node has two pointer's next and random, where next points to the next node and random points to any random node. We need to clone this list using random pointers.
 *
 * @return int
 */
Node* cloningUsingHashing(Node *head)
{
    map <Node *,Node *> cloneMap;

    for(Node *curr=head;curr!=NULL;curr=curr->next)
    {
        cloneMap[curr]=new Node(curr->data);
    }

    for(Node *curr=head;curr!=NULL;curr=curr->next)
    {
        Node *cloneCurr=cloneMap[curr];
        cloneCurr->next=cloneMap[curr->next];
        cloneCurr->random=cloneMap[curr->random];
    }

    return cloneMap[head];
}
int main()
{
    int a;
    Node *h1 = new Node(10);
    insertAtEnd(h1,5);
    insertAtEnd(h1,20);
    insertAtEnd(h1,15);
    insertAtEnd(h1,20);

    h1->random=h1->next->next;
    h1->next->random=h1->next->next->next;
    h1->next->next->random=h1;
    h1->next->next->next->random=h1->next->next;
    h1->next->next->next->next->random=h1->next->next->next;

    traverse(h1);
    Node *cloned=cloningUsingHashing(h1);
    traverse(cloned);

    return 0;
}