#include <bits/stdc++.h>
using namespace std;
/**
 * @brief 
 * 
 * Time complexity : O(n)
 * Auxillary space : O(n) due to recursive call stack
 * 
 * @param n 
 */
void func(int n)
{
    if (n == 0)
    {
        return;
    }
    func(n - 1);
    cout<<n<<" ";
}
int main()
{
    func(5);
    return 0;
}