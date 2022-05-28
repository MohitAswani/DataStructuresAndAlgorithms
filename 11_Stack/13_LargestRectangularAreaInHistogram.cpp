#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief We need to find the largest rectangular area which can be formed in a histogram. So the area which can be formed between two bars in histogram is equal to the distance between the bars multiplied by the min length bar between the two bars.
 *
 * For exampple : {6,2,5,4,1,5,6} that area between 6 and 4 is 2*(4).
 *
 * So the largest area can be found out by considering every element as smallest element and then find the smaller element next to it. The area between smaller two bars will be the consider element * distance between two bars.
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

    stack<int> s1;
    s1.push(arr.size()-1);
    next_small.push_back(arr.size()-1);

    for (int i = arr.size() - 2; i >= 0; i--)
    {

        while (!s1.empty() && arr[s1.top()] >= arr[i])
        {
            s1.pop();
        }

        next_small.push_back(s1.empty() ? arr.size() : s1.top());
        s1.push(i);
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