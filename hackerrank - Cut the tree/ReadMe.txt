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
3 ≤ N ≤ 10^5
1 ≤ number written on each vertex ≤ 1001

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
假设所有节点的值的和为S，则有S = F(T1) + F(T2)，即只要知道了F(T1)，也就知道了F(T2)；
如果求出所有边的F(T1)，就能知道最小的Tree_diff(T)；

首先，定义某条边的F(T1)为E所连的子树所有节点的和（其实方向不重要），记为F(E);
要求F(E)可以用递归方式：
1. 假设子树的根节点是N，则先求出N的其他边（除E之外）的F(E1)和F(E2)（一个节点最多只有3个边）；
2. 则F(E) = N + F(E1) + F(E2)，可以这样理解：子树所有节点的和，等于根节点的值，加上其左右子树的节点和；

其实，根据树的特性，可以从任意节点开始计算，递归得到所有边的F(E)。
递归层数为节点个数N，最后遍历所有边得到结果。
总体时间复杂度O(N)。