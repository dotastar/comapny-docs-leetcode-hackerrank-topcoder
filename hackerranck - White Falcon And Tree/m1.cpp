#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long Int;

const Int kMax = 1000000000ULL + 7;

struct Node
{
    Int a, b;
    vector<int> sibling;
};

vector<Node> tree;

bool help(vector<int> & path, int dst)
{
    if(path.back() == dst)
        return true;
    const Node & node = tree[path.back()];
    const int p = (path.size() < 2 ? 0 : *(path.rbegin() + 1));
    for(size_t i = 0;i < node.sibling.size();++i){
        const int n = node.sibling[i];
        if(n == p)
            continue;
        path.push_back(n);
        if(help(path, dst))
            return true;
        path.pop_back();
    }
    return false;
}

void solve(int u, int v, Int a, int b)
{
    vector<int> path(1, u);
    help(path, v);
    for(size_t i = 0;i < path.size();++i){
        Node & n = tree[path[i]];
        n.a = a;
        n.b = b;
    }
}

void solve(int u, int v, Int x)
{
    vector<int> path(1, u);
    help(path, v);
    for(size_t i = 0;i < path.size();++i){
        const Node & n = tree[path[i]];
        x = (n.a * x + n.b) % kMax;
    }
    cout<<x<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    tree.resize(n + 1);
    for(int i = 1;i <= n;++i)
        cin>>tree[i].a>>tree[i].b;
    for(int i  = 1;i < n;++i){
        int j, k;
        cin>>j>>k;
        tree[j].sibling.push_back(k);
        tree[k].sibling.push_back(j);
    }
    cin>>n;
    while(n--){
        int t, u, v;
        Int a, b;
        cin>>t>>u>>v>>a;
        switch(t){
            case 1:
                cin>>b;
                solve(u, v, a, b);
                break;
            default:
                solve(u, v, a);
        }
    }
    return 0;
}
