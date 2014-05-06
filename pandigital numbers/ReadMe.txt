https://projecteuler.net/problem=178

Step Numbers
Consider the number 45656. 
It can be seen that each pair of consecutive digits of 45656 has a difference of one.
A number for which every pair of consecutive digits has a difference of one is called a step number.
A pandigital number contains every decimal digit from 0 to 9 at least once.
How many pandigital step numbers less than 10^40 are there?



dozerg:
一个数10进制表示里面包含的digit情况，可以用10个bits标识，总共1024种情况。
令E(n, d, m)表示10进制长度为n的数中，有多少以d结尾且包含digit情况为m，其中0<=d<=9, 0<=m<=1023
那么有如下状态转换方程：
E(n+1, d, m) = SUM{E(n, d-1, mi)} + SUM{E(n, d+1, mj)}
其中：m == mi | (1 << d) == mj | (1 << d)

最终所求为：SUM{E(ni, di, 1023)}

