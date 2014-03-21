class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int r = 0;
        for(int i = x;i;i /= 10){
            r *= 10;
            r += i % 10;
        }
        return r == x;
    }
};

int main(){}