#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

struct Book{
    set<int> prev;
    vector<int> next;
};

map<int, Book> rel;
set<int> first;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        for(int c, p = 0;k--;p = c){
            cin>>c;
            if(p > 0){
                rel[p].next.push_back(c);
                rel[c].prev.insert(p);
            }else
                rel[c];
        }
    }
    for(const auto & b : rel)
        if(b.second.prev.empty())
            first.insert(b.first);
    while(!first.empty()){
        const int c = *first.begin();
        first.erase(first.begin());
        cout<<c<<' ';
        auto wh = rel.find(c);
        assert(rel.end() != wh);
        for(int n : wh->second.next){
            auto & b = rel[n];
            b.prev.erase(c);
            if(b.prev.empty())
                first.insert(n);
        }
    }
    cout<<endl;
    return 0;
}