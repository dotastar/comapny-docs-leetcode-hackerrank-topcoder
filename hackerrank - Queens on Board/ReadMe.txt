https://www.hackerrank.com/challenges/queens-on-board

Queens on Board

You have an N * M chessboard on which some squares are blocked out. In how many ways can you place one or more queens on the board such that no two queens attack each other? Two queens attack each other if one can reach the other by moving horizontally, vertically or diagonally without passing over any blocked square. At most one queen can be placed on a square. A queen cannot be placed on a blocked square.

Input Format
The first line contains the number of test cases T. T test cases follow. Each test case contains integers N and M on the first line. The following N lines contain M characters each representing the board. A ‘#’ represents a blocked square and a ‘.’ represents an unblocked square.

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
首先对于每行，计算出可能的Queens摆放方式，例如"....."只能放1个Q，有5种方式；而".#..."可以放1个Q 4种方式，和2个Q 3种方式，总共7种方式。
然后采用DP，令T(row, lm, dm, rm)表示从row行开始及以下，如果左中右移mask分别为lm, dm, rm时，有多少种摆放方式，则有：
T(row, lm, dm, rm) = {
	将lm, dm, rm与blocks进行处理，去掉被阻断的masks；
	对于row的每种可能的摆放方式，检查其可行性；
	令p为可行的摆放方式，
	lm = (lm|p)<<1;
	dm = (dm|p);
	rm = (rm|p)>>1;
	加下一行的摆放方式：T(row+1, lm, dm, rm)
}

由于0<=row<50, 0<=lm,dm,rm<32，故可以将(row, lm, dm, rm)拼成一个int，作为一个状态。

整个问题的解为T(0, 0, 0, 0)。