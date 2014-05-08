#include "../inc.h"

const int kDir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

struct Solution1
{
    Solution1(vector<vector<int>> & B, int k) :K(k){
        board.swap(B);
    }
    long long solve(int Ex, int Ey, int Sx, int Sy, int tx, int ty){
        Tx = --tx; Ty = --ty;
        visit.clear();
        visit.resize(board.size(), vector<bool>(board.front().size()));
        visit[--Sx][--Sy] = true;
        saveE.clear();
        return moveS(--Ex, --Ey, Sx, Sy);
    }
private:
    long long moveS(int Ex, int Ey, int Sx, int Sy){
        if (Sx == Tx && Sy == Ty)
            return 0;
        const auto h = hash(Ex, Ey, Sx, Sy);
        auto wh = saveE.find(h);
        if (wh != saveE.end())
            return wh->second;
        long long ret = -1;
        for (int i = 0; i < 4; ++i){
            const int nx = Sx + kDir[i][0];
            const int ny = Sy + kDir[i][1];
            if (!valid(nx, ny) || visit[nx][ny])
                continue;
            board[Sx][Sy] = 0;
            int r1 = moveE(Ex, Ey, nx, ny) + 1;
            board[Sx][Sy] = 1;
            visit[nx][ny] = true;
            long long r2 = moveS(Sx, Sy, nx, ny);
            visit[nx][ny] = false;
            if (r2 < 0)
                continue;
            r2 += r1;
            if (ret < 0 || ret > r2)
                ret = r2;
        }
        return (saveE[h] = ret);
    }
    int moveE(int Ex, int Ey, int Nx, int Ny) const{
        vector<vector<bool>> v(board.size(), vector<bool>(board.front().size()));
        vector<pair<int, int>> cur, tmp;
        cur.push_back(make_pair(Ex, Ey));
        v[Ex][Ey] = true;
        for (int ret = 0; !cur.empty() && ret < K; ++ret){
            for (size_t i = 0; i < cur.size(); ++i){
                const int x = cur[i].first;
                const int y = cur[i].second;
                if (x == Nx && y == Ny)
                    return ret;
                for (int i = 0; i < 4; ++i){
                    const int nx = x + kDir[i][0];
                    const int ny = y + kDir[i][1];
                    if (!valid(nx, ny) || v[nx][ny])
                        continue;
                    tmp.push_back(make_pair(nx, ny));
                    v[nx][ny] = true;
                }
            }
            cur.swap(tmp);
            tmp.clear();
        }
        return K;
    }
    bool valid(int x, int y) const{
        return (0 <= x && x < int(board.size()) && 0 <= y && y < int(board.front().size())
            && board[x][y] == 1);
    }
    static unsigned int hash(int Ex, int Ey, int Sx, int Sy){
        unsigned int r = Ex;
        r = (r << 8) + Ey;
        r = (r << 8) + Sx;
        r = (r << 8) + Sy;
        return r;
    }
    vector<vector<int>> board;
    vector<vector<bool>> visit;
    unordered_map<unsigned int, long long> saveE;
    int K;
    int Tx, Ty;
};

typedef Solution1 Solution;

void test()
{
    srand(time(0));
    for(;0;){
        int n = genRand(10, 100);
        int m = genRand(10, 100);
        vector<vector<int>> B(n, vector<int>(m, 1));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (genRand(0, 10) < 2)
                    B[i][j] = 0;
            }
        }
        int Ex = genRand(0, n - 1);
        int Ey = genRand(0, m - 1);
        int Sx, Sy;
        do{
            Sx = genRand(0, n - 1);
            Sy = genRand(0, m - 1);
        } while (Ex == Sx && Ey == Sy);
        int Tx = genRand(0, n - 1);
        int Ty = genRand(0, m - 1);
        //print(B);
        int K = genRand(5, 50);
        cout << "n, m, K: " << n << ' ' << m << ' ' << K << endl;
        B[Ex][Ey] = B[Sx][Sy] = B[Tx][Ty] = 1;
        cout << (Ex + 1) << ' '
            << (Ey + 1) << ' '
            << (Sx + 1) << ' '
            << (Sy + 1) << ' '
            << (Tx + 1) << ' '
            << (Ty + 1) << endl;
        Solution s(B, K);
        cout << s.solve(Ex + 1, Ey + 1, Sx + 1, Sy + 1, Tx + 1, Ty + 1) << endl;
    }
    {
        vector<vector<int>> B{
            { 1, 1, 0 },
            { 1, 0, 1 },
        };
        Solution s(B, 12);
        cout << s.solve(1, 2, 1, 1, 2, 3) << endl;  //-1
    }
    {
        vector<vector<int>> B{
            { 1, 1, 1, 1, 1 },
            { 1, 0, 1, 0, 1 },
            { 0, 1, 0, 1, 1 },
            { 1, 1, 1, 0, 0 },
            { 0, 1, 1, 1, 1 }
        };
        Solution s(B, 12);
        cout << s.solve(1, 5, 4, 3, 4, 1) << endl;  //26
    }
}

int main()
{
    test(); return 0;
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<vector<int>> B(n, vector<int>(m));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j)
            cin >> B[i][j];
    }
    Solution s(B, k);
    while (q-- > 0){
        int Ex, Ey, Sx, Sy, Tx, Ty;
        cin >> Ex >> Ey >> Sx >> Sy >> Tx >> Ty;
        cout << s.solve(Ex, Ey, Sx, Sy, Tx, Ty) << endl;
    }
}