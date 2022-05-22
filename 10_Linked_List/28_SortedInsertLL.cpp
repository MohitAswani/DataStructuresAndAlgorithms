#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

void traverse(Node *head){

    Node *curr=head;

    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }

    cout<<endl;
}

/**
 * @brief To perform sorted insert we do the following things : 
 * 
 * 1) If linked list is empty we return our new node.
 * 
 * 2) If the data to be inserted is less than head we insert it at head.
 * 
 * 3) If we find a bigger data node we insert the node before it.
 * 
 * 4) If the data is bigger than tail we insert it at end
 * 
 * Time complexity : O(n)  (Depends upon the position so time complexity is theta(x) where x is the position where data is inserted)
 * Auxillary space : O(1)
 * 
 * @param head 
 * @param data 
 */
void sortedInsertion(Node *&head,int data){
    Node *node=new Node(data);
    
    if(head==NULL){
        head=node;
        return ;
    }

    Node *curr=head;
    Node *prev=NULL;

    while(curr!=NULL){
        if(node->data<=curr->data){
            
            if(prev==NULL){    // Case when the data is smaller than the head.
                node->next=head;
                head=node;
                return ;
            }
            
            prev->next=node;  // Case when we find a bigger node other than the head.
            node->next=curr;
            return ;
        }
        
        prev=curr;
        curr=curr->next;
    }

    prev->next=node;    // Case whem the data is bigger than the tail.
    return ;
}
int main(){
    int a;
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);

    traverse(head);
    sortedInsertion(head,35);
    traverse(head);

    return 0;
}