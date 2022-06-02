# Infix to prefix conversion :

* We consider the following rules which converting : ![](2022-06-02-11-43-20.png)

* ![](2022-06-02-12-15-30.png)

## Naive approach :

* A naive approach is to convert the infix expression to prefix expression is to first paranethesise the expression based on associavity, precedence and paranthesis and then convert the inner most expressions to prefix and then the outer expressions.

* Examples : ![](2022-06-02-12-18-55.png), ![](2022-06-02-12-21-32.png)

## Efficeint approach :

* Operator precedence : ![](2022-06-02-13-46-30.png)

* Algorithm : ![](2022-06-02-13-47-56.png)

* When the precendence is same we consider the associativity. So if the associativity is L to R then current element is considered higher precedence (coz of reverse order), if its R to L then current element is considered lower precedence(coz of reverse order).

* Examples : ![](2022-06-02-13-48-31.png) ![](2022-06-02-13-49-40.png) ![](2022-06-02-13-49-58.png) 

* In the following example + and - have the same precedence and hence we use associasivity which is L to R hence the current + will be considered as having higher precendence and hence will be pushed. ![](2022-06-02-13-50-27.png)

* Time ocmplexity : O(n) where n is the length of the expression.