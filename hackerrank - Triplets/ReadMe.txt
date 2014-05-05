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
��������λ�õ�d[i]�����֪��[0,i)֮����x����С��d[i]���Լ�[i+1, end)֮����y��������d[i]����ΪP(i)={x, y}������d[i]Ϊ�м�����triple����ΪT(i)=x*y��
�����������������ظ�������������ظ�2�Σ����Է������£�
��d[i] == d[j], i < j����һ���ظ���Ԫ�أ���
P(i) = {xi, yi}
P(j) = {xj, yj}
�������¹��ɣ�
1�����xi == xj����˵��С��d[i]��Ԫ�غ�С��d[j]��Ԫ����ȫһ����
2�����xi < xj����˵������С��d[j]��Ԫ������d[i]֮��
3��������xi > xj��
����yi��yjҲ�����ƵĹ��ɡ�
��d[i]��d[j]Ϊ�м�����triple�����ֱ�Ϊ��
T(i) = xi*yi
T(j) = xj*yj
�����ظ���triple����Ϊ��
C��i, j) = MIN(xi, xj)*MIN(yi, yj) = xi * yj
����d[i]��d[j]Ϊ�м����Ĳ��ظ�triple����Ϊ��
T(i, j) = T(i) + T(j) - C(i,j)

����P(i)={x, y}ʱ��Ϊ�˴ﵽO(logN)��Ч�ʣ���Ҫʹ��Binary Index Tree�������Binary Indexed Trees.pdf������
ͬʱΪ�˽�ʡ�ڴ�ʹ��������Ҫ��hash table�洢BIT�������ǳ��õ����顣