#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
int main(){
    queue <ll> q;

    q.push(10);  // same as enqueue
    q.push(20);
    q.push(30);

    cout<<q.front()<<" "<<q.back()<<endl;

    q.pop();   // same as dequeue

    cout<<q.front()<<" "<<q.back()<<endl;

    cout<<q.size()<<endl;

    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }

    cout<<q.size()<<endl;

    // All the operations in queue have a time complexity of O(1).

    // Queue can be implemented on any underlying container that provides the following actions : empty(),size(),front(),back(),push_back(),pop_front().

    // Container which provide there functionalities : list and deque.

    // Again its implemented by default using deque and hence its a container adapter.

    return 0;
}