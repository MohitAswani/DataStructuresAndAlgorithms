#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In this problem we need to find the element which is just greater or equal to the current element on the left side of the array.
 *
 * To solve this problem we use a set and find the lower_bound for each element which gives us the ceil of each element.
 * 
 * If no lower_bound present then we print -1.
 * 
 * Time complexity : O(nlog(n))
 * Auxillary space : O(n)
 * 
 * @param arr
 */
void CeilOnLeft(vector<ll> arr)
{
    set<ll> s;

    s.insert(arr[0]);
    // Output for first element
    cout << -1 << " ";

    for (int i = 1; i < arr.size(); i++)
    {
        auto it = s.lower_bound(arr[i]);  // O(logn)

        if (it != s.end())
        {
            cout << *it << " ";
        }
        else
        {
            cout << -1 << " ";
        }
        s.insert(arr[i]);   // O(logn)
    }

    cout << endl;
}
int main()
{
    vector <ll> vect={2,8,30,15,25,12};

    CeilOnLeft(vect);

    return 0;
}