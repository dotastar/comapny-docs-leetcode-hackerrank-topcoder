https://www.hackerrank.com/challenges/insertion-sort

Insertion Sort is a simple sorting technique which was covered in previous challenges. Sometimes, arrays may be too large for us to wait around for insertion sort to finish. Is there some other way we can calculate the number of times Insertion Sort shifts each elements when sorting an array?

If ki is the number of elements over which ith element of the array has to shift then total number of shift will be k1 + k2 + �� + kN.

Input:
The first line contains the number of test cases T. T test cases follow. The first line for each case contains N, the number of elements to be sorted. The next line contains N integers a[1],a[2]��,a[N].

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
First test case is already sorted therefore there��s no need to shift any element. In second case it will proceed in following way.

Array: 2 1 3 1 2 -> 1 2 3 1 2 -> 1 1 2 3 2 -> 1 1 2 2 3
Moves:   -        1       -    2         -  1            = 4



dozerg:
����������O(N^2)ת���ɹ鲢����O(NlogN)���������£�
input: 2 1 3 1 2
�鲢���̣�
2 1 + 3 1 2
2 1 -> 1 2 => 1 shift
3 1 2 = 3 + 1 2
3 => 0 shift
1 2 => 0 shift
3 + 1 2 -> 1 2 3 => 2 shift
1 2 + 1 2 3 -> 1 1 2 2 3 => 1 shift

total 4 shift

ԭ����ͣ�
1. ��������ǰ�벿�ֺͺ�벿�ֶ����ź�����ô�����������������������¹��ɣ�
ǰ�벿�֣�a1, a2, ..., ai
��벿�֣�b1, b2, ..., bj
��������ax��ǰ�治���ڱ����������
��������bx���� ay <= bx < a[y+1]����ǰ����(i-y)��������������ֱ���a[y+1], a[y+2], ..., ai��

2. ���������shift�������������������������shift����֮�ͣ���������merge��shift������


