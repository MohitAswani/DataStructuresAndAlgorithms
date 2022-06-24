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
 * @brief Function used to find the nodes in the path from root to the given node.
 * 
 * Time complexity : Theta(n)
 * Auxillary space : O(1)
 * 
 * @param root 
 * @param node 
 * @param path_arr 
 * @return true 
 * @return false 
 */
bool path_array(Node *root,ll node,vector <Node *> &path_arr)
{
    if(root==NULL)
        return false;

    path_arr.push_back(root);

    if(root->key==node)
        return true;

    if(path_array(root->left,node,path_arr)||path_array(root->right,node,path_arr))
    {
        return true;
    }

    path_arr.pop_back();

    return false;
}
/**
 * @brief Lowest common ancestor of two nodes will be the lowest node which is an ancestor of both the given nodes.
 * 
 * Also lowest common ancestor can be used to find the distance between two nodes by finding the distance of the two nodes from the LCA.
 * 
 * In the naive solution we build the path arrays ( array containing all the elements from root to the given node) for both nodes and find the last common node's value.
 * 
 * Time complexity : O(n) (Theta(n)+Theta(n)+O(n))
 * Auxillary space : O(n) (for the two path arrays)
 * 
 * @param root 
 * @return Node* 
 */
Node* LowestCommonAncestorNaive(Node *root,ll n1,ll n2)
{
    vector <Node *> p_arr1;  // theta(n) to find this array
    vector <Node *> p_arr2;  // theta(n) to find this array

    if(path_array(root,n1,p_arr1)==false||path_array(root,n2,p_arr2)==false)
    {
        return NULL;
    }

    Node *lca=NULL;

    for(ll i=0;i<p_arr1.size()&&i<p_arr2.size();i++)  // O(n)
    {
        if(p_arr1[i]==p_arr2[i])
        {
            lca=p_arr1[i];
        }
    }

    return lca;
    
}
int main(){
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);

    cout<<LowestCommonAncestorNaive(root,20,50)->key<<endl;
    return 0;
}