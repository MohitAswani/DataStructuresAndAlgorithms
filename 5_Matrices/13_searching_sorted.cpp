#include <bits/stdc++.h>
using namespace std;
const int R = 4, C = 4;
/**
 * @brief In the below function we are searching for an element in the array by using the fact that the array is sorted row and columnwise. We either start from top right or bottom left (coz only then we can have both smaller and bigger elements )move accoringdly if element to be search is smaller or bigger.
 *
 * Time complexity : O(R+C)
 * Auxillary space : O(1)
 *
 * @param arr
 * @param x
 */
void searching(int arr[R][C], int x)
{
    if (x > arr[0][0] && x < arr[R - 1][C - 1]) // if element is not in this range then it is surely not present in the 2D matrix
    {
        int i = 0, j = C - 1;
        while (i < R && j >= 0)
        {
            if (arr[i][j] < x)
            {
                i++;
            }
            else if (arr[i][j] > x)
            {
                j--;
            }
            else
            {
                cout << "ELEMENT FOUND AT (" << i << "," << j << ")" << endl;
                return;
            }
        }
    }
    cout << "ELEMENT NOT FOUND" << endl;
}
int main()
{
    int arr[R][C] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};
    searching(arr, 29);
    return 0;
}