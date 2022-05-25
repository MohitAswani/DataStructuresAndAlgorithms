#include<bits/stdc++.h>
using namespace std;
/**
 * @brief In the below we are checking whether the k th bit is set using the left shift operator. 
 * 
 * To do so we shift 1 by k bits to left and find the & with n. If it is not zero we return zero.
 * 
 * Time complexity : O(1)
 * Auxillary space : O(1)
 * @param n 
 * @param k 
 * @return true 
 * @return false 
 */
bool func_left_shift(int n,int k){
    return (n&(1<<(k-1))!=0);
}
/**
 * @brief In the below we are checking whether the k th bit is set using the right shift operator.
 * 
 * To do so we shift n by k-1 bits. Then we find the mod 2 to get the last bit.
 * 
 * Time complexity : O(1)
 * Auxillary space : O(1)
 * 
 * @param n 
 * @param k 
 * @return true 
 * @return false 
 */
bool func_right_shift(int n,int k){
    return (n>>(k-1))%2==1;
}
int main(){
    int N=0;
    int K=2;
    cout<<boolalpha;
    cout<<func_left_shift(N,K)<<endl;
    cout<<func_right_shift(N,K)<<endl;
    cout<<noboolalpha;
    return 0;
}