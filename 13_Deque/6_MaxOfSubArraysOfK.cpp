#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/*
 * Problem : We are given a array and we need to find the maximum of every subarray of size k.
 *
 */

/**
 * @brief In this implementation traverse through the array and maintain a deque.
 * 
 * Our deque is such that on encoutering an element bigger than our front we pop the whole queue and add the element to the front ( since this element will stay in the group longer than all the element that were present earlier)
 * 
 * On encountering a smaller element we push to the back of the queue such that it is the smallest element in the queue and all the elements smaller than it are popped out.
 * 
 * And then we keep on printing the front of the queue.
 * 
 * Watch the video 'Maximums of all subarrays of size k' for better understanding.
 * 
 * Time complexity : O(n) ( Since every element enter and leaves the deque exactly once)
 * Auxillary space : O(k)
 * 
 * @param arr 
 * @param k 
 */
void MaxOfSubArrayK(vector <ll> arr,ll k)
{
    deque <ll> dq(k);

    for(ll i=0;i<k;i++)
    {

        // Adding smaller elements to the back and popping all the elements smaller than new element.
        while(!dq.empty()&&arr[i]>=arr[dq.back()])   
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    for(ll i=k;i<arr.size();i++)
    {
        cout<<arr[dq.front()]<<" "; // printing the front/largest element.

        // Removing the elements not part of the window
        while(!dq.empty()&&dq.front()<=i-k)
        {
            dq.pop_front();
        }

        // Removing all the smaller element than the current element.
        while(!dq.empty()&&arr[i]>=arr[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    cout<<arr[dq.front()]<<endl; // For the last iteration
}
int main()
{
    vector <ll> arr={20,40,30,10,60};
    MaxOfSubArrayK(arr,3);
    return 0;
}