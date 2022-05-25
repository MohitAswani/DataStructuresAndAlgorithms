# Uses of LCS (Longest Common Subsequence) :

1) Diff utitlity : its used to find the difference between two files. This is used in version control systems like git.

2) Minimum insertions and deletions to convert one string to another string : LCS can be used to find the minimum number of insertions and deletions to convert one string to another string. Eg : "GEEK" and
"GEFK" in these two we need to perfomr 1 deletion and 1 insertion. So insertions : length of word1 - LCS length.  And deletions : length of word2 - LCS length.

3) Shortest common super sequence : is the strings which is subsequence of both the strings. To find this string we find the LCS and then traverse both the strings and insert the characters which are not present in LCS in the same order as they occur in the two strings.

4) Longest palindromic subsequence : in this we will be given a string and we need to find the longest subsequence which is palindromic. So we find the LCS of the given strings and its reverse.

5) Longest repeated subsequence : in this we need to find the subsequence of a given string which occurs more than one in the set of subsequences of that string. So to solve this problem we find the LCS of the given strings with itself in such a way that when the two characters match their indices must not match.

6) Space obtimized DP solution of LCS : in this we need to obtimize the LCS problem. So in the tabulation solution of LCS we can use only 2 rows because we only need the previous row to find the current row so we can use a matrix with only 2 rows. 

7) Printing LCS : done is the tabulation part.