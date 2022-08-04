# Backtracking :

* Example of backtracking : Given a string, print all those permutations which do not contain "AB" as a substring.

* The naive approach to solve this problem is to find all the permutation and then check for the ones containing AB in them.

* The efficient approach is to keep on checking on every itteration whether the current string is valid or not and hence if its not prevent the further recursion and backtrack to the previous recursion.

* This will save us a lot of time and auxillary space.

* Backtracking is used to solve problem like n-queen and sudoku where at every recursive call we check whether the current state satisfies all the requirred conditions.
