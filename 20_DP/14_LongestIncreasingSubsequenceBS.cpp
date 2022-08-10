#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In the following implementation of LIS we use a tail vector which store the minimum possible tail value for the LIS of length (i+1).
 * 
 * So to use this vector we first insert the 1st element then we check if the last element is greater than the current element. If it is we push it to the vector else we find the lower bound and replace it with the current element.
 *
 * Time complexity : O(nlogn)
 * Auxillary space : O(n)
 *
 * @param nums
 * @return int
 */
int LIS(vector<ll> &nums)
{
    ll n = nums.size();

    vector<ll> tail;

    tail.push_back(nums[0]);

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > tail.back())
        {
            tail.push_back(nums[i]);
        }
        else
        {
            auto it = lower_bound(tail.begin(), tail.end(), nums[i]);
            *it = nums[i];
        }
    }

    return tail.size();
}
int main()
{
    vector<ll> nums = {3, 10, 20, 4, 6, 7};
    cout << LIS(nums) << endl;
    return 0;
}