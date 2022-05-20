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
 * @brief Idea behind this algorithm is that we have two pointers, one moves one node at a time another moves two nodes at a time. So if there is a cycle/loop in the linked list then these two pointer will definately meet if not then they won't meet.
 *
 * Time complexity : O(n)
 * Auxillary space : O(1)
 *
 * @param head
 */
void floydCycleDetection(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)   // we put it at the bottom so that they move away from the head
        {
            cout << "LOOP DETECTED" << endl;
            return;
        }
    }

    cout << "NO LOOP DETECTED" << endl;
}

int main()
{
    // Node *head=NULL;
    Node *head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(12);
    head->next->next->next = new Node(20);
    head->next->next->next->next = head->next;

    floydCycleDetection(head);

    return 0;
}