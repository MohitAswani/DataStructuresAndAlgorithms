#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief An element is called leader in an array if all the elements on the right of it are smaller than it.
 * To find this we simply traverse the array in reverse order and keep on printing the maximum elements.
 * The only problem with this solution is that it prints the element in reverse order but we can make a temp array and reverse it.
 *
 * Time complexity : O(n)
 * Auxillary space : O(1) in reverse order / O(n) in correct order.
 *
 * @param arr
 */
void op(vector<ll> &arr)
{
    int size = arr.size();
    int cur_ldr = INT_MIN;
    for (ll i = size - 1; i >= 0; i--)
    {
        if (arr.at(i) > cur_ldr)
        {
            cout << arr.at(i) << " ";
            cur_ldr = arr.at(i);
        }
    }
    cout << endl;
}
int main()
{
    vector<ll> arr{7, 10, 4, 3, 6, 5, 2};
    op(arr);
    // for(ll i=0;i<arr.size();i++)
    // {
    //     cout<<arr.at(i)<<" ";
    // }
    // cout<<endl;
    return 0;
}