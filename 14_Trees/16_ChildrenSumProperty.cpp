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
 * @brief For every node we check that its not null , its both child are not null and sum of its child if they exist is == root -> val.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(h)
 * 
 * @param root 
 * @return true 
 * @return false 
 */
bool ChildrenSum(Node *root)
{
    if(root==NULL)
    {
        return true;
    }

    if(root->left==NULL && root->right==NULL)
    {
        return true;
    }

    ll sum=0;

    if(root->left!=NULL)
    {
        sum+=root->left->key;
    }

    if(root->right!=NULL)
    {
        sum+=root->right->key;
    }

    return (sum==root->key)&&ChildrenSum(root->left)&&ChildrenSum(root->right);
}
int main(){
    Node *root=new Node(20);
    root->left=new Node(8);
    root->right=new Node(12);
    root->left->left=new Node(3);
    root->left->right=new Node(5);

    cout<<boolalpha;
    cout<<ChildrenSum(root)<<endl;
    cout<<noboolalpha;
    return 0;
}