/*
Proper prefix of "abc":
"","a","ab" (cannot be "abc" since its 'proper')

Suffix of "abc":
"","c","bc","abc"

Proper prefix of "abcd":
"","a","ab","abc" (cannot be "abc" since its 'proper')

Suffix of "abcd":
"","d","cd","bcd","abcd"

Now we need to find the LPS(longest prefix suffix array) for string:

Eg:

str="ababc"

lps[]={0,0,1,2,0}

str="abacabad"

lps={0,0,1,0,1,2,3,0}

str="abbabb"

lps={0,0,0,1,2,3}
*/

#include <bits/stdc++.h>
#define ll long long
#define rep(i, t) for (ll i = 0; i < t; i++)
using namespace std;
int longPropPreSuff(string str)
{
    for (int len = str.length() - 1; len > 0; len--)
    {
        bool flg = 1;
        for (int i = 0; i < len; i++)
        {
            if (str[i] != str[str.length() - len + i])
            {
                flg = 0;
                break;
            }
        }
        if(flg==1)
        {
            return len;
        }
    }
    return 0;
}
//To understand this approach look at KMP algo 1 video at 5:00
void fillLPS(string str, vector<ll> &lps)
{
    for(int i=0;i<str.length();i++)
    {
        lps.push_back(longPropPreSuff(str.substr(0,i+1)));
    }
}
// Time complexity : O(N^3)
int main()
{
    string str="abbabb";
    vector <ll> lps;
    fillLPS(str,lps);
    for(int i=0;i<lps.size();i++)
    {
        cout<<lps[i]<<" ";
    }
    cout<<endl;
    return 0;
}