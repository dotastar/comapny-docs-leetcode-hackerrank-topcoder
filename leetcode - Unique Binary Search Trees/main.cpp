#include "../inc.h"

class Solution {
public:
    int numTrees(int n) {
        vector<int> v(n + 1, 0);
        v[0] = v[1] = 1;
        for(int i = 2;i <= n;++i)
            for(int j = 0;j < i;++j)
                v[i] += v[i - 1 - j] * v[j];
        return v[n];
    }
    int numTrees2(int n) {
        double np = 1;
        for(int i = 2;i <= n;++i)
            np *= i;
        double n2p = np;
        for(int i = n + 1;i <= 2 * n;++i)
            n2p *= i;
        return int(n2p / np / np / (n + 1));
    }

    vector<TreeNode *> generateTrees(int n) {
        return help(1, n);
    }
    vector<TreeNode *> help(int s, int e){
        vector<TreeNode *> r;
        if (s > e){
            r.push_back(NULL);
            return r;
        }
        for (int i = s; i <= e; ++i){
            vector<TreeNode *> le = help(s, i - 1);
            vector<TreeNode *> ri = help(i + 1, e);
            for (size_t j = 0; j < le.size(); ++j){
                for (size_t k = 0; k < ri.size(); ++k){
                    r.push_back(new TreeNode(i));
                    r.back()->left = le[j];
                    r.back()->right = ri[k];
                }
            }
        }
        return r;
    }
};


int main(){}
