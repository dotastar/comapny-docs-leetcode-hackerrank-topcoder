#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int a = 1;
        for(int i = digits.size() - 1;a && i >= 0;--i){
            if(digits[i] < 9){
                ++digits[i];
                a = 0;
            }else
                digits[i] = 0;
        }
        if(a)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(){}