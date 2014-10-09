Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

dozerg:
令S(i)={MAX1, MAX2}表示子序列A[0, i)的乘积中的2个值，其中：
MAX1表示绝对值最大的正整数；
MAX2表示绝对值最大的负整数；

则有状态转换方程：
if A[i] >= 0:
  S(i+1) = {
    MAX1 = max(A[i], S(i).MAX1 * A[i]),
    MAX2 = S(i).MAX2 * A[i],
  };
else if A[i] < 0:
  S(i+1) = {
    MAX1 = S(i).MAX2 * A[i],
	MAX2 = min(A[i], S(i).MAX1 * A[i]),
  }

S(1) = {A[0], A[0]}
所有MAX1中的最大值，就是所求。