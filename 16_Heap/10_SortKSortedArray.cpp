#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief In this problem we will be given a k-sorted array which means that an element of index i will be present between the indices i-k and i+k in the sorted array.
 *
 * Naive : sort the array.
 *
 * Efficient : add first k elements to heap and retrieve min at each traversal and add the next element to the queue and then retrieve the remaining elements.
 *
 * Time complexity : O(k+ nlogk+klogk)= O((n+k)logk)
 * Auxillary space : O(k)
 *
 * @param arr
 * @param n
 * @param k
 */
void sortKSorted(int arr[], int n, int k)
{
    // Creating a min-heap
    // Adding first k+1 elements to the min-heap
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + k + 1); // O(k)
    int index = 0;

    // Adding elements after first k+1 elements one by one and retrieving the minimum of them.
    for (int i = k + 1; i < n; i++)
    {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]); // O(logk)
    }

    // Retrieving the remaining elements
    while (!pq.empty())
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}
int main()
{
    int arr[] = {10, 9, 7, 8, 4, 70, 50, 60};
    int size = sizeof(arr) / sizeof(int);

    sortKSorted(arr, size, 4);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}