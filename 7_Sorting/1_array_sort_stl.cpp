#include<bits/stdc++.h>
using namespace std;
int main(){
    //Sort can be used in container which allow random memory access : array,vector,deque
    int arr[]={10,20,5,7};
    int n=4;
    sort(arr,arr+n);   //increasing func
    for(auto elem:arr)
    cout<<elem<<" ";
    cout<<endl;
    sort(arr,arr+n,greater<int>());  //decreasing func
    for(auto elem:arr)
    cout<<elem<<" ";
    cout<<endl;
    
    return 0;
}