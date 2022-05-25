#include<bits/stdc++.h>
using namespace std;
/**
 * @brief To find the odd one occuring we use the fact that the ^ of the number will itself is zero hence taking the ^ of number which occurs even times will give zero. So taking the xor of all the number will leave us with a zero and the number which occurs odd times. 
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param arr 
 * @return int 
 */
int odd_one(vector <int> arr)
{
    int x=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        x=x^arr[i];
    }
    return x;
}
int main(){
    vector <int> v;
    v={4,3,3,4,4,5,5};
    cout<<"ODD ONE OCCURING :"<<odd_one(v)<<endl;
    return 0;
}