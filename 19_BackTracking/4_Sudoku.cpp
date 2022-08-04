#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
bool isSafe(vector<vector<ll>> &grid, int i, int j, int n)
{
    ll N = grid.size();

    for (ll k = 0; k < N; k++)
    {
        if (grid[k][j] == n || grid[i][k] == n)
            return false;
    }

    int s = sqrt(N);
    int rs = i - i % s;
    int cs = j - j % s;

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (grid[rs + i][cs + j] == n)
                return false;
        }
    }

    return true;
}
bool solve(vector<vector<ll>> &grid)
{
    ll N = grid.size();
    ll i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
                break;
        }

        if (grid[i][j] == 0)
            break;
    }

    if (i == N && j == N)
    {
        return true;
    }

    for (ll n = 1; n <= N; n++)
    {
        if (isSafe(grid, i, j, n))
        {
            grid[i][j] = n;

            if (solve(grid))
                return true;

            grid[i][j] = 0;
        }
    }

    return false;
}
int main()
{
    vector<vector<ll>> grid = {{1, 0, 3, 0}, {0, 0, 2, 1}, {0, 1, 0, 2}, {2, 4, 0, 0}};
    solve(grid);
    for (ll i = 0; i < grid.size(); i++)
    {
        for (ll j = 0; j < grid.size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}