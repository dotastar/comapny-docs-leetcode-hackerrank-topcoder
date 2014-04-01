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

using namespace std;

#define unordered_map map
#define unordered_set set

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

 
void print(const vector<int> & r)
{
    for(size_t j = 0;j < r.size();++j)
        cout<<r[j]<<" ";
    cout<<endl;
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
    vector<const TreeNode *> t(1, root);
    for(size_t i = 0, e = t.size();i < e;++i){
        root = t[i];
        if(root){
            cout<<root->val<<" ";
            t.push_back(root->left);
            if(root->left)
                e = t.size();
            t.push_back(root->right);
            if(root->right)
                e = t.size();
        }else
            cout<<"# ";
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
