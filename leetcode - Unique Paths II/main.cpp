#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        vector<vector<int> > save(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        help(obstacleGrid.size() - 1, obstacleGrid[0].size() - 1, obstacleGrid, save);
        return save.back().back();
    }
    void help(int i, int j, vector<vector<int> > &obstacleGrid, vector<vector<int> > & save){
        if(save[i][j] >= 0)
            return;
        if(obstacleGrid[i][j]){
            save[i][j] = 0;
            return;
        }
        if(!i && !j){
            save[i][j] = 1;
            return;
        }
        if(!i){
            help(0, j - 1, obstacleGrid, save);
            save[i][j] = save[i][j - 1];
            return;
        }
        if(!j){
            help(i - 1, 0, obstacleGrid, save);
            save[i][j] = save[i - 1][j];
            return;
        }
        help(i, j - 1, obstacleGrid, save);
        help(i - 1, j, obstacleGrid, save);
        save[i][j] = save[i - 1][j] + save[i][j - 1];
    }
};

int main(){}