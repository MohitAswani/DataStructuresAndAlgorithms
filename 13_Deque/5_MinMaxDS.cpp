#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief We maitain the min at front and max at back in the deque.
 * 
 */
class MinMaxDS
{
    deque<ll> dq;

public:
    void insertMin(ll x)
    {
        if (!dq.empty()&&x >= dq.front())
            return;

        dq.push_front(x);
    }

    void insertMax(ll x)
    {
        if (!dq.empty()&&x <= dq.back())
            return;

        dq.push_back(x);
    }

    ll getMin()
    {
        return dq.front();
    }

    ll getMax()
    {
        return dq.back();
    }

    void extractMin()
    {
        return dq.pop_front();
    }

    void extractMax()
    {
        return dq.pop_back();
    }
};
int main()
{
    MinMaxDS ds=MinMaxDS();

    ds.insertMax(10);
    ds.insertMin(2);

    cout<<ds.getMin()<<" "<<ds.getMax()<<endl;

    ds.insertMax(15);
    ds.insertMin(-2);

    cout<<ds.getMin()<<" "<<ds.getMax()<<endl;

    return 0;
}