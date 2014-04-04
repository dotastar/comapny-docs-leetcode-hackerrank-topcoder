I
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?


������ָ��p1��p2ָ���ͷ��ÿ��ѭ��ʱp1ָ�����ĺ�̣�
p2ָ������̵ĺ�̡���p2�ĺ��ΪNULL����������û�л���
�����л���p1==p2ʱѭ��������ֹ����ʱΪ��Ѱ�һ�����ڣ�
��p1����ָ���ͷ����Ȼÿ��ѭ����ָ���̣�p2ÿ��Ҳָ
���̡���p1��p2�ٴ����ʱ����ȵ���ǻ�����ڡ�

dozerg:
��������л����֮ǰ��������a���ڵ㣬����b���ڵ㣻
��һ��fastָ��ÿ����2����slowָ��ÿ����1����
��������λ�þ໷�������c���ڵ㣬��ô�����¹�ϵ��
fast = 2*slow
fast = a + N*b + c  //fast������slow֮ǰ���Ѿ��ƻ�N����
slow = a + c
�ɴ˿��Եõ���
c = N*b - a     //��Ȼ�����b >= a����ôN=1����֮��N=(a+b-1)/b

�ڶ��֣�fast����������ÿ��1����slow��c������ÿ��1����
��fast�ߵ������ʱ
fast = a
slow = c + a = N*b
��slowҲ�ڻ�����ڣ���fast��slow�������ڻ���ڡ