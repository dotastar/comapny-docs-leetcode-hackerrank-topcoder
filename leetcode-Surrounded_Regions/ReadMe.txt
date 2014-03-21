Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region .

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X



转换一下思路，真的需要开辟一个map在存储访问信息吗？其实这个可以省掉的，既然已经知道连通区域必须至少一个元素是在四边，那么一开始直接从四边开始扫描就好了，所以无法connect到得元素都是应该被清除的。所以，算法如下：
1. 从四条边上的O元素开始BFS，所有相连的O都赋个新值，比如‘Y’
2. 扫描整个数组，所有现存的O元素全部置为X，所有Y元素置为O
打完收工。代码实现如下：

1:       vector<int> xIndex;  
2:       vector<int> yIndex;  
3:       void solve(vector<vector<char>> &board) {  
4:            int row = board.size();  
5:            if(row == 0) return;  
6:            int col = board[0].size();  
7:            xIndex.clear();  
8:            yIndex.clear();            
9:            for(int i =0; i< row; i++)  
10:            {  
11:                 if(board[i][0] == 'O')  
12:                 {  
13:                      xIndex.push_back(i);  
14:                      yIndex.push_back(0);  
15:                 }  
16:                 if(board[i][col-1] == 'O')  
17:                 {  
18:                      xIndex.push_back(i);  
19:                      yIndex.push_back(col-1);  
20:                 }  
21:            }  
22:            for(int i =0; i< col; i++)  
23:            {  
24:                 if(board[0][i] == 'O')  
25:                 {  
26:                      xIndex.push_back(0);  
27:                      yIndex.push_back(i);  
28:                 }  
29:                 if(board[row-1][i] == 'O')  
30:                 {  
31:                      xIndex.push_back(row-1);  
32:                      yIndex.push_back(i);  
33:                 }  
34:            }            
35:            int k =0;  
36:            while(k<xIndex.size())  
37:            {  
38:                 int x = xIndex[k];  
39:                 int y = yIndex[k];     
40:                 board[x][y] = 'Y';  
41:                 if(x>0 && board[x-1][y] == 'O' ) {xIndex.push_back(x-1); yIndex.push_back(y);}  
42:                 if(x<row-1 && board[x+1][y] == 'O' ) {xIndex.push_back(x+1); yIndex.push_back(y);}                 
43:                 if(y>0 && board[x][y-1] == 'O' ) {xIndex.push_back(x); yIndex.push_back(y-1);}  
44:                 if(y<col-1 && board[x][y+1] == 'O' ) {xIndex.push_back(x); yIndex.push_back(y+1);}  
45:                 k++;  
46:            }  
47:            for(int i =0; i< row; i++)  
48:            {  
49:                 for(int j =0; j< col; j++)  
50:                 {  
51:                      if(board[i][j] =='O') board[i][j] = 'X';  
52:                      if(board[i][j] == 'Y') board[i][j] = 'O';  
53:                 }  
54:            }            
55:       }   