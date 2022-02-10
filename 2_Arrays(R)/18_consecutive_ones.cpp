#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief Here we just finding the maximum of frequency of one.
 * 
 * Time complexity : O(n)
 * Space complextiy : O(1)
 * 
 * @param arr 
 */
void op(vector<ll> &arr)
{
    ll size=arr.size();
    ll ones=0,maxo=0;
    for(ll i=0;i<size;i++)
    {
        if(arr.at(i)==1)
        {
            ones++;
            maxo=max(ones,maxo);
        }
        else
        {
            ones=0;
        }
    }
    cout<<maxo<<endl;
}
int main()
{
    vector<ll> arr{0,0,1,1,1,1,0,0,0,0,1,1,1};
    op(arr);
    return 0;
}