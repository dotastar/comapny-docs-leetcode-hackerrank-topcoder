#include <vector>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>
#include <queue>
#include <functional>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <utility>

using namespace std;

//#define unordered_map map
//#define unordered_set set

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct Box
{
    int h, w, d;
    Box(){}
    Box(int i, int j, int k) :h(i), w(j), d(k){}
    bool operator >(const Box & a) const{
        return (d > a.d);
    }
};
 
void print(const vector<int> & r)
{
    for(size_t j = 0;j < r.size();++j)
        cout<<r[j]<<" ";
    cout<<endl;
}

void print(const vector<long long> & r)
{
    for (size_t j = 0; j < r.size(); ++j)
        cout << r[j] << " ";
    cout << endl;
}

void print2(const vector<int> & r)
{
    for (size_t j = 0; j < r.size(); ++j){
        if (j)
            cout << ", ";
        cout << r[j];
    }
    cout << endl;
}

void print(const vector<double> & r)
{
    for(size_t j = 0;j < r.size();++j)
        cout<<r[j]<<" ";
    cout<<endl;
}

void print(const vector<pair<int, int> > & r)
{
    for(size_t j = 0;j < r.size();++j)
        cout<<"("<<r[j].first<<","<<r[j].second<<") ";
    cout<<endl;
}

void print(const vector<vector<int> > & r)
{
    for(size_t i = 0;i < r.size();++i)
        print(r[i]);
}

void print(ListNode * h){
    while(h){
        cout<<h->val<<"->";
        h = h->next;
    }
    cout<<endl;
}

void print(const vector<vector<char> > & board)
{
    for(size_t i = 0;i < board.size();++i){
        for(size_t j = 0;j < board[i].size();++j){
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
}

void printXO(const vector<vector<char> > & board)
{
    for(size_t i = 0;i < board.size();++i){
        cout<<i<<'\t';
        for(size_t j = 0;j < board[i].size();++j)
            cout<<('X' == board[i][j] ? 'X' : '_');
        cout<<endl;
    }
}

void printLine(const vector<string> & lines)
{
    for(size_t i = 0;i < lines.size();++i)
        cout<<lines[i]<<endl;
}

void print(const vector<vector<string> > & path)
{
    for(size_t i = 0;i < path.size();++i){
        cout<<'[';
        for(size_t j = 0;j < path[i].size();++j){
            if(j)
                cout<<",";
            cout<<path[i][j];
        }
        cout<<"]\n";
    }
    cout<<endl;
}

void print(const TreeNode * root)
{
    vector<const TreeNode *> t = {root};
    while(!t.empty()) {
        vector<const TreeNode *> tt;
        for(size_t i = 0; i < t.size(); ++i) {
            root = t[i];
            if(root) {
                cout << root->val << " ";
                tt.push_back(root->left);
                tt.push_back(root->right);
            } else
                cout << "# ";
        }
        while(!tt.empty() && !tt.back())
            tt.pop_back();
        if(!tt.empty())
            cout << "| ";
        t.swap(tt);
    }
    cout<<endl;
}

void print(const vector<string> & ss)
{
    for(size_t i = 0;i < ss.size();++i)
        cout<<ss[i]<<" ";
    cout<<endl;
}

void print(const set<int> & s)
{
    for(set<int>::const_iterator i = s.begin();i != s.end();++i)
        cout<<*i<<' ';
    cout<<endl;
}

void print(const vector<Box> & b)
{
    for (size_t i = 0; i < b.size(); ++i)
        cout << "(" << b[i].h << "," << b[i].w << "," << b[i].d << ") ";
    cout << endl;
}

int genRand(int from, int to)
{
    int range = to - from + 1;
    if (range <= 0)
        return 0;
    int r = rand();
    r <<= 16;
    r += rand();
    return (r % range + from);
}

template<typename T>
void genArray(vector<T> & A, int count, int from, int to)
{
    for (int i = 0; i < count; ++i)
        A.push_back(genRand(from, to));
}

void genPairArray(vector<pair<int, int> > & A, int count, int from, int to)
{
    for (int i = 0; i < count; ++i)
        A.push_back(make_pair(genRand(from, to), genRand(from, to)));
}

void genBoxArray(vector<Box> & A, int count, int from, int to)
{
    for (int i = 0; i < count; ++i)
        A.push_back(Box(genRand(from, to), genRand(from, to), genRand(from, to)));
}
