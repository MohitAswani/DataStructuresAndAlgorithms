#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
class TrieNode
{
public:
    TrieNode *child[2];
    TrieNode()
    {
        child[0] = NULL;
        child[1] = NULL;
    }
};
bool insert(TrieNode *root,vector <int> &row)
{
    bool flg=0;
    TrieNode *curr=root;
    for(int i=0;i<row.size();i++)   // O(cols)
    {
        if(curr->child[row[i]]==NULL)
        {
            curr->child[row[i]]=new TrieNode();
            flg=1;
        }
        curr=curr->child[row[i]];
    }

    return flg;
}

/**
 * @brief Create a trie and search if an element already present.
 * 
 * Time complexity : O(n*m)
 * Auxillary space : O(n*m)
 * 
 * @param matrix 
 * @return int 
 */
int countDistinct(vector<vector<int>> &matrix)
{
    TrieNode *root=new TrieNode();
    int drows=0;

    for(int i=0;i<matrix.size();i++)  // O(rows)
    {
        if(insert(root,matrix[i]))
            drows++;
    }

    return drows;
}
int main()
{
    vector <vector<int>> matrix={{1,1,0},{0,0,1},{1,1,0},{1,1,1}};
    cout<<countDistinct(matrix)<<endl;
    return 0;
}