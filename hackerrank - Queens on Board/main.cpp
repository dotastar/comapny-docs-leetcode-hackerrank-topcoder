#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <cassert>
#include <cstring>

using namespace std;

//simulation
//O(S^S), S=M*N
class Solution1
{
    void print(const vector<string> & board, size_t live, const string & dead){
        const int M = board.size(), N = board[0].size();
        for (int i = 0; i < M; ++i){
            for (int j = 0; j < N; ++j){
                cout << board[i][j];
            }
            cout << endl;
        }
        cout << "--- " << live;
        if (!dead.empty()){
            cout << ' ';
            for (size_t i = 0; i < dead.size(); ++i){
                const pair<int, int> & p = unhash(dead[i]);
                cout << '(' << p.first << ',' << p.second << ')';
            }
        }
        cout << endl;
        system("pause");
    }
    void kill(vector<string> & board, int x, int y, string & dead){
        if ('.' == board[x][y]){
            dead.push_back(tohash(x, y));
            board[x][y] = 'O';
        }
    }
    long long help(vector<string> & board, const string & left){
        const int M = board.size(), N = board[0].size();
        long long ret = left.size();
        for (size_t i = 0; i < left.size(); ++i){
            const pair<int, int> & p1 = unhash(left[i]);
            board[p1.first][p1.second] = 'X';
            string live, dead(1, left[i]);
            for (int y = p1.second + 1; y < N; ++y){
                if ('#' == board[p1.first][y])
                    break;
                kill(board, p1.first, y, dead);
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
                    live.push_back(tohash(x, y));
            }
            for (++x; x < M; ++x){
                for (y = 0; y < N; ++y){
                    if ('.' == board[x][y])
                        live.push_back(tohash(x, y));
                }
            }
            //print(board, live.size(), dead);
            ret += help(board, live);
            for (size_t j = 0; j < dead.size(); ++j){
                const pair<int, int> & p = unhash(dead[j]);
                board[p.first][p.second] = '.';
            }
        }
        return (ret % 1000000007);
    }
    char tohash(size_t i, size_t j){ return i * 5 + j; }
    pair<int, int> unhash(char h){ return make_pair(h / 5, h % 5); }
public:
    int solve(const vector<string> & B){
        vector<string> board(B);
        string left;
        for (size_t i = 0; i < board.size(); ++i){
            for (size_t j = 0; j < board[i].size(); ++j){
                if ('.' == board[i][j])
                    left.push_back(tohash(i, j));
            }
        }
        print(board, left.size(), string());
        return help(board, left) % 1000000007;
    }
};

struct Solution2
{
    typedef basic_string<unsigned char> __Board;
    typedef __Board::value_type         __Row;
    long long solve(const vector<string> & B){
        if (B.empty() || B[0].empty())
            return 0;
        //transform to bits representation
        for (size_t i = 0; i < B.size(); ++i){
            __Row row = 0;
            for (size_t j = 0; j < B[i].size(); ++j){
                if ('.' == B[i][j])
                    row |= (1 << j);
            }
            row = ~row;
            board.push_back(row);
            //generate possible placements for each row
            __Board p;
            genPlacements(row, p, B[i].size());
            placements.push_back(p);
        }
        bmask = (1 << B[0].size()) - 1;
        return help(0, 0, 0, 0);
    }
private:
    static void genPlacements(__Row block, __Board & ret, int M){
        for (int i = 0; i < M; ++i){
            //one Q
            __Row p1 = 1 << i;
            if (0 != (p1 & block))
                continue;
            ret.push_back(p1);
            //two Qs
            for (int j = i + 2; j < M; ++j){
                __Row p2 = p1 | (1 << j);
                if (0 != (p2 & block))
                    continue;
                __Row m2 = (1 << j) - (1 << (i + 1));
                if (0 == (m2 & block))
                    continue;   //there is no block between Qs
                ret.push_back(p2);
                //three Qs
                for (int k = j + 2; k < M; ++k){
                    __Row p3 = p2 | (1 << k);
                    if (0 != (p3 & block))
                        continue;
                    __Row m3 = ((1 << k) - (1 << (j + 1)));
                    if (0 == (m3 & block))
                        continue;   //there is no block between Q 2 and 3
                    ret.push_back(p3);
                }
            }
        }
    }
    __Row calcMask(__Row mask, __Row blocks){
        __Row b = mask & blocks;    //mask bits that hit the blocks
        mask &= ~b;
        return (mask & bmask);  //make sure mask does not exceed the boarder region
    }
    static int hash(size_t row, __Row lmask, __Row dmask, __Row rmask){
        int r = row;
        r <<= 8;
        r += lmask;
        r <<= 8;
        r += dmask;
        r <<= 8;
        r += rmask;
        return r;
    }
    long long help(size_t row, __Row lmask, __Row dmask, __Row rmask){
        if (row >= board.size())
            return 0;
        //rm blocked masks
        const __Row blocks = board[row];
        lmask = calcMask(lmask, blocks);
        dmask = calcMask(dmask, blocks);
        rmask = calcMask(rmask, blocks);
        //search for saved results
        const int h = hash(row, lmask, dmask, rmask);
        unordered_map<int, long long>::const_iterator wh = save.find(h);
        if (wh != save.end())
            return wh->second;
        //try all placements
        const __Row mask = lmask | dmask | rmask | blocks;    //real mask
        long long ret = 0;
        if (__Row(-1) != mask){
            const __Board & ps = placements[row];
            for (size_t i = 0; i < ps.size(); ++i){
                const __Row p = ps[i];
                if (0 != (mask & p))
                    continue;   //invalid placement
                ++ret;
                //next row
                ret += help(row + 1, (lmask | p) << 1, dmask | p, (rmask | p) >> 1);
            }
        }
        ret += help(row + 1, lmask << 1, dmask, rmask >> 1);
        return (save[h] = (ret % 1000000007));
    }
    __Board board;  //each unsigned char of M bits represents a row, ".#." -> 010
    vector<__Board> placements;
    unordered_map<int, long long> save;
    __Row bmask;    //boarder mask, 2^M - 1
};

