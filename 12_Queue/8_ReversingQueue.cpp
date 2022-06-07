#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief We make the user of stack data structure to reverse the queue.
 *
 * Time complexity : O(n)
 * Auxillary space : O(n)
 * @param q
 */
void reverseIterative(queue<ll> &q)
{
    stack<ll> s;

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

/**
 * @brief 
 * 
 * Time complexity : O(n)
 * Auxillary space : O(n)
 * 
 * @param q 
 */
void reverseRecursive(queue<ll> &q)
{
    if (q.empty())
        return;

    ll data = q.front();
    q.pop();
    reverseRecursive(q);
    q.push(data);
}
int main()
{
    queue <ll> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseIterative(q);


    reverseRecursive(q);

    return 0;
}