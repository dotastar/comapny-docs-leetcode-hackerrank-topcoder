/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
/*
class Solution {
public:
    typedef unordered_set<UndirectedGraphNode *> __NodeSet;
    typedef unordered_map<int, UndirectedGraphNode *> __Label2Node;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return NULL;
        __NodeSet old;
        addNode(node, old);
        __Label2Node young;
        for(__NodeSet::const_iterator i = old.begin();i != old.end();++i)
            young[(*i)->label] = new UndirectedGraphNode((*i)->label);
        for(__NodeSet::const_iterator i = old.begin();i != old.end();++i){
            UndirectedGraphNode * o = *i;
            UndirectedGraphNode * n = old2New(o, young);
            for(size_t i = 0;i < o->neighbors.size();++i)
                n->neighbors.push_back(old2New(o->neighbors[i], young));
        }
        return old2New(node, young);
    }
    void addNode(UndirectedGraphNode * n, __NodeSet & set){
        assert(n);
        if(set.count(n))
            return;
        set.insert(n);
        for(size_t i = 0;i < n->neighbors.size();++i)
            addNode(n->neighbors[i], set);
    }
    UndirectedGraphNode * old2New(UndirectedGraphNode * n, __Label2Node & young){
        if(!n)
            return NULL;
        return young.find(n->label)->second;
    }
};

class Solution2 {
public:
    typedef unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> __Old2New;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return NULL;
        __Old2New old2new;
        createNew(node, old2new);
        for(__Old2New::iterator it = old2new.begin();it != old2new.end();++it)
            for(size_t i = 0;i < it->first->neighbors.size();++i)
                it->second->neighbors.push_back(old2new[it->first->neighbors[i]);
        return old2new[node];
    }
    void createNew(UndirectedGraphNode * node, __Old2New & set){
        if(!node)
            return;
        __Old2New::iterator wh = set.find(node);
        if(wh != set.end())
            return;
        set.insert(make_pair(node, new UndirectedGraphNode(node->label)));
        for(size_t i = 0;i < node->neighbors.size();++i)
            createNew(node->neighbors[i], set);
    }
};
*/

int main(){}