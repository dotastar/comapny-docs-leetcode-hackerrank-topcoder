https://www.hackerrank.com/contests/w2/challenges/cut-the-tree


Atul is into graph theory, and he is learning about trees nowadays. He observed that the removal of an edge from a given tree T will result in formation of two separate trees T1 and T2.

Each vertex of the tree T is assigned a positive integer. Your task is to remove an edge, such that, the Tree_diff of the resultant trees is minimized. Tree_diff is defined as

 F(T) = Sum of numbers written on each vertex of a Tree T
 Tree_diff(T) = abs(F(T1) - F(T2))
Input Format
The first line will contain an integer N, i.e., the number of vertices in the tree.
The next line will contain N integers separated by a single space, i.e., the values assigned to each of the vertices.
The next (N-1) lines contain pair of integers separated by a single space and denote the edges of the tree.
In the above input, the vertices are numbered from 1 to N.

Output Format
A single line containing the minimum value of Tree_diff.

Constraints
3 �� N �� 10^5
1 �� number written on each vertex �� 1001

Sample Input

6
100 200 100 500 100 600
1 2
2 3
2 5
4 5
5 6
Sample Output

400
Explanation

Cutting the edge at 1 2 would result in Tree_diff = 1400
Cutting the edge at 2 3 would result in Tree_diff = 1400
Cutting the edge at 2 5 would result in Tree_diff = 800
Cutting the edge at 4 5 would result in Tree_diff = 600
Cutting the edge at 5 6 would result in Tree_diff = 400

Hence, the answer is 400.


dozerg:
�������нڵ��ֵ�ĺ�ΪS������S = F(T1) + F(T2)����ֻҪ֪����F(T1)��Ҳ��֪����F(T2)��
���������бߵ�F(T1)������֪����С��Tree_diff(T)��

���ȣ�����ĳ���ߵ�F(T1)ΪE�������������нڵ�ĺͣ���ʵ������Ҫ������ΪF(E);
Ҫ��F(E)�����õݹ鷽ʽ��
1. ���������ĸ��ڵ���N���������N�������ߣ���E֮�⣩��F(E1)��F(E2)��һ���ڵ����ֻ��3���ߣ���
2. ��F(E) = N + F(E1) + F(E2)������������⣺�������нڵ�ĺͣ����ڸ��ڵ��ֵ�����������������Ľڵ�ͣ�

��ʵ�������������ԣ����Դ�����ڵ㿪ʼ���㣬�ݹ�õ����бߵ�F(E)��
�ݹ����Ϊ�ڵ����N�����������бߵõ������
����ʱ�临�Ӷ�O(N)��