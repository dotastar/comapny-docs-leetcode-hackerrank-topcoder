Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

��ĸ���ĳ���Ϊ j���Ӵ��ĳ���Ϊ i������Ҫ��ľ��ǳ���Ϊ i 
���ִ��ڳ���Ϊ j ��ĸ���г��ֵĴ�������Ϊ t[i][j]����ĸ��
�����һ���ַ����Ӵ������һ���ַ���ͬ���򳤶�Ϊ i ���Ӵ�
�ڳ���Ϊ j ��ĸ���г��ֵĴ�������ĸ����ǰ j - 1 ���ַ���
�Ӵ����ֵĴ������� t[i][j] = t[i][j - 1]����ĸ�������һ
���ַ����Ӵ������һ���ַ���ͬ����ô����ǰ j - 1 ���ַ���
���ִ��Ĵ����⣬��Ҫ�����Ӵ���ǰ i - 1 ���ַ���ĸ����ǰ j
- 1 ���ַ��г��ֵĴ������� t[i][j] = t[i][j - 1] + t[i - 
1][j - 1]��
