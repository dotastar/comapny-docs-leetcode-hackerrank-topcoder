class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > r;
        for(vector<int> v;numRows-- > 0;){
            v.push_back(1);
            if(!r.empty()){
                vector<int> & p = r.back();
                for(size_t i = 0;i < p.size() - 1;++i)
                    v.push_back(p[i] + p[i + 1]);
                v.push_back(1);
            }
            r.resize(r.size() + 1);
            r.back().swap(v);
        }
        return r;
    }
};
