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
 * @brief We use level order traversal and finding the maximum width from all levels.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(h)
 * 
 * @param root 
 * @return int 
 */
int MaximumWidth(Node *root)
{
    if (root == NULL)
        return 0;

    queue<Node *> q;
    q.push(root);

    int maxWidth = -1;

    while (!q.empty())
    {
        int count = q.size();
        maxWidth = max(maxWidth, count);

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

    return maxWidth;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    cout<<MaximumWidth(root)<<endl;

    return 0;
}