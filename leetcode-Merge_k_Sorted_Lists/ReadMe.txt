Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.


dozerg:
算法复杂度分析：
假设k个list，平均每个list长度为n，
T(n, k) = T(2n, k/2) + nk   //每次合并后，list长度为2n，个数为k/2，合并过程中进行nk次操作
        = T(4n, k/4) + 2nk
        = ...
        = T(kn, 1) + log(k)*nk
令N=nk为node总数，那么最终复杂度为：O(N * logK)
