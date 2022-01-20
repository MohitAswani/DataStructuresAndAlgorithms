#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
void printLL(Node *head)
{
    if (head == NULL)
        return;

    cout << head->data << endl;
    printLL(head->next);

    // Time complexity : O(n)
    // Auxillary space : O(n) due to recursive call stack
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    printLL(head);

    return 0;
}