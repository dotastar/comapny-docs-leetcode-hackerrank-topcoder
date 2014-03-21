#include "../inc.h"

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if(board.empty() || board[0].empty())
            return;
        vector<int> ids(1);
        vector<vector<int> > m(board.size(), vector<int>(board[0].size()));
        for(size_t i = 0;i < board.size();++i){
            for(size_t j = 0;j < board[0].size();++j){
                if('O' == board[i][j]){
                    int d1 = -1;
                    if(0 < j && 'O' == board[i][j - 1])
                        d1 = m[i][j - 1];
                    int d2 = -1;
                    if(0 < i && 'O' == board[i - 1][j])
                        d2 = m[i - 1][j];
                    if(0 < i && i + 1 < board.size()
                            && 0 < j && j + 1 < board[0].size()){
                        if(0 <= d1 && 0 <= d2){
                            int d = min(ids[d1], ids[d2]);
                            help(ids, d1, d);
                            help(ids, d2, d);
                            m[i][j] = d;
                        }else if(0 <= d1)
                            m[i][j] = ids[d1];
                        else if(0 <= d2)
                            m[i][j] = ids[d2];
                        else{
                            m[i][j] = ids.size();
                            ids.push_back(m[i][j]);
                        }
                    }else{
                        if(0 < d1)
                            help(ids, d1, 0);
                        if(0 < d2)
                            help(ids, d2, 0);
                    }
                }
            }
        }
        for(size_t i = 1;i < ids.size();++i)
            ids[i] = ids[ids[i]];
        for(size_t i = 0;i < board.size();++i){
            for(size_t j = 0;j < board[0].size();++j){
                if('O' == board[i][j] && ids[m[i][j]])
                    board[i][j] = 'X';
            }
        }
    }
    void help(vector<int> & ids, int idx, int val){
        for(int t = idx, tt;t > val;t = tt){
            tt = ids[t];
            ids[t] = val;
        }
    }
};

int main()
{
    {
        char b[4][4] = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'},
        };
        vector<vector<char> > board;
        for(size_t i = 0;i < sizeof b / sizeof b[0];++i)
            board.push_back(vector<char>(b[i], b[i] + sizeof b[i] / sizeof b[i][0]));
        Solution().solve(board);
        print(board);
        cout<<endl;
    }
    {
        char b[4][4] = {
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'},
        };
        vector<vector<char> > board;
        for(size_t i = 0;i < sizeof b / sizeof b[0];++i)
            board.push_back(vector<char>(b[i], b[i] + sizeof b[i] / sizeof b[i][0]));
        Solution().solve(board);
        print(board);
        cout<<endl;
    }
    {
        const char * b[] = {
            "OXXOX",
            "XOOXO",
            "XOXOX",
            "OXOOO",
            "XXOXO"};
        vector<vector<char> > board;
        for(size_t i = 0;i < sizeof b / sizeof b[0];++i){
            string s(b[i]);
            board.push_back(vector<char>(s.begin(), s.end()));
        }
        Solution().solve(board);
        print(board);
        cout<<endl;
    }
    {
        const char * b[] = {
            "XOOXXXOXXOOOOOOOOOOO",
            "XOOXXOOXOOOXOXOXOOXO",
            "OOOXXXXOXOXXOOOOXOXO",
            "OOOXXOOXOOOXXXOOXOOX",
            "OOOOOOOXXXOOOOOOOOOO",
            "XOOOOXOXOXXOOOOOOXOX",
            "OOOXOOOXOXOXOXOXOXOX",
            "OOOXOXOOXXOXOXXOXXXO",
            "OOOOXOOXXOOOOXOOOXOX",
            "OOXOOXOOOOOXOOXOOOXO",
            "XOOXOOOOOOOXOOXOXOXO",
            "OXOOOXOXOXXOXXXOXXOO",
            "XXOXOOOOXOOOOOOXOOOX",
            "OXOOXXXOOOXXXXXOXOOO",
            "OOXXXOOOXXOOOXOXOOOO",
            "XOOXOXOOOOXOOOXOXOXX",
            "XOXOOOOOOXOOOXOXOOOO",
            "OXXOOOXXXOXOXOXXXXOO",
            "OXOOOOXXOOXOXOOXOOXX",
            "OOOOOOXXXXOXOOOXXOOO"
        };
        vector<vector<char> > board;
        for(size_t i = 0;i < sizeof b / sizeof b[0];++i){
            string s(b[i]);
            board.push_back(vector<char>(s.begin(), s.end()));
        }
        cout<<"before solve:\n";
        printXO(board);
        Solution().solve(board);
        cout<<"\nafter solve:\n";
        printXO(board);
        cout<<endl;
    }
}