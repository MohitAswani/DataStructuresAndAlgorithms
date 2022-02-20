#include <bits/stdc++.h>
using namespace std;
/**
 * @brief In this function we are trying to get the first set bit from the input number.
 * 
 * To find the first set bit we keep on shifting the bits to rights by 1 until we find one set bit or until the number becomes 0.
 * 
 * Time complexity : O(bits)
 * Auxillary space : O(1)
 * @param n 
 * @return unsigned int 
 */
unsigned int getFirstSetBit(int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            return res;

        n=n >> 1;
        res++;
    }
    return 0;
}
int main()
{
    cout<<getFirstSetBit(8)<<endl;
    return 0;
}