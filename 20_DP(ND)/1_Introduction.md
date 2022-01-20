# Dynamic programming:
 
* Dynamic programming is similiar to recursion (where we can use the same function to solve sub-problems), but instead of solving the same sub-problem over and over again we can store the result of the sub-problem and use it to solve the same sub-problem again.

* In simple words, it is an optimization over plain recursion.

* The idea is to reuse the solutions of sub-problems when there are overlapping sub-problems.

* There are two main ways to implement dynamic programming:
    * Memoization(Top down)
    * Tabulation(Bottom up)

## Applications of Dynamic programming:

* Bellman-Ford algorithm : to find the shortest path from a source vertex to all other vertices in a graph.

* Floyd Warshall algorithm : to find the shortest path between every pair of vertices in a graph.

* Diff utility (LCS) : use to find difference between two files using the longest common subsequence algorithm.

* Search close words (Edit distance) : use to find close words in a dictionary using edit distance algorithm.

* Resource allocation (0-1 knapsack) : find the optimal allocation of resources to maximize the value using 0-1 knapsack algorithm.