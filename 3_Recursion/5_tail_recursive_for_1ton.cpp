#include <bits/stdc++.h>
using namespace std;
/**
 * @brief 
 * A recursive function is said to be following Tail recursive if it invokes itself at the end of the function. That is, if all of the statements are executed before the function invokes itself then it is said to be following Tail Recursion.
 * 
 * The tail-recursive functions are considered better than non-tail recursive functions as tail-recursion can be optimized by the compiler. The idea used by compilers to optimize tail-recursive functions is simple, since the recursive call is the last statement, there is nothing left to do in the current function, so saving the current function’s stack frame is of no use.
 * 
 * The below function is tail recursive solution to print numbers from 1 to n.
 * 
 * @param n 
 * @param k 
 */
void func(int n,int k=1)
{
    if (k==n)
    {
        cout<<k<<endl;
        return;
    }
    cout<<k<<" ";
    func(n,k+1);
}
int main()
{
    func(5);
    return 0;
}