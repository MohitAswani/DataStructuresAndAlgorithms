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
 * @brief In the following function we check for the following cases : 
 * 
 * 1) If the list is empty we make the new node as the head.
 * 
 * 2) If it is not we traverse to the last element then insert a new element there and make it the head.
 * 
 * @param head 
 * @param data 
 */
void insertAtBeginNaive(Node *&head,ll data){
    Node *temp=new Node(data);

    if(head==NULL){
        head=temp;
        head->next=head;
    }
    else{

        Node *curr=head;

        while(curr->next!=head){
            curr=curr->next;
        }

        temp->next=curr->next;
        curr->next=temp;
        head=temp;
    }
}

/**
 * @brief This is a efficient way of inserting the element at the beginning. To insert at beginning we insert a new node after the head and then swap the data of that node and the head.
 * 
 * Time complexity : O(1)
 * Auxillary space : O(1)
 * 
 * @param head 
 * @param data 
 */
void insertAtBeginEfficient(Node *&head,ll data){
    Node *temp=new Node(data);

    if(head==NULL){
        head=temp;
        head->next=head;
    }
    else{
        temp->next=head->next;
        head->next=temp;

        swap(head->data,temp->data);
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
    insertAtBeginEfficient(head,40);
    traverse(head);

    return 0;
}