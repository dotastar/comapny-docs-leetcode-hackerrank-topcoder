#include "..\inc.h"

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        map<int, Interval> m;   //end -> interval
        for(size_t i = 0;i < intervals.size();++i){
            map<int, Interval>::iterator wh = m.lower_bound(intervals[i].start);
            if(wh != m.end() && wh->second.start <= intervals[i].end){
                map<int, Interval>::iterator it;
                for(it = wh;it != m.end();){
                    if(it->second.start > intervals[i].end)
                        break;
                    intervals[i].start = min(intervals[i].start, it->second.start);
                    intervals[i].end = max(intervals[i].end, it->second.end);
                    m.erase(it++);
                }
            }
            m[intervals[i].end] = intervals[i];
        }
        vector<Interval> r;
        for(map<int, Interval>::const_iterator it = m.begin();it != m.end();++it)
            r.push_back(it->second);
        return r;
    }
};

class Solution {
public:
    struct Comp{
        bool operator ()(const Interval & a, const Interval & b) const{
            return a.start < b.start;
        }
    };
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.empty())
            return intervals;
        sort(intervals.begin(), intervals.end(), Comp());
        size_t i = 0;
        for(size_t j = 1;j < intervals.size();++j){
            if(intervals[i].end >= intervals[j].start){
                intervals[i].end = max(intervals[i].end, intervals[j].end);
            }else
                intervals[++i] = intervals[j];
        }
        intervals.resize(i + 1);
        return intervals;
    }
};

int main()
{
    {
        vector<Interval> in;
        in.push_back(Interval(1,3));
        in.push_back(Interval(2,6));
        in.push_back(Interval(8,10));
        in.push_back(Interval(15,18));
        //print(Solution().merge(in));
    }
}