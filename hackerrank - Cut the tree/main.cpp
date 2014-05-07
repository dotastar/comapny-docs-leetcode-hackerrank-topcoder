#include "../inc.h"

struct Solution
{
    int solve(vector<int> & N, vector<pair<int, int>> & E){
        nodes.swap(N);
        edges.swap(E);
        node2edge.resize(nodes.size());   //each node has at most 3 edges
        for (size_t i = 0; i < edges.size(); ++i){
            node2edge[edges[i].first - 1].push_back(i);
            node2edge[edges[i].second - 1].push_back(i);
        }
        edge2sum.resize(edges.size());
        const int sum = calcEdgeSum(0, -1);
        int ret = sum;
        for (auto s : edge2sum){
            int r = sum - s;
            r = max(r, s) - min(r, s);
            ret = min(r, ret);
        }
        return ret;
    }
private:
    int calcEdgeSum(int nidx, int eidx){
        const auto & e = node2edge[nidx];
        int ret = nodes[nidx];
        for (auto i : e){
            if (eidx == i)
                continue;
            const auto & p = edges[i];
            int n = p.first - 1;    //get the other side
            if (n == nidx)
                n = p.second - 1;
            ret += (edge2sum[i] = calcEdgeSum(n, i));
        }
        return ret;
    }
    vector<int> nodes;
    vector<pair<int, int>> edges;
    vector<vector<int>> node2edge;
    vector<int> edge2sum;
};

void test()
{
    vector<int> N{ 100, 200, 100, 500, 100, 600 };
    vector<pair<int, int>> E{ { 1, 2 }, { 2, 3 }, { 2, 5 }, { 4, 5 }, { 5, 6 } };
    cout << Solution().solve(N, E) << endl;
}

int main()
{
    //test(); return 0;
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; ++i)
        cin >> nodes[i];
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i)
        cin >> edges[i].first >> edges[i].second;
    cout << Solution().solve(nodes, edges) << endl;
    return 0;
}