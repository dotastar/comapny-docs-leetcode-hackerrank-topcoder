https://www.hackerrank.com/challenges/queens-on-board

Queens on Board

You have an N * M chessboard on which some squares are blocked out. In how many ways can you place one or more queens on the board such that no two queens attack each other? Two queens attack each other if one can reach the other by moving horizontally, vertically or diagonally without passing over any blocked square. At most one queen can be placed on a square. A queen cannot be placed on a blocked square.

Input Format
The first line contains the number of test cases T. T test cases follow. Each test case contains integers N and M on the first line. The following N lines contain M characters each representing the board. A ��#�� represents a blocked square and a ��.�� represents an unblocked square.

Constraints
1 <= T <= 100
1 <= N <= 50
1 <= M <= 5

Output Format
Output T lines containing the required answer for each test case. As the answers can be really large, output them modulo 1000000007.

Sample Input:

4  
3 3  
...  
...  
...  
3 3  
.#.  
.#.  
...  
2 4  
.#..  
....  
1 1  
#
Sample Output:

17  
18  
14  
0 


dozerg:
���ȶ���ÿ�У���������ܵ�Queens�ڷŷ�ʽ������"....."ֻ�ܷ�1��Q����5�ַ�ʽ����".#..."���Է�1��Q 4�ַ�ʽ����2��Q 3�ַ�ʽ���ܹ�7�ַ�ʽ��
Ȼ�����DP����T(row, lm, dm, rm)��ʾ��row�п�ʼ�����£������������mask�ֱ�Ϊlm, dm, rmʱ���ж����ְڷŷ�ʽ�����У�
T(row, lm, dm, rm) = {
	��lm, dm, rm��blocks���д���ȥ������ϵ�masks��
	����row��ÿ�ֿ��ܵİڷŷ�ʽ�����������ԣ�
	��pΪ���еİڷŷ�ʽ��
	lm = (lm|p)<<1;
	dm = (dm|p);
	rm = (rm|p)>>1;
	����һ�еİڷŷ�ʽ��T(row+1, lm, dm, rm)
}

����0<=row<50, 0<=lm,dm,rm<32���ʿ��Խ�(row, lm, dm, rm)ƴ��һ��int����Ϊһ��״̬��

��������Ľ�ΪT(0, 0, 0, 0)��