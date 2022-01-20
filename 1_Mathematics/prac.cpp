#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
bool fun(int n){
    ll temp=0,cpy=n;
    while(cpy)
    {
        temp*=10;
        temp+=cpy%10;
        cpy=cpy/10;
    }

    return (temp==n);
}
int main(){
    int a;
    cout<<fun(111323111)<<endl;
    return 0;
}