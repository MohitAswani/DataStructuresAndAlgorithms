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

/**
 * @brief In the below function we try to reverse the nodes of a linked list in groups of K. 
 * 
 * If k<=n then kth node is the head of the linked list.
 * 
 * We first try to reverse the linked list unitl curr==NULL or count of nodes == k. So this will reverse the first k nodes if they exist.
 * 
 * Then we make a recursive call in which we reverse the next k nodes and so on.
 * 
 * Then to connect the k nodes we reversed in the current function to the rest of the linked list we attach the head of those k nodes to rest_head (which is the head of the remaining nodes returned by the recursive call). 
 * 
 * Also now the head of the linked list will be the prev which is the k th node.
 * 
 * Time complexity : O(n)  Coz we traverse through every node and reverse them
 * Auxillary space : O(n/k)  Coz we call for every k nodes.
 * 
 * @param head 
 * @param k 
 * @return Node* 
 */
Node* reverseInKRecursive(Node *head,ll k)
{
    Node *curr=head;
    Node *prev=NULL;
    Node *next=NULL;

    int count=0;

    while(curr!=NULL&&count<k)
    {
        next=curr->next;
        curr->next=prev;
        
        prev=curr;
        curr=next;
        count++;
    }

    if(curr!=NULL)
    {
        Node *rest_head=reverseInKRecursive(curr,k);
        head->next=rest_head;
    }

    return prev;
}

/**
 * @brief For better understanding watch the video : 'Reverse a linked list in groups of size k'
 * 
 * Time complexity : O(n)  Coz we traverse through every node and reverse them
 * Auxillary space : O(1) 
 * 
 * 
 * @param head 
 * @param k 
 * @return Node* 
 */
Node* reverseInKItterative(Node *head,ll k)
{
    Node *curr=head;
    Node *prevFirst=NULL;         // used to store the last node of the previous reversed list
    bool isFirstPass=true;        // used to detect is the current pass is the first pass, if so we make the head as the last node of the first k nodes (kth node).

    while(curr!=NULL)
    {
        Node *first=curr,*prev=NULL;
        int count=0;

        while(curr!=NULL&&count<k)          // normal reversal of list
        {
            Node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }

        if(isFirstPass){         // if first pass make the kth node as the head.
            head=prev;
            isFirstPass=false;
        }
        else{                    // else place the list after the previous k nodes
            prevFirst->next=prev;
        }

        prevFirst=first;         // store the tail of last k nodes.
    }

    return head;
}


int main()
{
    // Node *head=NULL;
    Node *head = new Node(10);
    insertAtEnd(head,20);
    insertAtEnd(head,30);
    insertAtEnd(head,40);
    insertAtEnd(head,50);
    insertAtEnd(head,60);
    insertAtEnd(head,70);

    traverse(head);
    head=reverseInKItterative(head,3);
    traverse(head);

    return 0;
}