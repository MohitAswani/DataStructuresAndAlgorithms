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
 * @brief In this function we need to find the sum of all the nodes which lie in a vertical lie or nodes which have the same horizontal distance from the root.
 * 
 * We just simply traverse the tree and store the elements in a map.
 * 
 * Time complexity : O(nlog(hd)+hd) ( Operations in map takes log(hd) time becuase there are hd elements in the map and we perform insert for n nodes hence n*log(hd) also we traverse the map which takes hd time).
 * 
 * Auxillary space : O(logn+hd)
 * 
 * @param root 
 * @param sums 
 * @param dist 
 */
void verticalSum(Node *root, map<ll, ll> &sums, int dist = 0)
{
    if (root == NULL)
        return;

    sums[dist] = root->key;

    verticalSum(root->left, sums, dist - 1);
    verticalSum(root->right, sums, dist + 1);
}
int main()
{
    Node *root = new Node(25);

    Insert(root,15);
    Insert(root,35);
    Insert(root,20);
    Insert(root,45);
    Insert(root,24);
    Insert(root,10);

    map <ll,ll> sums;

    verticalSum(root,sums);

    for(auto elem:sums)
    {
        cout<<elem.first<<" "<<elem.second<<endl;
    }
    return 0;
}