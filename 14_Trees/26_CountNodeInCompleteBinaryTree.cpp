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
 * @brief A complete binary tree is a tree in which all the levels are complete except the last level and the last level contains nodes from left to right.
 * 
 * Naive approach : is to count the number of nodes using the recursive method by traversing the whole tree. Time complexity : Theta(n) Auxillary space : O(h).
 * 
 * Efficeint solution : In this solution we use the fact that our tree is a complete binary tree.
 * So to check whether the tree is a complete binary tree or not we find the height of the left most node and the right of the right most node and compare them.
 * If their height is equal then we find the number of nodes using the formula 2^h-1.
 * Else we represent the process of checking for complete tree for its left and right subtree.
 * 
 * Time complexity : 
 * 
 * Best case : Perfect binary tree and the total work done will be theta(logn)
 * 
 * Other cases : in the other cases either the left subtree will be best case or the right subtree.
 * 
 * We can assume that the subtree which is not the best case has all but one node in the last level hence the upper bounded time complexity equation becomes T(n)<T(2n/3)+theta(h).
 * 
 * So the total work done = log(n)+log(2n/3)+log(4n/9)....1.
 * 
 * So the height of this is log3/2(n) and we can upper bound the work done to be logn
 * 
 * Time complexity : O(logn*logn)
 * 
 * @param root 
 * @return ll 
 */
ll CountNodesCompleteBinaryTree(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }

    Node* left_node=root;
    ll left_height=0;

    while(left_node!=NULL)           // O(logn)
    {
        left_height++;
        left_node=left_node->left;
    }

    Node* right_node=root;
    ll right_height=0;

    while(right_node!=NULL)         // O(logn)
    {
        right_height++;
        right_node=right_node->right;
    }

    if(left_height==right_height)
    {
        return static_cast<ll>(pow(2,left_height)-1);
    }
    
    return 1+CountNodesCompleteBinaryTree(root->left)+CountNodesCompleteBinaryTree(root->right);
}
int main(){
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    // root->right->left=new Node(60);
    // root->right->right=new Node(70);

    cout<<CountNodesCompleteBinaryTree(root)<<endl;
    return 0;
}