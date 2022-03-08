#include <bits/stdc++.h>
using namespace std;
const int R = 4, C = 4;
void transpose(int arr[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = i + 1; j < C; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}
/**
 * @brief To rotate a matrix by 90 degrees we first take the transpose of the matrix. After taking the transpose we reverse all the rows and we get the rotation of the matrix by 90 degrees.
 * 
 * Time complexity : O(R*C)
 * Auxillary space : O(1)
 * @param arr 
 */
void rotating(int arr[R][C])
{
    transpose(arr);

    // Reversing the rows
    for (int i = 0; i < R / 2; i++)
    {
        for (int j = 0; j < C; j++)
        {
            swap(arr[i][j], arr[R - i - 1][j]);
        }
    } 
}
void print(int arr[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << arr[i][j] << " ";

        cout << endl;
    }
}
int main()
{
    int arr[R][C] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    cout << "BEFORE THE ROTATION:" << endl;
    print(arr);

    rotating(arr);
    
    cout << "AFTER THE ROTATION:" << endl;
    print(arr);
    return 0;
}