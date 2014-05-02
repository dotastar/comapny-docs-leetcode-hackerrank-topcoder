#include "../inc.h"

int main()
{
    typedef pair<map<int, int>::iterator, bool> __Ret;
    int t;
    map<int, int> tasks;    //deadline -> total minutes before current deadline
    int ret = 0;
    for (cin >> t; t--;){
        int d, m;
        cin >> d >> m;
        __Ret ir = tasks.insert(make_pair(d, 0));
        if (ir.second){ //new insertion
            map<int, int>::iterator p = ir.first;
            if (p != tasks.begin()){
                --p;
                ir.first->second = p->second;   //get previous total
            }
        }
        for (; ir.first != tasks.end(); ++ir.first){
            ir.first->second += m;
            ret = max(ret, ir.first->second - ir.first->first);
        }
        cout << ret << endl;
    }
}