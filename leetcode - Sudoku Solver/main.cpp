#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        assert(board.size() == 9 && board[0].size() == 9);
        help(board, 0);
    }
    bool help(vector<vector<char> > &board, int c) {
        for(;c < 81;++c)
            if(board[c / 9][c % 9] == '.')
                break;
        if(c >= 81)
            return true;
        int i = c / 9;
        int j = c % 9;
        int bits = 0;
        //rule 1
        for(int jj = 0;jj < 9;++jj){
            if(board[i][jj] == '.')
                continue;
            bits |= (1 << (board[i][jj] - '1'));
        }
        //rule 2
        for(int ii = 0;ii < 9;++ii){
            if(board[ii][j] == '.')
                continue;
            bits |= (1 << (board[ii][j] - '1'));
        }
        if(bits == (1 << 9) - 1)
            return false;
        //rule 3
        int bi = i / 3 * 3, bj = j / 3 * 3;
        for(int ii = 0;ii < 9;++ii){
            int v = board[bi + ii / 3][bj + ii % 3];
            if('.' == v)
                continue;
            bits |= (1 << (v - '1'));
        }
        if(bits == (1 << 9) - 1)
            return false;
        //reverse bits
        bits = (1 << 9) - 1 - bits;
        if(0 == (bits & (bits - 1))){
            //only 1 option
            for(int ii = 0;ii < 9;++ii)
                if(bits & (1 << ii)){
                    board[i][j] = ii + '1';
                    return help(board, c + 1);
                }
        }
        //more than 1 options
        for(int ii = 0;ii < 9;++ii)
            if(bits & (1 << ii)){
                vector<vector<char> > tmp(board);
                tmp[i][j] = ii + '1';
                if(help(tmp, c + 1)){
                    board.swap(tmp);
                    return true;
                }
            }
        return false;
    }
};

class Solution2 {
public:
    void solveSudoku(vector<vector<char> > &board) {
        help(board, 0);
    }
    bool help(vector<vector<char>> & board, size_t index){
        size_t x, y;
        for(;;++index){
            if(index >= 81)
                return true;
            x = index / 9;
            y = index % 9;
            if('.' == board[x][y])
                break;
        }
        int mask = 0;
        for(size_t i = 0, bx = x / 3 * 3, by = y / 3 * 3;i < 9;++i){
            if('.' != board[x][i])
                mask |= 1 << (board[x][i] - '1');
            if('.' != board[i][y])
                mask |= 1 << (board[i][y] - '1');
            if('.' != board[bx + i / 3][by + i % 3])
                mask |= 1 << (board[bx + i / 3][by + i % 3] - '1');
        }
        if(mask >= 1023)
            return false;
        for(int i = 0;i < 9;++i){
            if(0 != (mask & (1 << i)))
                continue;
            board[x][y] = i + '1';
            if(help(board, index + 1))
                return true;
            board[x][y] = '.';
        }
    }
};

int main(){}