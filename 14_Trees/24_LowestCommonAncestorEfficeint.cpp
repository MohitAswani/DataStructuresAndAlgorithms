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
 * @brief To find the lowest common ancestor in one traversal of the tree we do normal recursive traversal and for every node we follow the following cases: 
 * 
 * 1) If the curr node is n1 or n2 then we are return that node.
 * 2) If one of the sub trees contains n1 and other subtree contains n2 then we return the current node.
 * 3) If one of its sub tree contains both nodes then we return that subtree.
 * 4) If none of its sub trees contains any of n1 and n2 then we return null.
 * 
 * Time complexity : O(n) (tree traversal only once)
 * Auxillary space : O(h) (recursive call stack due to tree traversal)
 * 
 * @param root 
 * @param n1 
 * @param n2 
 * @return Node* 
 */
Node *LowestCommonAncestor(Node *root,ll n1,ll n2)
{
    if(root==NULL)
    return NULL;

    if(root->key==n1||root->key==n2)  // Current node is equal to one or two of the given nodes.
    {
        return root;
    }

    Node *lca1=LowestCommonAncestor(root->left,n1,n2);
    Node *lca2=LowestCommonAncestor(root->right,n1,n2);

    if(lca1!=NULL&&lca2!=NULL)  // one subtree contains one node other contains another
    {
        return root;
    }
 
    if(lca1!=NULL)              // lca1 contains one both nodes
    {
        return lca1;
    }
    else if(lca2!=NULL)         // lca2 contains one both nodes
    {
        return lca2;
    }

    return NULL;                // none of the subtree contains any node.
}
int main(){
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);

    cout<<LowestCommonAncestor(root,20,50)->key<<endl;
    return 0;
}