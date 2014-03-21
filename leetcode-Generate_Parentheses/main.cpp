#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> r;
        if(n <= 0)
            return r;
        string s;
        help(s, 0, n, r);
        return r;
    }
    void help(string & s, int level, int left, vector<string> & r){
        if(!level && !left){
            r.push_back(s);
            return;
        }
        size_t old = s.size();
        if(level){
            s.push_back(')');
            help(s, level - 1, left, r);
            s.resize(old);
        }
        if(left){
            s.push_back('(');
            help(s, level + 1, left - 1, r);
        }
    }
};

void print(const vector<string> & v)
{
    for(size_t i = 0;i < v.size();++i)
        cout<<v[i]<<" ";
    cout<<endl;
}

int main()
{
    print(Solution().generateParenthesis(0));
    print(Solution().generateParenthesis(1));
    print(Solution().generateParenthesis(2));
    print(Solution().generateParenthesis(3));
}
