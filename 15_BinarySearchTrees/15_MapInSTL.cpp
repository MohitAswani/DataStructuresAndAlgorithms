#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
int main()
{
    map<ll, ll> m;
    // map<ll, ll,greater<ll>> m;  // Will store keys in decreasing order

    m.insert({10, 200});

    m[5] = 100;

    m.insert({3, 300});

    // If a key is already present this the following type of insert is completely ignored.
    m.insert({3, 400});

    // Also if a key is accessed using a square operator and if that key is not present then the key is inserted with a default value.

    cout << m.size() << endl;
    cout << m[20] << endl;
    cout << m.size() << endl;

    // We also use square brackets to update the value.

    m[3] = 400;

    // We can also access elements using at operator

    m.at(10) = 600;

    // But if the key is not present then it throws an exeception.

    for (auto &x : m)
    {
        cout << x.first << " " << x.second << endl;
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }

    // This will delete all the elements
    // m.clear();

    cout << m.size() << endl;

    // Find returns the iterator point to the element with a particular key if present else it returns end.

    if (m.find(5) == m.end())
        cout << "Not found" << endl;
    else
        cout << "Found" << endl;

    // Map has keys in sorted order.

    // Count function returns either 1 or 0 coz map doesn't allow duplicate key.

    if (m.count(5) == 0)
        cout << "Not found" << endl;
    else
        cout << "Found" << endl;

    // Lower bound returns the iterator to the element if present else to the element just greater than the given element.

    // If no greater element present then it returns m.end().

    auto it1=m.lower_bound(2);

    if(it1!=m.end())
        cout<<(*it1).first<<endl;
    else
        cout<<"No equal or greater value"<<endl;

    // Upper bound returns the iterator to element just greater than the given element.

    // If no greater element present then it returns m.end().

    auto it2=m.upper_bound(2);

    if(it2!=m.end())
        cout<<(*it2).first<<endl;
    else
        cout<<"No equal or greater value"<<endl;

    // Erase function can be used to remove elements by key or using itterator or using a range of itterators.

    return 0;
}