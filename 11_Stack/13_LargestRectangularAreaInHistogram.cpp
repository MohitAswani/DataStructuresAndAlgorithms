#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief We need to find the largest rectangular area which can be formed in a histogram. So the area which can be formed between two bars in histogram is equal to the distance between the bars multiplied by the min length bar between the two bars.
 *
 * For exampple : {6,2,5,4,1,5,6} that area between 6 and 4 is 2*(4).
 *
 * So the largest area can be found out by considering every element as smallest element and then find the smaller elements next to it. The area between smaller two bars will be the consider element * distance between two bars.
 * 
 * Steps :  * Initialize res=0;
            * Find previous smaller element for every element.
            * Find next smaller element for every element.
            * Do following for every element arr[i]
                * curr=arr[i]
                * curr+ = (i-prev_small-1)*arr[i]
                * curr+ = (next_small[i]-i-1)*arr[i]
                * res = max(res,curr)
            * return res 
 * 
 * Time complexity : O(n) (Three array traversals)
 * Auxillary space : O(n) (2 extra arrays and 1 extra stack)
 * 
 * @param arr
 */
void largestAreaInHistogram(vector<ll> &arr)
{
    vector<ll> prev_small;
    vector<ll> next_small;
    stack<int> s;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        int ans = s.empty() ? -1 : s.top();
        prev_small.push_back(ans);
        s.push(i);
    }

    while(!s.empty())
    {
        s.pop();
    }

    s.push(arr.size()-1);
    next_small.push_back(arr.size()-1);

    for (int i = arr.size() - 2; i >= 0; i--)
    {

        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }

        next_small.push_back(s.empty() ? arr.size() : s.top());
        s.push(i);
    }

    reverse(next_small.begin(), next_small.end());

    ll res=0;

    for(int i=0;i<arr.size();i++)
    {
        ll curr=arr[i];
        curr+=(i-prev_small[i]-1)*arr[i];
        curr+=(next_small[i]-i-1)*arr[i];
        res=max(res,curr);
    }

    cout<<res<<endl;
}
int main()
{
    vector <ll> v={6,2,5,4,1,5,6};
    largestAreaInHistogram(v);
    return 0;
}