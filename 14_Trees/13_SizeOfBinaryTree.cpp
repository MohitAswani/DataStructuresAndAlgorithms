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
 * @brief We add the 1 to the size of left subtree and right subtree.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(h)
 * 
 * @param root 
 * @return int 
 */
int size(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + size(root->left) + size(root->right);
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(15);
    root->right = new Node(20);
    root->left->left = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->left->left = new Node(60);
    root->right->left->right = new Node(70);

    cout << size(root) << endl;
    return 0;
}