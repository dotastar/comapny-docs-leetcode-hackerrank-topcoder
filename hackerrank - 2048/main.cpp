#include "../inc.h"

enum EMove{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

string moveString(EMove m)
{
    switch (m){
        case LEFT:return "LEFT";
        case RIGHT:return "RIGHT";
        case UP:return "UP";
        case DOWN:return "DOWN";
    }
    return "UNKNOWN";
}

struct Rules
{
    static bool addTile(vector<vector<int>> & board){
        vector<pair<int, int>> zero;
        for (size_t i = 0; i < board.size(); ++i){
            for (size_t j = 0; j < board[i].size(); ++j){
                if (!board[i][j])
                    zero.push_back(make_pair(i, j));
            }
        }
        if (zero.empty())
            return false;
        int r = rand() % zero.size();
        board[zero[r].first][zero[r].second] = addValue();
        return true;
    }
    static int addValue(){ return (0 == (rand() % 4) ? 4 : 2); }
    static pair<bool, int> move(vector<vector<int>> & board, EMove m){
        switch (m)        {
            case LEFT:return moveLeft(board);
            case RIGHT:return moveRight(board);
            case UP:return moveUp(board);
        }
        return moveDown(board);
    }
    static bool checkAlive(const vector<vector<int>> & board){
        for (size_t i = 0; i < board.size(); ++i){
            for (size_t j = 0; j < board[i].size(); ++j){
                if (!board[i][j])
                    return true;
                if (j && board[i][j - 1] == board[i][j])
                    return true;
                if (i && board[i - 1][j] == board[i][j])
                    return true;
            }
        }
        return false;
    }
    static void printBoard(const vector<vector<int>> & board){
        for (size_t i = 0; i < board.size(); ++i){
            for (size_t j = 0; j < board[i].size(); ++j)
                cout << board[i][j] << '\t';
            cout << endl;
        }
    }
    static int high(const vector<vector<int>> & board){
        int r = 0;
        for (size_t i = 0; i < board.size(); ++i){
            for (size_t j = 0; j < board[i].size(); ++j)
                r = max(r, board[i][j]);
        }
        return r;
    }
private:
    static pair<bool, int> moveLeft(vector<vector<int>> & board){
        int r = 0, score = 0;
        for (size_t i = 0; i < board.size(); ++i){
            vector<int> & v = board[i];
            for (size_t c = 0, j = 0; j < v.size();){
                if (v[j] && c != j){
                    if (v[c] == v[j]){
                        score += (v[c] += v[j]);
                        v[j++] = 0;
                        ++r;
                    } else if (!v[c]){
                        swap(v[c], v[j++]);
                        ++r;
                    } else
                        ++c;
                } else
                    ++j;
            }
        }
        return make_pair((r > 0), score);
    }
    static pair<bool, int> moveRight(vector<vector<int>> & board){
        int r = 0, score = 0;
        for (size_t i = 0; i < board.size(); ++i){
            vector<int> & v = board[i];
            for (size_t c = v.size() - 1, j = c; j < v.size();){
                if (v[j] && c != j){
                    if (v[c] == v[j]){
                        score += (v[c] += v[j]);
                        v[j--] = 0;
                        ++r;
                    } else if (!v[c]){
                        swap(v[c], v[j--]);
                        ++r;
                    } else
                        --c;
                } else
                    --j;
            }
        }
        return make_pair((r > 0), score);
    }
    static pair<bool, int> moveUp(vector<vector<int>> & board){
        int r = 0, score = 0;
        for (size_t j = 0; j < board[0].size(); ++j){
            for (size_t c = 0, i = 0; i < board.size();){
                if (board[i][j] && c != i){
                    if (board[c][j] == board[i][j]){
                        score += (board[c][j] += board[i][j]);
                        board[i++][j] = 0;
                        ++r;
                    } else if (!board[c][j]){
                        swap(board[c][j], board[i++][j]);
                        ++r;
                    } else
                        ++c;
                } else
                    ++i;
            }
        }
        return make_pair((r > 0), score);
    }
    static pair<bool, int> moveDown(vector<vector<int>> & board){
        int r = 0, score = 0;
        for (size_t j = 0; j < board[0].size(); ++j){
            for (size_t c = board.size() - 1, i = c; i < board.size();){
                if (board[i][j] && c != i){
                    if (board[c][j] == board[i][j]){
                        score += (board[c][j] += board[i][j]);
                        board[i--][j] = 0;
                        ++r;
                    } else if (!board[c][j]){
                        swap(board[c][j], board[i--][j]);
                        ++r;
                    } else
                        --c;
                } else
                    --i;
            }
        }
        return make_pair((r > 0), score);
    }
};

template<class S>
class Game
{
    typedef S   __Solution;
public:
    explicit Game(bool d = false)
        : board(4, vector<int>(4))
        , sc(0)
        , step(0)
        , debug(d)
    {
        Rules::addTile(board);
    }
    void run(){
        EMove m = LEFT;
        if (debug)
            printStep(m);
        for (int nop = 0;; ){
            m = next();
            pair<bool, int> r = Rules::move(board, m);
            if (r.first){
                Rules::addTile(board);
                nop = 0;
                sc += r.second;
                ++step;
                if (debug)
                    printStep(m);
            } else if (!Rules::checkAlive(board) || ++nop > 50)
                break;
        }
    }
    void print() const{
        if(!debug)
            printStep(LEFT);
        cout << "Score: " << sc << endl;
    }
    int score() const{ return sc; }
    int steps() const{ return step; }
    int high() const{ return Rules::high(board); }
private:
    EMove next() const{ return so.nextMove(board); }
    void printStep(EMove m) const{
        if (step)
            cout << "Step: " << step << '\t' << moveString(m) << endl;
        Rules::printBoard(board);
    }
    //fields
    vector<vector<int>> board;
    int sc, step;
    bool debug;
    mutable __Solution so;
};

struct SolutionRandom
{
    EMove nextMove(const vector<vector<int>> & board) {
        return randMove();
    }
    static EMove randMove(){
        switch (rand() % 4){
            case 0:return LEFT;
            case 1:return RIGHT;
            case 2:return UP;
        }
        return DOWN;
    }
};

struct SolutionGreedy
{
    EMove nextMove(const vector<vector<int>> & board) {
        init();
        //test
        testMove(board, LEFT);
        testMove(board, RIGHT);
        testMove(board, UP);
        testMove(board, DOWN);
        return mo;
    }
    void init(){
        mo = LEFT;
        s = 0;
    }
    void testMove(const vector<vector<int>> & board, EMove m){
        int r = moveScore(board, m);
        if (r > s){
            mo = m;
            s = r;
        }
    }
    static int moveScore(vector<vector<int>> board, EMove m){
        pair<bool, int> r = Rules::move(board, m);
        r.second += (r.first ? 1 : 0);
        return r.second;
    }
    EMove move() const{ return mo; }
    int score() const{ return s; }
private:
    EMove mo;
    int s;
};

struct SolutionGreedyNoDown
{
    EMove nextMove(const vector<vector<int>> & board) {
        so.init();
        so.testMove(board, UP);
        so.testMove(board, LEFT);
        so.testMove(board, RIGHT);
        return (so.score() ? so.move() : DOWN);
    }
private:
    SolutionGreedy so;
};

struct SolutionGreedyNoDownRand
{
    EMove nextMove(const vector<vector<int>> & board) {
        vector<int> s;
        int sum = 0;
        s.push_back(SolutionGreedy::moveScore(board, UP));
        sum += s.back();
        s.push_back(SolutionGreedy::moveScore(board, LEFT));
        sum += s.back();
        s.push_back(SolutionGreedy::moveScore(board, RIGHT));
        sum += s.back();
        if (!sum)
            return DOWN;
        int r = rand() % sum;
        if (r < s[0])
            return UP;
        r -= s[0];
        return (r < s[1] ? LEFT : RIGHT);
    }
};

template<int N>
struct SolutionSquare
{
    EMove nextMove(const vector<vector<int>> & board) {
        vector<int> s;
        int sum = 0;
        s.push_back(square(SolutionGreedy::moveScore(board, UP)));
        sum += s.back();
        s.push_back(square(SolutionGreedy::moveScore(board, LEFT)));
        sum += s.back();
        s.push_back(square(SolutionGreedy::moveScore(board, RIGHT)));
        sum += s.back();
        if (!sum)
            return DOWN;
        int r = rand() % sum;
        if (r < s[0])
            return UP;
        r -= s[0];
        return (r < s[1] ? LEFT : RIGHT);
    }
    static int square(int v){
        int r = v;
        for (int i = 1; i < N; ++i)
            r *= v;
        return r;
    }
};

struct SolutionIntelly
{
    EMove nextMove(const vector<vector<int>> & board) {
    }
};

typedef SolutionGreedyNoDownRand Solution;

struct IntSet
{
    IntSet() :sum(0), cnt(0){}
    void add(int v){
        if (!cnt)
            ma = mi = v;
        else{
            if (v > ma)
                ma = v;
            if (v < mi)
                mi = v;
        }
        sum += v;
        ++cnt;
    }
    int ave() const{
        if (!cnt)
            return 0;
        return (sum / cnt);
    }
    int max() const{ return (cnt ? ma : 0); }
    int min() const{ return (cnt ? mi : 0); }
private:
    int ma, mi, sum, cnt;
};


template<class S>
void testSolution(const char * name)
{
    IntSet score, steps, high;
    for (int i = 0; i < 100; ++i){
        Game<S> g;
        g.run();
        score.add(g.score());
        steps.add(g.steps());
        high.add(g.high());
    }
    cout << name
        << ":\n  score: " << score.ave() << " [" << score.min() << ", " << score.max() << "]"
        << "\n  steps: " << steps.ave() << " [" << steps.min() << ", " << steps.max() << "]"
        << "\n  high: " << high.max()
        << endl;
}

void benchmark()
{
#define __BENCH_MARK(S) testSolution<S>(#S)
    //__BENCH_MARK(SolutionRandom);
    //__BENCH_MARK(SolutionGreedy);
    __BENCH_MARK(SolutionGreedyNoDown);
    __BENCH_MARK(SolutionGreedyNoDownRand);
    __BENCH_MARK(SolutionSquare<2>);
    __BENCH_MARK(SolutionSquare<3>);
    __BENCH_MARK(SolutionSquare<4>);
#undef __BENCH_MARK
}


void test()
{
    Game<Solution> g(0);
    g.run();
    g.print();
}

int main()
{
    srand((unsigned int)time(NULL));

    benchmark();
    //test();
    return 0;


}