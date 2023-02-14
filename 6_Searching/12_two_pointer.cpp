#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Two pointer approach is another way of find if a pair with a given sum exists in a sorted array. So we first take two pointers one at 0 and one at n-1. We keep on moving these two pointers based on comparision of arr[l]+arr[r] with the given sum.
 * If arr[l]+arr[r]>x we make r--.
 * If arr[l]+arr[r]<x we make l++.
 *
 * Time complexity : O(n)
 * Auxillary space : O(1)
 *
 * For sorted pair : we use two pointer approach since that take O(n) time.
 * For unsorted pair : we use hashing since two pointer with sorting will require O(nlogn) time
 *
 * @param arr
 * @param size
 * @param x
 * @return int
 */
int sum(int arr[], int size, int x)
{
    int l = 0, r = size - 1;
    int cntr = 0;
    while (l < r)
    {
        int sum = arr[l] + arr[r];
        if (sum > x)
            r--;
        else if (sum < x)
            l++;
        else
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int arr[] = {2, 3, 4, 6, 6, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    int wsum = 12;
    cout << sum(arr, size, wsum) << endl;
    return 0;
}