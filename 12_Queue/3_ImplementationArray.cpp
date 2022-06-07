#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief This is simple implementation of queue data structure using an array and time complexity of all the operations is O(1) except the dequeu operations which has a time complexity of O(n).
 * 
 */
class SimpleQueueUsingArray
{
    int *arr;
    int size, cap;
    SimpleQueueUsingArray(int cap)
    {
        this->cap = cap;
        this->size = 0;
        this->arr = new int[this->cap];
    }

    void enqueue(int x)
    {
        if (!isFull())
        {
            arr[this->size] = x;
            this->size++;
        }
        else
        {
            cout << "Array is full" << endl;
        }
    }

    void dequeue()
    {
        if (!isEmpty())
        {
            for (ll i = 1; i < this->size; i++)
            {
                arr[i - 1] = arr[i];
            }
            this->size--;
        }
        else
        {
            cout << "Array is empty" << endl;
        }
    }

    int getFront()
    {
        if (!isEmpty())
        {
            return 0;
        }
        cout << "Array is empty" << endl;
        return -1;
    }

    int getRear()
    {
        if (!isEmpty())
        {
            return this->size - 1;
        }
        cout << "Array is empty" << endl;
        return -1;
    }

    bool isFull()
    {
        return this->size == this->cap;
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    int size()
    {
        return size;
    }
};

/**
 * @brief The efficient implementation of queue can be done using a circular array. In this the rear can be before as well as after the front hence it allows us to perform dequeue in O(1) time.
 * 
 * All operations in O(1).
 * 
 */
class EfficientQueueUsingArray
{
    int *arr;
    int size, cap,front;
    EfficientQueueUsingArray(int cap)
    {
        this->cap = cap;
        this->size = 0;
        this->front=0;
        this->arr = new int[this->cap];
    }

    void enqueue(int x)
    {
        if (!isFull())
        {
            int rear=getRear();
            rear=(rear+1)%cap; // going to the next element
            arr[rear]=x;
            size++;
        }
        else
        {
            cout << "Array is full" << endl;
        }
    }

    void dequeue()
    {
        if (!isEmpty())
        {
            front=(front+1)%cap;
            size--;
        }
        else
        {
            cout << "Array is empty" << endl;
        }
    }

    int getFront()
    {
        if (!isEmpty())
        {
            return front;
        }

        return -1;
    }

    int getRear()
    {
        if (!isEmpty())
        {
            return (front+size-1)%cap;     // this is the way to get the rear in an circular array.
        }

        return -1;
    }

    bool isFull()
    {
        return this->size == this->cap;
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    int size()
    {
        return size;
    }
};
int main()
{

    return 0;
}