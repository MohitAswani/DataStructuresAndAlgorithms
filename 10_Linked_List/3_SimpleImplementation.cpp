#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;  // data structures which contain a reference to the another data of the same type are called self referential data struct.
    node(int val){
        data=val;
        next=NULL;
    }
};
class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
int main(){
    // with struct
    node *head1 = new node(10);
    head1->next=new node(20);
    head1->next->next=new node(30);

    // with class
    Node *head2=new Node(10);
    head2->next=new Node(20);
    head2->next->next=new Node(30);
    
    return 0;
}