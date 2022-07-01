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
 * @brief In this question we are given the inorder and preorder traversal and we need to find the tree from it.
 *
 * Also to contruct a binary tree we need a inorder traversal so we can construct the tree using inorder and preorder or inorder and postorder.
 *
 * To solve this problem we use the preorder to find the root of the current tree/subtree which is the pre[0].
 *
 * Then we find the index of pre[0] in in array and all the elements from start upto pre[0] represent the left subtree and all the elements from pre[0]+1 to end represents the right subtree.
 *
 * And then we call the function recursively.
 *
 * Time complexity : O(N^2) (preorder traversal with linear search) (we can use hashing to make it O(N))
 * Auxillary space : O(h)   (since preorder traversal)
 *
 *
 * @param in
 * @param pre
 * @return Node*
 */
Node *TreeFromTraversalHelper(vector<ll> in, vector<ll> pre, ll is, ll ie, ll ps, ll pe)
{
    if (is > ie || ps > pe)
    {
        return NULL;
    }

    Node *node = new Node(pre[ps]);

    ll index = -1;

    for (int i = is; i <= ie; i++)
    {
        if (in[i] == node->key)
        {
            index = i;
            break;
        }
    }

    node->left = TreeFromTraversalHelper(in, pre, is, index - 1, ps + 1, ps + (index - is));
    node->right = TreeFromTraversalHelper(in, pre, index + 1, ie, ps + (index - is) + 1, pe);

    return node;
}
Node *TreeFromTraversal(vector<ll> in, vector<ll> pre)
{
    return TreeFromTraversalHelper(in, pre, 0, in.size() - 1, 0, pre.size() - 1);
}
int main()
{
    vector<ll> in = {20, 10, 40, 30, 50};
    vector<ll> pre = {10, 20, 30, 40, 50};

    Node *root = TreeFromTraversal(in, pre);
    return 0;
}