typedef Solution2 Solution;

void test()
{
    {
        vector<string> board{
        ".#...",
        };
        cout << Solution().solve(board) << endl;    //7
    }
    {
        vector<string> board{
        ".....",
        ".....",
        ".....",
        ".....",
        ".....",
        ".....",
        ".....",
        ".....",
        ".....",
        ".....",
        };
        cout << Solution().solve(board) << endl;
    }

    {
        vector<string> board{
        "..###",
        "...#.",
        "###.#",
        "#...#",
        ".#...",
        ".....",
        "..#..",
        "#.#..",
        "##.#.",
        "..###",
        ".#.#.",
        "#.#..",
        "..###",
        ".#.##",
        "###.#",
        ".....",
        "##..#",
        "..#.#",
        ".....",
        "##..#",
        ".##..",
        ".####",
        "###..",
        ".##.#",
        ".#.#.",
        "##..#",
        "#.###",
        "...##",
        ".##..",
        "####.",
        "#...#",
        "#.###",
        "##.##",
        "###.#",
        "####.",
        ".##..",
        "..#.#",
    };
        cout << Solution().solve(board) << endl;    //805129382
    }
    {
        vector<string> board{
        "#",
        ".",
        "#",
        ".",
        "#",
        "#",
        ".",
        "#",
        ".",
        "#",
        "#",
        "#",
        "#",
        "#",
        ".",
        ".",
        "#",
        ".",
        "#",
        "#",
        "#",
        "#",
        ".",
        "#",
        "#"
    };
        cout << Solution().solve(board) << endl;    //191
    }{
        vector<string> board{ ".#..", "...."};
        cout << Solution().solve(board) << endl;    //14
    }{
        vector<string> board{ "...", "...", "..." };
        cout << Solution().solve(board) << endl;    //17
    }{
        vector<string> board{
            ".#.",
            ".#.",
            "..."
        };
        cout << Solution().solve(board) << endl;    //18
    }{
        vector<string> board{
        "..",
        "..",
        "##",
        "..",
        "#.",
        "#.",
        ".#",
        "##",
        "##",
        ".#",
        "..",
        "##",
        "#.",
        "..",
        ".#",
        "##",
        "..",
        ".#",
        ".#",
        "..",
        "..",
        "#.",
        "##",
        ".#",
        ".#",
        ".#",
        "#.",
        "##",
        "#.",
        "..",
        "#.",
        "#.",
        "#.",
        ".."
        };
        cout << Solution().solve(board) << endl;    //4233599
    }
}

int main()
{
    test(); return 0;
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<string> b;
        for (int i = 0; i < n; ++i){
            string line;
            cin >> line;
            b.push_back(line);
        }
        cout << Solution().solve(b) << endl;
    }
    return 0;
}