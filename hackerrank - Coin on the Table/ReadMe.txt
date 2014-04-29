https://www.hackerrank.com/challenges/coin-on-the-table

You have a rectangular board consisting of n rows, numbered from 1 to n and m columns, numbered from 1 to m. The top left is (1,1) and bottom right is (n,m). Initially - at time 0 - there is a coin on the top-left cell of your board. Each cell of your board contains one of these letters:

*: Exactly one of your cells has letter '*'.

U: If at time t, the coin is on the cell(i,j) and cell(i,j) has letter 'U', the coin will be on the cell(i-1,j) in time t+1, if i > 1. Otherwise there is no coin on your board at time t+1.

L: If at time t, the coin is on the cell(i,j) and cell(i,j) has letter 'L', the coin will be on the cell(i,j-1) in time t+1, if j > 1. Otherwise there is no coin on your board at time t+1.

D: If at time t, the coin is on the cell(i,j) and cell(i,j) has letter 'D', the coin will be on the cell(i+1,j) in time t+1, if i < n. Otherwise there is no coin on your board at time t+1.

R: If at time t, the coin is on the cell(i,j) and cell(i,j) has letter 'R', the coin will be on the cell(i,j+1) in time t+1, if j < m. )therwise there is no coin on your board at time t+1.
When the coin reaches the cell that has letter ¡®*¡¯ it will be there permanently. When you punch on your board, your timer starts and the coin moves between cells. before doing that you want to do some operation so that you could be sure that at time k the coin will be on the cell having letter ¡®*¡¯. In each operation you can select a cell with some letter other than ¡®*¡¯ and change the letter to ¡®U¡¯, ¡®L¡¯, ¡®R¡¯ or ¡®D¡¯. You want to do as few operations as possible in order to achieve your goal. Your task is to find the minimum number of operations.

Input:
The first line of input contains three integers n and m and k. Next n lines contains m letters which describe you board.

Output:
on the only line of the output print an integer being the answer to the test.
If you cannot achieve your goal, output -1 please.

Constraints
n, m <= 51
k <= 1000

Sample input :

2 2 3  
RD  
*L
Sample output :

0
Sample input :

2 2 1  
RD  
*L
Sample output :

1
Explanation :

In the first example you don¡¯t have to change any letters, but in the second example you should change the letter of cell (1,1) to ¡®D¡¯.