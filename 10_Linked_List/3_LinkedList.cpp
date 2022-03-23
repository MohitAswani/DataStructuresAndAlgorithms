#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief 
 * 
 * The below DS contains a reference to its own type such DS's are called self-referencing data structures.
 * 
 * We can use struct (all variables public) or use class (all variables private) and declare all variables as public.
 * 
 */
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
    int a;
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    return 0;
}