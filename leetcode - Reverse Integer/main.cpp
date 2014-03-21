class Solution {
public:
    int reverse(int x) {
        if(!x)
            return 0;
        bool minus = false;
        if(x < 0){
            minus = true;
            x = -x;
        }
        int r = 0;
        for(;x;x /= 10)
            r = r * 10 + x % 10;
        return (minus ? -r : r);
    }
};

int main(){}
