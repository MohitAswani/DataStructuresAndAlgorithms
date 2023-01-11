#include<bits/stdc++.h>
using namespace std;
/**
 * @brief In this problem we think recursively.
 * To move n disks from A to C we first need to move n-1 disks from A to B. Then we need to move the n th disk from A to C and then we move the rest of the disks from B to C.
 * 
 * So the recursive solution is fun(n,A,B,C)=fun(n-1,A,C,B)(n-1 disks from A to B using C)+fun(n-1,B,A,C)(n-1 disks from B to C using A)
 * 
 * We come up with this solution using a bottom up approach when we consider 1 disk,2 disks,3 disks and so on.
 * 
 * The total number of moves for n disks will be moves(n)=2*moves(n-1)+1. So this comes out to 2^n-1.
 * 
 * Time complexity : O(2^n).
 * Auxillary space : O(n)
 * 
 * @param k 
 * @param source 
 * @param auxillary 
 * @param destination 
 */
void tower_of_hanoi(int k,char source='A',char auxillary='B',char destination='C')
{
    if(k==0)
    {
        return ;
    }
    tower_of_hanoi(k-1,source,destination,auxillary);
    cout<<"MOVING DISK "<<k<<" FROM "<<source<<" TO "<<destination<<endl;
    tower_of_hanoi(k-1,auxillary,source,destination);
}
int main(){
    tower_of_hanoi(4);
    return 0;
}