#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> stack;
        int r = 0;
        for(size_t i = 0;i < tokens.size();++i){
            if(tokens[i] == "+"){
                assert(!stack.empty());
                r += stack.back();
                stack.pop_back();
            }else if(tokens[i] == "-"){
                assert(!stack.empty());
                r = stack.back() - r;
                stack.pop_back();
            }else if(tokens[i] == "*"){
                assert(!stack.empty());
                r *= stack.back();
                stack.pop_back();
            }else if(tokens[i] == "/"){
                assert(!stack.empty());
                assert(0 != r);
                r = stack.back() / r;
                stack.pop_back();
            }else{
                if(i)
                    stack.push_back(r);
                r = atoi(tokens[i].c_str());
            }
        }
        assert(stack.empty());
        return r;
    }
};

class Solution2 {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> stack;
        for(const auto & s : tokens){
            if("+" == s){
                if(stack.size() < 2)
                    return -1;
                int right = stack.back();
                stack.pop_back();
                stack.back() += right;
            }else if("-" == s){
                if(stack.size() < 2)
                    return -1;
                int right = stack.back();
                stack.pop_back();
                stack.back() -= right;
            }else if("*" == s){
                if(stack.size() < 2)
                    return -1;
                int right = stack.back();
                stack.pop_back();
                stack.back() *= right;
            }else if("/" == s){
                if(stack.size() < 2)
                    return -1;
                int right = stack.back();
                if(!right)
                    return -1;
                stack.pop_back();
                stack.back() /= right;
            }else{
                int v = 0;
                istringstream iss(s);
                iss>>v;
                stack.push_back(v);
            }
        }
        return (stack.empty() ? -1 : stack.back());
    }
};

int main(){}