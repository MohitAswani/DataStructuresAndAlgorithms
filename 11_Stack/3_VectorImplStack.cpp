#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief The following is an vector implementation of stack ds and it is dynamically sized.
 *
 * The time complexity of push and pop on average is O(1) ( Since the insertion on vector has a worst case time complexity of O(n) but an average time complexity of O(1)).
 *
 */
class myStack
{
    vector<ll> v;

public:
    void push(ll x)
    {
        v.push_back(x);
    }

    ll pop()
    {
        if (this->isEmpty())
        {
            cout << "UNDERFLOW" << endl;
            return -1;
        }

        ll top = v.back();
        v.pop_back();
        return top;
    }

    ll peek()
    {
        if (this->isEmpty())
        {
            cout << "UNDERFLOW" << endl;
            return -1;
        }

        return v.back();
    }

    bool isEmpty()
    {
        return v.empty();
    }

    ll stackSize()
    {
        return v.size();
    }
};
int main()
{

    // CPP stack's behaviour on peek and pop on empty stack is undefined.

    myStack s;

    cout << s.pop() << endl;
    cout << s.peek() << endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    return 0;
}