#include <bits/stdc++.h>
#define ll long long
#define rep(i, t) for (ll i = 0; i < t; i++)
using namespace std;
//To understand this approach look at KMP algo 1 video at 9:00

// 
/**
 * @brief THIS ALGORITHM IS EXTREMELY HARD TO UNDERSTAND SO PLS LOOK AT THE VIDEO.
 * 
 * In the following solution we use the existing values of LPS to find the new LPS. 
 * 
 * We match the current character with the character next to last LPS.
 * 
 * If they are equal then we increase the LPS value.
 * 
 * Else we recursively try to find the previous LPS with which the i th character matches.
 * 
 * Time complexity : O(N) (At max the array will be traverse multiple times for the recursive case the time complexity is O(N))
 * 
 * @param str 
 * @param lps 
 */
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