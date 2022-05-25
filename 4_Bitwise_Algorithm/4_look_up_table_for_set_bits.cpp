#include<bits/stdc++.h>
using namespace std;
int table[256];
void initialize()
{
    table[0]=0;
    for(int i=1;i<256;i++)
    {
        table[i]=(i&1)+table[i/2];
    }
}
/**
 * @brief The most efficient way O(1)(because of preprocessing) of finding the number of set bits for mutliple large numbers is to use lookup table. 
 * 
 * In this method we find the number of set bits in the numbers from 0 to 255 using the fact that number of set bits in x = (i&1) + set bits in x/2. 
 * 
 * Then to find the set bits we break the large number in parts of 8 bits and find the set bits using the lookup table.
 * 
 * Time complexity : O(C)
 * Space complexity : O(C)
 * 
 * @param n 
 * @return int 
 */
int count(int32_t n)
{
     //in this function we are initializing the number of sets bits in numbers from 0 to 255
    int res=0;
    res=table[n&0xff];  //here we are breaking the number in 8 bits and then find its set bits
    n=n>>8;
    res+=table[n&0xff];
    n=n>>8;
    res+=table[n&0xff];
    n=n>>8;
    res+=table[n&0xff];
    return res;
}
int main(){
    initialize();
    cout<<"NUMBER OF SET BITS : "<<count(255)<<endl;
    return 0;
}