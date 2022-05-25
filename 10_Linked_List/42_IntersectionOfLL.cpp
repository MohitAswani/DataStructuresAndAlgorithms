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
 * @brief In this question we are given a linked list and we need to segregate the list in such a way that all the even elements of the list come first and in the same order as they appear in the list. And the rest of the odd elements appear after the even elements.
 *
 * To solve this we make two lists, one for even element and one for odd elements and keep on adding element till the list is over and then based on different conditions we just join these two lists.
 *
 * Time complexity : O(n)    (One traversal)
 * Auxillary space : O(1)
 *
 * @param node
 */
void oddEvenSegregation(Node *&head)
{
    Node *curr = head;
    Node *odd_start = NULL;
    Node *odd_end = NULL;
    Node *even_start = NULL;
    Node *even_end = NULL;

    while (curr != NULL)
    {
        Node *next = curr->next;
        if (curr->data % 2 == 0)
        {
            if (even_start == NULL)
            {
                even_start = curr;
                even_end = even_start;
                even_start->next = NULL;
            }
            else
            {
                even_end->next = curr;
                even_end = even_end->next;
                even_end->next = NULL;
            }
        }
        else
        {
            if (odd_start == NULL)
            {
                odd_start = curr;
                odd_end = odd_start;
                odd_start->next = NULL;
            }
            else
            {
                odd_end->next = curr;
                odd_end = odd_end->next;
                odd_end->next = NULL;
            }
        }

        curr = next;
    }

    if (even_start == NULL || odd_start == NULL)
        return;

    even_end->next = odd_start;

    head = even_start;
}
int main()
{
    int a;
    Node *head = new Node(13);
    head->next = new Node(11);
    head->next->next = new Node(12);
    head->next->next->next = new Node(13);

    traverse(head);
    oddEvenSegregation(head);
    traverse(head);

    return 0;
}