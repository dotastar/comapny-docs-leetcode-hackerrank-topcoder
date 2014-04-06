A non-empty zero-indexed array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P < Q < N, is called a slice of array A (notice that the slice contains at least two elements). The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).
For example, array A such that:
    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8
contains the following example slices:
slice (1, 2), whose average is (2 + 2) / 2 = 2;
slice (3, 4), whose average is (5 + 1) / 2 = 3;
slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.
The goal is to find the starting position of a slice whose average is minimal.
Write a function:
int solution(vector<int> &A);
that, given a non-empty zero-indexed array A consisting of N integers, returns the starting position of the slice with the minimal average. If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.
For example, given array A such that:
    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8
the function should return 1, as explained above.
Assume that:
N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−10,000..10,000].
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.


dozerg:
使用首位指针(h, t)表示当前slice，则有：
如果只有2个元素，那么只能++t，直到数组结束；
否则：（优先缩短slice）
	如果A[h] > ave，说明去掉h会降低ave，故++h；
	如果A[t+1] > ave，说明增加t会提高ave，故仍然++h；
	如果t到数组尾，只能++h；
	否则，增加t会降低ave，故++t；

others：
关窍在于一个slice要么是2个元素组成，要么是3个元素组成。
因为如果是规模>3的slice，那么整体的avg必然不可能小于这
个slice分割成的子slice（规模为2或3）的avg，所以在只考虑
slice的规模为2和3的情况下，线性复杂度就很好实现了。