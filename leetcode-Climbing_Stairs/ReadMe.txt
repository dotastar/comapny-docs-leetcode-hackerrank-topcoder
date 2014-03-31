You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


dozerg:
若先走1步，则剩余(n-1)步；
若先走2步，则剩余(n-2)步；
故有公式：
f(n) = f(n-1) + f(n-2)
即fabonacci数列