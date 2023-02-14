#include <bits/stdc++.h>
#define ll long long
#define rep(i, t) for (ll i = 0; i < t; i++)
using namespace std;

/**
 * @brief In the following solution we simply traverse the array and keep on storing the sum at particular element and if a sum repeats that means that the previous sub array from the first time it repeated and the current element had the sum 0.
 * 
 * Also we keep on checking for sum==0 for the case when the sum of inital elements is zero.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(n)
 * 
 * @param v 
 * @return true 
 * @return false 
 */
bool subarrayWithGivenSum(vector<ll> v)
{
    unordered_set<ll> s;
    ll sum = 0;
    for (auto elem : v)
    {
        sum += elem;
        if (s.find(sum) != s.end())
        {
            return true;
        }
        if(sum==0)  //this condition is used to check for the condn's like {4,-1,-3,5}
        {
            return true;
        }
        s.insert(sum);
    }
    return false;
}
int main()
{
    vector<ll> vect{-1,4,-3,5,2};
    cout << subarrayWithGivenSum(vect) << endl;
    return 0;
}