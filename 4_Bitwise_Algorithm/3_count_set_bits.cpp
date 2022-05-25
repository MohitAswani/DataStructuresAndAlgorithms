#include <bits/stdc++.h>
using namespace std;
/**
 * @brief In the below solution we are itterating through all the bits of a number and counting the set bits.
 * 
 * Time complexity : O(bits)
 * Auxillary space : O(1)
 * 
 * @param n 
 * @return int 
 */
int simple_1(int n)
{
    int res = 0;
    while (n > 0)
    {
        res+=(n&1);

        n=n>>1;
    }
    return res;
}
/**
 * @brief To find the number of set bits we use a special logic.
 * 
 * LOGIC : WHEN WE FIND N-1 ALL THE UNSET BITS BEFORE THE FIRST SET BIT TURN ON. AND THE FIRST SET BIT TURNS OFF. WHEN WE FIRST THE AND OF N AND N-1 THE LAST SET BIT TURNS OFF. SO BY FIND N&N-1 WE CAN ONLY ITERATE THROUGH ALL THE SET BITS ONLY. 
 * 
 * Time complexity : O(set bits)
 * Auxillary space : O(1)
 * @param n 
 * @return int 
 */
int b_and_k_algo(int n)
{
    int res=0;
    while(n>0)
    {
        n=(n&(n-1));
        res++;
    }
    return res++;
}
int main()
{
    cout << "NUMBER OF SET BITS :" << simple_1(8) << endl;
    cout << "NUMBER OF SET BITS :" << b_and_k_algo(8) << endl;
    return 0;
}