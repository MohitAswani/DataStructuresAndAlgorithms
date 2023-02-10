#include<bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief This is the most efficient code for finding the number of digits in a number.
 * 
 * Time complexity : O(1).
 * Auxillary space : O(1). 
 * 
 * @param n 
 * @return long long 
 */
long long digits(int n)
{
    return floor(log10(n)+1);
}
int main(){
    int n;
    cin>>n;
    cout<<digits(n)<<endl;
    return 0;
}