https://www.hackerrank.com/challenges/task-scheduling


You have a long list of tasks that you need to do today. Task i is specified by the deadline by which you have to complete it (Di) and the number of minutes it will take you to complete the task (Mi). You need not complete a task at a stretch. You can complete a part of it, switch to another task and then switch back.

You��ve realized that it might not actually be possible complete all the tasks by their deadline, so you have decided to complete them so that the maximum amount by which a task��s completion time overshoots its deadline is minimized.

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

With only the first task, it can be completed in 2 minutes, and so you won��t overshoot the deadline.

 

With the first two tasks, the optimal schedule can be:
time 1: task 2
time 2: task 1 
time 3: task 1

We��ve overshot task 1 by 1 minute, hence returning 1 

 

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
���������񰴵���ʱ��d��������������¹��ɣ����di < dj��������i������������j��ɣ����ܱ�֤���ʱ��С������֤����
�ʶ�������i�������ʱ����:
S(i) = m1 + m2 + ... + mi
����ֱ����di��Ϊ�����ʶ������S(di) = SUM{m[1], m[di]}
���di�ж�����񣬽�����m�ۼӼ��ɡ�
��ʱΪ��
R(di) = S(di) - di

O(N^2)�������ǣ�
1. ��������ʱά��di����O(logN)��
2. ����S(di) = SUM{m[1], m[di]}��O(N)��
�ܹ�N��ѭ�������Ӷ�O(N*(logN + N)) = O(N^2)��

��һ��������ֱ�Ӵ�S(di)��Ȼ��ÿ����������ʱ����S(di)�����������S(d)�����Ӷ�һ����


O(N*logN*logN)��������
����������ֵ��������ɹ��Ϊ2�ֲ�����
1������S(di)��֮�����е�S(d)��
2����ѯ����R(di) = S(di) - di��
���ֳ���������Binary Index Tree�����������Binary Indexed Trees.pdf�����ܡ�
����2�ֲ�������O(logN)�ĸ��Ӷȡ�

���ǽ�����������������������S(d)֮�����ʱ���ܻ�仯��
����֮ǰ���ʱ��dx�㣬������S(di)����2�������
1��if di < dx������T(di)��T(dx)������ͬ���ȣ������ʱ������dx�㣻
2��else��T(di)���Ժ��T(d)�������ˣ�T(dx)δ�䣬��ʱҪ���¼������ʱ�㣻
��I(di)��ʾdi��100000֮������ʱ��
�ܽ���������2�ֲ�����
1������I(di)����ǰ��I(d)��
2����ȡ����I(di)��
�������ʹ�÷����Binary Index Tree����index[1] = N, index[2] = N - 1,...

����һ������Ĳ��裺
1. ����S(di)��O(logN)
2. ��ȡdi��֮������ʱ��dx=I(di)�����㳬ʱʱ��R(dx) = S(dx) - dx��O(logN)
3. ����dx��R(dx)����di��֮ǰ�����ʱ�㣺O(logN*logN)
	3.1 �����ǰ���ʱ��ĳ�ʱ��R(dx)���������޸ģ�
	3.2 ������Ҫ�޸����ʱ��Ϊdx��
4. ��ȡ��������ʱ��I(1)�������䳬ʱʱ�䣻O(logN)
�ܹ�N��ѭ�������Ӷ�O(N*logN*logN)