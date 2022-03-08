#include <bits/stdc++.h>
using namespace std;
const int N = 4;
/**
 * @brief The below function is used to get the cofactor of the matrix in the temp array. We get the cofactor by excluding all the element in the row and column of the element whose cofactor is to be found.
 * 
 * Time complexity : O(n*n)
 * Auxillary space : O(1)
 * 
 * @param mat 
 * @param temp 
 * @param p 
 * @param q 
 * @param n 
 */
void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];
            }
            if (j == n - 1)
            {
                j = 0;
                i++;
            }
        }
    }
}
/**
 * @brief The following function is used to get the determinant of the matrix using recursion. To find the determinant we multiply the first row elements with the determinant of its cofactor and the sign according to its order. And we repeat this process recursively.
 * 
 * Time complexity : O(N*N)
 * Auxillary space : O(N*N)
 * 
 * @param mat 
 * @param n 
 * @return int 
 */
int determinant(int mat[N][N], int n)
{
    int D = 0;
    if (n == 1)
    {
        return mat[0][0];
    }
    int temp[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            temp[i][j] = 0;
    }
    int sign = 1;
    for (int i = 0; i < n; i++)
    {
        getCofactor(mat, temp, 0, i, n);
        D += mat[0][i] * sign * determinant(temp, n - 1);
        sign = -sign;
    }
    return D;
}

int main()
{
    int mat[N][N] = {{1, 0, 2, -1},
                     {3, 0, 0, 5},
                     {2, 1, 4, -3},
                     {1, 0, 5, 0}};
    cout << determinant(mat, N) << endl;
    return 0;
}