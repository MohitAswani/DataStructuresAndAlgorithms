# Variations of LIS :

1) Minimum deletions to make the array sorted : to find this value we simply delete the LIS from the length of the array.

2) Maximum increasing sum subsequence : in this problem we need to find the increasing subsequence with maximum sum.
    
    * We can solve this problem similiar to the dp implementation of the LIS and instead of storing the LIS we can store the sums of subsequence.

3) Maximium length bitonic subsequence : a bitonic subsequence is a one which first increases and then decreases.
    * To find the maximum length bitonic subsequence we find the LIS and LDS (longest decreasing subsequence) and find the maximum value of (lis[i]+lis[j]-1).

    * We can find lds by doing lis for the reversed vector.

    * This problem can be solved using dp in O(n^2) and bs in O(nlogn).