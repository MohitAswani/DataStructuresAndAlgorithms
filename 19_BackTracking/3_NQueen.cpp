#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
bool isSafe(vector<vector<ll>> &board, ll r, ll c)
{
    ll m = board.size();
    ll n = board[0].size();

    for (int i = 0; i < n; i++)
    {
        if (board[r][i] == 1)
            return false;
    }

    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) // upper diagonal
    {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = r, j = c; i < m && j >= 0; i++, j--) // lower diagonal
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}
bool nQueenHelper(vector<vector<ll>> &board, int col)
{
    ll m = board.size();
    ll n = board[0].size();

    if (col == m)
    {
        return true;
    }

    for (ll i = 0; i < m; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            if (nQueenHelper(board,col + 1))
            {
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}
bool nQueen(vector<vector<ll>> &board)
{
    ll m = board.size();
    ll n = board[0].size();

    if (nQueenHelper(board, 0))
    {
        for (ll i = 0; i < m; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        return true;
    }

    return false;
}
int main()
{
    vector<vector<ll>> board(4, vector<ll>(4, 0));
    nQueen(board);
    return 0;
}