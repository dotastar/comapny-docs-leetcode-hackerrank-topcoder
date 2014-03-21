#include "../inc.h"

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> r;
        for(size_t i = 0;i < words.size();){
            string line = words[i++];
            assert(line.size() <= L);
            int j = 0, sz = line.size();
            for(;i + j < words.size();++j){
                if(sz + words[i + j].size() + j + 1 > L)
                    break;
                sz += words[i + j].size();
            }
            if(j > 0){
                bool ne = (i + j < words.size());
                for(sz = L - sz;j > 0;--j, ++i){
                    if(ne){
                        int k = (sz + j - 1) / j;
                        line.append(k, ' ');
                        sz -= k;
                    }else
                        line.push_back(' ');
                    line.append(words[i]);
                }
            }
            line.resize(L, ' ');
            r.push_back(line);
        }
        return r;
    }
};

int main()
{
    {
        const char * w[] = {"Here","is","an","example","of","text","justification."};
        vector<string> words(w, w + sizeof w / sizeof w[0]);
        printLine(Solution().fullJustify(words, 14));
        cout<<endl;
    }
    {
        const char * w[] = {"This", "is", "an", "example", "of", "text", "justification."};
        vector<string> words(w, w + sizeof w / sizeof w[0]);
        printLine(Solution().fullJustify(words, 16));
        cout<<endl;
    }
    {
        const char * w[] = {"What","must","be","shall","be."};
        vector<string> words(w, w + sizeof w / sizeof w[0]);
        printLine(Solution().fullJustify(words, 12));
        cout<<endl;
    }
}
