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
 * @brief For level order / breadth first traversal we can have the following two approaches :
 *
 * 1) Find the height of the tree and use the node at distance k function to find all the nodes from 0 to h. (Time complexity : O(n*h))
 *
 * 2) Use queue to perform BFS traversal.
 *
 * Time complexity of the below function : Theta(n) (Coz every node is enqueued and dequeued only once)
 * Auxillary space of the below function : O(n)     ( Size of the biggest queue or width of binary tree)(In a perfectly balanced n/2 node in the last/biggest level)
 * 
 * @param root
 */
void LevelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        cout << curr->key << " ";

        if (curr->left != NULL)
            q.push(curr->left);

        if (curr->right != NULL)
            q.push(curr->right);
    }

    cout << endl;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(15);
    root->right = new Node(20);
    root->left->left=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    root->right->left->left=new Node(60);
    root->right->left->right=new Node(70);

    LevelOrderTraversal(root);
    return 0;
}