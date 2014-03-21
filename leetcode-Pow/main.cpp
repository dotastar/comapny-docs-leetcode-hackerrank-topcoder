class Solution {
public:
    double pow(double x, int n) {
        if(n < 0){
            x = 1 / x;
            n = -n;
        }
        double r = 1;
        for(int m = 0x40000000;m;m >>= 1){
            r *= r;
            if(m & n)
                r *= x;
        }
        return r;
    }
};

int main(){}
