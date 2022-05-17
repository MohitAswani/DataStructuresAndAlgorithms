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

/**
 * @brief This function uses two traversals of linked list hence it is naive.
 *
 * @param head
 */
void middleNaive(Node *head)
{

    Node *curr = head;
    int count = 0;

    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    curr = head;

    for (int i = 0; i < count / 2; i++)
    {
        curr = curr->next;
    }

    cout << curr->data << endl;
}

/**
 * @brief In the following function we use the fast and slow traversal. So by the time fast is at end , slow is at the middle.
 * 
 * In case of even nodes the condition for termination is fast==NULL and for odd nodes condition for termination is fast->next==NULL. (Check the example in previous files). 
 * 
 * Time complexity : O(n)   (One traversal)
 * Auxillary space : O(1)
 * 
 * @param head 
 */
void middleEfficient(Node *head){
    
    Node *slow=head;
    Node *fast=head;

    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }

    cout<<slow->data<<endl;
}
int main()
{
    int a;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    middleNaive(head);
    middleEfficient(head);

    return 0;
}