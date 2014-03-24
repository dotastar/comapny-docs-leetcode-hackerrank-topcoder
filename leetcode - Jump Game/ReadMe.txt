I
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

思路： 从下标i开始，能走到的最远下标为i+A[i],且i~i+A[i]范围内都是可以走到的。
所以遍历A,不断更新能走到的最远下标即可。当最终max>=len-1，说明max以及max之前
的路径都是可以走到的，即包含在这之内的len-1这一位是可以走到的。


II
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)