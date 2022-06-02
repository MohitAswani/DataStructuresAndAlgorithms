# Evaluating postfix expressions :

* Algorithms : * Idea to evaluate postfix expression is to simply apply a operator on the last two operands.

* To implement this we use the following algorithm :  ![](2022-06-02-12-10-54.png)

* Examples : ![](2022-06-02-12-11-26.png) ![](2022-06-02-12-11-55.png)

* Time complexity : O(n) (1 traversal , no use of precedence , associativity and paranthesis).

* In infix to postfix we maintain a stack of operators in postfix evaluation we maintain a stack of operands.