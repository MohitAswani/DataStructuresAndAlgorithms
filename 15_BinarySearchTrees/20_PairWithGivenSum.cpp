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
 * @brief 
 * 
 * Method 1 : Store the inorder traversal in a array and then find the pair with sum using two pointer approach.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(n)
 * 
 * 
 * Method 2: Perform inorder traversal or any traversal and find if the map contains sum-root->key else insert root->key into the set.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(n)
 * 
 * @param root 
 * @param sum 
 * @param s 
 * @return true 
 * @return false 
 */
bool isPairSum(Node *root, int sum, unordered_set<ll> &s)
{
    if (root == NULL)
    {
        return false;
    }

    if (isPairSum(root->left, sum, s) == true)
        return true;

    if (s.find(sum - root->key) != s.end())
        return true;
    else
        s.insert(root->key);

    return isPairSum(root->right, sum, s);
}
int main()
{
    Node *root = new Node(10);

    Insert(root, 5);
    Insert(root, 20);
    Insert(root, 15);
    Insert(root, 40);

    unordered_set<ll> s;
    cout << isPairSum(root, 27, s) << endl;

    return 0;
}