#include <cmath>
#include <cstdio>
#include <vector>
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
    vector<unsigned char> reach;
    explicit Sibling(int i = 0):id(i){}
    void add(int node){
        const size_t sz = (node + 7) / 8;
        if(reach.size() < sz + 1)
            reach.resize(sz + 1);
        reach[sz] |= (1 << (node % 8));
    }
    void add(const vector<unsigned char> & r){
        size_t i = 0;
        for(;i < reach.size() && i < r.size();++i)
            reach[i] |= r[i];
        if(i < r.size())
            reach.insert(reach.end(), r.begin() + i, r.end());
    }
    int contain(int node) const{
        if(reach.empty())
            return -1;
        const size_t sz = (node + 7) / 8;
        if(sz >= reach.size())
            return 0;
        return (0 == (reach[sz] & (1 << (node % 8))) ? 0 : 1);
    }
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

void show()
{
    cout<<"Nodes:\n";
    for(size_t i = 1;i < tree.size();++i)
        cout<<i<<": "<<tree[i].a<<' '<<tree[i].b<<endl;
    cout<<"Edges:\n";
    for(size_t i = 0;i < edge.size();++i){
        cout<<i<<':';
        const Edge & e = edge[i];
        for(int j = 0;j < 2;++j){
            const Sibling & s = e.sibling[j];
            cout<<"\n  "<<s.id;
            if(!s.reach.empty()){
                cout<<" {";
                for(size_t k = 1;k < tree.size();++k)
                    if(1 == s.contain(k))
                        cout<<k<<' ';
                cout<<'}';
            }
        }
        cout<<endl;
    }
}

void show(const vector<int> & p)
{
    cout<<"path: ";
    for(size_t i = 0;i < p.size();++i)
        cout<<p[i]<<' ';
    cout<<endl;
}

void help(Sibling & sibling)
{
    sibling.add(sibling.id);
    const Node & node = tree[sibling.id];
    for(size_t i = 0;i < node.edge.size();++i){
        Edge & e = edge[node.edge[i]];
        Sibling *s1, *s2;
        e.getSibling(sibling.id, s1, s2);
        if(&sibling == s1)
            continue;   //skip self
        help(*s2);
        sibling.add(s2->reach);
    }
}

void help(Edge & edge)
{
    help(edge.sibling[0]);
    help(edge.sibling[1]);
}

template<class F>
void solve(int from, int dst, F & func)
{
    func(tree[from]);
    for(int c = from;c != dst;){
        const Node & node = tree[c];
        for(size_t i = 0;i < node.edge.size();++i){
            Edge & e = edge[node.edge[i]];
            Sibling *s1, *s2;
            e.getSibling(c, s1, s2);
            if(s1->contain(dst) == 0 || s2->contain(dst) == 1){
                c = s2->id;
                func(tree[c]);
                break;
            }
        }
    }
}

struct T1
{
    Int a, b;
    void operator ()(Node & n) const{
        n.a = a;
        n.b = b;
    }
    T1(Int aa, Int bb):a(aa),b(bb){}
};

struct T2
{
    Int x;
    void operator ()(const Node & n){
        x = (n.a * x + n.b) % kMax;
    }
    explicit T2(Int xx):x(xx){}
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    tree.resize(n + 1);
    for(int i = 1;i <= n;++i)
        cin>>tree[i].a>>tree[i].b;
    edge.resize(n - 1);
    for(int i  = 0;i < n - 1;++i){
        int j, k;
        cin>>j>>k;
        edge[i].sibling[0].id = j;
        edge[i].sibling[1].id = k;
        tree[j].edge.push_back(i);
        tree[k].edge.push_back(i);
    }
    help(edge[0]);
show();
    cin>>n;
    while(n--){
        int t, u, v;
        Int a, b;
        cin>>t>>u>>v>>a;
        switch(t){
            case 1:{
                cin>>b;
                T1 t(a, b);
                solve(u, v, t);
show();
                break;}
            default:{
                T2 t(a);
                solve(u, v, t);
                cout<<t.x<<endl;
                break;}
        }
    }
    return 0;
}
