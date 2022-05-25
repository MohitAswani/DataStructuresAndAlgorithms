#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node(char d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtBegin(Node *&head, char data)
{
    Node *node = new Node(data);
    node->next = head;
    head = node;
}

void insertAtEnd(Node *&head, char data)
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
 * @brief In this method we push the element of the linked list in a stack and then compare them with the linked list , if they are equal then we return true else false.
 *
 * Time complexity : O(n)
 * Auxillary space : O(N)
 *
 * @param head
 * @return true
 * @return false
 */
bool palindromeLLNaive(Node *head)
{
    stack<char> stk;

    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        stk.push(curr->data);
    }

    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        if (stk.top() != curr->data)
        {
            return false;
        }
        stk.pop();
    }

    return true;
}

/**
 * @brief In this solution we reverse the linked list after the middle or the first middle (in case of even node LL) and then we compare the reverse list with the list from head using the reversed linked list becomes null.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param head 
 * @return true 
 * @return false 
 */
bool palindromeEfficient(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    // We compare fast->next and not fast since in case of even nodes we want the first middle.
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *curr = slow->next;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    slow->next = prev;

    Node *rev = prev;
    curr=head;

    while (rev != NULL)
    {
        if (rev->data != curr->data)
        {
            return false;
        }
        rev = rev->next;
        curr = curr->next;
    }

    return true;
}
int main()
{
    Node *h1 = new Node('M');
    insertAtEnd(h1, 'A');
    insertAtEnd(h1, 'N');
    insertAtEnd(h1, 'A');
    insertAtEnd(h1, 'M');

    cout << palindromeEfficient(h1) << endl;
    return 0;
}