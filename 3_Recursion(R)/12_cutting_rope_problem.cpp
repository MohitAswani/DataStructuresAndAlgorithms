#include<bits/stdc++.h>
using namespace std;
/**
 * @brief In the below function we are given the length of a rope and we are given the length we can divide it into (a,b,c).
 * We need to find the maximum parts which can be formed by dividing it into parts of a,b,c.
 * In the below solution we recursively decrease the length of rope by a,b,c. We keep on doing this until the length of the rope becomes <=0.
 * Then we find the maximum of all the parts that can be formed and return it.
 * 
 * Time complexity : O(3^n)
 * Auxillary space : O(n)
 * 
 * @param n 
 * @param a 
 * @param b 
 * @param c 
 * @return int 
 */
int func(int n,int a,int b,int c)
{
    if(n==0)
    {
        return 0;
    }
    if(n<0)
    {
        return -1;
    }
    int maxi;
    int A=func(n-a,a,b,c);
    int B=func(n-b,a,b,c);
    int C=func(n-c,a,b,c);
    maxi=max(A,B);
    maxi=max(maxi,C);

    if(maxi==-1)
    return -1;

    return maxi+1;
}
int main(){
    cout<<func(44,11,12,8)<<endl;
    return 0;
}