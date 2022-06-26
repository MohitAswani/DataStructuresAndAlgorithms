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
 * @brief In this solution we keep on pushing the left node till it becomes null then we print the left node first and then visit its right node.
 * 
 * Also we need the last visited item in the Last in first out order hence we use a stack.
 * 
 * Time complexity: O(n) (Pushes every node once and pops every node once)
 * Auxillary space: O(h)
 * @param root 
 */
void Inorder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL) // for the items on the left side.
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << curr->key << " "; // for printing the current node

        curr = curr->right; // for the items on the right side.
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    Inorder(root);

    return 0;
}