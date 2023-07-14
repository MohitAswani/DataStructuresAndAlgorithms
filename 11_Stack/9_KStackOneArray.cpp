#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief
 *
 * Naive approach : A naive approach to this problem is to divide the array in k parts. But the issue with this approach is that our stack size is limited and we wont be able to use available provided by other empty stacks.
 *
 * Efficient approach : 
 * 
 * To do this efficient we use two extra arrays : top and next.
 * 
 * Top array stores the position at which the top element of any stack is present.
 * 
 * Also we want to use the space efficient and not waste any space if its available to do that we use an array called next which stores the next element of the stack and hence we don't need to store the elements in consecutive blocks we can just use next array to refer to the next element.
 * 
 * Next array server two purposes : it tells us the next slot , it tells us about the next free slot.
 * 
 * Also we have a element called freeTop which gives us the top of free stack.
 *
 * We are basically using array implementation of linked list to implement K stacks.
 *
 * Watch the video : 'K Stacks in an array'
 *
 *
 */
class KStacks
{
    int *arr, *top, *next;
    int K, freeTop, cap;

public:
    KStacks(int K, int n)
    {
        this->K = K;
        this->cap = n;

        arr = new int[cap];
        next = new int[cap];
        top = new int[K];

        for (int i = 0; i < K; i++)
        {
            top[i] = -1;
        }

        freeTop = 0;

        for (int i = 0; i < cap - 1; i++)
        {
            next[i] = i + 1;
        }
        next[cap - 1] = -1;
    }

    void push(int x, int sn) // Where sn is the stack number from 0->k-1
    {

        // Order of the operations we perform to push an element is extremely important.

        if (isFull())
        {
            cout << "STACK OVERFLOW" << endl;
            return;
        }

        int i = freeTop;
        freeTop = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = x;
    }

    int pop(int sn)
    {
        if (isEmpty(sn))
        {
            cout << "STACK UNDERFLOW" << endl;
            return -1;
        }

        int i = top[sn];
        top[sn] = next[i];
        next[i] = freeTop;
        freeTop = i;
        return arr[i];
    }

    bool isFull()
    {
        return (freeTop == -1);
    }

    bool isEmpty(int sn)
    {
        return (top[sn] == -1);
    }

    int size(int sn)
    {
        int e = top[sn];

        int size = 0;

        while (e != -1)
        {
            e = next[e];
            size++;
        }

        return size;
    }

    int topofstack(int sn)
    {
        return (top[sn] == -1) ? -1 : arr[top[sn]];
    }

    ~KStacks()
    {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};
int main()
{
    KStacks stk(3, 6);

    stk.push(100,0);
    cout<<stk.topofstack(0)<<endl;

    stk.push(200,0);
    cout<<stk.topofstack(0)<<endl;

    stk.push(300,0);
    cout<<stk.topofstack(0)<<endl;

    stk.push(400,1);
    cout<<stk.topofstack(1)<<endl;
    
    cout<<stk.size(0)<<endl;
    cout<<stk.size(1)<<endl;

    stk.pop(0);
    cout<<stk.size(0)<<endl;

    return 0;
}