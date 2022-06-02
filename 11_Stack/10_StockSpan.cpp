#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In this problem we need to find the span of stocks.
 *
 * The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock is less than the price on the given day.
 *
 * In the naive approach we use two loops to find the solution.
 * 
 * Time complexity : O(n^2)
 * Auxillary space : O(1)
 * 
 * @param prices
 */
void stockSpanNaive(vector<ll> &prices)
{
    for (int i = 0; i < prices.size(); i++)
    {
        int span = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (prices[i] >= prices[j])
            {
                span++;
            }
            else
                break;
        }
        cout<<span<<" ";
    }
}

/**
 * @brief To solve this problem efficient we make the following observations :
 * 
 * 1) If there is greater element on the left side of the current element then the span is (Index of current element-Index of closest greater element on left side).
 * 
 * 2) Otherwise the span is index of current element + 1.
 * 
 * 3) To find the element greater than the current element we need all the elements which were greater than the previous element and we need them in LIFO order.
 * 
 * To better understand the solution watch the video : 'Stock span problem'
 * 
 * Time complexity : O(n)       // Since every element is push and pop only once hence at max the only 2n stack operations are performed hence the time complexity is O(n).
 * 
 * Auxillary space : O(n)      // Since at max only n elements can be present in the stack and that is when the elements are in decreasing order.
 * 
 * @param stock 
 */
void stockSpanEfficient(vector <ll> &stock)
{
    stack <int> stk;

    // Processing the first element
    stk.push(0);   // We storing index rather than element since we need index for calculating span
    cout<<1<<" ";  // Span of first element is always 1

    for(int i=1;i<stock.size();i++)
    {
        // In the below loop we are removing all the top items from the stack which are less than or equal to the current item.
        while(!stk.empty()&&stock[stk.top()]<=stock[i])   
        {
            stk.pop();
        }

        // If stack is empty then the current element is the greater element else there exists a greater element.
        int span = stk.empty()?i+1:i-stk.top();
        cout<<span<<" ";
        stk.push(i);
    }

}
int main()
{
    vector <ll> stocks={60,10,20,15,35,50};

    stockSpanNaive(stocks);
    cout<<endl;
    stockSpanEfficient(stocks);
    return 0;
}