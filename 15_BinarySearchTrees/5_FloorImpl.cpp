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
 * @brief We simply perform BST search and if the key is less than the given key we make it as the floorNode and keep on searching in its right node.
 *
 * If the curr node is bigger than the given key we go to its left.
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
Node *FloorItt(Node *root, ll key)
{
    Node *floorNode = NULL;
    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->key == key)
        {
            return root;
        }
        else if (curr->key < key)
        {
            floorNode = curr;
            curr = curr->right;
        }
        else if (curr->key > key)
        {
            curr = curr->left;
        }
    }

    return floorNode;
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->right = new Node(80);

    Node *floorNode = FloorItt(root, 45);

    if (floorNode != NULL)
    {
        cout << floorNode->key << endl;
    }

    return 0;
}