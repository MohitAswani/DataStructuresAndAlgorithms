# Memoization

* In memoization instead of computing the same thing over and over again, we can store the result of the computation in memory and use that result instead of computing it again.

* Memoization is very easy to implement. We take the recursive solution and add a memo variable to it which stores the results of the previous computations. Hence memoization decreases the time complexity of the recursive solution to O(n) or smaller values compared to the recursive solution.

* The toughest part in DP problems is to come up with recursive solution which has overlapping subproblems.
Then we just make a memo variable , initialize it a value which is not possible and then we can use that memo variable to store the result of the previous computations in the recursive solution.

* We can use DP when the problem has overlapping subproblems.

* This is top down approach since we are breaking the main problem into sub-problems and solving the sub-problems.