#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * 
 * Conditions for this problem:
 * 1)All the elements are from 1 to max(arr)
 * 2) 1<=max(arr)<=n-1
 * 
 * So we need to find the single repeating element from the given set of elements.
 * 
 * We will be using the algorithm which is used to find the first element of a loop in linked list.
 * 
 * This problem can be solved in two phases : 
 * 1) In phase 1 we move one ptr one steps at a time and another two steps at a time. When we do this we will surely meet once inside the loop.
 * 2) In phase 2 we move a element outside and one remains inside. And when we move these two at the same phase then they surely meet at the first element of the loop
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param arr 
 * @param size 
 * @return int 
 */
int repeating_element(int arr[], int size)
{
    int slow = arr[0], fast = arr[0];

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    slow = arr[0];

    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int main()
{
    int arr[] = {4, 2, 1, 3, 2, 2};
    int size = sizeof(arr) / sizeof(int);
    cout << repeating_element(arr, size) << endl;
    return 0;
}