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
 * @brief We simply use a stack and keep on pushing its child to it. And we push the right item first and then the left item as it is a LIFO data structure.
 * 
 * Time complexity : O(n)      (Every element is pushed and poped once)
 * Auxillary space : O(n)      (Because we are pushing right and left node together)
 * 
 * @param root 
 */
void Preorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;

    s.push(root);

    while (s.empty() == false)
    {
        Node *curr = s.top();
        s.pop();
        cout << curr->key << " ";

        if (curr->right != NULL)  // We push right first since its a stack and LIFO.
            s.push(curr->right);

        if (curr->left != NULL)
            s.push(curr->left);
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