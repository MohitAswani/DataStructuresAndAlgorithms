#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for(int i=(n-2)/2;i>=0;i--)
    {
        maxHeapify(arr,n,i);
    }
}

/**
 * @brief The idea of heap sort is based on the idea of selection sort in which we find the max in the array and swap it with the last element and keep on repeating this process.
 *
 * Step 1: Build the heap ( max-heap for increasing order and min-heap for decreasing order).
 * 
 * Step 2: Repeatedly swap root with last node, reduce heap size by one and heapify. And we keep on doing this until the second last element.
 * 
 * Heap sort can be seen as an improvement of selection sort by using the heap DS.
 * 
 * Time complexity : O(nlogn) ( For all cases )
 * 
 * nlogn is the best time complexity any algorithm can provide including merge (nlogn in worst case) and quick sort (nlogn on average) .
 * 
 * If we compare heap sort with quick and merge sort constants in heap sort are higher and hence in practise it takes more time than quick and merge sort.
 * 
 * Heap sort is used in hybrid sorting algo's like intro sort. Intro sort using quick sort , but when the recursion depth of quick sort goes beyond nlogn it switches to heap sort.
 * 
 * Intro sort is used in STL library sort implementation.
 * 
 * @param arr
 * @param n
 */
void heapSort(int arr[], int n)
{
    buildHeap(arr,n);
    for(int i=(n-1);i>=1;i--)  // O(n)
    {
        swap(arr[i],arr[0]);
        maxHeapify(arr,i,0);  // O(logn)
    }
}

int main()
{
    int arr[]={10,4,5,7,19,11,20};
    int size=sizeof(arr)/sizeof(int);

    heapSort(arr,size);

    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}