#include "../inc.h"

//simulate the movements
//O(4^N), N is 'steps'
struct Solution1
{
    int solve(const vector<string> & B, int steps){
        board = B;
        //find '*'
        for (size_t i = 0; i < board.size(); ++i){
            size_t wh = board[i].find('*');
            if (wh != string::npos){
                end.first = i;
                end.second = wh;
                break;
            }
        }
        return help(pair<int, int>(0, 0), steps);
    }
private:
    int help(const pair<int, int> & cur, int steps){
        //check
        if (!valid(cur))
            return -1;
        assert(steps >= 0);
        int dis = distance(cur, end);
        if (dis > steps)
            return -1;
        if (path.count(cur) > 0)
            return -1;  //find cycle
        //get destination
        if (!dis)
            return 0;
        path.insert(cur);
        //move without changes
        const char S = sign(cur);
        int ret = help(moveNext(cur, S), steps - 1);
        if (!ret){
            path.erase(cur);
            return 0;
        }
        if (mod.count(cur) > 0){
            path.erase(cur);
            return ret;
        }
        //move with changes
        mod.insert(cur);
        const char * const Dir = "UDLR";
        for (int i = 0; i < 4; ++i){
            if (S == Dir[i])
                continue;
            sign(cur, Dir[i]);
            int r = help(moveNext(cur, Dir[i]), steps - 1);
            if (r < 0)
                continue;
            ++r;
            if (ret < 0 || r < ret)
                ret = r;
            if (1 == ret)
                break;
        }
        sign(cur, S);
        mod.erase(cur);
        path.erase(cur);
        return ret;
    }
    static pair<int, int> moveNext(const pair<int, int> & cur, char s){
        pair<int, int> r(cur);
        switch (s){
            case 'L':--r.second; break;
            case 'R':++r.second; break;
            case 'U':--r.first; break;
            case 'D':++r.first; break;
        }
        return r;
    }
    char sign(const pair<int, int> & pos) const{
        assert(valid(pos));
        return board[pos.first][pos.second];
    }
    void sign(const pair<int, int> & pos, char s){
        assert(valid(pos));
        board[pos.first][pos.second] = s;
    }
    bool valid(const pair<int, int> & pos) const{
        return (0 <= pos.first && pos.first < int(board.size())
            && 0 <= pos.second && pos.second < int(board[pos.first].size()));
    }
    int distance(const pair<int, int> & p1, const pair<int, int> & p2) const{
        assert(valid(p1) && valid(p2));
        int r1 = p1.first - p2.first;
        if (r1 < 0)
            r1 = -r1;
        int r2 = p1.second - p2.second;
        if (r2 < 0)
            r2 = -r2;
        return r1 + r2;
    }
    vector<string> board;
    pair<int, int> end;
    set<pair<int, int>> path, mod;
};

//BFS
//O(MN)
struct Solution2
{
    int solve(const vector<string> & B, int steps){
        if (B.empty() || B.back().empty())
            return -1;
        board = B;
        save.resize(B.size(), vector<int>(B[0].size(), -1));
        //BFS
        help(0, 0, steps, 0);
        //find '*'
        for (size_t i = 0; i < board.size(); ++i){
            size_t wh = board[i].find('*');
            if (wh != string::npos)
                return save[i][wh];
        }
        return -1;
    }
private:
    void help(int row, int col, int steps, int changes){
        if (valid(row, col) && steps-- >= 0 && shorter(changes, save[row][col])){
            save[row][col] = changes;
            help(row + 1, col, steps, changes + (board[row][col] != 'D' ? 1 : 0));
            help(row - 1, col, steps, changes + (board[row][col] != 'U' ? 1 : 0));
            help(row, col + 1, steps, changes + (board[row][col] != 'R' ? 1 : 0));
            help(row, col - 1, steps, changes + (board[row][col] != 'L' ? 1 : 0));
        }
    }
    bool valid(int row, int col) const{
        return (0 <= row && row < int(board.size())
            && 0 <= col && col < int(board[0].size()));
    }
    static bool shorter(int d1, int d2){
        if (d1 < 0)
            return false;
        if (d2 < 0)
            return true;
        return (d1 < d2);
    }
    vector<string> board;
    vector<vector<int>> save;
};

typedef Solution2 Solution;

void test()
{
    cout << Solution().solve({ "RD", "*L" }, 3) << endl;
    cout << Solution().solve({ "RD", "*L" }, 1) << endl;
    {
        vector<string> B{
            "DRLULLRRRLRDLRRLU",
            "URUURLRLLLDULRRRR",
            "RRDLDDLDRRDRURRLR",
            "RRRRRRRLDULDDUDLD",
            "RULRDDULDUDULRDUD",
            "LRURUDURRUURDDUDL",
            "URURDLRUULRRDLDLR",
            "RLRUDLDRUUDULUDUU",
            "RULLURDRDUURLDRDR",
            "ULDUDUUULLURURURR",
            "LDRDLDRRLDDRRLRLD",
            "RDDLURRRDDLRDURLD",
            "ULRLRLRRLLLRRURRL",
            "RLLLDRDURLRURLUDD",
            "DRLDURRLURUULLRDU",
            "RURRUDL*LDDDRUUUD",
            "UUUUDDLRURULRRDRD",
            "URDUUDRDLDRLLULRU",
            "DRDUUULUUDURULDDL",
            "LLULDRLRRRUDLDRRR"
        };
        for (int i = 0; i <= 100; ++i)
            cout << i << ": " << Solution().solve(B, i) << endl;
    }
}

int main()
{
    test(); return 0;
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> board(n);
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    cout << Solution().solve(board, k) << endl;
    return 0;
}