There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i 
to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.





�����ɵ�һ���⡣��ֱ�׵Ľⷨ���Ǵ�ÿһ���㿪ʼ��������������Ȼ���ҳ����ʣ���������ĵ㡣�����O(n^2)�ġ������������Բ������ĵ���������д������ѭ����ô�򵥡� 

��ϸ��һ�£���ʵ����ǰ���������������͵������ 

���κ�һ���ڵ㣬��ʵ����ֻ�����͵���ģ����壺 

diff[i] = gas[i] �C cost[i]  0<=i <n 

��ô��������������⣺ 

1. �ܷ��ڻ�����һȦ�� 

2. ����ܣ������������ 

��һ�����⣬�ܼ򵥣��Ҷ�diff���������Ӻ;ͺ��ˣ�leftGas = ��diff[i]�� ������leftGas����ֵ����ô�϶�������ôһ����ʼ�㡣����Ǹ�ֵ����˵�����͵���Ĵ����͵Ĺ������������н⡣�õ���һ������Ĵ�ֻ��ҪO(n)�� 

���ڵڶ������⣬�������� 

���裬���Ǵӻ���ȡһ������[i, j], j>i�� Ȼ�������������diff�Ӻͣ����� 

sum[i,j] = ��diff[k] where i<=k<j 

���sum[i,j]С��0����ô������϶�������[i,j]������������һ�������ԭ��һ�����ٸ����ӣ�����i��[0,n]�Ľ⣬��ô����֪�� ����sum[k,i-1] (0<=k<i-1) �϶���С��0�ģ�������Ӧ����k��ͬ��sum[i,n]һ���Ǵ���0�ģ����򣬽�Ͳ�Ӧ����i������i��n֮���ĳ���㡣���Եڶ���Ĵ𰸣���ʵ������0��n֮�䣬�ҵ���һ�����������У���������еĽ�β��Ȼ��n������0�ġ� 

���ˣ��������ⶼ������һ��ѭ���н����