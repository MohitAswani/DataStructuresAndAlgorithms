#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief To solve this problem efficient and using only O(n) extra space we do that following.
 *
 * We first try to find the previous small of every element. 
 * 
 * But while poping out the larger elements from the stack to find the previous small, we find the area of the rectangle with the element being poped as the smallest element in the rectangle. 
 * 
 * So the element next to it in the stack (if it exists) will be previous smaller element and the element for which we are currently checking is the next smaller element. So we find the area using the previous solutions logic.
 *
 * Also in the end we check the stack for all the elements which do not have a next smallest element.
 * 
 * Time complexity : O(n) (One traversal)
 * Auxillary space : O(n) (Uses one stack)
 * 
 * 
 * For better understanding watch the video : 'Largest rectangular area in a histogram'.
 *
 * @param arr
 */
void largestAreaInHistogramEfficient(vector<ll> &arr)
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
            ll curr = arr[tp] * (stk.empty() ? i : (i - stk.top() - 1));  // now s.top() is the previous small
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

    cout<<res<<endl;
}
int main()
{
    vector<ll> v = {6, 2, 5, 4, 1, 5, 6};
    largestAreaInHistogramEfficient(v);
    return 0;
}