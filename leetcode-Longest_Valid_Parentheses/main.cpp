#include "../inc.h"

class Solution {
public:
    //O(N) space
    int longestValidParentheses1(string s) {
        vector<int> stack, his;
        int r = 0;
        for(size_t i = 0;i < s.size();++i){
            switch(s[i]){
                case '(':stack.push_back(i);break;
                case ')':
                    if(!stack.empty()){
                        int c = i - stack.back() + 1;
                        his.resize(stack.size());
                        stack.pop_back();
                        his[stack.size()] += c;
                        r = max(r, his[stack.size()]);
                    }else
                        his.clear();
                default:;
            }
        }
        return r;
    }
    //O(N) space
    int longestValidParentheses2(string s) {
        vector<int> stack;
        int r = 0;
        for(size_t i = 0;i < s.size();++i)
            switch(s[i]){
                case '(':stack.push_back(i);break;
                default:
                    if(!stack.empty() && '(' == s[stack.back()]){
                        stack.pop_back();
                        r = max<int>(r, i - (stack.empty() ? -1 : stack.back()));
                    }else
                        stack.push_back(i);
            }
        return r;
    }



    //from zhang lei at http://fisherlei.blogspot.com/2013/03/leetcode-longest-valid-parentheses.html
    int longestValidParenthesesOther(string s) {  
        const char* str = s.c_str();  
        int nMax=0;  
        const char *p = str;  
        vector<const char*> sta;  
        while(*p !='\0')  
        {  
            if(*p == '(')  
            {  
                sta.push_back(p);                      
            }  
            else  
            {  
                if(!sta.empty() && *sta.back()=='(')  
                {  
                    sta.pop_back();  
                    nMax = max<int>(nMax, p-(sta.empty()?str-1:sta.back()));  
                }  
                else  
                {  
                    sta.push_back(p);  
                }  
            }  
            p++;  
        }  
        return nMax;  
    }  


};

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> istack;
        vector<pair<int, int>> pstack;
        pair<int, int> cur;
        int r = 0;
        for(size_t i = 0;i < s.size();++i){
            if('(' == s[i]){
                istack.push_back(i);
                if(cur.first + 1 <= cur.second){
                    pstack.push_back(cur);
                    cur = {0, 0};
                }
            }else{
                if(!istack.empty()){
                    cur.first = istack.back();
                    cur.second = i;
                    istack.pop_back();
                    while(!pstack.empty()){
                        if(pstack.back().second + 1 == cur.first){
                            cur.first = pstack.back().first;
                            pstack.pop_back();
                        }else
                            break;
                    }
                    r = max(r, cur.second - cur.first + 1);
                }else
                    pstack.clear();
            }
        }
        return r;
    }
};

int main()
{
    cout<<Solution().longestValidParentheses3("()")<<endl;
    cout<<Solution().longestValidParentheses3("(()")<<endl;
    cout<<Solution().longestValidParentheses3(")()())")<<endl;
    cout<<Solution().longestValidParentheses2("(()()")<<endl;
    cout<<Solution().longestValidParentheses2("()(())")<<endl;
    cout<<Solution().longestValidParentheses2("())(())")<<endl;
    cout<<Solution().longestValidParentheses2("))(())()((((((())(()))((())(((((((()))())((((())())(()())))))))))((()((()(()(()()((()()()(()()()))(()()(()(())())))()())()(((((")<<endl;
}
