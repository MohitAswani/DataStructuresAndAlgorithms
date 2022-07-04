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
Node *Insert(Node *root, int x)
{
    if (root == NULL)
    {
        Node *newNode = new Node(x);
        return newNode;
    }
    else if (root->key > x)
    {
        root->left = Insert(root->left, x);
    }
    else if (root->key < x)
    {
        root->right = Insert(root->right, x);
    }

    return root;
}
/**
 * @brief
 *
 * Naive : find max in left subtree and min right subtree and root should lie in between them.
 *
 * Time complexity : O(n^2)
 *
 * Efficeint : For every node we pass a range as input and check that the node lies in that range else return false.
 *
 * Time complexity : O(n)
 * Auxillary space : O(n)
 *
 * @param root
 * @param min
 * @param max
 * @return true
 * @return false
 */
bool checkForBST(Node *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }

    if (min < root->key && root->key < max)
    {
        return checkForBST(root->left, min, root->key) & checkForBST(root->right, root->key, max);
    }

    return false;
}

ll prevKey = INT_MIN;
/**
 * @brief  
 * Efficeint : Inorder traversal of a BST should be sorted.
 *
 * Time complexity : O(n)
 * Auxillary space : O(h)
 * 
 * @param root 
 * @return true 
 * @return false 
 */
bool checkForBSTInorder(Node *root)
{
    if (root == NULL)
        return true;

    if (checkForBSTInorder(root->left) == false)
        return false;

    if (root->key <= prevKey)
        return false;

    prevKey = root->key;

    return checkForBSTInorder(root->right);
}

int main()
{
    Node *root = new Node(20);

    Insert(root, 8);
    Insert(root, 30);
    root->right->left = new Node(18);
    Insert(root, 35);

    cout << checkForBST(root) << endl;

    return 0;
}