#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief Here we use the same approach as the last problem. The only difference being we sort the unsorted array.
 * 
 * Time complexity : O(nlogn) this is the best time complexity of sorting
 * Auxillary space : O(1)
 * 
 * @param arr 
 */
void op(vector<ll> &arr)
{
    sort(arr.begin(),arr.end());
    ll size = arr.size();
    ll prev = arr.at(0), freq = 1;
    for (ll i = 1; i < size; i++)
    {
        if (arr.at(i) == prev)
            freq++;
        else
        {
            cout << prev << " " << freq << endl;
            freq = 1;
            prev = arr.at(i);
        }
    }
    cout << prev << " " << freq << endl;
    return;
}
int main()
{
    vector<ll> arr{100,40,50,10, 20, 20, 30, 30, 30,40};
    op(arr);
    return 0;
}