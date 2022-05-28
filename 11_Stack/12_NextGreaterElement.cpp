#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief In this problem we are given an array of integers and we need to find the greater element than the current element which is closest to it.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(n)
 * 
 * @param arr 
 */
void nextGreaterElement(vector <ll> &arr)
{
    int n=arr.size();
    stack <int> s;
    s.push(arr[n-1]);
    stack <int> nextGreater;
    nextGreater.push(-1);

    for(int i=n-2;i>=0;i--)
    {

        while(!s.empty()&&s.top()<=arr[i])
        {
            s.pop();
        }

        
        nextGreater.push(s.empty()?-1:s.top());
        s.push(arr[i]);
    }

    while(!nextGreater.empty())
    {
        cout<<nextGreater.top()<<" ";
        nextGreater.pop();
    }
    cout<<endl;
}
int main()
{
    vector <ll> arr={5,15,10,8,6,12,9,18};
    nextGreaterElement(arr);

    return 0;
}