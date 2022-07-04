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
 * @brief We perform level order traversal and keep on storing the nodes with a hd in map and in this way we get the last nodes for every horizontal distance and hence bottom view.
 *
 * Time complexity : O(n*log(hd)+n) (n for the level order traversal and log(hd) for insert into map and n for traversal).
 * Auxillary space : O(hd+logn)
 *
 * @param root
 */
void bottomView(Node *root)
{
    // Level order traversal

    // Queue with node and horizontal distance.
    queue<pair<Node *, int>> q;
    map<ll, Node *> mp;

    q.push({root, 0});

    while (!q.empty())
    {
        Node *curr = q.front().first;
        int hd = q.front().second;
        mp[hd] = curr;
        q.pop();

        if (curr->left != NULL)
        {
            q.push({curr->left, hd - 1});
        }

        if (curr->right != NULL)
        {
            q.push({curr->right, hd + 1});
        }
    }

    for (auto elem : mp)
    {
        cout << elem.second->key << " ";
    }

    cout << endl;
}
int main()
{
    Node *root = new Node(25);

    Insert(root, 15);
    Insert(root, 35);
    Insert(root, 20);
    Insert(root, 45);
    Insert(root, 24);
    Insert(root, 10);

    bottomView(root);

    return 0;
}