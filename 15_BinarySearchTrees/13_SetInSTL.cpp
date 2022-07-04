#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
class Test
{
public:
    ll val;

    Test(ll v)
    {
        this->val=v;
    }

    // To change the behaviour of a set we override the '<' operator.
    bool operator<(const Test &t) const
    {
        return (this->val < t.val);
    }
};
int main()
{

    // Set are used to store data in sorted way.

    set<ll> s;
    // set <ll,greater<ll>> s; // storing in decreasing order
    s.insert(10);
    s.insert(5);
    s.insert(10); // set ignores duplicate values
    s.insert(20);
    s.insert(20);

    for (int x : s)
        cout << x << " ";
    cout << endl;

    for (auto it = s.begin(); it != s.end(); it++)
        cout << (*it) << " ";
    cout << endl;

    for (auto it = s.rbegin(); it != s.rend(); it++) // iterating in reverse direction
        cout << (*it) << " ";
    cout << endl;

    // Find function : used to search an element in set

    auto it = s.find(10); // if present returns an iterator pointing to the element.
                          // if not present it returns an iterator to s.end()

    if (it == s.end())
        cout << "Not found" << endl;
    else
        cout << "Found" << endl;

    // Clear function will delete all the elements of the set

    s.clear();

    cout << s.size() << endl;

    s.insert(10);
    s.insert(5);
    s.insert(20);

    // Count function will count the occurence of an element but for set it just returns 0 or 1.

    // Count can also be used to find a element in set using the occurence count.

    if (s.count(10))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    // Erase function will remove an element from the set

    s.erase(5);

    for (int x : s)
        cout << x << " ";
    cout << endl;

    // We can also use erase an element using its iterator

    auto it1 = s.find(10);

    s.erase(it1);

    for (int x : s)
        cout << x << " ";
    cout << endl;

    // We can also erase to remove element in an range of itterators

    s.erase(s.begin(), s.end());

    s.insert(10);
    s.insert(5);
    s.insert(20);

    // lower_bound function in the set class is similiar to the one in vectors and arrays, only difference being that it is a member of the set class.

    // This function returns the iterator to the element if it present else it returns the iterator to the greater element.

    // If the given element is greater than the largest then it returns s.end().

    auto it2 = s.lower_bound(12);

    if (it2 != s.end())
        cout << *it2 << endl;
    else
        cout << "Given element is greatar than the largest" << endl;

    // upper_bound function in the set class is similiar to the one in vectors and arrays, only difference being that it is a member of the set class.

    // This function returns the iterator to just greater element if it present or not present.

    // If the given element is greater than the largest then it returns s.end().

    auto it3 = s.upper_bound(25);

    if (it3 != s.end())
        cout << *it3 << endl;
    else
        cout << "Given element is greatar than the largest" << endl;

    set <Test> s1;

    s1.insert(Test(1));    
    s1.insert(Test(5));    
    s1.insert(Test(3));    

    for(auto e:s1)
        cout<<e.val<<" ";
    cout<<endl;

    return 0;
}