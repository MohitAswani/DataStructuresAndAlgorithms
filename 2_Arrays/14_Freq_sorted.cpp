#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief Here we need to find the frequency of all the elements in a sorted array. So we basically mainter a prev and a freq where we store that freq of prev and if a new element occurs we modify the prev.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param arr 
 */
void op(vector<ll> &arr)
{
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
    vector<ll> arr{10, 20, 20, 30, 30, 30,40};
    op(arr);
    return 0;
}