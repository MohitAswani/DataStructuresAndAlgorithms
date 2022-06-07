#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief To implement a stack using queue, we make use of another auxillary queue.
 * 
 * top() : we just return front of the first queue.( O(1) )
 * size() : we just return the size of the first queue. ( O(1) )
 * pop() : we just dequeue the first queue. ( O(1) )
 * push() : we need to add an element to the front but queue normal adds an element to the rear. So we use first push all the element in the auxillary queue. Then we push the element in the main queue and push rest of the elements after it.
 * 
 */
class StackUsingQueuePush      // push operation is costly
{
    queue<ll> q1, q2;

public:
    ll top()
    {
        return q1.front();
    }

    ll size()
    {
        return q1.size();
    }

    ll pop()
    {
        ll data = q1.front();
        q1.pop();
        return data;
    }

    void push(ll x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
};


class StackUsingQueuePop       // pop operation is costly
{
    queue<ll> q1, q2;
    ll top_of_stack=-1;

public:
    ll top()
    {
        return top_of_stack;
    }

    ll size()
    {
        return q1.size();
    }

    ll pop()
    {
        if(q1.empty())
        return -1;


        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        ll data=q1.front();
        q1.pop();

        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }

        return data;
    }

    void push(ll x)
    {
        q1.push(x);  
        top_of_stack=x;
    }
};

void reverseQueue(queue <ll> &q1)
{
    if(q1.empty())
    {
        return ;
    }

    ll temp=q1.front();
    q1.pop();
    reverseQueue(q1);
    q1.push(temp);
}

/**
 * @brief In this we reverse the queue and then push the element and then again reverse the queue.
 * 
 */
class StackUsingOneQueue
{
    queue<ll> q1;

public:
    ll top()
    {
        return q1.front();
    }

    ll size()
    {
        return q1.size();
    }

    ll pop()
    {
        ll data=q1.front();
        q1.pop();
        return data;
    }

    void push(ll x)
    {
        reverseQueue(q1);
        q1.push(x);
        reverseQueue(q1);
    }
};

int main()
{
    StackUsingOneQueue s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<s.top()<<endl;

    cout<<s.size()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;


    return 0;
}