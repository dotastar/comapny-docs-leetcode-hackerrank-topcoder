http://www.careercup.com/question?id=5083698865111040

Given a amount and several denominations of coins, find all 
possible ways that amount can be formed?
eg amount = 5, denominations = 1,2,3. 
Ans- 5 ways 
1) 1,1,1,1,1 
2) 1,1,1,2 (combinations aren't counted eg 1,2,1,1 etc) 
3) 1,1,3 
4) 1,2,2 
5) 2,3

dozerg:
令T(i, j)表示A[1...i]有多少种组合，总额是j，则有状态转换方程：
T(i, j) = T(i - 1, j) + T(i, j - A[i])



follow up:
Give an algorithm which makes change for an amount of money C with as few coins as possible.
Return the minimum count of coins, or -1 if there is no way to make chages.

dozerg:
令T(i, j)表示A[1...i]需要最少的coins数，总额是j，则有状态转换方程：
T(i, j) = MIN{T(i - 1, j), T(i, j - A[i]) + 1}