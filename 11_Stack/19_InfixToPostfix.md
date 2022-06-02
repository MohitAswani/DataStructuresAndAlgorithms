# Infix to postfix conversion :

* We consider the following rules which converting : ![](2022-06-02-11-43-20.png)

* ![](2022-06-02-11-43-39.png)

## Naive approach :

* A naive approach is to convert the infix expression to postfix expression is to first paranethesise the expression and then convert the inner most expressions in postfix and then the outer expressions.

* Examples: ![](2022-06-02-11-46-16.png) ![](2022-06-02-11-49-24.png)

## Efficeint approach :

* Left paranethesis has the lowest precendence.

* Algorithm : ![](2022-06-02-12-02-48.png)

* When the precendence is same we consider the associativity. So if the associativity is L to R then current element is considered lower precedence, if its R to L then current element is considered higher precedence.

* Examples : ![](2022-06-02-12-03-19.png) ![](2022-06-02-12-04-02.png) ![](2022-06-02-12-04-24.png) ![](2022-06-02-12-05-00.png)

* Time complexity : O(n) (since we traverse the infex expression only once and also push and pop is O(1) time operations).