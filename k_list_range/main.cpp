#include "../inc.h"

//return: [from, to]
pair<int, int> solve(const vector<vector<int> > & lists)
{
    pair<int, int> ret(0, -1);
    if(lists.empty())
        return ret;
    for(size_t i = 0;i < lists.size();++i)
        if(lists[i].empty())
            return ret;
    if(lists.size() < 2)
        return make_pair(lists[0][0], lists[0][0]);
    vector<pair<int, int> > order;      //(list_index, index_in_list)
    vector<int> indices(lists.size());  //current index of each list
    size_t from = 0, to = 0;
    vector<int> has(lists.size());
    for(;;){
        pair<int, int> cur(-1, 0);
        int finish = 0;
        for(size_t i = 0;i < lists.size();++i){
            if(indices[i] >= lists[i].size()){
                ++finish;
                continue;
            }
            if(cur.first < 0 || lists[i][indices[i]] < lists[cur.first][cur.second]){
                cur.first = i;
                cur.second = indices[i];
            }
        }
        if(finish >= lists.size())
            break;
        order.push_back(cur);
        ++indices[cur.first];
        //update range
        to = order.size() - 1;
        ++has[cur.first];
        size_t i = 0;
        for(;i < has.size();++i)
            if(!has[i])
                break;
        if(i >= has.size()){
            for(;from < to;++from){
                if(has[order[from].first] < 2)
                    break;
                --has[order[from].first];
            }
            assert(from < to);
            pair<int, int> r(lists[order[from].first][order[from].second],
                    lists[order[to].first][order[to].second]);
            if(ret.second < ret.first || r.second - r.first < ret.second - ret.first)
                ret = r;
        }
    }
    return ret;
}

int main()
{
    {
        const int arr1[] = {4, 10, 15, 24, 26};
        const int arr2[] = {0, 9, 12, 20};
        const int arr3[] = {5, 18, 22, 30};
        vector<vector<int> > lists;
        lists.push_back(vector<int>(arr1, arr1 + sizeof arr1 / sizeof arr1[0]));
        lists.push_back(vector<int>(arr2, arr2 + sizeof arr2 / sizeof arr2[0]));
        lists.push_back(vector<int>(arr3, arr3 + sizeof arr3 / sizeof arr3[0]));
        pair<int, int> ret = solve(lists);
        cout<<ret.first<<", "<<ret.second<<endl;
    }

}
