#include <bits/stdc++.h>
using namespace std;
/**
 * @brief In this algorithm we assume a1 is the smaller array and a2 is the bigger array. 
 * 
 * And if this assumption is true then we basically divide the two arrays in two parts such that left part contains all the smaller elements and right half contains all the bigger elements.
 * 
 * We do binary search in the smaller array and try to find a index for which the above condition will be satisfied. 
 * 
 * If this condition is satisfied we find the median by :
 * 
 * 1) If sum of lengths is even : maximum of the maximum of the left part of the arrays.
 * 
 * 2) If sum of lengths is odd : average of maximum of the maximum of the left part of the arrays and minimum of the minimum of the right part of the arrays.
 * 
 * To understand watch the video.
 * 
 * Time complexity : O(n1)
 * Auxillary space : O(1)
 * 
 * @param arr1 
 * @param n1 
 * @param arr2 
 * @param n2 
 * @return double 
 */
double median(int arr1[], int n1, int arr2[], int n2)
{
    if (n1 < n2)
    {
        int begin1 = 0, end1 = n1;
        while (begin1 <= end1)
        {
            int i1 = (begin1 + end1) / 2;
            int i2 = (n1 + n2 + 1) / 2 - i1;
            //We use these ternary operators for corner cases which there is nothing on the left or right side.
            int min1 = (i1 == n1) ? INT_MAX : arr1[i1];
            int max1 = (i1 == 0) ? INT_MIN : arr1[i1 - 1];
            int min2 = (i2 == n2) ? INT_MAX : arr2[i2];
            int max2 = (i2 == 0) ? INT_MIN : arr2[i2 - 1];

            if (max1 <= min2 && max2 <= min1)
            {
                if ((n1 + n2) % 2)
                {
                    return static_cast<double>(max(max1, max2));
                }
                else
                {
                    return static_cast<double>((max(max1, max2) + min(min1, min2)) / 2.00);
                }
            }
            else if (max1 > min2)
                end1 = i1 - 1;
            else
                begin1 = i1 + 1;
        }
    }
    else
    {
        swap(n1, n2);
        swap(arr1, arr2);
        int begin1 = 0, end1 = n1;
        while (begin1 <= end1)
        {
            int i1 = (begin1 + end1) / 2;
            int i2 = (n1 + n2 + 1) / 2 - i1;
            int min1 = (i1 == n1) ? INT_MAX : arr1[i1];
            int max1 = (i1 == 0) ? INT_MIN : arr1[i1 - 1];
            int min2 = (i2 == n2) ? INT_MAX : arr2[i2];
            int max2 = (i2 == 0) ? INT_MIN : arr2[i2 - 1];

            if (max1 <= min2 && max2 <= min1)
            {
                if ((n1 + n2) % 2)
                {
                    return static_cast<double>(max(max1, max2));
                }
                else
                {
                    return static_cast<double>((max(max1, max2) + min(min1, min2)) / 2.00);
                }
            }
            else if (max1 > min2)
                end1 = i1 - 1;
            else
                begin1 = i1 + 1;
        }
        swap(n1, n2);
        swap(arr1, arr2);
    }
    return 0;
}
int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int size1 = sizeof(arr1) / sizeof(int);
    int arr2[] = {7, 15, 25, 30, 35, 55, 65, 75, 85};
    int size2 = sizeof(arr2) / sizeof(int);
    cout << median(arr1, size1, arr2, size2) << endl;
    return 0;
}