#include "../inc.h"

bool valid(const vector<string> & board, const pair<int, int> & pos)
{
    return (0 <= pos.first && pos.first < board.size() && 0 <= pos.second && pos.second < board[pos.first].size());
}

char sign(const vector<string> & board, const pair<int, int> & pos)
{
    assert(valid(board, pos));
    return board[pos.first][pos.second];
}

int distance(const pair<int, int> & p1, const pair<int, int> & p2)
{
    int r1 = p1.first - p2.first;
    if (r1 < 0)
        r1 = -r1;
    int r2 = p1.second - p2.second;
    if (r2 < 0)
        r2 = -r2;
    return r1 + r2;
}

int solve(const vector<string> & board, int steps)
{
    //find '*'
    pair<int, int> end;
    for (size_t i = 0; i < board.size(); ++i){
        size_t wh = board[i].find('*');
        if (wh != string::npos){
            end.first = i;
            end.second = wh;
            break;
        }
    }
    //walk through
    vector<pair<int, int> > path;
    pair<int, int> cur(0, 0), nearest(0, 0);
    path.push_back(cur);
    int dis = distance(cur, end);
    if (dis > steps)
        return -1;
    for (int i = 0; i < steps; ++i){
        switch (sign(board, cur)){
            case '*':return 0;
            case 'L':--cur.second; break;
            case 'R':++cur.second; break;
            case 'U':--cur.first; break;
            case 'D':++cur.first; break;
        }
        if (!valid(board, cur))
            break;
        path.push_back(cur);
        //calc nearest point
        int curdis = distance(cur, end);
        if (curdis < steps - 1 - i){
            if (curdis < dis){
                dis = curdis;
                nearest = cur;
            }
        }
    }
    //change char from 'nearest' to 'end'




    return ;
}

void test()
{
    cout << solve({ "RD", "*L" }, 3) << endl;
}

int main()
{
    test(); return 0;
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> board(n);
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    cout << solve(board, k) << endl;
    return 0;
}