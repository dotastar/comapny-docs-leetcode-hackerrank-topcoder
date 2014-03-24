#include "../inc.h"

using namespace std;


class Solution1 {
public:
    //O(N^3)
    int maxPoints(vector<Point> &points) {
        if(points.size() < 3)
            return points.size();
        int ret = 0;
        for(size_t i = 0;i < points.size() - 1;++i){
            int base = 1;
            for(size_t j = i + 1;j < points.size();++j){
                if(points[j].y == points[i].y && points[i].x == points[j].x){
                    ++base;
                    continue;
                }
                int a = points[j].y - points[i].y;
                int b = points[i].x - points[j].x;
                int c = points[i].x * points[j].y - points[j].x * points[i].y;
                int r = base + 1;
                for(size_t k = j + 1;k < points.size();++k){
                    if(a * points[k].x + b * points[k].y == c)
                        ++r;
                }
                if(r > ret)
                    ret = r;
            }
            if(base > ret)
                ret = base;
        }
        return ret;
    }
};

class Solution2 {
public:
    //O(N^2)
    int maxPoints(vector<Point> &points) {
        if(points.size() < 3)
            return points.size();
        int ret = 0;
        for(size_t i = 0;i < points.size() - 1;++i){
            unordered_map<double, int> m;
            int rpt = 1, inf = 0;
            for(size_t j = i + 1;j < points.size();++j){
                if(points[j].y == points[i].y && points[i].x == points[j].x){
                    ++rpt;
                    continue;
                }
                int a = points[j].y - points[i].y;
                int b = points[i].x - points[j].x;
                if(b)
                    ++m[double(a) / b];
                else
                    ++inf;
            }
            for(unordered_map<double, int>::const_iterator j = m.begin();j != m.end();++j)
                if(inf < j->second)
                    inf = j->second;
            inf += rpt;
            if(inf > ret)
                ret = inf;
        }
        return ret;
    }
};

int main()
{
    {
        vector<Point> v;
        v.push_back(Point(-4,1));
        v.push_back(Point(-7,7));
        v.push_back(Point(-1,5));
        v.push_back(Point(9,-25));
        cout<<Solution2().maxPoints(v)<<endl;
    }
}