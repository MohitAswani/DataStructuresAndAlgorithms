#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief To find the k closest elements to number we make max-heap of pair of integers and store the abs diff as the first element and the element as the second element.
 * 
 * We initially store the first k elements.
 * 
 * After which we compare the difference of top of heap element with the difference of current element.
 * 
 * Time complexity : O((n)logk)
 * Auxillary space : O(k)
 * 
 * @param arr 
 * @param n 
 * @param x 
 * @param k 
 */
void kClosest(int arr[], int n, int x, int k)
{
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < k; i++)   // O(klogk)
    {
        pq.push({abs(arr[i]-x),arr[i]});
    }

    for (int i = k ; i < n; i++)   // O((n-k)logk)
    {
        if (pq.top().first > abs(arr[i]-x))
        {
            pq.pop();
            pq.push({abs(arr[i]-x),arr[i]});
        }
    }

    while (!pq.empty())        // O(klogk)
    {
        cout << pq.top().second << " ";
        pq.pop();
    }
}
int main()
{
    int arr[] = {20,40,5,100,150};
    int n = sizeof(arr) / sizeof(int);

    kClosest(arr, n, 100, 3);
    return 0;
}