#include <bits/stdc++.h>
using namespace std;
void solve()
{
    //C. Pair Programming
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    int inda = 0, indb = 0;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        b.push_back(temp);
    }
    int sum = k;
    while (a.size() > 0 || b.size() > 0)
    {
        int p = a.front();
        int q = b.front();
        if (p == 0)
        {
            c.push_back(p);
            a.erase(a.begin());
            k++;
        }
        else if (q == 0)
        {
            c.push_back(q);
            b.erase(b.begin());
            k++;
        }
        else
        {
            if (k >= p)
            {
                if (a.size() != 0)
                {
                    c.push_back(p);
                    a.erase(a.begin());
                }
            }
            else if (k >= q)
            {
                if (b.size() != 0)
                {
                    c.push_back(q);
                    b.erase(b.begin());
                }
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (int num : c)
    {
        cout << num << " ";
    }
    cout << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}