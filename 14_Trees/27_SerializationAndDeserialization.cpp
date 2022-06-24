#include <bits/stdc++.h>
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
        key = k;
        left = NULL;
        right = NULL;
    }
};

/*
 * Serialization : is to convert tree into a string or array such that we can do the vice-versa.
 * Deserialization : is to convert string or array into tree.
 * 
 * Applications :
 * 
 * Since a tree is just made up of pointers and we cannot send pointers accross a network hence we first serialize a tree and send it accross a network.
 * 
 * Implementation :
 * 
 * To implement serialization we can just use -1 for NULL and simply do one of the traversals.
 */

/**
 * @brief Performing simple preorder traversal and adding -1 for NULL.
 * 
 * Time complexity : Theta(n)
 * Auxillary space : O(h)
 * 
 * @param root 
 * @param arr 
 */
void serialize(Node *root,vector <ll> &arr)
{
    if(root==NULL)
    {
        arr.push_back(-1);
        return ;
    }

    arr.push_back(root->key);
    serialize(root->left,arr);
    serialize(root->right,arr);
}


ll ind=0;
/**
 * @brief Considering the current index element as root and simply traversing the array as it is a preorder traversal.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(h)
 * 
 * @param root 
 * @param arr 
 */
Node *deserialize(vector <ll> &arr)
{
    if(ind==arr.size())
    {
        return NULL;
    }

    ll val=arr[ind];
    ind++;

    if(val==-1)
        return NULL;
    
    Node *root=new Node(val);
    root->left=deserialize(arr);
    root->right=deserialize(arr);

    return root;
}


int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    vector <ll> arr;

    serialize(root,arr);

    Node *root1=deserialize(arr);

    return 0;
}