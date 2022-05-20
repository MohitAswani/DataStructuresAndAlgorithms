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
 * @brief In this we do that reverse of the previous solution. 
 * 
 * So we get reversed nodes before the current node and we try to reverse the current node.
 *
 * To reverse the current node we store an extra param prev and make the next of head point to the prev.
 * 
 * Then we pass in the next node as the head and curr as the prev to the next recursive call.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param head
 */
Node *reverseRecursive(Node *head, Node *prev = NULL)
{

    // Base cases
    if (head == NULL)
    {
        return head;
    }
    if(head->next == NULL)
    {
        head->next=prev;
        return head;
    }

    // Recursive case
    Node *next = head->next;
    head->next = prev;
    return reverseRecursive(next, head);
}
int main()
{
    // Node *head=NULL;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    traverse(head);
    head = reverseRecursive(head);
    traverse(head);

    return 0;
}