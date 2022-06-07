#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief Given a number n, print first n numbers (in increasing order) such that all these numbers have digits in set {5,6}.
 *
 * We push 5 and 6 to the queue, then for every existing element we append 5 and 6 in the respective order and our final result is the requirred array.
 *
 * Time complexity : O(n)
 * Auxillary space : O(n)
 * 
 * 
 * This solution can also be used to generate all the numbers in increasing order using digits from 0-9.
 * @param n
 */
void printFirstN(ll n)
{
    queue<ll> q;

    q.push(5);
    q.push(6);

    for (ll i = 0; i < n; i++)
    {
        ll data = q.front();
        cout << data << " ";
        q.pop();
        q.push(data * 10 + 5);
        q.push(data * 10 + 6);
    }

    cout << endl;
}
int main()
{
    printFirstN(10);
    return 0;
}