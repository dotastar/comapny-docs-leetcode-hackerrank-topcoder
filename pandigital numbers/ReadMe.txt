https://projecteuler.net/problem=178

Step Numbers
Consider the number 45656. 
It can be seen that each pair of consecutive digits of 45656 has a difference of one.
A number for which every pair of consecutive digits has a difference of one is called a step number.
A pandigital number contains every decimal digit from 0 to 9 at least once.
How many pandigital step numbers less than 10^40 are there?



dozerg:
һ����10���Ʊ�ʾ���������digit�����������10��bits��ʶ���ܹ�1024�������
��E(n, d, m)��ʾ10���Ƴ���Ϊn�����У��ж�����d��β�Ұ���digit���Ϊm������0<=d<=9, 0<=m<=1023
��ô������״̬ת�����̣�
E(n+1, d, m) = SUM{E(n, d-1, mi)} + SUM{E(n, d+1, mj)}
���У�m == mi | (1 << d) == mj | (1 << d)

��������Ϊ��SUM{E(ni, di, 1023)}

