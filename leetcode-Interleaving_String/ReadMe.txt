Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.


dozerg:
令T(i, j)表示s1.substr(0, i)和s2.substr(0, j)是否可生成s3.substr(0, i + j)，则状态转换方程为：
T(i, j) = (T(i - 1, j) && s1[i - 1] == s3[i + j - 1])
       || (T(i, j - 1) && s2[j - 1] == s3[i + j - 1])
T(0, 0) = true