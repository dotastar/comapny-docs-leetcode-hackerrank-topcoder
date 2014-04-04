#include "../inc.h"

class Solution {
public:
    int minPathSum1(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        return help(grid, grid.size() - 1, grid[0].size() - 1);
    }
    int help(const vector<vector<int> > & grid, int x2, int y2){
        assert(0 <= x2 && 0 <= y2);
        if (0 == x2){
            int r = 0;
            for (int i = 0; i <= y2; ++i)
                r += grid[0][i];
            return r;
        }
        if (0 == y2){
            int r = 0;
            for (int i = 0; i <= x2; ++i)
                r += grid[i][0];
            return r;
        }
        int r1 = help(grid, x2 - 1, y2);
        int r2 = help(grid, x2, y2 - 1);
        if (r1 > r2)
            r1 = r2;
        return r1 + grid[x2][y2];
    }
    int minPathSum2(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        vector<vector<int> > save(grid.size(), vector<int>(grid[0].size(), -1));
        help(grid, 0, 0, 0, save);
        return save.back().back();
    }
    void help(const vector<vector<int> > & grid, int x, int y, int d, vector<vector<int> > & save){
        if (save[x][y] >= 0 && save[x][y] <= d)
            return;
        save[x][y] = d;
        if (x + 1 == int(grid.size()) && y + 1 == int(grid[0].size()))
            return;
        if (x + 1 < int(grid.size()))
            help(grid, x + 1, y, d + grid[x + 1][y], save);
        if (y + 1 < int(grid[0].size()))
            help(grid, x, y + 1, d + grid[x][y + 1], save);
    }
    int minPathSum3(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        vector<vector<int> > sum(grid.size(), vector<int>(grid[0].size(), 0));
        for (size_t x = 0; x < grid.size(); ++x){
            for (size_t y = 0; y < grid[0].size(); ++y){
                int s = (x ? sum[x - 1][y] : -1);
                if (y && (s < 0 || s > sum[x][y - 1]))
                    s = sum[x][y - 1];
                if (s < 0)
                    s = 0;
                sum[x][y] = s + grid[x][y];
            }
        }
        return sum.back().back();
    }
    int minPathSum4(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        vector<int> ret(grid[0].size());
        for (size_t i = 0; i < grid.size(); ++i){
            ret[0] += grid[i][0];
            for (size_t j = 1; j < grid[i].size(); ++j)
                ret[j] = (!i ? ret[j - 1] : min(ret[j - 1], ret[j])) + grid[i][j];
        }
        return ret.back();
    }
};

int main()
{
    {
        vector<vector<int> > g{ { 1, 2 }, { 1, 1 } };
        cout << Solution().minPathSum4(g) << endl;
    }{
    vector<vector<int> > g{ { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
        cout << Solution().minPathSum4(g) << endl;
    }
}
