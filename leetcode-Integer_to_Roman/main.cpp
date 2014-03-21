class Solution {
public:
    string intToRoman(int num) {
        string r;
        help(r, num / 1000, "M");
        num %= 1000;
        help(r, num / 100, "CDM");
        num %= 100;
        help(r, num / 10, "XLC");
        num %= 10;
        help(r, num, "IVX");
        return r;
    }
    void help(string & r, int c, const char * p){
        switch(c){
            case 3:r.push_back(*p);
            case 2:r.push_back(*p);
            case 1:r.push_back(*p);break;
            case 4:r.push_back(*p);
            case 5:r.push_back(p[1]);break;
            case 6:r.push_back(p[1]);
                   r.push_back(*p);break;
            case 7:r.push_back(p[1]);
                   r.push_back(*p);
                   r.push_back(*p);break;
            case 8:r.push_back(p[1]);
                   r.push_back(*p);
                   r.push_back(*p);
                   r.push_back(*p);break;
            case 9:r.push_back(*p);
                   r.push_back(p[2]);break;
            default:;
        }
    }
};
