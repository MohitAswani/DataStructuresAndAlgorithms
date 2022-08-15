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
 * @brief Get the Successor object but only when the right child of node is non-empty.
 *
 * @param curr
 * @return Node*
 */
Node *getSuccessor(Node *curr)
{
    curr = curr->right;

    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}
/**
 * @brief Will delete the key element based on the three cases of delete.
 *
 * Time complexity : O(h)
 * Auxillary space : O(h)
 *
 * @param root
 * @param key
 * @return Node*
 */
Node *DeleteRecursive(Node *root, ll key)
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
            root->right = DeleteRecursive(root->right, succ->key);
        }
    }
    else if (root->key > key)
    {
        root->left = DeleteRecursive(root->left, key);
    }
    else
    {
        root->right = DeleteRecursive(root->right, key);
    }

    return root;
}
int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->right = new Node(80);

    root = DeleteRecursive(root, 15);

    return 0;
}