I
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

˼·�� ���±�i��ʼ�����ߵ�����Զ�±�Ϊi+A[i],��i~i+A[i]��Χ�ڶ��ǿ����ߵ��ġ�
���Ա���A,���ϸ������ߵ�����Զ�±꼴�ɡ�������max>=len-1��˵��max�Լ�max֮ǰ
��·�����ǿ����ߵ��ģ�����������֮�ڵ�len-1��һλ�ǿ����ߵ��ġ�


II
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)