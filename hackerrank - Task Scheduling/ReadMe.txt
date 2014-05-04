https://www.hackerrank.com/challenges/task-scheduling


You have a long list of tasks that you need to do today. Task i is specified by the deadline by which you have to complete it (Di) and the number of minutes it will take you to complete the task (Mi). You need not complete a task at a stretch. You can complete a part of it, switch to another task and then switch back.

You’ve realized that it might not actually be possible complete all the tasks by their deadline, so you have decided to complete them so that the maximum amount by which a task’s completion time overshoots its deadline is minimized.

Input:
The first line contains the number of tasks T. Each of the next T lines contains two integers Di and Mi.

Output:
Output T lines. The ith line should contain the minimum maximum overshoot you can obtain by optimally scheduling the first i tasks on your list. See the sample input for clarification.

Constraints:
1 <= T <= 100000
1 <= Di <= 100000
1 <= Mi <= 1000

Sample Input:
5
2 2
1 1
4 3
10 1
2 1

Sample Output:
0
1
2
2
3

With only the first task, it can be completed in 2 minutes, and so you won’t overshoot the deadline.

 

With the first two tasks, the optimal schedule can be:
time 1: task 2
time 2: task 1 
time 3: task 1

We’ve overshot task 1 by 1 minute, hence returning 1 

 

With the first three tasks, the optimal schedule can be:
time 1 : task 2
time 2 : task 1
time 3 : task 3
time 4 : task 1
time 5 : task 3
time 6 : task 3

Task 1 has a deadline 2, and it finishes at time 4. So it exceeds its deadline by 2.
Task 2 has a deadline 1, and it finishes at time 1. So it exceeds its deadline by 0.
Task 3 has a deadline 4, and it finishes at time 6. So it exceeds its deadline by 2.

The maximum time by which you overshoot is thus 2. No schedule can do better than this.


dozerg:
将所有任务按到期时间d进行排序后，有如下规律：如果di < dj，则任务i必须先于任务j完成，才能保证最大超时最小。（反证法）
故对于任务i，其完成时间是:
S(i) = m1 + m2 + ... + mi
可以直接以di作为任务标识，即：S(di) = SUM{m[1], m[di]}
如果di有多个任务，将所有m累加即可。
超时为：
R(di) = S(di) - di

O(N^2)的做法是：
1. 增加任务时维持di有序，O(logN)；
2. 计算S(di) = SUM{m[1], m[di]}，O(N)；
总共N次循环，复杂度O(N*(logN + N)) = O(N^2)。

另一个变种是直接存S(di)，然后每次增加任务时更新S(di)及后面的所有S(d)，复杂度一样。


O(N*logN*logN)的做法：
根据上面变种的做法，可归结为2种操作：
1）更新S(di)及之后所有的S(d)；
2）查询任意R(di) = S(di) - di；
这种场景可以用Binary Index Tree来做，详见《Binary Indexed Trees.pdf》介绍。
这样2种操作都是O(logN)的复杂度。

但是仅仅这样还不够，当更新完S(d)之后，最大超时可能会变化。
假设之前最大超时在dx点，更新完S(di)后，有2种情况：
1）if di < dx，由于T(di)和T(dx)增加相同幅度，故最大超时还是在dx点；
2）else，T(di)及以后的T(d)都增加了，T(dx)未变，这时要重新计算最大超时点；
令I(di)表示di到100000之间的最大超时点
总结起来还是2种操作：
1）更新I(di)及以前的I(d)；
2）获取任意I(di)；
这里可以使用反向的Binary Index Tree，即index[1] = N, index[2] = N - 1,...

新增一个任务的步骤：
1. 更新S(di)；O(logN)
2. 获取di及之后的最大超时点dx=I(di)，计算超时时间R(dx) = S(dx) - dx；O(logN)
3. 根据dx和R(dx)更新di及之前的最大超时点：O(logN*logN)
	3.1 如果当前最大超时点的超时比R(dx)大，则无需修改；
	3.2 否则，需要修改最大超时点为dx；
4. 获取整体的最大超时点I(1)，返回其超时时间；O(logN)
总共N次循环，复杂度O(N*logN*logN)