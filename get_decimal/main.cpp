#include "../inc.h"

string solve(int a, int b)
{
    if(!b)
        return "INF";
    //handle sign
    bool minus = false;
    if(a < 0){
        a = -a;
        minus = !minus;
    }
    if(b < 0){
        b = -b;
        minus = !minus;
    }
    assert(0 <= a && 0 < b);
    //integer part
    int r1 = a / b;
    a %= b;
    //float part
    string r2, r3;
    map<int, size_t> pos;
    for(;a && r3.empty();a %= b){
        map<int, size_t>::const_iterator wh = pos.find(a);
        if(pos.end() == wh){
            pos[a] = r2.size();
            a *= 10;
            int d = a / b;
            assert(0 <= d && d < 10);
            r2.push_back(d + '0');
        }else{
            r3 = r2.substr(wh->second);
            r2.resize(wh->second);
        }
    }
    //generate result
    ostringstream oss;
    if(minus)
        oss<<'-';
    oss<<r1;
    if(!r2.empty() || !r3.empty()){
        oss<<'.';
        if(!r2.empty())
            oss<<r2;
        if(!r3.empty())
            oss<<'('<<r3<<')';
    }
    return oss.str();
}

int main()
{
    cout<<solve(-3, 2)<<endl;
    cout<<solve(13, -3)<<endl;
    cout<<solve(-13, -33)<<endl;
    cout<<solve(13000, 332)<<endl;
    cout<<solve(7, 43)<<endl;
    cout<<solve(1, 1666)<<endl;
    cout<<solve(3, 166600000)<<endl;
    //cout<<solve(13000000, 33343534)<<endl;
}

