# Tabulation

* Tabulation is a bottom up approach compared to memoization which is top down approach. 

* In tabulation we start from 0,1,2....and to till the value which we need to find. For example in fibonacci series we need to find the value at position n so we go from 0 to n. And we store the values of the dependencies(values which we need for our solution) in a table. 

* In general we fill the table in such a way that the dependencies are already filled when we are finding the value of the current cell. 

# Comparision between memoization and tabulation

* Memoization is easy to implement if we know the recursive solution for the problem. Most of the time when we see a problem we write the recursive solution and then we see if the sub-solutions are overlapping or not. If they are overlapping then we can use memoization.

* Tabulation is faster in comparision to memoization.And also there is no space requirred for recursive call overhead.