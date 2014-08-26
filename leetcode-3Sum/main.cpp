#include "../inc.h"

class Solution {
public:
    vector<vector<int> > threeSum1(vector<int> &num) {
        vector<vector<int> > r;
        if(num.empty())
            return r;
        map<int, int> m;
        for(size_t i = 0;i < num.size();++i)
            ++m[num[i]];
        vector<int> v;
        help(r, v, m, m.begin());
        return r;
    }
    template<class Iter>
    void help(vector<vector<int> > & r, vector<int> & v, map<int, int> & m, Iter it){
        if(v.size() == 2){
            int le = 0 - v[0] - v[1];
            if(le <= v[1])
                return;
            Iter wh = m.find(le);
            if(wh == m.end())
                return;
            v.push_back(le);
            r.push_back(v);
            return;
        }else if(v.size() == 3){
            if(0 == v[0] + v[1] + v[2])
                r.push_back(v);
            return;
        }
        if(it == m.end())
            return;
        size_t old = v.size();
        Iter n = it;
        ++n;
        for(int i = 0;i <= it->second;++i){
            v.resize(old);
            v.resize(old + i, it->first);
            help(r, v, m, n);
        }
    }

	//O(N^3 * logN)
    vector<vector<int> > threeSum2(vector<int> &num) {
        vector<vector<int> > r;
        if(num.size() < 3)
            return r;
        for(size_t i = 0;i < num.size();++i)
            for(size_t j = i + 1;j < num.size();++j)
                for(size_t k = j + 1;k < num.size();++k)
                    if(num[i] + num[j] + num[k] == 0){
                        vector<int> v(3, num[i]);
                        v[1] = num[j];
                        v[2] = num[k];
                        sort(v.begin(), v.end());
                        if(r.end() == find(r.begin(), r.end(), v))
                            r.push_back(v);
                    }
        return r;
    }

	//O(N^2 * logN)
    vector<vector<int> > threeSum3(vector<int> &num) {
        vector<vector<int> > r;
        if(num.size() < 3)
            return r;
        unordered_map<int, int> m;
        for(size_t i = 0;i < num.size();++i)
            ++m[num[i]];
        for(size_t i = 0;i < num.size();++i)
            for(size_t j = i + 1;j < num.size();++j){
                int le = -num[i] - num[j];
                unordered_map<int, int>::const_iterator wh = m.find(le);
                if(wh == m.end())
                    continue;
                int c = 1;
                if(le == num[i])
                    ++c;
                if(le == num[j])
                    ++c;
                if(c > wh->second)
                    continue;
                vector<int> v(3, num[i]);
                v[1] = num[j];
                v[2] = le;
                sort(v.begin(), v.end());
                if(r.end() == find(r.begin(), r.end(), v))
                    r.push_back(v);
            }
        return r;
    }

    vector<vector<int> > threeSum4(vector<int> &num) {
        vector<vector<int> > r;
        if(num.size() < 3)
            return r;
        map<int, int> m;
        for(size_t i = 0;i < num.size();++i)
            ++m[num[i]];
        for(map<int, int>::const_iterator it = m.begin();it != m.end();++it){
            for(size_t i = 1;i <= 3 && int(i) <= it->second;++i){
                int s = i * it->first;
                if(3 == i){
                    if(0 == s)
                        r.push_back(vector<int>(3, it->first));
                    break;
                }
                int av = (0 - s) / (3 - i);
                if(av < it->first)
                    break;
                map<int, int>::const_iterator jt = it;
                for(++jt;jt != m.end();++jt){
                    for(size_t j = 1;i + j <= 3 && int(j) <= jt->second;++j){
                        int s = i * it->first + j * jt->first;
                        if(3 == i + j){
                            if(0 == s){
                                vector<int> v(i, it->first);
                                v.resize(3, jt->first);
                                r.push_back(v);
                            }
                            break;
                        }
                        int av = (0 - s) / (3 - i - j);
                        if(av < jt->first)
                            break;
                        if(av > jt->first){
                            map<int, int>::const_iterator kt = m.find(av);
                            if(kt == m.end())
                                continue;
                            vector<int> v(1, it->first);
                            v.push_back(jt->first);
                            v.push_back(kt->first);
                            r.push_back(v);
                        }
                    }
                }
            }
        }
        return r;
    }

