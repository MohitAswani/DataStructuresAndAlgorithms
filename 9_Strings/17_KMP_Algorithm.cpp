#include <bits/stdc++.h>
#define ll long long
#define rep(i, t) for (ll i = 0; i < t; i++)
using namespace std;
void fillLPS(string str, vector<ll> &lps)
{
    int len=0,n=str.length(),i=1;
    lps.push_back(0);
    while(i<n)
    {
        if(str[len]==str[i])
        {
            len++;
            lps.push_back(len);
            i++;
        }
        else 
        {
            if(len==0)
            {
                lps.push_back(len);
                i++;
            }
            else
            {
                len=lps[len-1];
            }
        }
    }
}
// Time complexity : O(N)

void KMP(string text,string patt)
{
    int n=text.length();
    int m=patt.length();

    vector <ll> lps;
    fillLPS(patt,lps);
    int i=0,j=0;
    while(i<n)
    {
        if(text[i]==patt[j])
        {
            i++;j++;
        }

        if(j==m)
        {
            cout<<i-j<<endl;
            j=lps[j-1];
        }
        else if(i<n&&text[i]!=patt[j])
        {
            if(j==0)
            {
                i++;
            }
            else 
            {
                j=lps[j-1];
            }
        }
    }

    /*
    Time complexity analysis : in every itteration we are either moving ahead in the head or sliding the patter ahead.

    So we are doing N work for traversing the text and N for sliding the pattern so the overall time complexity is O(N)
    */
}
int main()
{
    KMP("abcabcabc","abc");
    return 0;
}