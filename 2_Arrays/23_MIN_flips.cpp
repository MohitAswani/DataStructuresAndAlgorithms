#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief In this question we can flip consecutive elements to become the other elements. So we need to find the minimum number of flip requirred to make all the elements same.
 * We notice a pattern that the difference between no. of flips required for 1 or 0 is either 1 or 0.
 * And when the 1st and last element are the same then the difference between the number of flips required for 0 or 1 is one. 
 * And we need to flip the element which does not occur at the beginning.
 * If the difference between flips is 0 then we can flip any element. 
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param arr 
 */
void op(vector<ll> &arr)
{
    ll n = arr.size();
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])  // we only need to start counting when two consecutive elements are different.
        {
            // In both the cases 1) a[0]==a[n-1] & 2) a[0]!=a[n-1] we flip the element which is not a[0]
            if (arr[i] != arr[0])   
            {
                cout << "From " << i + 1;
            }
            else
            {
                cout<< " to "<< i<<endl;
            }
        }
    }
}
int main()
{
    vector<ll> arr{1,1,0,0,1,0,0,0,0,0,0,0,1,1,1};
    op(arr);
    return 0;
}