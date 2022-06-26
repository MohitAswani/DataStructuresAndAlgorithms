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
 * @brief In the space optimized solution we print the curr element and push its right child into stack and then just move to the left.
 * 
 * So we only use the stack for storing the right elements. And once we are done with the left elements we deal with the right elements.
 * 
 * Also we don't push the root in the stack.
 *
 * Time complexity : O(n)      (Every element is pushed and poped once)
 * Auxillary space : O(h)      (Because we are pushing right node only)
 *
 * @param root
 */
void Preorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;

    Node *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            cout << curr->key << " ";

            if (curr->right != NULL)
            {
                s.push(curr->right);
            }

            curr = curr->left;
        }

        if (s.empty() == false)
        {
            curr = s.top();
            s.pop();
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    Preorder(root);
    return 0;
}