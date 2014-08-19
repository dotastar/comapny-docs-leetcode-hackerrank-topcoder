#include "../inc.h"

class Solution {
public:
    //O(N) time, O(N) space
    void reverseWords1(string &s) {
        if(s.empty())
            return;
        string r;
        int t, h;
        bool e = true;
        for(int i = s.size() - 1;i >= 0;--i){
            if(e){
                if(!isspace(s[i])){
                    e = false;
                    t = i + 1;
                }
            }else{
                if(isspace(s[i])){
                    e = true;
                    h = i + 1;
                    if(!r.empty())
                        r.push_back(' ');
                    r.append(s.substr(h, t - h));
                }
            }
        }
        if(!e){
            h = 0;
            if(!r.empty())
                r.push_back(' ');
            r.append(s.substr(h, t - h));
        }
        r.swap(s);
    }
    //O(N) time, O(1) space
    void reverseWords(string &s) {
        if(s.empty())
            return;
        //rm rendundant space and reverse each word
        size_t t, h;
        bool e = true;
        for(size_t i = t = 0;i < s.size();++i){
            if(e){
                if(!isspace(s[i])){
                    e = false;
                    h = t;
                    if(t != i)
                        s[t] = s[i];
                    ++t;
                }
            }else{
                if(isspace(s[i])){
                    e = true;
                    for(size_t j = t - 1;j > h;++h, --j)
                        swap(s[h], s[j]);
                    if(t < s.size())
                        s[t++] = ' ';
                }else{
                    if(t != i)
                        s[t] = s[i];
                    ++t;
                }
            }
        }
        if(!e){ //last word
            for(size_t j = t - 1;j > h;++h, --j)
                swap(s[h], s[j]);
            s.resize(t);
        }else if(t > 0)
            s.resize(t - 1);
        else{
            s.clear();
            return;
        }
        //reverse total string
        for(h = 0, t = s.size() - 1;h < t;++h, --t)
            swap(s[h], s[t]);
    }
};

class Solution2 {
public:
    void reverseWords(string &s) {
        int f = -1, t = 0;
        for(int i = 0;i <= s.length();++i){
            if(i >= s.length() || isspace(s[i])){
                if(f >= 0){
                    for(int j = f, k = t - 1;j < k;++j, --k)
                        swap(s[j], s[k]);
                    s[t++] = ' ';
                }
                f = -1;
            }else{
                if(f < 0)
                    f = t;
                s[t++] = s[i];
            }
        }
        if(t > 0 && s[t - 1] == ' ')
            --t;
        s.resize(t);
        for(int i = 0, j = s.length() - 1;i < j;++i, --j)
            swap(s[i], s[j]);
    }
};

int main()
{
    {
        string s = "1 ";
        Solution().reverseWords(s);
        cout<<s<<endl;
    }{
        string s = " the sky  is\n blue\t";
        Solution().reverseWords(s);
        cout<<s<<endl;
    }{
        string s = "   ";
        Solution().reverseWords(s);
        cout<<s<<endl;
    }{
        string s = "the sky is blue";
        Solution().reverseWords(s);
        cout<<s<<endl;
    }
}
