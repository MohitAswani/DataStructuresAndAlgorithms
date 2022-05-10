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
 * @brief Itteratively traveses the linked list and returns the position if element found else returns -1.
 * 
 * Linear linked list do not allow binary search since the time required to find the middle element is not O(1) hence binary search is not possible in linear linked list.
 * 
 * Special types of linked list called skip list allow binary search.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param head 
 * @param data 
 * @return int 
 */
int searchItterative(Node *&head, int data)
{
    int pos=0;
    Node *curr=head;

    while(curr!=NULL)
    {
        if(curr->data==data)
        return pos+1; 

        pos+=1;
        curr=curr->next;
    }

    return -1;
}
/**
 * @brief Recursively traverses the linked list and if the element is found the position is returned else it returns -1.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(n) due to the recursive call stack.
 * @param head 
 * @param data 
 * @param pos 
 * @return int 
 */
int searchRecursive(Node *&head, int data,int pos=0)
{
    if(head==NULL)
    {
        return -1;
    }

    if(head->data==data)
    {
        return pos+1;
    }

    return searchRecursive(head->next,data,pos+1);
}
int main()
{
    int a;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout<<searchItterative(head,60)<<endl;
    cout<<searchRecursive(head,30)<<endl;

    return 0;
}