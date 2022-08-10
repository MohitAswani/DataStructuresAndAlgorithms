#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief This solution is similar to LIS problem with minor changes.
 * 
 * @param nums 
 * @return int 
 */
int MIS(vector<ll> &nums)
{
    ll n = nums.size();

    vector<ll> mis(n, 0);

    mis[0] = nums[0];

    for (int i = 0; i < n; i++)
    {
        mis[i] = nums[i];
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                mis[i] = max(mis[i], mis[j] + nums[i]);
            }
        }
    }

    return *max_element(mis.begin(), mis.end());
}
int main()
{
    vector<ll> nums = {3, 4, 2, 8, 10, 5, 1};
    cout << MIS(nums) << endl;
    return 0;
}