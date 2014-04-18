#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

class CMedian
{
public:
    void add(int v){
        if (bigger.empty() || v >= *bigger.begin())
            bigger.insert(v);
        else
            smaller.insert(v);
        adjust();
    }
    bool remove(int v){
        if (bigger.empty())
            return false;
        if (v >= *bigger.begin()){
            if (!rm(v, bigger))
                return false;
        } else if (!rm(v, smaller))
            return false;
        adjust();
        return true;
    }
    bool getMedian(long long & v, bool & dem, bool & minus){
        if (bigger.empty())
            return false;
        if (bigger.size() > smaller.size()){
            dem = false;
            v = *bigger.begin();
        } else{
            long long r = *bigger.begin();  //overflow!
            r += *smaller.rbegin();
            v = r / 2;
            dem = (r & 1);
            minus = r < 0;  //-0.5 for example
        }
        return true;
    }
private:
    bool rm(int v, multiset<int> & s){
        if (s.empty())
            return false;
        auto wh = s.find(v);
        if (wh == s.end())
            return false;
        s.erase(wh);
        return true;
    }
    void adjust(){
        while (smaller.size() > bigger.size()){
            auto last = smaller.end();
            --last;
            int i = *last;
            smaller.erase(last);
            bigger.insert(i);
        }
        while (bigger.size() > smaller.size() + 1){
            int i = *bigger.begin();
            bigger.erase(bigger.begin());
            smaller.insert(i);
        }
    }
    multiset<int> bigger, smaller;
};

void median(vector<char> s, vector<int> X) {
    CMedian m;
    long long r;
    bool dem, minus;
    for (size_t i = 0; i < s.size(); ++i){
        switch (s[i]){
            case 'a':
                m.add(X[i]);
                if (!m.getMedian(r, dem, minus))
                    cout << "Wrong!";
                else{
                    if (!r && dem && minus)
                        cout << '-';
                    cout << r << (dem ? ".5" : "");
                }
                break;
            case 'r':
                if (!m.remove(X[i]) || !m.getMedian(r, dem, minus))
                    cout << "Wrong!";
                else{
                    if (!r && dem && minus)
                        cout << '-';
                    cout << r << (dem ? ".5" : "");
                }
        }
        cout << endl;
    }
}

void test()
{
    vector<char> s{ 'r', 'a', 'a', 'a', 'r', 'r', 'r'};
    vector<int> X{ 1, 1, 2, 1, 1, 2, 1 };
    median(s, X);
}

int main(void){

    //Helpers for input and output
    //test();    return 0;

    int N;
    cin >> N;

    vector<char> s;
    vector<int> X;
    char temp;
    int tempint;
    for (int i = 0; i < N; i++){
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
    }

    median(s, X);
    return 0;
}
