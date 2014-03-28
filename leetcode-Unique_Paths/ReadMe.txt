I
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach 
the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

II
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.




和Unique Path一样的转移方程：
Step[i][j] = Step[i-1][j] + Step[i][j-1] if Array[i][j] ==0
or            = 0 if Array[i][j] =1

[Code]
1:       int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {  
2:            int m = obstacleGrid.size();  
3:            if(m ==0) return 0;  
4:            int n = obstacleGrid[0].size();  
5:            if(obstacleGrid[0][0] ==1) return 0;  
6:            vector<int> maxV(n,0);  
7:            maxV[0] =1;  
8:            for(int i =0; i<m; i++)  
9:            {  
10:                 for(int j =0; j<n; j++)  
11:                 {  
12:                      if(obstacleGrid[i][j] ==1)  
13:                           maxV[j]=0;  
14:                      else if(j >0)  
15:                           maxV[j] = maxV[j-1]+maxV[j];  
16:                 }  
17:            }  
18:            return maxV[n-1];  
19:       }  