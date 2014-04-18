#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

void print(const vector<vector<char> > & board, size_t s)
{
    const int M = board.size(), N = board[0].size();
    for (int i = 0; i < M; ++i){
        for (int j = 0; j < N; ++j){
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << "--- " << s << endl;
}

void kill(vector<vector<char> > & board, int x, int y, vector<pair<int, int> > & dead)
{
    if ('.' == board[x][y]){
        dead.push_back(make_pair(x, y));
        board[x][y] = 'O';
    }
}

long long help(vector<vector<char> > & board, const vector<pair<int, int> > & left)
{
    //print(board, left.size());
    const int M = board.size(), N = board[0].size();
    long long ret = left.size();
    for (size_t i = 0; i < left.size(); ++i){
        const pair<int, int> & p1 = left[i];
        board[p1.first][p1.second] = 'X';
        vector<pair<int, int> > live, dead(1, p1);
        for (int y = p1.second + 1; y < N; ++y){
            if ('#' == board[p1.first][y])
                break;
            board[p1.first][y] = 'O';
            dead.push_back(make_pair(p1.first, y));
        }
        for (int x = p1.first + 1, x1 = x, y1 = p1.second + 1, y2 = p1.second - 1; x < M; ++x, ++x1, ++y1, --y2){
            if (x1 < M){
                if ('#' == board[x1][p1.second])
                    x1 = M;
                else
                    kill(board, x1, p1.second, dead);
            }
            if (y1 < N){
                if ('#' == board[x][y1])
                    y1 = N;
                else
                    kill(board, x, y1, dead);
            }
            if (0 <= y2){
                if ('#' == board[x][y2])
                    y2 = -1;
                else
                    kill(board, x, y2, dead);
            }
        }
        int x = p1.first, y = p1.second + 1;
        for (; y < N; ++y){
            if ('.' == board[x][y])
                live.push_back(make_pair(x, y));
        }
        for (++x; x < M; ++x){
            for (y = 0; y < N; ++y){
                if ('.' == board[x][y])
                    live.push_back(make_pair(x, y));
            }
        }
        ret += help(board, live);
        for (size_t j = 0; j < dead.size(); ++j)
            board[dead[j].first][dead[j].second] = '.';
    }
    return ret;
}

int solve(vector<vector<char> > & board)
{
    vector<pair<int, int> > left;
    for (size_t i = 0; i < board.size(); ++i){
        for (size_t j = 0; j < board[i].size(); ++j){
            if ('.' == board[i][j])
                left.push_back(make_pair(i, j));
        }
    }
    return help(board, left) % 1000000007;
}

void test()
{
    vector<vector<char> > board{ { '.', '#', '.','.' }, { '.', '.', '.' ,'.'} };
    cout << solve(board) << endl;
}

int main()
{
    //test(); return 0;

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<vector<char> > board(n);
        for (int i = 0; i < n; ++i){
            board[i].resize(m);
            string line;
            cin >> line;
            board[i].assign(line.begin(), line.end());
        }
        cout << solve(board) << endl;
    }
    return 0;
}