#include<bits/stdc++.h>
using namespace std;
/**
 * @brief To find the square root of n we take l=0,r=n. Then we just search for a number such that mid*mid==x. Also we need to find the largest number which satisfies mid*mid<x and hence we store it in a variable and output the last/largest value. That is the condition when the number is not a perfect square.
 * 
 * time complexity : O(logn)
 * space complexity: O(1)
 * 
 * @param x 
 * @return int 
 */
int sqaure_root(int x)
{
    int l=0,r=x;
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(mid*mid==x)
        return mid;
        else if(mid*mid>x)
        r=mid-1;
        else if(mid*mid<x)
        {
            l=mid+1;
            ans=mid; 
        }
    }
    return ans;
}
int main(){
    cout<<sqaure_root(0)<<endl;
    return 0;
}