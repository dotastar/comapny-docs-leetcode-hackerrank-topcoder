I
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

II
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
���ڳ�����һ��֮������е�������������Ʊ�ʾ��ÿһλ1���ֵĴ�����3������������������Щ1���㣬ʣ�µľ������յ�����
��ones��¼����ǰ����ı���Ϊֹ��������1���֡�1�Ρ���mod 3 ֮��� 1������λ��
��twos��¼����ǰ����ı���Ϊֹ��������1���֡�2�Ρ���mod 3 ֮��� 2������λ��
��ones��twos�е�ĳһλͬʱΪ1ʱ��ʾ������1����3�Σ���ʱ��Ҫ���㡣���ö���
��ģ�������Ƽ��㡣����ones��¼�������ս����


����һ������n�����������飬��һ������x����b�Σ�һ������y����c�Σ�
�������е���������a�Σ�����b��c������a�ı������ҳ�x��y.