#include<bits/stdc++.h>
using namespace std;
int counting_bits(int num, int arr[], int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if ((num & arr[i]) == num)
        {
            count++;
        }
    }
    return count;
}
int maxAND(int arr[], int N)
{
    int res = 0;
    for (int i = 31; i >= 0; i--)
    {
        int cnt = counting_bits(res | (1 << i), arr, N);
        if (cnt >= 2)
        {
            res = res | (1 << i);
        }
    }
    return res;
}
int main(){
    int arr[]={1,4,5,16,17};
    int size=sizeof(arr)/sizeof(int);
    cout<<maxAND(arr,size)<<endl;
    return 0;
}