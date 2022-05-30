#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief We can use this stack to get the minimum element in O(1) time complexity.
 * 
 * We wont have the problem of getting a element below that top of auxi_stack getting removed since if the element is below that top , then it for sure entered the stack after the top of auxi.
 * 
 * Time complexity : O(1)
 * Auxillary space : O(n)
 * 
 */
class GetMinStack
{
    stack <ll> main_stack;
    stack <ll> auxi_stack;

    public:

    void push(ll x)
    {
        main_stack.push(x);
        // we also do equal since we dont want poping of a copy to be affect the minimum.
        if(auxi_stack.top()>=x)  
        {
            auxi_stack.push(x);
        }
    }

    void pop()
    {
        if(main_stack.top()==auxi_stack.top())
        {
            auxi_stack.pop();
        }

        main_stack.pop();
    }

    ll getMin()
    {
        return auxi_stack.top();
    }

    ll top()
    {
        return main_stack.top();
    }

    ll size()
    {
        return main_stack.size();
    }

    ll empty()
    {
        return main_stack.empty();
    }
};
int main(){
    int a;
    // cout<<fun(a)<<endl;
    return 0;
}