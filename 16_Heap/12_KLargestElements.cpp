#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief We need to find the k largest elements in a array.
 *
 * Naive : Sort the array.
 *
 * Efficeint : Insert all the elements in a priority queue and get the top k elements.
 *
 * Time complexity : O(n+klogn)
 *
 * Most efficeint : Insert k elements in a min heap and compare the top element with every element from k+1 elements.
 *
 * If smaller then ignore else remove the top and add the larger element.
 *
 * Print the contents of the heap.
 *
 * Time complexity : O(k+(n-k)logk) (Generally k<n)
 *
 * @param arr
 * @param n
 * @param k
 */
void kLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + k); // O(k)

    for (int i = k + 1; i < n; i++)
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
int main()
{
    int arr[] = {5, 15, 10, 20, 8, 25, 18};
    int n = sizeof(arr) / sizeof(int);

    kLargest(arr, n, 3);
    return 0;
}