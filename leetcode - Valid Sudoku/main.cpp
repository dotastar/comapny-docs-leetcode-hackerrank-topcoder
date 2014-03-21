#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if(board.size() != 9)
            return false;
        //rule 1
        for(int i = 0;i < 9;++i){
            if(board[i].size() != 9)
                return false;
            int b = 0;
            for(int j = 0;j < 9;++j){
                if(board[i][j] == '.')
                    continue;
                int v = board[i][j] - '0';
                if(b & (1 << v))
                    return false;
                b |= (1 << v);
            }
        }
        //rule 2
        for(int j = 0;j < 9;++j){
            int b = 0;
            for(int i = 0;i < 9;++i){
                if(board[i][j] == '.')
                    continue;
                int v = board[i][j] - '0';
                if(b & (1 << v))
                    return false;
                b |= (1 << v);
            }
        }
        //rule 3
        for(int j = 0;j < 9;j += 3)
            for(int i = 0;i < 9;i += 3){
                int b = 0;
                for(int di = 0;di < 3;++di)
                    for(int dj = 0;dj < 3;++dj){
                        if(board[i + di][j + dj] == '.')
                            continue;
                        int v = board[i + di][j + dj] - '0';
                        if(b & (1 << v))
                            return false;
                        b |= (1 << v);
                    }
            }
        return true;
    }
};

int main(){}