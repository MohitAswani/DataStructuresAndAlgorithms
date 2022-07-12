#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
class MinHeap
{
public:
    int *arr;
    int size;
    int capacity;

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

    /**
     * @brief Given a binary heap and a index with possible violation, we need to fix the heap.
     *
     * We find the smallest out of i,left(i),right(i) and if smallest !=i then we swap smallest with i and perform heapify on smallest.
     *
     * Time complexity : O(h)  (h=log(n))
     * Auxillary space : O(h)
     */
    void heapify(int i)
    {
        int smallest = i;

        if (left(i) != -1 && arr[left(i)] < arr[smallest])
        {
            smallest = left(i);
        }

        if (right(i) != -1 && arr[right(i)] < arr[smallest])
        {
            smallest = right(i);
        }

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            return heapify(smallest);
        }
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

    mh.arr[0] = 120; // Adding error to the heap

    mh.print();

    mh.heapify(0);

    mh.print();

    return 0;
}