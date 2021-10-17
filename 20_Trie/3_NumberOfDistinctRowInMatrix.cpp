#include <bits/stdc++.h>
#define alphabet_size 2
using namespace std;
const int m=4,n=3;
bool matrix[m][n]={{1,0,0},
                   {1,1,1},
                   {1,0,0},
                   {1,1,1}};
struct TrieNode
{
    vector <TrieNode *> child;
    bool isEnd; //indicates if the field is the
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < alphabet_size; i++)
            child.push_back(NULL);
    }
};
bool insert(TrieNode *root,int row)
{
    TrieNode *curr=root;
    bool flg=false;
    for(int i=0;i<n;i++)
    {
        if(curr->child[matrix[row][i]]==NULL)
        {
            curr->child[matrix[row][i]]=new TrieNode();
            flg=true;
        }
        curr=curr->child[matrix[row][i]];
    }
    return flg;
}
int countDistinct()
{
    TrieNode *root=new TrieNode();
    int drow=0;
    for(int i=0;i<m;i++)
    {
        drow+=insert(root,i);
    }
    return drow;
}
/*
Time complexity : Theta(mn)

Auxillary space : O(mn)
(Since at most we will need space for m*n trienodes)
*/
int main(){
    cout<<countDistinct()<<endl;
}