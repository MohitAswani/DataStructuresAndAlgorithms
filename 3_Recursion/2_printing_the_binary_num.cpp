#include<bits/stdc++.h>
using namespace std;
/**
 * @brief The below function finds the binary equivalent of a number using the divide by 2 logic.
 * 
 * Time complexity : O(logn)
 * Auxillary space : O(logn) due to recursive call stack
 * 
 * @param n 
 */
void binary(int n)
{
    if(n==0)
    return ;

    binary(n/2);
    cout<<n%2;
}
int main(){
    binary(8);
    return 0;
}