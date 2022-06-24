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
 * @brief We just find the max of root and max of left subtree and max of right subtree.
 *
 * Time complexity : O(n)
 * Auxillary space : O(h)
 * 
 * Can also be solved using level order traversal. But then the time complexity is O(n) and auxillary space is O(w).
 * 
 * So for a skewed tree (with more height and less width) iterative solution is better and for a perfect/balanced tree (with almost all the node) recursive is better.
 *
 * @param root
 * @return int
 */
int maxi(Node *root)
{
    if (root == NULL)
        return INT_MIN;

    return max(root->key, max(maxi(root->left), maxi(root->right)));
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

    cout << maxi(root) << endl;
    return 0;
}