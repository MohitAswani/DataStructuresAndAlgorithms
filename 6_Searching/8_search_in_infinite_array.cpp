#include <bits/stdc++.h>
using namespace std;
int binary_search(int arr[], int x, int l, int r)
{
    if (l > r)
    {
        return -1;
    }
    int mid = (l + r) / 2;
    if (arr[mid] < x)
    {
        return binary_search(arr, x, mid + 1, r);
    }
    else if (arr[mid] > x)
    {
        return binary_search(arr, x, l, mid - 1);
    }
    else
    {
        return mid;
    }
}
/**
 * @brief To search in an infinite array we first find the index of a number where arr[r]>=x and to search we keep on mutliplying the r by 2 until we satisfy the condition. Then we perform the binary search from (r/2+1,r).
 *
 * This algorithm is commonly known as unbounded binary search
 *
 * Time complexity : O(log n)
 * Auxillary space : O(log n) due to the binary search
   (In the above time complexities n is the position where we can find number)
 *
 * @param arr
 * @param size
 * @param x
 * @return int
 */
int search_in_infinite(int arr[], int size, int x)
{
    if (arr[0] == x)
        return 0;

    int r = 1;
    while (arr[r] < x)
        r = 2 * r;

    if (arr[r] == x)
        return r;

    return binary_search(arr, x, r / 2 + 1, r - 1); 
}
int main()
{
    int arr[] = {2, 4, 6, 7, 9, 10, 11, 14, 16, 18, 19, 20, 30, 40, 45, 46, 49, 51, 53, 55, 58, 60};
    int x = 2;
    int size = sizeof(arr) / sizeof(int);
    cout << search_in_infinite(arr, size, x) << endl;
    return 0;
}