https://www.hackerrank.com/contests/2048-game/challenges/2048

2048 is a 1 player game, currently popularized by gabriele cirulli. It consists of a 4 x 4 board. It initially starts with 2 tiles with numbers 2 or 4 in each of them. You are allowed to make the moves LEFT, RIGHT, UP or DOWN on which the tiles slide in the corresponding direction. If two adjacent cells share the same number, they merge into one along the direction in which it slides. The new number on the merged tile is equal to the sum of the merged tiles. On every move, a random tile appears (2 with a probability of 0.75 and 4 with a probability of 0.25) on an empty location on the board.

Update

We¡¯ve increased the difficulty by increasing the number of the final tile to 4096!

The game ends when you can create a tile numbered 4096 or if there are no two adjacent tiles sharing the same number. You are given 10000 moves to create the tile 4096 after which the game is terminated.

In the current format of the game, on compile and test, the game ends on creating a tile numbered 128. On submission, the game ends on creating the tile numbered 4096. Your objective is to create the 4096 tile.

Input Format
Input consists of 4 lines each containing 4 numbers separated by a single space.
0 indicates an empty space.

Output Format
Print LEFT, RIGHT, UP or DOWN depending on the direction in which you want to slide the tiles.

Note
We have provided template for some languages which will handle I/O. For those languages, you can just fill in the function.

Scoring

For every tile that is merged, the number on the new tile is added to the score. The final score is then divided by 100.

Sample Input

0 0 0 2
0 2 8 2
2 32 16 2
32 64 4 8
Sample Output #0

LEFT
Explanation #0

On LEFT, the entire tiles slide to the left side of the board. It results in the following state. Empty cell at (1,3) will be newly populated with a tile numbered 2.

2 0 0 0
2 8 2 2
2 32 16 2
32 64 4 8
Sample Output #1

RIGHT
Explanation #1

For the same Input #0, on RIGHT, the tiles remain as is as there will be no merge, but the tile at (0, 0) will slide in the right direction. One of the empty cells (0,0) or (0,1) or (0,2) or (1,0) will be populated with a new tile numbered 2 or 4. In this scenario, it is (1,0) with a tile numbered 2.

0 0 0 2
2 2 8 2
2 32 16 2
32 64 4 8
Sample Output #2

UP
Explanation #2

For the same Input #0, on UP, the tiles slide UP resulting in the following board. There are no tiles to be merged. One of the empty cells (2,0) or (3,0) or (3,1) or (3,2) will be populated with a new tile numbered 2 or 4. In this scenario, it is (3,0) with a tile numbered 4.

0 0 0 2          2 2 8 4
0 2 8 2    ->    32 32 16 2
2 32 16 2        0 64 4 8
32 64 4 8        4 0 0 0
Sample Output #3

DOWN
Explanation #3

For the same Input #0, on DOWN, tiles at (1,3) and (2,3) will be merged. A new tile numbered 2 appears at (0, 0) resulting in the following board.

2 0 0 0
0 2 8 2
2 32 16 4
32 64 4 8