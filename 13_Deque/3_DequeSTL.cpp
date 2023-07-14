#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/*
 * Allows insertions and deletion from both the ends.

 * Deque in CPP is implemented differently from most of the other languages.

 * Most of the other languages implement deque using doubly linked list.

 * But CPP STL implementation of deque guarantees few extra things :
    * Allows us to have random access.
    * Allows us to do arbitary number of insertion in O(1) time which is not provided by deque implementation of other languages.
 *
 * 
 */
int main()
{
    deque<ll> dq = {10, 20, 30};

    dq.push_front(5);
    dq.push_back(50);

    for (auto x : dq)
        cout << x << " ";
    cout << endl;

    cout << dq.front() << " " << dq.back() << endl;

    auto it = dq.begin();

    it++;

    dq.insert(it, 20); // will add a element just before the given iterator.

    for (auto x : dq)
        cout << x << " ";
    cout << endl;

    dq.pop_front();
    dq.pop_back();

    for (auto x : dq)
        cout << x << " ";
    cout << endl;

    cout << dq.size() << endl;

    return 0;
}