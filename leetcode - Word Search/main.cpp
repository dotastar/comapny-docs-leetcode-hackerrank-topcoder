#include "..\inc.h"

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.empty())
            return true;
        if(board.empty() || board[0].empty())
            return false;
        if(word.size() > board.size() * board[0].size())
            return false;
        vector<vector<bool> > used(board.size(), vector<bool>(board[0].size()));
        return help(board, word, 0, -1, -1, used);
    }
    bool help(const vector<vector<char> > &board,
        string word, size_t idx,
        int i, int j,
        vector<vector<bool> > & used)
    {
        if(idx >= word.size())
            return true;
        if(!idx){
            for(i = 0;i < int(board.size());++i)
                for(j = 0;j < int(board[0].size());++j)
                    if(board[i][j] == word[idx]){
                        used[i][j] = true;
                        if(help(board, word, 1, i, j, used))
                            return true;
                        used[i][j] = false;
                    }
        }else{
            if(i > 0 && !used[i - 1][j] && board[i - 1][j] == word[idx]){
                used[i - 1][j] = true;
                if(help(board, word, idx + 1, i - 1, j, used))
                    return true;
                used[i - 1][j] = false;
            }
            if(i + 1 < int(used.size()) && !used[i + 1][j] && board[i + 1][j] == word[idx]){
                used[i + 1][j] = true;
                if(help(board, word, idx + 1, i + 1, j, used))
                    return true;
                used[i + 1][j] = false;
            }
            if(j > 0 && !used[i][j - 1] && board[i][j - 1] == word[idx]){
                used[i][j - 1] = true;
                if(help(board, word, idx + 1, i, j - 1, used))
                    return true;
                used[i][j - 1] = false;
            }
            if(j + 1 < int(used[0].size()) && !used[i][j + 1] && board[i][j + 1] == word[idx]){
                used[i][j + 1] = true;
                if(help(board, word, idx + 1, i, j + 1, used))
                    return true;
                used[i][j + 1] = false;
            }
        }
        return false;
    }
};

int main()
{
    {
        vector<vector<char> > b;
        string s = "ABCE";
        b.push_back(vector<char>(s.begin(), s.end()));
        s = "SFCS";
        b.push_back(vector<char>(s.begin(), s.end()));
        s = "ADEE";
        b.push_back(vector<char>(s.begin(), s.end()));

        cout<<Solution().exist(b, "ABCCED")<<endl;
        cout<<Solution().exist(b, "SEE")<<endl;
        cout<<Solution().exist(b, "ABCB")<<endl;
    }{
        vector<vector<char> > b;
        string s = "aaaa";
        b.push_back(vector<char>(s.begin(), s.end()));
        s = "aaaa";
        b.push_back(vector<char>(s.begin(), s.end()));
        s = "aaaa";
        b.push_back(vector<char>(s.begin(), s.end()));
        s = "aaaa";
        b.push_back(vector<char>(s.begin(), s.end()));
        s = "aaab";
        b.push_back(vector<char>(s.begin(), s.end()));

        cout<<Solution().exist(b, "aaaaaaaaaaaaaaaaaaaa")<<endl;
    }
}