#include "../inc.h"

struct Solution1{
    //O(N^2)
    void solve(const vector<pair<int, int>> & T)
    {
        typedef pair<map<int, int>::iterator, bool> __Ret;
        map<int, int> tasks;    //deadline -> total minutes before current deadline
        int ret = 0;
        for (size_t i = 0; i < T.size(); ++i){
            __Ret ir = tasks.insert(make_pair(T[i].first, 0));
            if (ir.second){ //new insertion
                map<int, int>::iterator p = ir.first;
                if (p != tasks.begin()){
                    --p;
                    ir.first->second = p->second;   //get previous total
                }
            }
            for (; ir.first != tasks.end(); ++ir.first){
                ir.first->second += T[i].second;
                ret = max(ret, ir.first->second - ir.first->first);
            }
            cout << ret << endl;
        }
    }
};

class Solution2{
    static const int kMaxD = 100000;
    int sum[kMaxD];     //binary index tree for sums
    int index[kMaxD];   //binary index tree for result index, in reverse order
    //sum operations
    //获取到期时间d及之前所有任务的耗时总和
    int getSum(int d){
        assert(d > 0);
        int r = 0;
        for (; d; d -= d & (-d))
            r += sum[d - 1];
        return r;
    }
    //给到期时间d增加新任务，耗时m
    void updateSum(int d, int m){
        assert(d > 0);
        if(m > 0){
            for (; d <= kMaxD; d += d & (-d))
                sum[d - 1] += m;
        }
    }
    //计算到期时间d的超时量
    int overshoots(int d){
        int r = getSum(d) - d;
        return r;
    }
    //index operations
    //获取到期时间d及之后，超时最长的到期时间点
    int getIndex(int d){
        d = kMaxD + 1 - d;  //index is in reverse order
        assert(d > 0);
        int ri = -1;
        int rs = 0;
        for (; d; d -= d & (-d)){
            int i = index[d - 1] + kMaxD - d + 1;
            int s = overshoots(i);
            if (ri < 0 || s > rs){
                ri = i;
                rs = s;
            }
        }
        return ri;
    }
    //更新到期时间d及之前，新时间点rd的超时时间s。
    //如果s比已有时间点的超时时间更长，则更新成为rd；
    //否则保持不变。
    void updateIndex(int d, int rd, int s){
        for (d = kMaxD + 1 - d; d <= kMaxD; d += d & (-d)){
            int r = index[d - 1] + kMaxD - d + 1;
            if (r != rd && overshoots(r) < s)
                index[d - 1] = rd + d - kMaxD - 1;
        }
    }
    //插入新任务的到期时间d和耗时m
    //返回最大超时
    int insert(int d, int m){
        updateSum(d, m);
        int dd = getIndex(d);    //get result index of [d, kMaxD]
        m = overshoots(dd);
        updateIndex(d, dd, m); //update result index of [0, d)
        d = getIndex(1);
        m = overshoots(d);
        return (m > 0 ? m : 0);
    }
public:
    Solution2(){
        memset(sum, 0, sizeof sum);
        memset(index, 0, sizeof index);
    }
    //O(N*logN*logN)
    void solve(const vector<pair<int, int>> & T){
        for (size_t i = 0; i < T.size(); ++i)
            cout << insert(T[i].first, T[i].second) << endl;
    }
};

typedef Solution2 Solution;

void test()
{
    {
        vector<pair<int, int>> T;
        T.push_back(make_pair(2, 2));
        T.push_back(make_pair(1, 1));
        T.push_back(make_pair(4, 3));
        T.push_back(make_pair(10, 1));
        T.push_back(make_pair(2, 1));
        Solution().solve(T);
    }
}

int main()
{
    test(); return 0;
    int t;
    cin >> t;
    vector<pair<int, int>> tasks(t);
    for (int i = 0; i < t; ++i)
        cin >> tasks[i].first >> tasks[i].second;
    Solution().solve(tasks);
}
