#include "../inc.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() < word2.size())
            word1.swap(word2);
        if(word2.empty())
            return word1.size();
        vector<int> dis(word1.size());
        for(size_t i = 0;i < dis.size();++i)
            dis[i] = i + 1;
        for(size_t i = 0;i < word2.size();++i){
            vector<int> d;
            for(size_t j = 0;j < word1.size();++j){
                int r = i;
                if(j)
                    r = dis[j - 1];
                if(word2[i] != word1[j])
                    ++r;
                if(!d.empty())
                    r = min(r, d.back() + 1);
                r = min(r, dis[j] + 1);
                d.push_back(r);
            }
            d.swap(dis);
        }
        return dis.back();
    }
};

int main()
{
    cout<<Solution().minDistance("", "")<<endl;
    cout<<Solution().minDistance("sea", "ate")<<endl;
    cout<<Solution().minDistance("sitting", "kitten")<<endl;
}
