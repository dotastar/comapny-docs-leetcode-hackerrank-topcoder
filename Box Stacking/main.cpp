#include "../inc.h"

namespace twoD{
    struct CmpBox{
        bool operator ()(const pair<int, int> & b1, const pair<int, int> & b2) const{
            return b1.first > b2.first;
        }
    };
    int solve(const vector<pair<int, int> > & boxes)
    {
        if (boxes.empty())
            return 0;
        //rotate box if possible
        vector<pair<int, int> > bx;
        for (size_t i = 0; i < boxes.size(); ++i){
            bx.push_back(boxes[i]);
            if (boxes[i].first != boxes[i].second)
                bx.push_back(make_pair(boxes[i].second, boxes[i].first));
        }
        //sort by bottom size
        sort(bx.begin(), bx.end(), CmpBox());
        //stack boxes, choose the highest if bottoms are equal
        int ret = 0, cur = bx[0].second;
        for (size_t i = 1; i < bx.size() - 1; ++i){
            if (bx[i].first == bx[i - 1].first){
                cur = max(cur, bx[i].second);
            } else{
                ret += cur;
                cur = bx[i].second;
            }
        }
        return (ret + cur);
    }
}

namespace threeD{
    int solve(const vector<Box> & boxes)
    {
        if (boxes.empty())
            return 0;
        //rotate box if possible
        vector<Box> bx;
        for (size_t i = 0; i < boxes.size(); ++i){
            int v[3] = { boxes[i].h, boxes[i].w, boxes[i].d };
            sort(v, v + 3);
            bx.push_back(Box(v[0], v[1], v[2]));
            if (v[1] > v[0])
                bx.push_back(Box(v[1], v[0], v[2]));
            if (v[2] > v[1])
                bx.push_back(Box(v[2], v[0], v[1]));
        }
        //sort by larger side of bottom
        sort(bx.begin(), bx.end(), greater<Box>());
        //stack boxes
        vector<int> ret(bx.size());
        int r = 0;
        for (size_t i = 0; i < bx.size(); ++i){
            ret[i] = bx[i].h;
            for (size_t j = 0; j < i; ++j){
                if (bx[j].w > bx[i].w && bx[j].d > bx[i].d)
                    ret[i] = max(ret[i], ret[j] + bx[i].h);
            }
            r = max(r, ret[i]);
        }
        return r;
    }
}

namespace followup{
    struct Ret
    {
        Ret() :r(0){}
        void addBox(const Box & b){
            int v[3] = { b.h, b.w, b.d };
            sort(v, v + 3);
            size_t sz = ret[0].size();
            calcBox(0, sz, v[0], v[1], v[2]);
            calcBox(1, sz, v[1], v[0], v[2]);
            calcBox(2, sz, v[2], v[0], v[1]);
        }
        int result() const{ return r; }
    private:
        void calcBox(int index, int size, int h, int w, int d){
            ret[index].push_back(Box(h, w, d));
            Box & b = ret[index].back();
            for (size_t i = 0; i < 3; ++i){
                const vector<Box> & r = ret[i];
                for (int j = 0; j < size; ++j){
                    if (r[j].w > w && r[j].d > d)
                        b.h = max(b.h, r[j].h + h);
                }
            }
            r = max(r, b.h);
        }
        vector<Box> ret[3];
        int r;
    };

    int solve(const vector<Box> & boxes)
    {
        Ret r;
        for (size_t i = 0; i < boxes.size(); ++i)
            r.addBox(boxes[i]);
        return r.result();
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    {
        vector<pair<int, int> > b;
        genPairArray(b, 5, 1, 5);
        print(b);
        cout << twoD::solve(b) << endl;
    }
    cout << "---\n";
    {
        vector<Box> b;
        genBoxArray(b, 5, 1, 10);
        print(b);
        cout << threeD::solve(b) << endl;
        //cout << followup::solve(b) << endl;
    }{
        vector<Box> b;
        b.push_back(Box(4, 9, 8));
        b.push_back(Box(8, 8, 5));
        b.push_back(Box(4, 6, 2));
        b.push_back(Box(1, 6, 2));
        b.push_back(Box(3, 10, 1));
        print(b);
        cout << followup::solve(b) << endl;
        /*
        h   w   d
        4   8   9
        8   5   8
        6   2   4
        10  1   3
        Total Height: 28
        */
    }
}