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
 * @brief If the element matches the key we return true else we compare it to the current key and move accordingly.
 * 
 * Time complexity : O(h)  (For a skewed tree height can become n)
 * Auxillary space : O(h)
 * 
 * @param root 
 * @param x 
 * @return true 
 * @return false 
 */
bool SearchRecursive(Node *root, int x)
{
    if (root == NULL)
        return false;

    if (root->key == x)
        return true;
    else if (root->key < x)
        return SearchRecursive(root->right, x);
    else
        return SearchRecursive(root->left, x);
}

/**
 * @brief If the element matches the key we return true else we compare it to the current key and move accordingly.
 * 
 * Time complexity : O(h)   (For a skewed tree height can become n)
 * Auxillary space : O(1)
 * 
 * @param root 
 * @param x 
 * @return true 
 * @return false 
 */
bool SearchItterative(Node *root,int x)
{
    Node *curr=root;

    while(curr!=NULL)
    {
        if(curr->key==x)
        {
            return true;
        }
        else if(curr->key>x)
        {
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
    }

    return false;
}
int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->right = new Node(80);

    cout<<SearchRecursive(root, 80)<<endl;
    cout<<SearchItterative(root, 80)<<endl;

    return 0;
}