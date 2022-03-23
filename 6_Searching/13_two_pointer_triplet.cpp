#include <bits/stdc++.h>
using namespace std;
bool isPair(int arr[], int start, int size, int x)
{
    int l = start, r = size - 1;
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
            cout << arr[l] << " " << arr[r] << " ";
            return 1;
        }
    }
    return 0;
}
/**
 * @brief To find the triplets with a given sum we find use the same approach as the two pointer problem to find the pair. But we use another for loop just for the third element and for the other two elements we use the isPair function.
 *
 * Time complexity : O(n^2)
 * Space complexity : O(1)
 *
 * The two pointer approach is the best approach to solve this problem for the following reason :
 * 1) Hashing will also require O(n^2) time complexity and it will also require O(n) auxillary space.
 * 2) Two pointer approach will require O(nlogn) for sorting the array, O(n^2) for the searching hence it will also require O(n^2) time complexity but it will only require O(1) auxillary space hence it is better than hashing.
 *
 * For sorted triplet finding: two pointer
 * For unsorted triplet finding: sorting then two pointer
 * 
 * @param arr
 * @param size
 * @param x
 * @return int
 */
int isTriplet(int arr[], int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        int xf = x - arr[i];
        int l = i + 1, r = size - 1;  // we start from i+1 so as to prevent repetitions
        if (isPair(arr, i + 1, size - 1, xf))
        {
            cout << arr[i] << endl;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int arr[] = {2, 4, 8, 9, 20, 40};
    int size = sizeof(arr) / sizeof(int);
    int wsum = 32;
    cout << isTriplet(arr, size, wsum) << endl;
    return 0;
}