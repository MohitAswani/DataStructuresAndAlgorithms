# Variations of LIS :

1) Minimum deletions to make the array sorted : to find this value we simply delete the LIS from the length of the array.

2) Maximum increasing sum subsequence : in this problem we need to find the increasing subsequence with maximum sum.
    
    * We can solve this problem similiar to the dp implementation of the LIS and instead of storing the LIS we can store the sums of subsequence.

3) Maximium length bitonic subsequence : a bitonic subsequence is a one which first increases and then decreases.
    * To find the maximum length bitonic subsequence we find the LIS and LDS (longest decreasing subsequence) and find the maximum value of (lis[i]+lis[j]-1).

    * We can find lds by doing lis for the reversed vector.

    * This problem can be solved using dp in O(n^2) and bs in O(nlogn).

4) Building bridges : in this problem we will be pair of number which represent the bridges connecting two cities and we need to find the maximum number of bridges we can make so that there is no crossing.

    * To solve this problem we sort the array according to the first value of pair and if the first value is same we then sort it according to the second value.

    * After sorting we find the LIS of the sorted array corresponding to second values.

5) Longest chain of pairs : in this problem we are given an array of pair and we need to select a group of pair such that for all adjacent pairs (a,b) and (c,d) b < c (no collision).

    * To solve this problem we sort the array according to the first value.

    * Then we find the LIS of the sorted array.

    * This problem is similiar to the activity selection problem of greedy algorithm in which we found max number of acitivities which can be performed provided only one activity can happen at a time.