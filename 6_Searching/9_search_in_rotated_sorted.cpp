#include <bits/stdc++.h>
using namespace std;
/**
 * @brief In a rotated array one part of the array will be sorted and the other part not be.
 * 
 * So we first check if the required element is present in the middle.
 * 
 * Then we check if the left part is sorted or the right part. Then we search for our element using the range of the sorted part. If the requirred element is in the sorted part we search for it else we move to the other part.
 * 
 * And the non-sorted part will also contain a sorted part and a unsorted part.
 * 
 * We keep on doing this until we find the element or l becomes greater than r.
 *
 * Time complexity : O(logn)
 * Auxillary space : O(1)
 *
 * @param arr
 * @param x
 * @param n
 * @return int
 */
int searching(int arr[], int x, int n)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == x) // if x is the mid element
            return mid;

        if (arr[l] < arr[mid]) // if the left part is sorted
        {
            if (arr[l] <= x && arr[mid] > x) // if x is in this range of sorted part
            {
                r = mid - 1; // we search this part
            }
            else
            {
                l = mid + 1; // else we search the right half.
            }
        }
        else // if the right part is sorted
        {
            if (arr[mid] < x && arr[r] >= x) // if x is the range of sorted part
            {
                l = mid + 1; // we search this part
            }
            else
            {
                r = mid - 1; // else we search the left half.
            }
        }
    }
    return -1;
}
int main()
{
    int arr[] = {100, 500, 10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(int);
    int x = 50;
    cout << searching(arr, x, size) << endl;
    return 0;
} //