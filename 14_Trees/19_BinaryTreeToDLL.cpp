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

Node *previous = NULL;

/**
 * @brief In this function we traverse the node inorder and make the use of previous to store the previously processed node.
 * 
 * We also return the head which will be assigned a value only when the prev is NULL and after that we keep adding nodes such that prev->next=curr_node and curr_node->prev=prev.
 * 
 * And every recursive call returns the head. Which is assigned only when the previous is null so it is the first node to be visited.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(h)
 * 
 * @param root 
 * @return Node* 
 */
Node *BinaryTreeToDLL(Node *root)
{
    if (root == NULL)
    {
        return root;
    }

    Node *head = BinaryTreeToDLL(root->left);

    if (previous == NULL)  // for first now prev is NULL
    {
        head = root;
    }
    else
    {
        previous->right = root;
        root->left = previous;
    }

    previous = root;

    BinaryTreeToDLL(root->right);

    return head;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    BinaryTreeToDLL(root);

    return 0;
}