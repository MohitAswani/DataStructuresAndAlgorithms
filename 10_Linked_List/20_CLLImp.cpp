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
int main(){
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=head;  // next of the last node points to the head.

    // This way of creating a circular link list is not correct because we must make sure that after any operation on the linked list the last node points to the head.

    return 0;
}