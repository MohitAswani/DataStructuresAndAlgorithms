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
 * @brief To find if a tree is balanced or not in O(n) time complexity we use the same function to return the height as well as check for balanced nature.
 *
 * We find the height of the left subtree, if it returns -1 then its not balanced.
 *
 * Then we find the height of the right subtree, if it returns -1 then its not balanced.
 *
 * Then we find the difference between the two heights and if it is greater than 1 than we return -1 else we return the height of the current node.
 *
 * Time complexity : O(n)
 * Auxillary space : O(h)
 *
 * @param root
 * @return int
 */
int BalancedTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = BalancedTree(root->left);

    // Checking if left subtree is balanced
    if (lh == -1)
        return -1;

    int rh = BalancedTree(root->right);

    // Checking if right subtree is balanced
    if (rh == -1)
        return -1;

    // Check if the root is balanced
    if (abs(lh - rh) > 1)
    {
        return -1;
    }

    // Returning the height if the tree is balanced
    return max(lh, rh) + 1;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    cout << BalancedTree(root) << endl;
    return 0;
}