A non-empty zero-indexed array A consisting of N integers is given.
A monotonic_pair is a pair of integers (P, Q), such that 0 ≤ P ≤ Q < N and A[P] ≤ A[Q].
The goal is to find the monotonic_pair whose indices are the furthest apart. More precisely, we should maximize the value Q − P. It is sufficient to find only the distance.
For example, consider array A such that:
    A[0] = 5
    A[1] = 3
    A[2] = 6
    A[3] = 3
    A[4] = 4
    A[5] = 2
There are eleven monotonic_pairs: (0,0), (0, 2), (1, 1), (1, 2), (1, 3), (1, 4), (2, 2), (3, 3), (3, 4), (4, 4), (5, 5). The biggest distance is 3, in the pair (1, 4).
Write a function:
int solution(vector<int> &A);
that, given a non-empty zero-indexed array A of N integers, returns the biggest distance within any of the monotonic_pairs.
For example, given:
    A[0] = 5
    A[1] = 3
    A[2] = 6
    A[3] = 3
    A[4] = 4
    A[5] = 2
the function should return 3, as explained above.
Assume that:
N is an integer within the range [1..300,000];
each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.



dozerg:
对iris算法的解释：
假设下标对(i, j)为所求结果，0 <= i <= j < N，则有如下结论：
1）A[i]是A[0...i]中最小的。反证：如果存在i' < i，且A[i'] < A[i]，则下标对(i', j)才是所求结果，所以i'不存在；
2）A[j]是A[j...N-1]中最大的。反证法同上。

故先将所有可能的i，存入lefti队列中；
将所有可能的j，存入righti栈中；
循环处理以下逻辑：
        if (lefti.front() > righti.back()){
            righti.pop_back();	//i > j，故j向后移
        } else if (A[lefti.front()] <= A[righti.back()]){
            r = max(r, righti.back() - lefti.front());	//找到可能的一对(i, j)
            righti.pop_back();	//j后移，检查是否有更好的结果
        } else
            lefti.pop_front();	//A[i] > A[j]，则i后移，寻找更小的A[i]
