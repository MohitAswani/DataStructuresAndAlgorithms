#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if(matrix[i][0]==2222)
                    {
                        matrix[i][0]=3333;
                    }
                    else
                    {
                        matrix[i][0] = 1111;
                    }
                    if(matrix[0][j]==2222)
                    {
                        matrix[0][j]=3333;
                    }
                    else
                    {
                        matrix[i][] = 1111;
                    }
                    matrix[0][j] = 2222;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 1111)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] != 2222)
                        matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == 2222)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};
int main()
{
    int a, b;
    vector<vector<int>> matrix =
        {
            {0, 2, 3, 0},
            {5, 2, 7, 8},
            {0, 10, 11, 12}};
    Solution sol;
    sol.setZeroes(matrix);
    return 0;
}