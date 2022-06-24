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

int maxLevel = 0;
/**
 * @brief In the recursive solution of this solution we have a variable level which denotes the current level and if its value is greater than the maxLevel then we encounter the level for the first time and hence the first node we encounter is the leftmost node.
 * 
 * We set the maxLevel to 0 initially as we want to print the root.
 * 
 * Time complexity : Theta(n)      // Preorder traversal
 * Auxillary space : Theta(h)
 * 
 * @param root 
 * @param level 
 */
void leftViewRec(Node *root, int level = 1)
{
    if (root == NULL)
        return;

    if (maxLevel < level)
    {
        cout << root->key << endl;
        maxLevel = level;
    }

    leftViewRec(root->left, level + 1);
    leftViewRec(root->right, level + 1);
}

/**
 * @brief In the following function we are doing level order traversal and printing the first node of every level.
 * 
 * Time complexity : O(n)      // Preorder traversal
 * Auxillary space : O(w)/O(n)
 * 
 * @param root 
 */
void leftViewItt(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        int count = q.size();

        // Printing the left most node of every level
        cout << q.front()->key << endl;

        for (int i = 0; i < count; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left != NULL)
                q.push(front->left);

            if (front->right != NULL)
                q.push(front->right);
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
    root->right->right = new Node(60);

    leftViewRec(root);
    leftViewItt(root);
    return 0;
}