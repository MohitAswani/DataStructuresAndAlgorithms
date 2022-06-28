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
 * @brief We simply perform BST search and if the key is greater than the given key we make it as the ceilNode and keep on searching in its left node to find a smaller value.
 *
 * If the curr node is less than the given key we go to its right.
 *
 * We keep on search till we reach NULL.
 *
 * Time complexity : O(h)
 * Auxillary space : O(1)
 *
 * @param root
 * @param key
 * @return Node*
 */
Node *CeilItt(Node *root, ll key)
{
    Node *ceilNode = NULL;
    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->key == key)
        {
            return root;
        }
        else if (curr->key > key)
        {
            ceilNode = curr;
            curr = curr->left;
        }
        else if (curr->key < key)
        {
            curr = curr->right;
        }
    }

    return ceilNode;
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->right = new Node(80);

    Node *ceilNode = CeilItt(root, 19);

    if (ceilNode != NULL)
    {
        cout << ceilNode->key << endl;
    }

    return 0;
}