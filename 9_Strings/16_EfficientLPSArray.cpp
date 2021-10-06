#include <bits/stdc++.h>
#define ll long long
#define rep(i, t) for (ll i = 0; i < t; i++)
using namespace std;
//To understand this approach look at KMP algo 1 video at 9:00

// THIS ALGORITHM IS EXTREMELY HARD TO UNDERSTAND SO PLS LOOK AT THE VIDEO
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

// At max the array will be traverse multiple times for the recursive case the time complexity is O(N)
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