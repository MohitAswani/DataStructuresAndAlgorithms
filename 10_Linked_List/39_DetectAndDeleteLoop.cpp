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
 * @brief Building on the floyd cycle detection algo , we can say that once the slow and fast node meet , we can move the slow node to the start of the linked list.
 *
 * And one by one move that fast and slow node. The node where they meet is the start node of the loop.
 *
 * Time complexity : O(n)
 * Auxillary space : O(1)
 *
 * @param head
 */
void floydCycleDetectionAndDeletion(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) // we put it at the bottom so that they move away from the head
        {
            break;
        }
    }

    if (slow != fast)
        return;
    if (slow == head) // special case for when the whole linked list a loop
    {
        while (slow->next != head)
        {
            slow = slow->next;
        }

        slow->next = NULL;
        cout << "LOOP REMOVED" << endl;
        return;
    }

    slow = head;

    // In the below loop we compare the next pointers so that when a loop is detected we can remove the loop by making the next pointer of the node just before that start node of loop to NULL.

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
    cout << "LOOP REMOVED" << endl;
}

int main()
{
    // Node *head=NULL;
    Node *head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(12);
    head->next->next->next = new Node(20);
    head->next->next->next->next = head->next;

    floydCycleDetectionAndDeletion(head);
    traverse(head);

    return 0;
}