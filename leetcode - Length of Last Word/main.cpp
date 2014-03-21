class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(!s)
            return 0;
        int p = 0, c = 0;
        for(;*s;++s)
            if(' ' == *s){
                if(c){
                    p = c;
                    c = 0;
                }
            }else
                ++c;
        return (c ? c : p);
    }
};

int main(){}