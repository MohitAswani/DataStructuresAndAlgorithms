#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

class QueueUsingStackEnqueue   // 1 2 3 4 5 6
{
    stack<ll> s1;
    stack<ll> s2;

public:
    void enqueue(ll x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    ll dequeue()
    {
        ll data = s1.top();
        s1.pop();
        return data;
    }

    ll top()
    {
        return s1.top();
    }

    ll size()
    {
        return s1.size();
    }
}; 
class QueueUsingStackDequeue   // 6 5 4 3 2 1
{
    stack<ll> s1;
    stack<ll> s2;

public:
    void enqueue(ll x)
    {
        s1.push(x);
    }

    ll dequeue()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        ll data = s2.top();
        s2.pop();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        return data;
    }

    ll top()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        ll data = s2.top();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        return data;
    }

    ll size()
    {
        return s1.size();
    }
};

void insertAtBottom(stack <ll> &s,ll x)
{
    if(s.empty())
    {
        s.push(x);
        return ;
    }

    ll data=s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(data);
}

class QueueUsingOneStack  // 1 2 3 4 5 6
{
    stack<ll> s1;

public:
    void enqueue(ll x)
    {
        insertAtBottom(s1,x);
    }

    ll dequeue()
    {
        ll data=s1.top();
        s1.pop();
        return data;
    }

    ll top()
    {
        return s1.top();
    }

    ll size()
    {
        return s1.size();
    }
};

int main()
{
    QueueUsingOneStack q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout<<q.size()<<endl;
    cout<<q.top()<<endl;

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    return 0;
}