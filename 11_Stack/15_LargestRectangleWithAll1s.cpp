#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief To find the solution to this problem in which we need to find the largest area with all 1s.
 * For example in |0 1 1 0| the largest area with all 1s is 6.
                  |1 1 1 1|
                  |1 1 1 1|
                  |1 1 0 0|
 *
 * To find the largest area we consider every row as base of the histogram and the number of 1s above a 1 as the height of the histogram and then we find the maximum area in the histogram.
 *
 * Time complexity : O(R X C).
 * Auxillary space : O(C)  // required by largestAreaInHistogramEfficient
 * 
 * @return int
 */
void largestRectangleWithAll1s(vector<vector<ll>> rect)
{
    ll n = rect.size(), m = rect[0].size();
    ll res = 0;

    res = max(res, largestAreaInHistogramEfficient(rect[0]));

    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (rect[i][j] == 1)
            {
                rect[i][j] += rect[i - 1][j];
            }
        }

        // Time complexity : O(C), Auxillary space : O(C)
        res = max(res, largestAreaInHistogramEfficient(rect[i]));  
    }

    cout << res << endl;
}
ll largestAreaInHistogramEfficient(vector<ll> &arr)
{
    ll n = arr.size();
    stack<ll> stk;

    ll res = 0;

    for (ll i = 0; i < n; i++)
    {
        while (!stk.empty() && arr[stk.top()] >= arr[i])
        {
            ll tp = stk.top();
            stk.pop();
            // considering tp as the smallest element in the rectangle.
            ll curr = arr[tp] * (stk.empty() ? i : (i - stk.top() - 1));
            res = max(res, curr);
        }
        stk.push(i);
    }

    while (!stk.empty())
    {
        ll tp = stk.top();
        stk.pop();
        ll curr = arr[tp] * (stk.empty() ? n : (n - stk.top() - 1));
        res = max(res, curr);
    }

    return res;
}
int main()
{
    int a;
    // cout<<fun(a)<<endl;
    return 0;
}