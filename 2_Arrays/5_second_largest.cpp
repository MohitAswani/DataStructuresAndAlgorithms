#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief Here we maintain two elements max and second max. If a new maximum is discovered the old max becomes smax and new max becomes max. 
 * Another case is when a element is smaller than max but larger than smax or the smax is -1 (initial case).
 * 
 * Time complexity : O(n)
 * Space complexity : O(1)
 * 
 * @param arr 
 * @param size 
 * @return int 
 */
int op(ll arr[], int size)
{
    ll max = size - 1;
    ll smax = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[max])  // when a new maximum element is encountered
        {
            smax = max;
            max = i;
        }
        else if (arr[i] < arr[max])   
        {
            if (smax == -1 || arr[smax] < arr[i])  // when a new second maximum element is encountered
            {
                smax = i;
            }
        }
    }
    return smax;
}
int main()
{
    ll arr[] = {1, 2, 3, 4, 5, 8, 7,100,99};
    int size = sizeof(arr) / sizeof(arr[0]);
    int pos = op(arr, size) + 1;
    cout << pos << endl;
    return 0;
}