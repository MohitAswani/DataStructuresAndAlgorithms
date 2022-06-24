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
 * @brief In the following method every node goes into 2 data-structures once and comes out once so total 4 operations
 *
 * Time complexity : O(n)
 * Auxillary space : O(w)
 *
 * @param root
 */
void SpiralTraversalBasic(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    bool reverse = false;

    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        vector<ll> levels;

        for (int i = 0; i < count; i++) // Loop printing only one level at a time
        {
            Node *curr = q.front();
            q.pop();

            levels.push_back(curr->key);

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }

        if (reverse)
        {
            for (auto it = levels.rbegin(); it != levels.rend(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
        else
        {
            for (auto it = levels.begin(); it != levels.end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }

        reverse = !reverse;
    }
}
/**
 * @brief So we need a more efficient solution such that every node is push and poped only once.
 * 
 * For that we use two stacks and push the elements into either one of them depending on the order we want to print it in.
 * 
 * To see how it works take an example and solve it.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(w)
 * 
 * @param root 
 */
void SpiralTraversalEfficeint(Node *root)
{
    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);

    while (!(s1.empty() && s2.empty()))
    {
        if (s1.empty())
        {
            while (!s2.empty())
            {
                Node *curr = s2.top();
                s2.pop();

                cout << curr->key << " ";

                // For the stack which handles element in reverse order(s2) we push right first and then left.

                if (curr->right != NULL)
                    s1.push(curr->right);

                if (curr->left != NULL)
                    s1.push(curr->left);
            }

            cout << endl;
        }
        else
        {
            while (!s1.empty())
            {
                Node *curr = s1.top();
                s1.pop();

                cout << curr->key << " ";

                if (curr->left != NULL)
                    s2.push(curr->left);

                if (curr->right != NULL)
                    s2.push(curr->right);
            }

            cout << endl;
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
    root->right->right = new Node(70);
    root->left->left->left = new Node(80);
    root->left->left->right = new Node(90);
    root->left->right->left = new Node(100);
    root->left->right->right = new Node(110);

    SpiralTraversalBasic(root);
    SpiralTraversalEfficeint(root);
    return 0;
}