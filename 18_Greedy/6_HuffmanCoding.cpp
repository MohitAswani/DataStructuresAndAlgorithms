#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief
 *
 * Huffman coding is a popular loseless compression technique.
 *
 * And in huffman coding every character is encoded with variable length strings.
 *
 * Variable length in huffman coding requires the following conditions :
 *
 * 1) Greedy idea : The most frequent character has smallest code.
 *
 * 2) Prefix requirement for decompression : No code should be prefix of any other.
 *
 *
 * HUFFMAN ALGORITHM :
 *
 * The idea to implement this algorithm is by using a binary tree and this binary tree is called a huffman tree.
 *
 * Every input character is a leaf.
 *
 * Every left child edge is labelled as 0 and right edge as 1.
 *
 * Every root to leaf path represents huffman code of the leaf.
 *
 * And we can traverse the binary tree and print the codes.
 *
 * Also the characters with highest frequency will be present in the top of the binary tree and hence their codes can be accessed very quickly.
 *
 * This binary tree follows all the properties of huffman algorithm :
 *
 * 1) greedy : most freq char has shortest code
 *
 * 2) variable leaf coding
 *
 * 3) Prefix free : since all the nodes are in the left side hence they won't have the same prefix.
 *
 * All the nodes which do not contain character so the internal nodes will store $ symbol.
 *
 *
 * BUILDING THE TREE :
 *
 * 1) Create leaf nodes and build a min heap h of all the leaf nodes initially.
 *
 * 2) While h.size() > 1 :
 *
 *   a) left = h.extractMin()
 *   b) right = h.extractMin()
 *   c) Create a new tree node :
 *          *) with value = $
 *          *) freq = left.freq + right.freq
 *          *) left and right children are left and right
 *   d) Insert the new node into h.
 *
 * 3) The root of the tree is the only node left in the heap.
 *
 * WATCH THE VIDEO 'Huffman Algorithms' FOR MORE DETAILS.
 *
 * PRINT CODES :
 *
 * void printCodes(root,str="")
 * {
 *   if(root==NULL)
 *   return;
 *   if(root.ch != '$')
 *     cout<<root.ch<<" : "<<str<<endl;
 *     return ;
 *   printCodes(root.left,str+"0");
 *   printCodes(root.right,str+"1");
 * }
 *
 */

class Node
{
public:
    ll freq;
    char ch;
    Node *left, *right;
    Node(ll f, char c, Node *l = NULL, Node *r = NULL)
    {
        freq = f;
        ch = c;
        left = l;
        right = r;
    }
};

struct compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

/**
 * @brief Create a Huff graph using the above logic.
 * 
 * Time complexity : O(nlogn)
 * Auxillary space : O(n)
 * 
 * @param arr 
 * @param freq 
 * @return Node* 
 */
Node *createHuff(vector<char> &arr, vector<ll> &freq)
{
    int n = arr.size();
    priority_queue<Node *, vector<Node *>, compare> h;

    for (int i = 0; i < n; i++)            // O(nlogn)
        h.push(new Node(freq[i], arr[i]));

    while (h.size() > 1)                  // O(nlogn)
    {
        Node *l = h.top();
        h.pop();
        Node *r = h.top();
        h.pop();

        Node *node = new Node(l->freq + r->freq, '$', l, r);
        h.push(node);
    }

    return h.top();
}

/**
 * @brief 
 * 
 * Time complexity : O(n)
 * Auxillary space : O(n)
 * 
 * @param root 
 * @param str 
 */
void printCodes(Node *root, string str = "")
{
    if (root->ch != '$')
    {
        cout << root->ch << " " << str << endl;
        return;
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
int main()
{
    vector<char> arr = {'a', 'd', 'e', 'f'};
    vector<ll> freq = {30, 40, 80, 60};
    Node *h = createHuff(arr, freq);
    printCodes(h, "");
    return 0;
}