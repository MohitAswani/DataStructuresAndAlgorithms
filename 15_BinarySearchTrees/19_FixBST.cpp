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
Node *getSuccessor(Node *curr)
{
    curr = curr->right;

    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}
Node *DeleteNode(Node *root, ll key)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->key == key)
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = getSuccessor(root);
            root->key = succ->key;
            root->right = DeleteNode(root->right, succ->key);
        }
    }
    else if (root->key > key)
    {
        root->left = DeleteNode(root->left, key);
    }
    else
    {
        root->right = DeleteNode(root->right, key);
    }

    return root;
}
/**
 * @brief In this function we are given a BST with two-nodes swapped, we need to fix the BST by swapping those two nodes.
 *
 * To fix the BST we can look at the inorder traversal of the BST. And we try to find the two nodes voilating the sorted order. And then we swap these two nodes.
 *
 * Also there are two cases in this approach 1) the two swapped nodes are adjacent 2) the two swapped nodes are not adjacent.
 *
 * So find the nodes we have two pointers first and second which are set which curr_node->val < prev_node->val. First will be set to prev_node and second will always be set as curr_node.
 *
 * Time complexity : O(n)
 * Auxillary space : O(h)
 *
 * @param root
 * @return Node*
 */
void fixBST(Node *root, Node *&prev, Node *&first, Node *&second)
{
    if (root == NULL)
        return;

    fixBST(root->left, prev, first, second);

    // Main logic for checking the order.
    if (prev != NULL && root->key < prev->key)
    {
        if (first == NULL) // first is always set as prev
        {
            first = prev;
        }
        second = root; // second is always set as curr.
    }

    prev = root;

    fixBST(root->left, prev, first, second);
}
Node *FixBST(Node *root)
{
    Node *prev = NULL, *first = NULL, *second = NULL;
    fixBST(root, prev, first, second);
}
int main()
{
    Node *root = new Node(20);

    return 0;
}