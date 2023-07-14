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

/**
 * @brief If find the position of the pattern in a string we use the KMP algorithm.
 * 
 * So the only difference between the naive and the KMP algorithm is the fact that instead starting every match from the first position we start it from the lps because those are the strings which we know will match.
 * 
 * Time complexity : O(N)
 * Auxillary space : O(M) (M is pattern size)
 * 
 * Time complexity analysis : in every itteration we are either moving ahead in the head or sliding the patter ahead.
 * 
 * So we are doing N work for traversing the text and N for sliding the pattern so the overall time complexity is O(N)
 * 
 * @param text 
 * @param patt 
 */
void KMP(string text,string patt)
{
    int n=text.length();
    int m=patt.length();

    vector <ll> lps;
    fillLPS(patt,lps);  // Time complexity : O(N)
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
}
int main()
{
    KMP("abcabcabc","abc");
    return 0;
}