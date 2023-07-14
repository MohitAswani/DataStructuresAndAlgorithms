#include <bits/stdc++.h>
#define ll long long
#define rep(i, t) for (ll i = 0; i < t; i++)
using namespace std;

/**
 * @brief In this problem we need to find the leftmost element which is repeating in the whole string.
 *
 * We simply store the first occurance of every element and if that element occurs again we find the minimum of its index.
 *
 * Time complexity : O(n+char)
 * Space complexity : O(char)
 *
 * @param str
 * @return int
 */
int func(string str)
{
    vector<ll> count(256, -1); // Also taking into account the uppercase elements
    ll ans = INT_MAX;
    // In this algorithm we keep track of index of first occurence of every element.
    for (int i = 0; i < str.length(); i++)
    {
        if (count[str[i]] == -1) // if the element occurs once
        {
            count[str[i]] = i;
        }
        else // if the element occurs again
        {
            ans = min(ans, count[str[i]]);
        }
    }

    return (ans == INT_MAX) ? -1 : ans;
}
int main()
{
    string str = "geeksforgeeks";
    // For example in the above string 'g' is the leftmost repeating element
    cout << func(str) << endl;
    return 0;
}