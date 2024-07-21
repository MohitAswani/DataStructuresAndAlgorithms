#include <bits/stdc++.h>
using namespace std;
int hoare_partition(int arr[], int l, int r)
{
    srand(time(nullptr));
    int p = rand() % (r - l + 1) + l; //generating random pivot to prevent worst case for sorted arrays.
    swap(arr[l], arr[p]);
    int pivot = arr[l];
    int i = l - 1, j = r + 1;
    while (1)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}
void qsort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = hoare_partition(arr, l, r);
        qsort(arr, l, p);     //we call for left half from l to p
        qsort(arr, p + 1, r); //we call for right halp from p+! to r
    }
}
/*
*We call for left half and right half differently for hoare's partition from lomuto's partition as
hoare's does not fix the pivot at its correct position rather it only creates partitions.

*Hoare's partition is very fast compared to lomuto but it is also not stable.

*Only the naive partitioning algo is stable.
*/
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {8, 4, 7, 9, 3, 10, 5};
    int size = sizeof(arr) / sizeof(int);
    print(arr, size);
    qsort(arr, 0, size - 1);
    print(arr, size);
    return 0;
}