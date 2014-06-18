https://www.hackerrank.com/contests/w5/challenges/closest-number

You are given 3 numbers a, b and x. You need to output the multiple of x which is closest to ab. If more than one answer exists , display the smallest one.

Input Format 
The first line contains T, the number of testcases. 
T lines follow, each line contains 3 space separated integers (a, b and x respectively)

Output Format 
For each test case , output the multiple of x which is closest to ab

Constraints 
1 ¡Ü T ¡Ü 10^5 
1 ¡Ü x ¡Ü 10^9 
0 < a^b ¡Ü 10^9 
1 ¡Ü a ¡Ü 10^9 
-10^9 ¡Ü b ¡Ü 10^9

Sample Input

3
349 1 4
395 1 7
4 -2 2
Sample Output

348
392
0
Explanation

The closest multiple of 4 to 349 is 348. 
The closest multiple of 7 to 395 is 392. 
The closest multiple of 2 to 1/16 is 0.