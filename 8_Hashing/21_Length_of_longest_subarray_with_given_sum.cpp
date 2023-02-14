#include <bits/stdc++.h>
#define ll long long
#define rep(i, t) for (ll i = 0; i < t; i++)
using namespace std;

/**
 * @brief Same as the previous problem except that here we are storing the index of the first time the sum occured and finding the length of longest subarray using the same.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(n)
 * 
 * @param v 
 * @param given_sum 
 * @return int 
 */
int LengthOfLongestSubarrayWithGivenSum(vector<ll> v,int given_sum)
{
    unordered_map<ll,ll> s;
    ll sum=0;
    ll ans=0;
    for (ll i=0;i<v.size();i++)
    {
        sum += v[i];
        if(s.find(sum-given_sum)!=s.end())
        {
            ans=max(ans,s[sum-given_sum]+1);
        }
        else
        {
            s.insert({sum,i});
        }

        if(sum==given_sum)
        {
            ans=max(ans,i+1);
        }
    }
    return ans;
}
int main()
{
    vector<ll> vect{3,2,5,6};
    ll sum=10;
    cout << LengthOfLongestSubarrayWithGivenSum(vect,sum) << endl;
    return 0;
}