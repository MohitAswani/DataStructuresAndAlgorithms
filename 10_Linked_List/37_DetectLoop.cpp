#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    bool visited;
    Node(int d)
    {
        data = d;
        next = NULL;
        visited=false;
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
 * @brief In this we modify the node of the linked list and we store another variable 'visited' in each node and if a node is visited again then there is a loop else no loop.
 * 
 * Time complexity : O(n)
 * Auxillary space : Little more coz of isVisited.
 * 
 * @param head 
 */
void naiveDetectALoopModifyLL(Node *&head){

    Node *curr=head;

    while(curr!=NULL)
    {
        if(curr->visited==true)
        {
            cout<<"LOOP DETECTED"<<endl;
            return;
        }
        curr->visited=true;
        curr=curr->next;
    }

    cout<<"NO LOOP DETECTED"<<endl;
}

/**
 * @brief In this solution after we visited every node we make the next of the visited node equal to a dummy node. So when we encounter a node whose next is the dummy node then that means that there is a loop in the linked list.
 * 
 * But this function will eventually destroy the LL.
 * 
 * Time complexity : O(N)
 * Auxillary space : O(1)
 * 
 * @param head 
 */
void naiveDetectALoopDestroyLL(Node *&head){

    Node *curr=head;
    Node *temp=new Node(INT_MAX);

    while(curr!=NULL)
    {
        if(curr->next==temp)
        {
            cout<<"LOOP DETECTED"<<endl;
            return;
        }

        Node *next=curr->next;
        curr->next=temp;
        curr=next;
    }

    cout<<"NO LOOP DETECTED"<<endl;
}

/**
 * @brief We use hashing to detect if there is a loop.
 * 
 * Time complexity : O(N)
 * Auxillary space : O(N)
 * 
 * @param head 
 */
void detectALoopHashing(Node *&head){

    Node *curr=head;
    unordered_set <Node *> l;

    while(curr!=NULL)
    {
        if(l.find(curr)!=l.end())
        {
            cout<<"LOOP DETECTED"<<endl;
            return;
        }

        l.insert(curr);
        curr=curr->next;
    }

    cout<<"NO LOOP DETECTED"<<endl;
}
int main()
{
    // Node *head=NULL;
    Node *head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(12);
    head->next->next->next = new Node(20);
    // head->next->next->next->next = head->next;

    // naiveDetectALoopModifyLL(head);
    // naiveDetectALoopDestroyLL(head);
    detectALoopHashing(head);

    return 0;
}