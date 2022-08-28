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
        if ((i - 1) / 2 <= size)
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

    ll extractMin()
    {
        if (size == 0)
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return arr[0];
        }

        swap(arr[0], arr[size - 1]);
        size--;
        heapify(0);
        return arr[size];
    }

    void decreaseKey(int i, int x)
    {
        arr[i] = x;

        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void deleteKey(int i)
    {
        swap(arr[i], arr[size - 1]);
        size--;

        heapify(i);
    }

    /**
     * @brief To convert the given array into a heap we call heapify function for all the nodes from the innermost right node which is the parent of the last left on the right.
     *
     * To find the innermost right node we do floor(((size-1)-1)/2) which is the parent of the last node.
     *
     * Time complexity : O(n) ( This function looks like a O(nlogn) function but if we do some maths we can see that its is an O(n) function. Also max number of nodes at height h is ceil(n/2^(h+1)) )
     * Auxillary space : O(h)
     *
     */
    void buildHeap()
    {
        for (int i = (size - 2) / 2; i >= 0; i--)
        {
            heapify(i);
        }
    }
};
int main()
{
    MinHeap mh = MinHeap(15);

    mh.arr[0] = 10;
    mh.arr[1] = 5;
    mh.arr[2] = 20;
    mh.arr[3] = 2;
    mh.arr[4] = 4;
    mh.arr[5] = 8;

    mh.size = 6;

    mh.print();

    mh.buildHeap();

    mh.print();

    return 0;
}