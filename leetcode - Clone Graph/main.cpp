#include "../inc.h"

class Solution {
public:
    typedef unordered_set<UndirectedGraphNode *> __NodeSet;
    typedef unordered_map<int, UndirectedGraphNode *> __Label2Node;
    //O(N^2 * logN)
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return NULL;
        __NodeSet old;
        addNode(node, old); //add all old graph nodes to set 'old', recursively, O(NlogN)
        __Label2Node young;
        //create new nodes according to set 'old', O(N)
        for(__NodeSet::const_iterator i = old.begin();i != old.end();++i)
            young[(*i)->label] = new UndirectedGraphNode((*i)->label);
        //copy neighborhood of old node, O(N*N*logN)
       for(__NodeSet::const_iterator i = old.begin();i != old.end();++i){
            UndirectedGraphNode * o = *i;   //old node
            UndirectedGraphNode * n = old2New(o, young); //new node, O(logN)
            for(size_t i = 0;i < o->neighbors.size();++i)   //O(NlogN)
                n->neighbors.push_back(old2New(o->neighbors[i], young));
        }
        return old2New(node, young);
    }
    void addNode(UndirectedGraphNode * n, __NodeSet & set){
        assert(n);
        if(set.count(n))    //O(logN)
            return;
        set.insert(n);
        for(size_t i = 0;i < n->neighbors.size();++i)
            addNode(n->neighbors[i], set);
    }
    //find coordinate new old, O(logN)
    UndirectedGraphNode * old2New(UndirectedGraphNode * n, __Label2Node & young){
        if(!n)
            return NULL;
        return young.find(n->label)->second;
    }
};

class Solution2 {
public:
    typedef unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> __Old2New;
    //O(N^2 * logN)
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return NULL;
        __Old2New old2new;
        createNew(node, old2new);   //O(NlogN)
        //copy neighborhood of old node, O(N*N*logN)
        for(__Old2New::iterator it = old2new.begin();it != old2new.end();++it)
            for(size_t i = 0;i < it->first->neighbors.size();++i)
                it->second->neighbors.push_back(old2new[it->first->neighbors[i]]);
        return old2new[node];
    }
    //O(NlogN)
    void createNew(UndirectedGraphNode * node, __Old2New & set){
        if(!node)
            return;
        __Old2New::iterator wh = set.find(node);    //O(logN)
        if(wh != set.end())
            return;
        set.insert(make_pair(node, new UndirectedGraphNode(node->label)));
        for(size_t i = 0;i < node->neighbors.size();++i)
            createNew(node->neighbors[i], set);
    }
};

int main(){}