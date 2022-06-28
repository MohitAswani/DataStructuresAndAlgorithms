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
 * @brief Similar to the search algorithm but the only added step being the insertion of a leaf node.
 * 
 * Time complexity : O(h)  (For a skewed tree height can become n)
 * Auxillary space : O(h)
 * 
 * @param root 
 * @param x 
 * @return Node* 
 */
Node *InsertRecursive(Node *root, int x)
{
    if (root == NULL)
    {
        Node *newNode = new Node(x);
        return newNode;
    }
    else if (root->key > x)
    {
        root->left = InsertRecursive(root->left, x);
    }
    else if (root->key < x)
    {
        root->right = InsertRecursive(root->right, x);
    }

    return root;
}

/**
 * @brief Similar to the search algorithm but the only added step being the insertion of a leaf node.
 * 
 * Time complexity : O(h)  (For a skewed tree height can become n)
 * Auxillary space : O(1)
 * 
 * @param root 
 * @param x 
 * @return Node* 
 */
Node *InsertItterative(Node *root, int x)
{
    Node *newNode = new Node(x);
    Node *curr = root;

    if (curr == NULL)
    {
        return newNode;
    }

    while (curr != NULL)
    {
        if (curr->key == x)
        {
            delete newNode;
            break;
        }
        else if (curr->key > x)
        {
            if (curr->left == NULL)
            {
                curr->left = newNode;
                break;
            }
            curr = curr->left;
        }
        else
        {
            if (curr->right == NULL)
            {
                curr->right = newNode;
                break;
            }
            curr = curr->right;
        }
    }

    return root;
}
int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);

    root = InsertRecursive(root, 7);
    root = InsertItterative(root, 90);

    return 0;
}