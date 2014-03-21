#include <iostream>
#include <vector>
#include <cassert>

template<int N>
void printPath(const int (&path)[N], int len)
{
    assert(0 < len && len <= N);
    for(int i = 0;i < len;++i)
        std::cout<<(path[i] + 1)<<", ";
    std::cout<<"\n";
}

template<int N>
bool hasNode(const int (&path)[N], int len, int n)
{
    assert(0 < len && len <= N);
    for(int i = 0;i < len;++i)
        if(path[i] == n)
            return true;
    return false;
}

template<int N>
void findPaths(const bool (&nodes)[N][N], int (&path)[N], int cur, int to)
{
    if(cur >= N)
        return;
    assert(cur > 0);
    int last = path[cur - 1];
    for(int i = 0;i < N;++i)
        if(nodes[i][last]){
            if(!hasNode(path, cur, i)){
                path[cur] = i;
                if(i == to)
                    printPath(path, cur + 1);
                else
                    findPaths(nodes, path, cur + 1, to);
            }
        }
}

template<int N>
void printPaths(const bool (&nodes)[N][N], int from, int to)
{
    assert(0 < from && from <= N && 0 < to && to <= N);
    if(from == to){
        std::cout<<from<<"\n";
        return;
    }
    assert(N > 1);
    int path[N] = {from - 1};
    findPaths(nodes, path, 1, to - 1);
}

int main()
{
    //1 for connected, 0 for disconnected
    const bool nodes[8][8] = {
        {0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 1, 0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 0, 1, 0}
    };

    printPaths(nodes, 2, 5);
}