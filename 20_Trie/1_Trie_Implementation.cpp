#include <bits/stdc++.h>
#define alphabet_size 256
using namespace std;
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
/* 
    1) This is a simple implementation of trie only for lowercase english alphaphets and also we can implement for all character by using a array of size 
    256 or if we want to save space we can use unordered_maps.

    2) Every trienode has 2 parts one is the array which stores the character and reference to them.

    3) Other part is the isend flag which tells whether the present trienode stores the last character of a word in trie DS.
    
*/
bool search(TrieNode *root,string key)
{
    TrieNode *curr = root;
    for (size_t i = 0; i < key.length(); i++)
    {
        if(curr->child[key[i]]==NULL)
        return false;

        curr=curr->child[key[i]];
    }
    return curr->isEnd;
}
/*
To search a element in trie we go character by character and if the child array corresponding to the current element is null / has 
isEnd as true then the word is not present. But even if the child element never becomes null for any character still the 
child element for the last element of the word we are searching for must have isEnd as true.

Time complexity : O(word length)
(The time complexity is big of word length because in the worst case we only need to traverse the whole word)

Auxillary space : O(1)
*/
void insert(TrieNode *root,string word)
{
    TrieNode *curr = root;
    for (size_t i = 0; i < word.length(); i++)
    {
        if(curr->child[word[i]]==NULL)
        {
            curr->child[word[i]]=new TrieNode();
        }

        curr=curr->child[word[i]];
    }
    curr->isEnd=true;
}
/*
To insert a element into trie we insert each element of the word one by one and after inserting a particular element add the next 
node in the child node of the current character and if the current element is last we mark the isEnd as true. 

Time complexity : theta(word length)
(The time complexity is theta word length because the we only need to traverse the word and the creation of new node take constant time (256 traversals for every node))

Auxillary space : O(word length)
(The auxillary space requirred to create a trie is constant since we only need to allocat space for the trie nodes which store the character of word in the dictionary)
*/
bool isEmpty(TrieNode *root)
{
    for(size_t i=0;i<alphabet_size;i++)
    {
        if(root->child[i]!=NULL)
        return false;
    }
    return true;
}
TrieNode *delKey(TrieNode *root,string key,size_t i=0) //using pass by reference so that it does not create copy for every recursive call of the function
{
    if(root==NULL)
    return NULL;

    if(i==key.length())
    {
        root->isEnd=false;
        if(isEmpty(root))
        {
            delete root;
            root=NULL;
        }
        return root;
    }
    
    root->child[key[i]]=delKey(root->child[key[i]],key,i+1);

    if(isEmpty(root)&&root->isEnd==false)
    {
        delete root;
        root=NULL;
    }
    return root;
}
/*
The above code deals with all the case of delete in a trie and better understanding watch the video.

Time complexity : O(key length)
(The time complexity is this because the recursive function traverses the string and perform constant amount of work for each character).
*/
void lexicographicRank(TrieNode *root,string temp="")
{
    if(root==NULL)
    return ;

    if(root->isEnd==true)
    {
        cout<<temp<<endl;
    }

    for(int i=0;i<alphabet_size;i++)
    {
        if(root->child[i]!=NULL)
        {
            lexicographicRank(root->child[i],temp+static_cast<char>(i));
        }
    }
}
/*

Time complexity : theta(Total number of character in the words stored in the trie)
(This is because we are traversing the whole trie)

*/
void prefixSearch(TrieNode *root,string prefix)
{
    TrieNode *curr = root;
    for (size_t i = 0; i < prefix.length(); i++)
    {
        if(curr->child[prefix[i]]==NULL)
        return ;

        curr=curr->child[prefix[i]];
    }
    lexicographicRank(curr,prefix);
}
/*

Time complexity : theta(prefix length + length of the outputs)
(This is because after finding the words having that prefix we prefix all the other character associated with those trienodes)

*/
int main()
{
    TrieNode *root=new TrieNode(); //this is a difference between Trie and other DS. In other DS we usually has root as NULL but not for Trie .
    
    insert(root,"bat");
    insert(root,"bad");
    insert(root,"cat");
    insert(root,"cut");

    // cout<<boolalpha;
    // cout<<search(root,"Mohit")<<endl;
    // cout<<search(root,"Moh")<<endl;
    // cout<<search(root,"cat")<<endl;
    // cout<<search(root,"cad")<<endl;


    // cout<<search(root,"Mohit")<<endl;
    // delKey(root,"Mohit");
    // cout<<search(root,"Mohit")<<endl;
    // cout<<noboolalpha;

    // lexicographicRank(root);

    prefixSearch(root,"cu");
    return 0;
}