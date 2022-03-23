#include <bits/stdc++.h>
using namespace std;
/**
 * @brief In this question we use the same approach as the previous question, the only difference being that we maitain a counter to count the number of pairs which satisfy the condition.
 * 
 * Time complexity : O(n^2)
 * Auxillary space : O(1)
 * 
 * @param arr 
 * @param size 
 * @param x 
 * @return int 
 */
int sum(int arr[], int size, int x)
{
    int cntr = 0;
    for (int i = 0; i < size; i++)
    {
        int xf = x - arr[i];
        int l = i + 1, r = size - 1;  // we start from i+1 so as to prevent repetitions.
        while (l < r)
        {
            int sum = arr[l] + arr[r];
            if (sum > xf)
                r--;
            else if (sum < xf)
                l++;
            else
            {
                printf("%d+%d+%d\n", arr[i], arr[l], arr[r]);
                cntr++;
                l++;
                r--;
            }
        }
    }
    return cntr;
}
int main()
{
    int arr[] = {2, 3, 4, 8, 9, 10, 20, 40};
    int size = sizeof(arr) / sizeof(int);
    int wsum = 32;
    cout << sum(arr, size, wsum) << endl;
    return 0;
}