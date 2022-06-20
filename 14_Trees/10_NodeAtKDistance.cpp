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
/**
 * @brief We keep on decreasing k and print the nodes once k is equal to 0.
 * 
 * Time complexity : O(n)       ( Depends on k )
 * Auxillary space : O(h)       ( Depends on k )
 * 
 * @param root 
 * @param k 
 */
void NodesAtDistanceK(Node *root,int k)
{
    if(root==NULL)
    return ;

    if(k==0)
    {
        cout<<root->key<<" ";
    }
    else
    {
        NodesAtDistanceK(root->left,k-1);
        NodesAtDistanceK(root->right,k-1);
    }
}
int main(){
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->right=new Node(70);
    root->right->right->right=new Node(80);

    NodesAtDistanceK(root,2);

    return 0;
}