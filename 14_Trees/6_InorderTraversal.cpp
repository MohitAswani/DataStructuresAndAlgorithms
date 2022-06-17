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
 * @brief For the inorder traversal of a tree we are making recursive call for left child , printing the root and then making a recursive call for the right child.
 * 
 * Time complexity : O(n) (Since every node takes constant amount of time)
 * Auxillary space : O(height) (At max the number of nodes in recursive call stack will be equal to the height of the tree )
 * 
 * @param root 
 */
void inorder(Node *root)
{
    // Base condition
    if(root==NULL)
    return ;

    // Recursive condition
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    inorder(root);
    return 0;
}