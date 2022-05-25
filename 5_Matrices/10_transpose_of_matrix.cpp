#include <bits/stdc++.h>
using namespace std;
const int R = 2, C = 2;
/**
 * @brief In the below function we just swap the elements below the diagonal with those above it to get the transpose.
 * 
 * The below method is in-place and happens in one traversal.
 * 
 * Time complexity : O(R*C)
 * Auxillary space : O(1) since this is a in-place process.
 * 
 * @param arr 
 */
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
    int arr[R][C] = {{1, 1}, {2, 2}};
    transpose(arr);  
    print(arr);
    return 0;
}