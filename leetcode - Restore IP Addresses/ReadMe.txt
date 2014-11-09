Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

Solution1:
�ݹ�Ľ����ִ��ֳ��ĸ����֣�ÿ����������0<=p<=255��Ҫע��һЩ�߽�case������010��û����˼�ģ���0.10.010.1����

Solution2:
DP�ⷨ��
����A.B.C.D��ʾ�κκϷ���IP��ַ����ÿ��s.substr(0, i)ά��4������������У�
R1(i)��ʾs.substr(0, i)Ϊ�Ϸ���A��
R2(i)��ʾs.substr(0, i)Ϊ�Ϸ���A.B��
R3(i)��ʾs.substr(0, i)Ϊ�Ϸ���A.B.C��
R4(i)��ʾs.substr(0, i)Ϊ�Ϸ���A.B.C.D��

��������״̬ת�����̣�
R1(i) = {
	s.substr(0, i), if s.substr(0, i) is valid A;
}
R2(i) = {
	R1(i - 1) + '.' + s.substr(i - 1, 1), if s.substr(i - 1, 1) is valid B;
OR  R1(i - 2) + '.' + s.substr(i - 2, 2), if s.substr(i - 2, 2) is valid B;
OR  R1(i - 3) + '.' + s.substr(i - 3, 3), if s.substr(i - 3, 3) is valid B;
}
R3(i) = {
	R2(i - 1) + '.' + s.substr(i - 1, 1), if s.substr(i - 1, 1) is valid C;
OR  R2(i - 2) + '.' + s.substr(i - 2, 2), if s.substr(i - 2, 2) is valid C;
OR  R2(i - 3) + '.' + s.substr(i - 3, 3), if s.substr(i - 3, 3) is valid C;
}
R4(i) = {
	R3(i - 1) + '.' + s.substr(i - 1, 1), if s.substr(i - 1, 1) is valid D;
OR  R3(i - 2) + '.' + s.substr(i - 2, 2), if s.substr(i - 2, 2) is valid D;
OR  R3(i - 3) + '.' + s.substr(i - 3, 3), if s.substr(i - 3, 3) is valid D;
}

��Ȼ�������Ľ��ΪR4(s.length())��
