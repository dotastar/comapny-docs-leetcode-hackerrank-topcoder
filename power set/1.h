using namespace std;

//from Miguel Oliveira
void PowerSet(int i, const vector<pair<int,int> >& vo, vector<int>& cur) {
    if (i == vo.size()) {
        if (cur.size() == 0)
            cout << "NULL" << endl;
        else {
            for (size_t i = 0; i < cur.size(); i++)
                cout << cur[i] << " ";
            cout << endl;
        }
    } else {
        size_t cur_size = cur.size();
        PowerSet(i+1, vo, cur); // don't use any of these numbers
        for (int k = 1; k <= vo[i].second; k++) {
            cur.push_back(vo[i].first); // use this number k times
            PowerSet(i+1, vo, cur);
        }
        cur.resize(cur_size); // get cur vector to previous size
    }
}
void PowerSet(int v[], int n) {
    sort(v, v+n);
    vector<pair<int,int> > voccur;
    for (int i = 0; i < n ; i++) {
        int num = 1;
        for (; i+1 < n && v[i] == v[i+1]; i++)
            num++;
        voccur.push_back(make_pair(v[i], num));
    }
    vector<int> cur_set;
    PowerSet(0, voccur, cur_set);
}