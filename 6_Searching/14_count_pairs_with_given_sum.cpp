#include <bits/stdc++.h>
using namespace std;
/**
 * @brief In this question we use the same approach as the previous question, the only difference being that we maitain a counter to count the number of pairs which satisfy the condition.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
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
            cntr++;
            l++;
            r--;
        }
    }
    return cntr;
}
int main()
{
    int arr[] = {2, 3, 4, 6, 6, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    int wsum = 12;
    cout << sum(arr, size, wsum) << endl;
    return 0;
}