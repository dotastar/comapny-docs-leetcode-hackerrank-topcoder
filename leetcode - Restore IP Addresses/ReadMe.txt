Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

Solution1:
递归的将数字串分成四个部分，每个部分满足0<=p<=255。要注意一些边界case，比如010是没有意思的，“0.10.010.1”。

Solution2:
DP解法。
假设A.B.C.D表示任何合法的IP地址。对每个s.substr(0, i)维护4个结果集，其中：
R1(i)表示s.substr(0, i)为合法的A；
R2(i)表示s.substr(0, i)为合法的A.B；
R3(i)表示s.substr(0, i)为合法的A.B.C；
R4(i)表示s.substr(0, i)为合法的A.B.C.D；

则有如下状态转换方程：
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

显然最后所求的结果为R4(s.length())；
