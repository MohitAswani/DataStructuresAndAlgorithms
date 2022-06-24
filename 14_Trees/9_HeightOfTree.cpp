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
 * @brief We just traverse the left and right subtree and add 1 to the maximum of their heights.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(h) (h+1 to be exact)
 * 
 * @param root 
 * @return int 
 */
int height(Node *root)
{
    if(root==NULL)
    return 0;

    return max(height(root->left),height(root->right))+1;
}
int main(){
    // Height can be counted on the basic of nodes or on the basic of edges.
    // Here we count on the basic of nodes.

    // // Height 4
    // Node *root=new Node(30);
    // root->left=new Node(40);
    // root->left->left=new Node(70);
    // root->left->left->left=new Node(80);
    // root->right=new Node(60);

    // Height 3
    Node *root=new Node(10);
    root->left=new Node(8);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);

    cout<<height(root)<<endl;
    return 0;
}