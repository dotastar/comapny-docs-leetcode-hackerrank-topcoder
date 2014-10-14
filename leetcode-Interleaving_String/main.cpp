#include "../inc.h"

class Solution {
public:
    struct Pos{
        size_t i, j, k;
        bool operator <(const Pos & a) const{
            if(i != a.i)
                return i < a.i;
            if(j != a.j)
                return j < a.j;
            return k < a.k;
        }
    };
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        map<Pos, bool> save;
        return help(s1, s2, s3, 0, 0, 0, save);
    }
    bool help(string s1, string s2, string s3, size_t i, size_t j, size_t k, map<Pos, bool> & save){
        Pos p;
        p.i = i;
        p.j = j;
        p.k = k;
        map<Pos, bool>::const_iterator wh = save.find(p);
        if(wh != save.end())
            return wh->second;
        for(;i < s1.size() && j < s2.size() && k < s3.size();){
            if(s1[i] == s3[k]){
                if(s2[j] == s3[k] && help(s1, s2, s3, i, j + 1, k + 1, save)){
                    save[p] = true;
                    return true;
                }
                ++i, ++k;
            }else if(s2[j] == s3[k]){
                ++j, ++k;
            }else{
                save[p] = false;
                return false;
            }
        }
        if(k == s3.size()){
            bool r = (i == s1.size() && j == s2.size());
            save[p] = r;
            return r;
        }
        if(i == s1.size()){
            bool r = (s2.substr(j) == s3.substr(k));
            save[p] = r;
            return r;
        }
        bool r = (s1.substr(i) == s3.substr(k));
        save[p] = r;
        return r;
    }
};

class Solution2 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        if (s1.size() < s2.size())
            s1.swap(s2);
        vector<bool>  dp(s1.size() + 1);
		for (size_t j = 0; j <= s2.size(); ++j){
			dp[0] = (!j || (dp[0] && s2[j - 1] == s3[j - 1]));
			for (size_t i = 1; i <= s1.size(); ++i)
				dp[i] = ((dp[i - 1] && s1[i - 1] == s3[i + j - 1]) || (j > 0 && dp[i] && s2[j - 1] == s3[i + j - 1]));
		}
        return dp.back();
    }
};

class Solution3 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        vector<bool> r(s2.size() + 1);
        r[0] = true;
        for(size_t i = 0;i <= s1.size();++i){
            if(i > 0)
                r[0] = (r[0] && s1[i - 1] == s3[i - 1]);
            for(size_t j = 0;j < s2.size();++j)
                r[1 + j] = ((r[j] && (s3[i + j] == s2[j]))
                        || (i > 0 && r[1 + j] && s3[i + j] == s1[i - 1]));
        }
        return r.back();
    }
};

int main()
{
	{
		string s1 = "a";
		string s2 = "d";
		string s3 = "aa";
		cout << Solution().isInterleave(s1, s2, s3)
			<< " " << Solution2().isInterleave(s1, s2, s3)
			<< endl;
	}{
		string s1 = "aabcc";
        string s2 = "dbbca";
        string s3 = "aadbbcbcac";
        cout << Solution().isInterleave(s1, s2, s3)
            << " " << Solution2().isInterleave(s1, s2, s3)
            << endl;
    }{
        string s1 = "aabcc";
        string s2 = "dbbca";
        string s3 = "aadbbbaccc";
        cout << Solution().isInterleave(s1, s2, s3)
            << " " << Solution2().isInterleave(s1, s2, s3)
            << endl;
    }{
        string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
        string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
        string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
        cout << Solution().isInterleave(s1, s2, s3)
            << " " << Solution2().isInterleave(s1, s2, s3)
            << endl;
    }
}
