#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
class MinHeap
{
    int *arr;
    int size;
    int capacity;

public:
    MinHeap(int c)
    {
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    int left(int i)
    {
        if ((2 * i + 1) < size)
        {
            return 2 * i + 1;
        }

        return -1;
    }

    int right(int i)
    {
        if ((2 * i + 2) < size)
        {
            return 2 * i + 2;
        }

        return -1;
    }

    int parent(int i)
    {
        if ((i - 1) / 2 < size)
        {
            return (i - 1) / 2;
        }

        return -1;
    }

    void print()
    {
        for (ll i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    /**
     * @brief To insert an item to the min-heap we first add it to the end of the array and then we check whether the insert value is less than its parent if yes then we swap it with its parent.
     * We keep doing this until parent < child or we reach root.
     *
     * Time complexity : O(log(size))
     * Auxillary space : O(1)
     *
     * @param elem
     * @return true
     * @return false
     */
    bool insert(int elem)
    {
        if (size == capacity)
            return false;

        arr[size] = elem;
        size++;

        for (ll i = size - 1; i != 0 && arr[parent(i)] > arr[i];)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }

        return true;
    }
};
int main()
{
    MinHeap mh = MinHeap(15);

    mh.insert(10);
    mh.insert(20);
    mh.insert(15);
    mh.insert(40);
    mh.insert(50);
    mh.insert(100);
    mh.insert(25);
    mh.insert(45);

    mh.print();

    mh.insert(12);

    mh.print();

    return 0;
}