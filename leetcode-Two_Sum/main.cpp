#include "../inc.h"

class Solution {
public:
    //O(N * logN)
    vector<int> twoSum1(vector<int> &numbers, int target) {
        vector<int> save(numbers);
        sort(numbers.begin(), numbers.end());
        size_t i = 0, j;
        for(;i < numbers.size();++i){
            j = help(numbers, i + 1, numbers.size() - i - 1, target - numbers[i]);
            if(j >= numbers.size() || numbers[j] + numbers[i] != target)
                continue;
            break;
        }
        vector<int> r;
        for(size_t k = 0;k < save.size();++k){
            if(numbers[i] == save[k])
                r.push_back(k + 1);
            else if(numbers[j] == save[k])
                r.push_back(k + 1);
        }
        return r;
    }
    size_t help(const vector<int> &numbers, int from, int len, int v){
        while(len > 0){
            int m = len / 2;
            if(numbers[from + m] < v){
                from += m + 1;
                len -= m + 1;
            }else
                len = m;
        }
        return from;
    }

    //O(N)
    vector<int> twoSum2(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        vector<int> r(2);
        for(size_t i = 0;i < numbers.size();++i){
            int v = target - numbers[i];
            unordered_map<int, int>::const_iterator wh = m.find(v);
            if(wh == m.end()){
                m[numbers[i]] = i;
            }else{
                r[0] = min(wh->second, int(i)) + 1;
                r[1] = max(wh->second, int(i)) + 1;
                break;
            }
        }
        return r;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, size_t> h;
        for(size_t i = 0;i < numbers.size();++i){
            auto wh = h.find(target - numbers[i]);
            if(h.end() != wh)
                return {wh->second + 1, i + 1};
            h[numbers[i]] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> n;
    n.push_back(3);
    n.push_back(2);
    n.push_back(4);
    Solution().twoSum2(n, 6);
}