    //O(N^2), no need for post repetition check
    vector<vector<int> > threeSum5(vector<int> &num) {
        vector<vector<int> > r;
        if (num.size() < 3)
            return r;
        //record each number and times
        unordered_map<int, int> m;
        for (size_t i = 0; i < num.size(); ++i)
            ++m[num[i]];
        //sort numbers
        sort(num.begin(), num.end());
        //iterate first number(smallest)
        for (size_t i = 0; i < num.size() - 2; ++i){
            if (num[i] > 0)
                break;
            if (i && num[i] == num[i - 1])  //skip repeated first number
                continue;
            size_t j = i + 1;
            if (num[j] == num[i]){  //handle second number == first number
                int v = -2 * num[i];
                unordered_map<int, int>::const_iterator wh = m.find(v);
                //if third number > second number, that's OK
                //else if third number == second number, we should check if the number appears 3 times or more
                if (wh != m.end() && (v > num[j] || (v == num[j] && wh->second >= 3))){
                    r.push_back(vector<int>(2, num[i]));
                    r.back().push_back(v);
                }
                ++j;
            }
            for (; j < num.size() - 1; ++j){
                if (num[j] == num[j - 1])   //skip repeated second number
                    continue;
                int v = -num[i] - num[j];
                if (v < num[j]) //third number must >= second number
                    break;
                unordered_map<int, int>::const_iterator wh = m.find(v);
                //if third number > second number, that's OK
                //else if third number == second number, we should check if the number appears 2 times or more
                if (wh != m.end() && (v > num[j] || (v == num[j] && wh->second >= 2))){
                    r.push_back(vector<int>(1, num[i]));
                    r.back().push_back(num[j]);
                    r.back().push_back(v);
                }
            }
        }
        return r;
    }
};

class Solution2 {
public:
	//O(N^2 * logN)
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > r;
        sort(num.begin(), num.end());
        for(int i = 0;i < num.size();++i){
            if(i > 0 && num[i - 1] == num[i])
                continue;
            if(num[i] > 0)
                break;
            for(int j = i + 1;j < num.size();++j){
                if(j > i + 1 && num[j - 1] == num[j])
                    continue;
                if(num[i] + 2 * num[j] > 0)
                    break;
                const int k = 0 - num[i] - num[j];
                if(binary_search(num.begin() + j + 1, num.end(), k))
                    r.push_back({num[i], num[j], k});
            }
        }
        return r;
    }
};

void test(vector<int> & n)
{
    vector<vector<int> > r = Solution().threeSum5(n);
    sort(r.begin(), r.end());
    vector<vector<int> > c;
    /*
    c = Solution().threeSum1(n);
    sort(c.begin(), c.end());
    if (r != c){
        cout << "array: ";
        print(n);
        cout << "Solution 5:\n";
        print(r);
        cout << "Solution 1:\n";
        print(c);
        exit(1);
    }
    c = Solution().threeSum2(n);
    sort(c.begin(), c.end());
    if (r != c){
        cout << "array: ";
        print(n);
        cout << "Solution 5:\n";
        print(r);
        cout << "Solution 2:\n";
        print(c);
        exit(1);
    }
    c = Solution().threeSum3(n);
    sort(c.begin(), c.end());
    if (r != c){
        cout << "array: ";
        print(n);
        cout << "Solution 5:\n";
        print(r);
        cout << "Solution 3:\n";
        print(c);
        exit(1);
    }
    c = Solution().threeSum4(n);
    sort(c.begin(), c.end());
    if (r != c){
        cout << "array: ";
        print(n);
        cout << "Solution 5:\n";
        print(r);
        cout << "Solution 4:\n";
        print(c);
        exit(1);
    }*/
}

int main()
{
    {
        int a[] = { -1, 0, 1, 2, -1, -4 };
        vector<int> n(a, a + sizeof a / sizeof a[0]);
        test(n);
    }{
        int a[] = {-9,1,-6,-4,-4,0,-1,2,-6,5,6,-9,-10,-8,0,9,-6,4,-8,6,4,1,-10,-1,-9,-9,5,-4};
        vector<int> n(a, a + sizeof a / sizeof a[0]);
        test(n);
}{
        int a[] = {-7,-10,-1,3,0,-7,-9,-1,10,8,-6,4,14,-8,9,-15,0,-4,-5,9,11,3,-5,-8,2,-6,-14,7,-14,10,5,-6,7,11,4,-7,11,11,7,7,-4,-14,-12,-13,-14,4,-13,1,-15,-2,-12,11,-14,-2,10,3,-1,11,-5,1,-2,7,2,-10,-5,-8,-10,14,10,13,-2,-9,6,-7,-7,7,12,-5,-14,4,0,-11,-8,2,-6,-13,12,0,5,-15,8,-12,-1,-4,-15,2,-5,-9,-7,12,11,6,10,-6,14,-12,9,3,-10,10,-8,-2,6,-9,7,7,-7,4,-8,5,-4,8,0,3,11,0,-10,-9};
        vector<int> n(a, a + sizeof a / sizeof a[0]);
        test(n);
    }{
        int a[] = {12,13,-10,-15,4,5,-8,11,10,3,-11,4,-10,4,-7,9,1,8,-5,-1,-9,-4,3,-14,-11,14,0,-8,-6,-2,14,-9,-4,11,-8,-14,-7,-9,4,10,9,9,-1,7,-10,7,1,6,-8,12,12,-10,-7,0,-9,-3,-1,-1,-4,8,12,-13,6,-7,13,5,-14,13,12,6,8,-2,-8,-15,-10,-3,-1,7,10,7,-4,7,4,-4,14,3,0,-10,-13,11,5,6,13,-4,6,3,-13,8,1,6,-9,-14,-11,-10,8,-5,-6,-7,9,-11,7,12,3,-4,-7,-6,14,8,-1,8,-4,-11};
        vector<int> n(a, a + sizeof a / sizeof a[0]);
        test(n);
    }
    cout << "PASS\n";
}
