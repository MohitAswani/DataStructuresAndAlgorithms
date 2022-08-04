#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
bool isSafe(vector<vector<ll>> &maze, int i, int j)
{
    ll m = maze.size();
    ll n = maze[0].size();

    return (i < m  && j < n  && maze[i][j] == 1);
}
bool solveMazeHelper(vector<vector<ll>> &maze, vector<vector<ll>> &path, int i, int j)
{
    ll m = maze.size();
    ll n = maze[0].size();

    if (i == m - 1 && j == n - 1)
    {
        path[i][j] = 1;
        return true;
    }

    if (isSafe(maze, i, j))
    {
        path[i][j] = 1;

        if (solveMazeHelper(maze, path, i + 1, j))
        {
            return true;
        }

        if (solveMazeHelper(maze, path, i, j + 1))
        {
            return true;
        }

        path[i][j] = 0;
    }

    return false;
}
bool solveMaze(vector<vector<ll>> &maze)
{
    ll m = maze.size();
    ll n = maze[0].size();

    vector<vector<ll>> path(m, vector<ll>(n, 0));

    if (solveMazeHelper(maze, path, 0, 0))
    {
        for (ll i = 0; i < m; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }

        return true;
    }

    return false;
}

int main()
{
    vector<vector<ll>> maze = {{1, 0, 1}, {1, 1, 1}, {1, 1, 1}};
    solveMaze(maze);
    return 0;
}