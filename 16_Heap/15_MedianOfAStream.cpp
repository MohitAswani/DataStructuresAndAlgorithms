#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In this solution we maitain two heaps, one is max heap with smaller elements and one is min heap with bigger elements.
 * 
 * Whenever we want to insert a new element when first compare the size of two heaps.
 * 
 * If smaller heap is bigger we push element into the larger heap.
 * 
 * We compare the top of smaller heap (max elem) with the element to be inserted, if the element to be inserted is less than the top then we push the top in the bigger heap and element in the smaller heap. If not we push the current element in the bigger heap.
 * 
 * Median is top of both heaps / 2.
 * 
 * If both heaps have same size we push the element into smaller heap.
 * 
 * We compare the top of smaller heap (max elem) with the element to be inserted, if the element to be inserted is less than or equal to the top then we push the element in the smaller heap. If not we push the current element in the bigger heap and the top of bigger heap (min element) in the smaller heap.
 * 
 * Median is the top of smaller element heap.
 * 
 * Time complexity : O(nlogk)
 * Auxillary space : O(n)
 * 
 * @param arr 
 */
void medianOfAStream(vector <ll> arr)
{
    priority_queue <ll> pq1;
    priority_queue <ll,vector<ll>,greater<ll>> pq2;

    pq1.push(arr[0]);
    cout<<arr[0]<<endl;

    for(int i=1;i<arr.size();i++)  // (n-1)
    {
        if(pq1.size()>pq2.size())
        {
            if(arr[i]<pq1.top())  // Log k
            {
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(arr[i]);
            }
            else
            {
                pq2.push(arr[i]);
            }
            cout<<(pq1.top()+pq2.top())/2.00<<endl;
        }
        else
        {  
            if(arr[i]<=pq1.top()) // Log k
            {
                pq1.push(arr[i]);
            }
            else
            {
                pq2.push(arr[i]);
                pq1.push(pq2.top());
                pq2.pop();
            }
            cout<<(pq1.top())<<endl;
        }
    }
}
int main(){
    vector <ll> arr={25,7,10,15,20};

    return 0;
}