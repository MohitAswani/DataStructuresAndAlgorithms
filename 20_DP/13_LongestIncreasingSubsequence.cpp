#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In the following solution we initialize the lis of the 0th index element as 1 and for the rest of the element we check for all the previous elements.
 * 
 * If the any of the previous element is smaller than the current element then we add one to it and find the maximum out of all these values.
 * 
 * Time complexity : O(n^2)
 * Auxillary space : O(n)
 * 
 * @param nums 
 * @return int 
 */
int LIS(vector<ll> &nums)
{
    ll n = nums.size();

    vector<ll> lis(n, 0);

    lis[0] = 1;

    for (int i = 0; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    return *max_element(lis.begin(), lis.end());
}
int main()
{
    vector<ll> nums = {3, 4, 2, 8, 10, 5, 1};
    cout << LIS(nums) << endl;
    return 0;
}