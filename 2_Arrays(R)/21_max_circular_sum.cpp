#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief In this problem we will get maximum sums by normal subarrays in some cases and circular subarrays in some cases.
 * For normal subarrays we use kadane.
 * For circular sum, by using examples we see the pattern that the elements we leave are the ones which give the minimum sum in normal subarray. So we find the minimum sum using kadane and subtract it from the total sum of the array.
 * In max_sum < 0 condition we find if the whole array is made up of negative elements or not if yes then we just return the element with maximum value. This condition is necessary or else the code will give the wrong answer.Since in this case we will only return a single integer.
 *
 * Time complexity : O(n)
 * Space complexity : O(1)
 *
 * @param arr
 */
void op(vector<ll> &arr)
{
    // finding the maximum sum below
    ll n = arr.size();
    ll max_sum = arr.at(0), maxi = arr.at(0);
    for (ll i = 1; i < n; i++)
    {
        maxi = max(maxi + arr.at(i), arr.at(i));
        max_sum = max(max_sum, maxi);
    }

    // if all the elements are negative then we will only return the least negative number.
    if (max_sum < 0)
    {
        cout << max_sum << endl;
        return;
    }

    // finding the minimum sum below for the maximum circular sum
    ll min_sum = arr.at(0), mini = arr.at(0), sum = arr.at(0);
    for (ll i = 1; i < n; i++)
    {
        mini = min(mini + arr.at(i), arr.at(i));
        min_sum = min(min_sum, mini);
        sum += arr.at(i);
    }

    // finding the maximum out of normal maximum and circular maximum.
    max_sum = max(max_sum, sum - min_sum);
    cout << max_sum << endl;
}
int main()
{
    vector<ll> arr{-6, -1, -8};
    op(arr);
    return 0;
}