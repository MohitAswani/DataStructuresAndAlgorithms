#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
class Node
{
    public:

    int key;
    Node *left;
    Node *right;

    Node(int k)
    {
        key=k;
        left=NULL;
        right=NULL;
    }
};
void Inorder(Node *root)
{
    stack <Node *> s;

    s.push(root);

    while(!s.empty())
    {
        while(s.top()->left!=NULL)
        {
            s.push(s.top()->left);
        }

        Node *curr=s.top();
        s.pop();
        cout<<curr->key<<" ";

        if(curr->right!=NULL)
        {
            s.push(curr->right);
        }
    }

    cout<<endl;
}
int main(){
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(60);
    root->right->right=new Node(70);

    Inorder(root);

    return 0;
}