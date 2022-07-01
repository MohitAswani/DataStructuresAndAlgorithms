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
/**
 * @brief In this problem we need to find the amount of time it will require to burn the binary tree if we start burning from a given leaf.
 *
 * Basically this question can be seen as find the farthest node from the given leaf.
 *
 * We assume that we are always given a leaf node.
 * 
 * In this function we do the following two things :
 * 
 * 1) We find the height of the tree and return the height.
 * 2) We find if the child subtrees of the node contain the requirred leaf node. If it is in the left-subtree we  take the dist from that node and increment it by one and find the maximum value of dist from that node + height of right subtree. And we do the same if its in the right subtree.
 * 
 * This will give us the required answer.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(h)
 *  
 * @param root
 * @param leaf
 * @param dist
 * @return ll
 */
ll res = 0;
ll BurnBinaryTree(Node *root, ll leaf, ll &dist)
{
    if (root == NULL)
        return 0;
    
    if(root->key==leaf)
    {
        dist=0;
        return 1;
    }

    ll ldist = -1, rdist = -1; // distance from the given leaf node

    ll lh = BurnBinaryTree(root->left, leaf, ldist);  // height of left subtree
    ll rh = BurnBinaryTree(root->right, leaf, rdist);  // height of right subtree

    if (ldist != -1)         // if the left subtree contains the required leaf node
    {
        dist = ldist + 1;    // increment the distance 
        res = max(res, dist + rh);  // find the maximum of distance and height of the other subtree
    }
    else if (rdist != -1)   // if the left subtree contains the required leaf node
    {
        dist = rdist + 1;
        res = max(res, dist + lh);
    }

    return max(lh, rh) + 1;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    ll dist=-1;
    BurnBinaryTree(root,40,dist);
    cout<<res<<endl;

    return 0;
}