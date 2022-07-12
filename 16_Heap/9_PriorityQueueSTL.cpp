#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
class Person
{
public:
    ll age;
    db ht;
    Person(ll a, db h)
    {
        age = a;
        ht = h;
    }
};
struct myCmp
{
    bool operator()(Person const &p1, Person const &p2)
    {
        return p1.ht < p2.ht;
    }
};
int main()
{

    // Priority queue is usually implemented using heap DS.
    // Priority queue is by default a max-heap in cpp.

    priority_queue<ll> pq;

    pq.push(10);
    pq.push(15);
    pq.push(5);

    cout << pq.size() << endl;

    cout << pq.top() << endl; // Will give us the max element in heap

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    // Following is the way  to create priority queue with min item at the top or with min-heap.

    // We add vector here becuase heap is implemented using vector and hence requires us to tell it the DS which it should use.

    priority_queue<ll, vector<ll>, greater<int>> mpq;

    mpq.push(10);
    mpq.push(15);
    mpq.push(5);

    cout << mpq.size() << endl;

    cout << mpq.top() << endl;

    while (!mpq.empty())
    {
        cout << mpq.top() << " ";
        mpq.pop();
    }

    // We can also create a priority queue using a existing vector or array.

    int arr[] = {10, 5, 15};

    // This is better way of creating a heap since buildHeap function has only O(n) time complexity whereas every push has time complexity of O(logn).
    priority_queue<int> bpq(arr, arr + 3);

    while (!bpq.empty())
    {
        cout << bpq.top() << " ";
        bpq.pop();
    }
    cout<<endl;

    // TIME COMPLEXITIES :
    // top, size, empty : O(1)
    // push,pop : O(logn)
    // Building priority queue using array or vector : O(n)

    // Another way of creating a min-heap is to multiply each element with -1 and then use a max-heap and while pop we multiply every element with -1 which will give the same effect as min-heap.

    // If we use a priority queue of a pair the element will be ordered by first element and for other behaviors we will have to write our own comparator.
    // Same goes for custom user defined DS.

    Person parr[] = {Person(21, 5.7), Person(23, 6.7), Person(35, 4.7)};

    priority_queue<Person, vector<Person>, myCmp> ppq(parr, parr + 3);

    while (!ppq.empty())
    {
        cout << ppq.top().age << " " << ppq.top().ht << endl;
        ppq.pop();
    }

    // Applications of priority queue :
    // 1) Dijkstra algorithm
    // 2) Prim algorithm
    // 3) Huffman algorithm
    // 4) Heap sort
    // Any other place where heap is used.
    // Whereever we need get_min or get_max we use priority queue.

    // STL priority doesn't have decrease key and to deal with this we can change our algorithm.

    // Cpp has max-heap by default whereas other languages have min-heap by default.

    return 0;
}