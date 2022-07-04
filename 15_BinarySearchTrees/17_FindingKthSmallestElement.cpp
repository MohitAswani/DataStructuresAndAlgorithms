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
    ll lcount;
    Node(int k)
    {
        lcount = 0;
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
        root->lcount++;
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
 * Naive: To store all the elements in a set and itterate the set K time to find the answer.
 *
 * Time complexity : O(k)
 * Auxillary space : O(n)
 *
 * Efficeint:  To find the kthSmallestElement using a BST we make the use of count of elements on the left of current node.
 *
 * So if lcount+1 if equal to k then that means that current element is the answer.
 *
 * If lcount+1>k then that means our element is on left side.
 *
 * If lcount+1<k then that means our element is on right side. And then we substract lcount+1 from k and find for the (lcount+1-k)th element in the right subtree.
 *
 * Time complexity : O(h)
 * Auxillary space : O(h)
 *
 * @param root
 * @param k
 * @return ll
 */
ll kthSmallest(Node *root, ll k)
{
    if (root == NULL)
        return NULL;

    if ((root->lcount + 1) == k)
    {
        return root->key;
    }
    else if ((root->lcount + 1) > k)
    {
        return kthSmallest(root->left, k);
    }
    else if ((root->lcount + 1) < k)
    {
        return kthSmallest(root->right, k - (root->lcount + 1));
    }
}
int main()
{
    Node *root = new Node(50);

    Insert(root, 20);
    Insert(root, 10);
    Insert(root, 40);
    Insert(root, 4);
    Insert(root, 100);
    Insert(root, 70);
    Insert(root, 120);
    Insert(root, 60);
    Insert(root, 80);

    kthSmallest(root, 3);
    return 0;
}