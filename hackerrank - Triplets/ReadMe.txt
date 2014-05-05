https://www.hackerrank.com/challenges/triplets

There is an integer array d which does not contain more than two elements of the same value. How many distinct ascending triples (d[i] < d[j] < d[k], i < j < k) are present? 

Input format
The first line contains an integer N denoting the number of elements in the array. This is followed by a single line containing N integers separated by a single space with no leading/trailing spaces

Output format:
A single integer that denotes the number of distinct ascending triples present in the array

Constraints:
N <= 10^5
Every element of the array is present at most twice
Every element of the array is a 32-bit non-negative integer

Sample input:
6
1 1 2 2 3 4

Sample output:
4

Explanation:
The distinct triplets are
(1,2,3)
(1,2,4)
(1,3,4)
(2,3,4)

  The elements of the array might not be sorted. Make no assumptions of the same.


Bobthebuilder24:
You should note that you only need to know the number of elements that are smaller/larger than a particular element to know how many triples it serves as the middle point for. Using this you can calculate the number of triples quite easily, the only remaining problem is to get rid of duplicates, but given that you are limited to at most 2 of the same element, this is trivial.

I solved using a Binary Index Tree http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binaryIndexedTrees .

I also did a small write up, http://www.kesannmcclean.com/?p=223 .


dozerg:
对于任意位置的d[i]，如果知道[0,i)之间有x个数小于d[i]，以及[i+1, end)之间有y个数大于d[i]，记为P(i)={x, y}，则以d[i]为中间数的triple个数为T(i)=x*y。
但是由于数组中有重复的数，且最多重复2次，可以分析如下：
令d[i] == d[j], i < j，是一对重复的元素，且
P(i) = {xi, yi}
P(j) = {xj, yj}
则有如下规律：
1）如果xi == xj，则说明小于d[i]的元素和小于d[j]的元素完全一样；
2）如果xi < xj，则说明部分小于d[j]的元素排在d[i]之后；
3）不可能xi > xj。
对于yi和yj也有类似的规律。
以d[i]和d[j]为中间数的triple个数分别为：
T(i) = xi*yi
T(j) = xj*yj
其中重复的triple个数为：
C（i, j) = MIN(xi, xj)*MIN(yi, yj) = xi * yj
故以d[i]和d[j]为中间数的不重复triple个数为：
T(i, j) = T(i) + T(j) - C(i,j)

计算P(i)={x, y}时，为了达到O(logN)的效率，需要使用Binary Index Tree（详见《Binary Indexed Trees.pdf》）。
同时为了节省内存使用量，需要用hash table存储BIT，而不是常用的数组。