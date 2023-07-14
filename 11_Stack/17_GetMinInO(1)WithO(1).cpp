#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief The below solution is only applicable for positive elements. So we store the min in special variable min. And when we encounter a new min we store the (elem to be pushed - current min) in the place of new minimum and make the elem to be pushed as the new minimum.
 *
 * Time complexity : O(1)
 * Auxillary space : O(1)
 * 
 * This is applicable only when stack contains positive elements.
 *
 */
class GetMinStackPositive
{
    stack<ll> s;
    ll min; 

public:
    void push(ll x)
    {
        if (s.empty())
        {
            s.push(x);
            min = x;
        }
        else if (x <= min)
        {
            s.push(x - min);
            min = x;
        }
        else
        {
            s.push(x);
        }
    }

    ll pop()
    {
        ll t = s.top();
        if (t < 0)
        {
            ll res = min;
            min = min - t;
            return res;
        }

        s.pop();
        return t;
    }

    ll getMin()
    {
        return min;
    }

    ll top()
    {
        return (s.top()>0)?s.top():min;
    }
};

/**
 * @brief So instead of using <0 for positive numbers, for negative numbers we use <2*x.
 * 
 * We push 2*x-m only when x<=min. So 2*x-min is always going to be less than or equal to x and x is going to be our new min.
 * Also we can make sure that 2*x-min which is x+(x-min) will always be <x for x<=min.
 * 
 * Time complexity : O(1)
 * Auxillary space : O(1)
 */
class GetMinStackAll
{
    stack<ll> s;
    ll min;

public:
    void push(ll x)
    {
        if (s.empty())
        {
            s.push(x);
            min = x;
        }
        else if (x <= min)
        {
            s.push(2*x - min);
            min = x;
        }
        else
        {
            s.push(x);
        }
    }

    ll pop()
    {
        ll t = s.top();
        if (t <= min)
        {
            ll res = min;
            min = 2*min - t;
            return res;
        }

        s.pop();
        return t;
    }

    ll getMin()
    {
        return min;
    }

    ll top()
    {
        return (s.top()<=min)?min:s.top();
    }
};
int main()
{
    return 0;
}