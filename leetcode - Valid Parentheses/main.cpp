#include "..\inc.h"

class Solution {
public:
    bool isValid(string s) {
        vector<int> q;
        for(size_t i = 0;i < s.size();++i){
            switch(s[i]){
                case '(':q.push_back(0);break;
                case ')':
                    if(q.empty() || q.back() != 0)
                        return false;
                    q.pop_back();
                    break;
                case '[':q.push_back(1);break;
                case ']':
                    if(q.empty() || q.back() != 1)
                        return false;
                    q.pop_back();
                    break;
                case '{':q.push_back(2);break;
                case '}':
                    if(q.empty() || q.back() != 2)
                        return false;
                    q.pop_back();
                    break;
                default:assert(0);
            }

        }
        return q.empty();
    }
};

int main(){}
