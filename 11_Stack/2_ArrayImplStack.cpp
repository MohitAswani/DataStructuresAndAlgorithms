#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief Below is an implementation of stack data structure using an array and we do handle underflow and overflow in the below DS.
 *
 * But the below stack has a fixed size and doesn't grow dynamically.
 *
 * In this DS we remove from the end so that pop and push happen in O(1).
 *
 * For dynamically sized stack we can use a vector.
 *
 */
class myStack
{
    ll size;
    ll *arr;
    ll top;

public:
    myStack(ll size)
    {
        this->size = size;
        arr = new ll[size];
        top = -1;
    }

    void push(ll x)
    {
        if (this->stackSize() == size)
        {
            cout << "Overflow" << endl;
            return;
        }

        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Underflow" << endl;
            return;
        }

        arr[top] = 0;
        top--;
    }

    ll peek()
    {
        if (top == -1)
        {
            cout << "Underflow" << endl;
            return -1;
        }

        return arr[top];
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    ll stackSize()
    {
        return (top + 1);
    }

    ~myStack()
    { // Adding a destructor so as to delete the array once the stack is destroyed
        delete[] arr;
    }
};
int main()
{
    // CPP stack's behaviour on peek and pop on empty stack is undefined.

    myStack s(5);

    s.pop();
    cout << s.peek() << endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    return 0;
}