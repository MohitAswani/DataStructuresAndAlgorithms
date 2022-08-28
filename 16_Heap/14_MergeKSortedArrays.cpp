#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In this problem we are given k sorted arrays and we need to combine them into a single sorted array.
 *
 * We use a min heap of size k with every element having 3 fields, {value, pos of array , pos given elemenet in the array}.
 *
 * And now we keep on removing and top and adding the next element from the same array into our heap until all the arrays become empty.
 *
 * Time complexity : O(nklog(k))
 * Auxillary space : O(k)
 * 
 * @param arr
 * @return vector<int>
 */
class Triplet
{
public:
    ll val;
    ll pos_of_array;
    ll pos_in_array;
    Triplet(ll v1, ll v2, ll v3)
    {
        val = v1;
        pos_of_array = v2;
        pos_in_array = v3;
    }
};
struct myCmp
{
    bool operator()(Triplet const &t1, Triplet const &t2)
    {
        return t1.val > t2.val;
    }
};
vector<ll> mergeKSorted(vector<vector<ll>> &arr)
{
    priority_queue<Triplet, vector<Triplet>, myCmp> pq;

    int k = arr.size();

    for (ll i = 0; i < k; i++) // k
    {
        pq.push(Triplet(arr[i][0], i, 0)); // Log k
    }

    vector<ll> ans;

    while (!pq.empty()) // Will run n*k times at max
    {
        Triplet temp = pq.top();
        pq.pop(); // Log k
        ans.push_back(temp.val);

        if (temp.pos_in_array + 1 < arr[temp.pos_of_array].size())
        {
            pq.push(Triplet(arr[temp.pos_of_array][temp.pos_in_array + 1], temp.pos_of_array, temp.pos_in_array + 1)); // Log k
        }
    }

    return ans;
}
int main()
{
    vector<vector<ll>> arr = {{10, 20, 30}, {5, 15}, {1, 9, 11, 18}};

    vector<ll> val = mergeKSorted(arr);

    for (int i = 0; i < val.size(); i++)
        cout << val[i] << " ";
    cout << endl;

    return 0;
}