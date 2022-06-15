#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief
 *
 * PROBLEM : In this problem we are given the amount of petrol present at each station and we the distance from the next petrol station assuming all of them are in a circle. We need to find the petrol station from where we can successful go around the whole circle else return -1.
 *
 * Naive solution : We will apply the brute force approach and for each petrol pump check whether we can go arround the whole circle.
 *
 * Time complexity : O(n^2)
 * Auxillary space : O(1)
 * 
 * @param petrol
 * @param dist
 * @return ll
 */
ll CircularTourNaive(vector<ll> &petrol, vector<ll> &dist)
{
    for (ll start = 0; start < petrol.size(); start++)
    {
        int currPetrol = 0;
        int end = start;

        while (true)
        {
            currPetrol += petrol[end] - dist[end];

            if (currPetrol < 0)
                break;

            end = (end + 1) % (petrol.size());   // increasing the n in a circular way.
            if (end == start)
            {
                return start + 1;
            }
        }
    }

    return -1;
}

/**
 * @brief 
 * 
 * BETTER SOLUTION : In this solution we do the following :
 * 
 * Keep on adding the petrol pumps to the end of the deque while curr_petrol is >=0.
 * 
 * Keep removing items from the front of deque while curr_petrol<0.
 * 
 * @param petrol 
 * @param dist 
 * @return ll 
 */
ll CircularTourBetter(vector<ll> &petrol, vector<ll> &dist)
{
    
}
/**
 * @brief Idea behind this solution is that if curr_petrol becomes negative at pi then none of the petrol pumps from p0 to pi can be the solution.
 * 
 * So we will start finding the curr_petrol from p(i+1) and if it again becomes negative we add it to the prev_petrol.
 * 
 * Adding doing that we take the final current_petrol and add it to the final prev_petrol and check if its positive if yes then we return the index just next to the one will last negative current_petrol.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param petrol 
 * @param dist 
 * @return ll 
 */
ll CircularTourEfficient(vector<ll> &petrol, vector<ll> &dist)
{
    int start=0,curr_pet=0;
    int prev_pet=0;

    for(int i=0;i<petrol.size();i++)
    {
        curr_pet+=petrol[i]-dist[i];

        if(curr_pet<0)
        {
            start=i+1;
            prev_pet+=curr_pet;
            curr_pet=0;
        }
    }

    return ((prev_pet+curr_pet)>=0)?(start+1):-1;
}
int main()
{
    return 0;
}