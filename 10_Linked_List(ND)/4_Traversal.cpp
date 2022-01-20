#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
void printLL(Node *head)
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<endl;
        curr=curr->next;
    }

    // Time complexity : O(n)
    // Auxillary space : O(1)

}
int main(){
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);

    printLL(head);

    /*
     when we pass head to a function , a copy of that head variable is made within the function so we need not worry about
     the head of main
    */
    
    return 0;
}