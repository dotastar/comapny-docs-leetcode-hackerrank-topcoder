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
    //��ȡ����ʱ��d��֮ǰ��������ĺ�ʱ�ܺ�
    int getSum(int d){
        assert(d > 0);
        int r = 0;
        for (; d; d -= d & (-d))
            r += sum[d - 1];
        return r;
    }
    //������ʱ��d���������񣬺�ʱm
    void updateSum(int d, int m){
        assert(d > 0);
        if(m > 0){
            for (; d <= kMaxD; d += d & (-d))
                sum[d - 1] += m;
        }
    }
    //���㵽��ʱ��d�ĳ�ʱ��
    int overshoots(int d){
        int r = getSum(d) - d;
        return r;
    }
    //index operations
    //��ȡ����ʱ��d��֮�󣬳�ʱ��ĵ���ʱ���
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
    //���µ���ʱ��d��֮ǰ����ʱ���rd�ĳ�ʱʱ��s��
    //���s������ʱ���ĳ�ʱʱ�����������³�Ϊrd��
    //���򱣳ֲ��䡣
    void updateIndex(int d, int rd, int s){
        for (d = kMaxD + 1 - d; d <= kMaxD; d += d & (-d)){
            int r = index[d - 1] + kMaxD - d + 1;
            if (r != rd && overshoots(r) < s)
                index[d - 1] = rd + d - kMaxD - 1;
        }
    }
    //����������ĵ���ʱ��d�ͺ�ʱm
    //�������ʱ
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
