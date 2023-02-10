#include <bits/stdc++.h>
using namespace std;
/*
Advantages:

* This matrix will have dynamic rows which are different from dynamic rows in double pointer matrix since and in the latter we will have to first allocate a size to the rows. An array of vector can have rows with any number of columns.
* It is easy to pass to an function since we don't need to pass it as pointer/array of pointers.

Disadvantages:

* Not as cache friendly.

*/
void print(vector<int> arr[], int m)
{
    cout << "PRINTING USING PRINT FUNCTION: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";

        cout << endl;
    }
}
int main()
{
    int m = 3, n = 2;
    vector<int> arr[m]; // this is an array of vectors

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            arr[i].push_back(i + j); // pushing elements in each vector belonging to the array of vectors.
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    print(arr, m);
    return 0;
}