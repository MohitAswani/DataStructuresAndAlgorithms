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
    int height;

    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

// Function to get the height (Imp coz of NULL nodes)
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Rotation
    y->left = T2;
    x->right = y;

    // Updating heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    // Updating heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return y;
}

/**
 * @brief Perform the normal BST insertion.
 * The current node must be one of the ancestors of the newly inserted node. Update the height of the current node.
 * Get the balance factor (left subtree height – right subtree height) of the current node.
 * If balance factor is greater than 1, then the current node is unbalanced and we are either in Left Left case or left Right case. To check whether it is left left case or not, compare the newly inserted key with the key in left subtree root.
 * If balance factor is less than -1, then the current node is unbalanced and we are either in Right Right case or Right-Left case. To check whether it is Right Right case or not, compare the newly inserted key with the key in right subtree root.
 *
 * Time complexity : O(logn)
 * Auxillary space : O(logn)
 *
 * @param root
 * @param x
 * @return Node*
 */
Node *insert(Node *root, int x)
{
    if (root == NULL)
    {
        Node *newNode = new Node(x);
        return newNode;
    }
    else if (root->key > x)
    {
        root->left = insert(root->left, x);
    }
    else if (root->key < x)
    {
        root->right = insert(root->right, x);
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    // Left left case
    if (balance > 1 && x < root->left->key)
    {
        return rightRotate(root);
    }

    // Right right case
    if (balance < -1 && x > root->right->key)
    {
        return leftRotate(root);
    }

    // Left right case
    if (balance > 1 && x > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right left case
    if (balance < -1 && x < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
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

/**
 * @brief
 *
 * Perform the normal BST deletion.
 * The current node must be one of the ancestors of the deleted node. Update the height of the current node.
 * Get the balance factor (left subtree height – right subtree height) of the current node.
 * If balance factor is greater than 1, then the current node is unbalanced and we are either in Left Left case or Left Right case. To check whether it is Left Left case or Left Right case, get the balance factor of left subtree. If balance factor of the left subtree is greater than or equal to 0, then it is Left Left case, else Left Right case.
 * If balance factor is less than -1, then the current node is unbalanced and we are either in Right Right case or Right Left case. To check whether it is Right Right case or Right Left case, get the balance factor of right subtree. If the balance factor of the right subtree is smaller than or equal to 0, then it is Right Right case, else Right Left case.
 *
 * Time complexity : O(logn)
 * Auxillary space : O(logn)
 *
 * @param root
 * @param key
 * @return Node*
 */
Node *deleteNode(Node *root, ll key)
{

    // STEP 1 : PERFORM STANDARD BST DELETE
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
            root->right = deleteNode(root->right, succ->key);
        }
    }
    else if (root->key > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        root->right = deleteNode(root->right, key);
    }

    // If the tree has only one node then return
    if (root == NULL)
        return root;

    // Step 2: Update the height
    root->height = max(height(root->left), height(root->right)) + 1;

    // Step 3: Getting the balance
    int balance = getBalance(root);

    // If the node is unbalanced we have 4 cases

    // Left left
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Right right
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Left right
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right left
    if (balance < -1 && getBalance(root->right) < 0)
    {
        root->right = leftRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    /* Constructing tree given in
    the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    root = deleteNode(root, 10);

    cout << "\nPreorder traversal after"
         << " deletion of 10 \n";
    preOrder(root);

    return 0;
}