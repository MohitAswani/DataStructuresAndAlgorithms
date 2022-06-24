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

int res=0;
/**
 * @brief Diameter of a tree will be the maximum value of 1+left_height+right_height.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(h)
 * 
 * @param root 
 * @return int 
 */
int DiameterHelper(Node *root)
{
    if(root==NULL)
    return 0;

    int lh=DiameterHelper(root->left);
    int rh=DiameterHelper(root->right);

    res=max(res,lh+rh+1);

    return 1+max(lh,rh);
}
int Diameter(Node *root)
{
    DiameterHelper(root);
    return res;
}
int main(){
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);

    cout<<Diameter(root)<<endl;
    return 0;
}