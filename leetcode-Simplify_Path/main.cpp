#include "../inc.h"

class Solution {
public:
    string simplifyPath(string path) {
        string c;
        vector<string> p;
        for(size_t i = 0;i < path.size();++i){
            if('/' == path[i]){
                help(p, c);
                c.clear();
            }else
                c.push_back(path[i]);
        }
        help(p, c);
        return help(p);
    }
    void help(vector<string> & p, string c){
        if(c.empty() || "." == c)
            return;
        if(".." == c){
            if(!p.empty())
                p.pop_back();
            return;
        }
        p.push_back(c);
    }
    string help(const vector<string> & p){
        if(p.empty())
            return "/";
        string r;
        for(size_t i = 0;i < p.size();++i){
            r.push_back('/');
            r.append(p[i]);
        }
        return r;
    }
};

class Solution2 {
public:
    string simplifyPath(string path) {
        vector<string> que;
        string dir;
        for(size_t i = 0;i <= path.size();++i){
            const char c = (i < path.size() ? path[i] : '/');
            if('/' == c){
                if(".." == dir){
                    if(!que.empty())
                        que.pop_back();
                }else if("." != dir && !dir.empty())
                    que.push_back(dir);
                dir.clear();
            }else
                dir.push_back(c);
        }
        if(que.empty())
            return "/";
        ostringstream oss;
        for(string d : que)
            oss<<'/'<<d;
        return oss.str();
    }
};

int main()
{
    cout<<Solution().simplifyPath("/home/")<<endl;
    cout<<Solution().simplifyPath("/a/./b/../../c/")<<endl;
    cout<<Solution().simplifyPath("/../")<<endl;
    cout<<Solution().simplifyPath("/home//foo/")<<endl;
}
