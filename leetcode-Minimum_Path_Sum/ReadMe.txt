Given a m x n grid filled with non-negative numbers, find a path 
from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.




dozerg:
令T(i, j)为到达(i, j)位置时的最小路径和，状态转移方程为：
T(i, j) = min{T(i - 1,j), T(i, j - 1)} + A[i][j]
故为2维DP