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
 * @brief To print a new line after every level we make the use of NULL pointer. After we traverse every level we push NULL into the queue.
 *
 * So for root we push NULL after pushing root.
 *
 * When we encounter a NULL in the queue it means that we have completely travesed the current level and hence we print a new line and push another NULL into the queue.
 *
 * So we use NULL as a next level marker.
 *
 * Time complexity : Theta(n+h) (becuase every node is pushed and poped out of the queue once and there will h NULL becuase there are h levels)
 * Auxillary space : O(width)/O(n) (width almost n/2)
 *
 * @param root
 */
void LevelOrderLine(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    // We stop at size one because at the end we will have a NULL pointer in the queue.
    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            cout << endl;
            q.push(NULL);
        }
        else
        {
            cout << curr->key << " ";

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }
    }

    cout << endl;
}
/**
 * @brief In this solution we have two loop outer loop makes sure that queue is not empty and gives us the size of the current level.
 * 
 * Inner loops print only the current level.
 * 
 * Time complexity : O(n) 
 * Auxillary space : O(width)/O(n) 
 *
 * @param root 
 */
void LevelOrderLineTwo(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;

    q.push(root);

    while (!q.empty())                
    {
        int count = q.size();

        for (int i = 0; i < count; i++)   // Loop printing only one level at a time
        {
            Node *curr = q.front();
            q.pop();

            cout << curr->key << " ";

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }

        cout<<endl;
    }
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(15);
    root->right = new Node(20);
    root->left->left = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->left->left = new Node(60);
    root->right->left->right = new Node(70);

    LevelOrderLine(root);
    return 0;
}