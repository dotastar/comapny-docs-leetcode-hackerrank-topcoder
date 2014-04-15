https://www.hackerrank.com/challenges/insertion-sort

Insertion Sort is a simple sorting technique which was covered in previous challenges. Sometimes, arrays may be too large for us to wait around for insertion sort to finish. Is there some other way we can calculate the number of times Insertion Sort shifts each elements when sorting an array?

If ki is the number of elements over which ith element of the array has to shift then total number of shift will be k1 + k2 + … + kN.

Input:
The first line contains the number of test cases T. T test cases follow. The first line for each case contains N, the number of elements to be sorted. The next line contains N integers a[1],a[2]…,a[N].

Output:
Output T lines, containing the required answer for each test case.

Constraints:
1 <= T <= 5
1 <= N <= 100000
1 <= a[i] <= 1000000

Sample Input:

2  
5  
1 1 1 2 2  
5  
2 1 3 1 2
Sample Output:

0  
4   
Explanation
First test case is already sorted therefore there’s no need to shift any element. In second case it will proceed in following way.

Array: 2 1 3 1 2 -> 1 2 3 1 2 -> 1 1 2 3 2 -> 1 1 2 2 3
Moves:   -        1       -    2         -  1            = 4



dozerg:
将插入排序O(N^2)转换成归并排序O(NlogN)，流程如下：
input: 2 1 3 1 2
归并过程：
2 1 + 3 1 2
2 1 -> 1 2 => 1 shift
3 1 2 = 3 + 1 2
3 => 0 shift
1 2 => 0 shift
3 + 1 2 -> 1 2 3 => 2 shift
1 2 + 1 2 3 -> 1 1 2 2 3 => 1 shift

total 4 shift

原理解释：
1. 如果数组的前半部分和后半部分都已排好序，那么整个数组的逆序对数，有如下规律：
前半部分：a1, a2, ..., ai
后半部分：b1, b2, ..., bj
对于任意ax，前面不存在比它大的数。
对于任意bx，令 ay <= bx < a[y+1]，则前面有(i-y)个比它大的数，分别是a[y+1], a[y+2], ..., ai。

2. 整个数组的shift次数，等于任意子数组排序的shift次数之和，加上最终merge的shift次数。


