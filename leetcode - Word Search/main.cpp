#include "..\inc.h"

//dfs
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

//bfs, using tree for duplicate test, but TLE
class Solution2 {
public:
    struct Node{
        pair<int, int> p;
        vector<Node *> rel; //[0] is parent, others are children
        Node(const pair<int, int> & pp = { -1, -1 }) :p(pp), rel(1){}
        void addChild(Node * n){
            assert(n);
            n->rel[0] = this;
            rel.push_back(n);
        }
        Node * parent() const{ return rel[0]; }
        ~Node(){
            for (size_t i = 1; i < rel.size(); ++i)
                delete rel[i];
        }
    };
    bool exist(vector<vector<char> > &board, string word) {
        if (word.empty())
            return true;
        if (board.empty() || board.size() * board[0].size() < word.size())
            return false;
        Node root;
        vector<Node *> que, tmp;
        for (size_t i = 0; i < board.size(); ++i)
            for (size_t j = 0; j < board[i].size(); ++j)
                if (word[0] == board[i][j]){
            Node * n = new Node({ i, j });
            que.push_back(n);
            root.addChild(n);
                }
        const pair<int, int> DIR[] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        for (size_t i = 1; i < word.size() && !que.empty(); ++i, tmp.clear()){
            for (auto c : que){
                auto p = c->p;
                for (const auto & d : DIR){
                    p.first += d.first;
                    p.second += d.second;
                    if (0 <= p.first && p.first < board.size()
                        && 0 <= p.second && p.second < board[0].size()
                        && word[i] == board[p.first][p.second]){
                        bool found = false;
                        for (Node * n = c->parent(); n; n = n->parent()){
                            if (n->p == p){
                                found = true;
                                break;
                            }
                        }
                        if (!found){
                            Node * n = new Node(p);
                            tmp.push_back(n);
                            c->addChild(n);
                        }
                    }
                    p.first -= d.first;
                    p.second -= d.second;
                }
            }
            que.swap(tmp);
        }
        return !que.empty();
    }
};

//dfs again
class Solution3 {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word.empty())
            return true;
        if (board.empty() || board.size() * board[0].size() < word.size())
            return false;
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size()));
        return help(board, used, word, 0, -1, -1);
    }
    bool help(const vector<vector<char>> & board, vector<vector<bool>> & used, const string & word, size_t len, int x, int y){
        if (len >= word.size())
            return true;
        if (!len){
            for (size_t i = 0; i < board.size(); ++i)
                for (size_t j = 0; j < board[i].size(); ++j)
                    if (word[0] == board[i][j]){
                used[i][j] = true;
                if (help(board, used, word, 1, i, j))
                    return true;
                used[i][j] = false;
                    }
        } else{
            const pair<int, int> DIR[] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
            for (const auto & d : DIR){
                x += d.first;
                y += d.second;
                if (0 <= x && x < board.size()
                    && 0 <= y && y < board[0].size()
                    && word[len] == board[x][y]
                    && !used[x][y]){
                    used[x][y] = true;
                    if (help(board, used, word, len + 1, x, y))
                        return true;
                    used[x][y] = false;
                }
                x -= d.first;
                y -= d.second;
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