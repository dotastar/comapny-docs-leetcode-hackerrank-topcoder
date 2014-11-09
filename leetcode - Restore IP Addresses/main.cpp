#include "..\inc.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        if(s.size() < 4 || 12 < s.size())
            return r;
        string v;
        help(r, s, 0, 0, v);
        return r;
    }
    void help(vector<string> & r, string s, int idx, int part, string & v){
        if(4 == part && idx == s.size()){
            r.push_back(v);
            return;
        }
        int rma = (3 - part) * 3;
        int rmi = (3 - part) * 1;
        size_t old = v.size();
        for(int i = 1;i <= 3;++i){
            int left = s.size() - idx - i;
            if(rmi <= left && left <= rma){
                if(3 == i){
                    int v = 100 * (s[idx] - '0') + 10 * (s[idx + 1] - '0') + s[idx + 2] - '0';
                    if(v > 255)
                        continue;
                }
                v.resize(old);
                v.append(s, idx, i);
                if(part < 3)
                    v.push_back('.');
                help(r, s, idx + i, part + 1, v);
            }
            if('0' == s[idx])
                break;
        }
    }
};

class Solution2 {
public:
	vector<string> restoreIpAddresses(string s) {
		if (s.size() < 4 || 12 <s.size())
			return{};
		vector<vector<string>> p[3];
		for (size_t i = 0; i < 3; ++i)
			p[i].resize(4);
		for (size_t i = 0; i < s.size(); ++i){
			vector<vector<string>> cur(4);
			if (help(s, 0, i))
				cur[0].push_back(s.substr(0, i + 1));
			for (size_t k = 0; k < 3; ++k){
				if (k > i || !help(s, i - k, i))
					continue;
				const string u = "." + s.substr(i - k, k + 1);
				for (int j = 1; j < 4; ++j)
				for (string pu : p[k][j - 1])
					cur[j].push_back(pu + u);
			}
			p[2].swap(p[1]);
			p[1].swap(p[0]);
			p[0].swap(cur);
		}
		return p[0].back();
	}
	bool help(string s, size_t f, size_t t){
		assert(f <= t && t < s.size());
		if (f + 3 <= t || (f < t && '0' == s[f]))
			return false;
		int v = 0;
		for (; f <= t && v < 256; ++f)
			v = v * 10 + s[f] - '0';
		return (v < 256);
	}
};

int main()
{
	{
		print(Solution2().restoreIpAddresses("0000"));
		print(Solution2().restoreIpAddresses("25525511135"));
		print(Solution2().restoreIpAddresses("010010"));

	}
	cout << "---\n";
	{
		print(Solution().restoreIpAddresses("0000"));
		print(Solution().restoreIpAddresses("25525511135"));
		print(Solution().restoreIpAddresses("010010"));
	}
}