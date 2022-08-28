#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

// Making a basic trie for lowercase english characters.

// We can also make it for all the character by making an array of length 256. If we want to optimize the space we can also use unordered map.

// An empty trie is represent with a node with all its child as NULL which is different from a binary in which we represent an empty binary tree as NULL.
class TrieNode
{
public:
    TrieNode *child[26];

    // Indicates if this node is where a word is ending.
    bool isEnd;

    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

/**
 * @brief To insert a value in trie , we traverse the string and find if there is a child node for the current character if yes we go to that node else we insert a new node and go to that node.
 *
 * At the end we mark the isEnd of the last node as true.
 *
 * Time complexity : Theta(word length)
 * Auxillary space : O(k*word length)
 *
 * @param root
 * @param key
 */
void insert(TrieNode *root, string key)
{
    TrieNode *curr = root;

    for (int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';

        if (curr->child[index] == NULL)
        {
            curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
    }

    curr->isEnd = true;
}

/**
 * @brief To find a string in trie we keep on traversing the string and finding the respective childs for the character. If we dont find a child for the given character we return null else we keep on looking.
 *
 * Also if we find nodes for all the characters of the string we still check whether the last character is the end and return result accordingly.
 *
 * Time complexity : O(word length) (may take lesser time)
 * Auxillary space : O(1)
 *
 * @param root
 * @param key
 * @return true
 * @return false
 */
bool search(TrieNode *root, string key)
{
    TrieNode *curr = root;

    for (int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';

        if (curr->child[index] == NULL)
        {
            return false;
        }

        curr = curr->child[index];
    }

    return curr->isEnd;
}

bool isEmpty(TrieNode *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i] != NULL)
            return false;
    }

    return true;
}

/**
 * @brief To delete a key from the trie we we write the following conditions : 
 * 
 * 1) If current character is not the last of the key : recursively call delete key. And if after the recursive call the child of root are empty and current node is not the ending node we delete it.
 *  
 * 2) If current character is the last of the key : make the end zero and check if it has some child elements . If it doesnt we delete it else we dont.
 * 
 * Time complexity : O(word length)  (Every character takes constant time)
 * Auxillary space : O(word length)  ( Recursive call stack )
 * 
 * @param root 
 * @param key 
 * @param i 
 * @return TrieNode* 
 */
TrieNode *deleteKey(TrieNode *root, string key, int i = 0)
{
    if (root == NULL)
        return NULL;

    if (i == key.size())
    {
        root->isEnd = false;

        if (isEmpty(root))
        {
            delete root;
            return NULL;
        }

        return root;
    }

    int index = key[i] - 'a';

    root->child[index] = deleteKey(root, key, i + 1);

    if (isEmpty(root) && root->isEnd == false)
    {
        delete root;
        return NULL;
    }

    return root;
}
int main()
{
    TrieNode *root = new TrieNode();

    insert(root, "geek");
    insert(root, "geeks");
    insert(root, "bat");
    insert(root, "but");

    cout << search(root, "geek") << endl;

    root=deleteKey(root,"geek");

    cout << search(root, "geek") << endl;

    return 0;
}