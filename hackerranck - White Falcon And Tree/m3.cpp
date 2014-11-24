#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long Int;

const Int kMax = 1000000000ULL + 7;

struct Node
{
    Int a, b;
    vector<int> edge;
};

struct Sibling
{
    int id;
    set<int> reach;
    explicit Sibling(int i = 0):id(i){}
};

struct Edge
{
    Sibling sibling[2];
    void getSibling(int id, Sibling *& n1, Sibling *& n2){
        n1 = &sibling[0];
        n2 = &sibling[1];
        if(sibling[0].id != id)
            swap(n1, n2);
    }
};

vector<Node> tree;
vector<Edge> edge;

void help(Sibling & sibling)
{
    sibling.reach.insert(sibling.id);
    const Node & node = tree[sibling.id];
    for(size_t i = 0;i < node.edge.size();++i){
        Edge & e = edge[node.edge[i]];
        Sibling *s1, *s2;
        e.getSibling(sibling.id, s1, s2);
        if(&sibling == s1)
            continue;   //skip self
        help(*s2);
        sibling.reach.insert(s2->reach.begin(), s2->reach.end());
    }
}

void help(Edge & edge)
{
    help(edge.sibling[0]);
    help(edge.sibling[1]);
}

void help(vector<int> & path, int dst)
{
    while(path.back() != dst){
        const int c = path.back();
        const Node & node = tree[c];
        for(size_t i = 0;i < node.edge.size();++i){
            Edge & e = edge[node.edge[i]];
            Sibling *s1, *s2;
            e.getSibling(c, s1, s2);
            if((!s1->reach.empty() && s1->reach.count(dst) == 0)
                    || (!s2->reach.empty() && s2->reach.count(dst) > 0)){
                path.push_back(s2->id);
//cout<<"add "<<s2->id<<endl;
                break;
            }
        }
    }
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
    edge.resize(n);
    for(int i  = 0;i < n - 1;++i){
        int j, k;
        cin>>j>>k;
        edge[i].sibling[0].id = j;
        edge[i].sibling[1].id = k;
        tree[j].edge.push_back(i);
        tree[k].edge.push_back(i);
    }
    help(edge[0]);
//cout<<"begin\n";
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
