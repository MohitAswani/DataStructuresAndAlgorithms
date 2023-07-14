#include <bits/stdc++.h>
using namespace std;
/**
 * @brief
 * 
 * Peak element is any element which is bigger than its neighbouring elements.
 * 
 * If there is an independenet array then it will always have peak element.
 * 
 * To search for a peak element we perform binary search. We stop when we encounter this condition :
 (the current element is bigger than its left element or its the leftmost element) or (the current element is bigger than its right element or its the rightmost element).
 * 
 * For perform the binary search by comparing the mid element with left side and if its left element is bigger we move to the left else we move to the right.
 * 
 * If mid is not the peak and one of the two elements near it is bigger than mid then we can surely say that side contains an peak.
 *
 * 
 * time complexity : O(logn)
 * auxillary space : O(1)
 *
 * @param arr
 * @param size
 * @return int
 */
int peak_element(int arr[], int size)
{
    // 
    int l = 0, r = size - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == size - 1 || arr[mid + 1] <= arr[mid])) // we need one of two in both cases to be true.
            return arr[mid];

        if (mid > 0 && arr[mid - 1] >= arr[mid]) // if left side is bigger than left contains a peak
            r = mid - 1;
        else // else right contains a peak
            l = mid + 1;
    }
    return -1;
}
int main()
{
    int arr[] = {5, 1000, 30, 40, 50, 130, 150, 670};
    int size = sizeof(arr) / sizeof(int);
    cout << peak_element(arr, size);
    return 0;
}