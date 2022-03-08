#include<bits/stdc++.h>
using namespace std;
const int R=3,C=2;
void print(int arr[R][C])
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
int main(){

    // Unfortunatily there is not way to pass an 2D matrix to function without declaring global sizes..

    int arr[R][C]={10,20,30,40,50,60};
    print(arr);
    return 0;
}