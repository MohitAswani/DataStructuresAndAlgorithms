#include <bits/stdc++.h>
#define ll long long
using namespace std;


// The two solutions find the GCD using euclidean algorithm which is based on the following fact :
// GCD(A,B)=GCD(A-B,B) or GCD(A,B)=GCD(A%B,B)
//This is the MOST EFFICIENT WAY of finding GCD.


/**
 * @brief Based on the fact that GCD(A,B)=GCD(A%B,B).
 * 
 * Time complexity : O(log(min(a,b))).
 * Auxillary space : O(log(min(a,b))).
 * 
 * @param a 
 * @param b 
 * @return ll 
 */
ll gcd_rec(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd_rec(b,a%b);
}

/**
 * @brief Based on the fact that GCD(A,B)=GCD(A%B,B).
 * 
 * Time complexity : O(log(min(a,b))).
 * Auxillary space : O(1).
 * 
 * @param a 
 * @param b 
 * @return ll 
 */
ll gcd_itt(int a,int b)
{
    while(b!=0)
    {
        ll temp_a=a;
        a=b;
        b=temp_a%b;
    }
    return a;

    // Time complexity : O(log(min(a,b)))
    // Auxillary space : 1
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd_rec(a,b)<<endl;
    cout<<gcd_itt(a,b)<<endl;
    return 0;
}