#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief Doubly linked contains a reference to its previous as well as next node.
 */
class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};
int main(){
    int a;
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->prev=head;
    head->next->next=new Node(30);
    head->next->next->prev=head->next;

    return 0;
}