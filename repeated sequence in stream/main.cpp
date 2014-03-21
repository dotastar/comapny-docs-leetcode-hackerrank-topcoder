#include "..\inc.h"

class input_stream
{
public:
    input_stream(){srand(int(time(0)));}
    // Character or -1
    int read(){
        return rand() % 26 + 'a';
    }
};

void solve()
{
    const int LEN = 7;
    string seq;
    map<int, vector<int> > h2i;  //hash -> index
    int h = 0;
    input_stream is;
    //first LEN chars
    for(int i = 0;i < LEN;++i){
        int c = is.read();
        seq.push_back(c);
        h = (h << 2) + c;
    }
    h2i[h].push_back(seq.size());
    //following chars
    for(;;){
        h -= seq[seq.size() - LEN] << (2 * LEN - 2);
        int c = is.read();
        seq.push_back(c);
        h = (h << 2) + c;
        vector<int> & v = h2i[h];
        if(!v.empty()){
            string cur = seq.substr(seq.size() - LEN, LEN);
            for(size_t i = 0;i < v.size();++i){
                if(cur == seq.substr(v[i] - LEN, LEN)){
                    cout<<"total sequence size: "<<seq.size()<<endl;
                    cout<<"find repeats at pos "<<(v[i] - LEN)<<" and "<<(seq.size() - LEN)<<endl;
                    cout<<cur<<endl;
                    return;
                }
            }
        }
        v.push_back(seq.size());
    }
}

int main()
{
    solve();
}