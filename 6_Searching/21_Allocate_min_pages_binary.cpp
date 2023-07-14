#include <bits/stdc++.h>
using namespace std;

/**
 * @brief In this solution we perform binary search for all the possible max sum values from max value to total sum.
 * 
 * If the solution is feasible we decrease the possible max value and if not possible we increase the same.
 * 
 * Time complexity : O(logn) (where n is the difference between max value and total sum)
 * Auxillary space : O(1)
 * 
 * @param arr 
 * @param size 
 * @param k 
 * @return int 
 */
int minPages(int arr[], int size, int k)
{
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        maxi = max(maxi, arr[i]);
    }
    int l = maxi, r = sum, ans = 0; //the solution will always lie in the range (max,sum)
    while (l <= r)
    {
        int mid = (l + r) / 2; //now we do binary search to find the more accurate solution
        int grps = 1;
        int grp_sum = 0;
        for (int i = 0; i < size; i++)
        {
            grp_sum += arr[i];
            if (grp_sum > mid)
            {
                grps++;
                grp_sum = arr[i];
            }
        }
        if (grps > k) //if not feasible we go to the right
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1; //if feasible we go to left
            ans = mid;
        }
    }
    return ans;

}
int main()
{
    int a[] = {5, 10, 20};
    int size = sizeof(a) / sizeof(int);
    cout << minPages(a, size, 2) << endl;
    return 0;
}