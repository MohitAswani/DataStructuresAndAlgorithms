#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In the below implementation we maitain the two ends of the array as the heads of stacks and push the elements likewise.
 *  
 */
class TwoStacks{
    ll *arr;
    ll cap;
    ll top1;
    ll top2;

    TwoStacks(ll n){
        arr=new ll[n];
        cap=n;
        top1=-1;
        top2=n;
    }

    void push1(ll x)
    {
        if(top1<top2-1)
        {
            top1++;
            arr[top1]=x;
        }
        else
        {
            cout<<"OVERFLOW"<<endl;
        }
    }

    void push2(ll x)
    {
        if(top1<top2-1)
        {
            top2--;
            arr[top2]=x;
        }
        else
        {
            cout<<"OVERFLOW"<<endl;
        }
    }

    void pop1()
    {
        if(top1>=0)
        {
            arr[top1]=0;
            top1--;
        }
        else
        {
            cout<<"UNDERFLOW"<<endl;
        }
    }

    void pop2()
    {
        if(top2<this->cap)
        {
            arr[top2]=0;
            top2++;
        }
        else
        {
            cout<<"UNDERFLOW"<<endl;
        }
    }

    ll size1()
    {
        return top1+1;
    }

    ll size2()
    {
        return cap-top2;
    }

};
int main(){
    return 0;
}