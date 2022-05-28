#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief This solution is closely related to the stock span problem. To find the element greater than the current element we need all the elements which were greater than the previous element and we need them in LIFO order.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(n)
 * 
 * @param arr 
 */
void previousGreaterElement(vector <ll> &arr)
{
    stack <int> s;

    for(int i=0;i<arr.size();i++)
    {

        // In the below loop we are removing all the top items from the stack which are less than or equal to the current item.
        while(!s.empty()&&s.top()<=arr[i])
        {
            s.pop();
        }

        // If stack is empty then we print -1 else we print top of the stack.
        int ans=s.empty()?-1:s.top();
        cout<<ans<<" ";
        s.push(arr[i]);
    }
    cout<<endl;
}
int main()
{
    vector <ll> arr={15,10,18,12,4,6,2,8};

    previousGreaterElement(arr);

    return 0;
}