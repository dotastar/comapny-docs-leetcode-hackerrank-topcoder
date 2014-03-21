#include <iostream>
#include <vector>
#include <set>

//O(N^2) solution
bool found(const std::vector<int> & vec, int val)
{
    for(size_t i = 0;i < vec.size();++i)
        if(vec[i] == val)
            return true;
    return false;
}
void rmDuplicatesN2(const std::vector<int> & in, std::vector<int> & out)
{
    out.clear();
    for(size_t i = 0;i < in.size();++i)
        if(!found(out, in[i]))
            out.push_back(in[i]);

    for(size_t i = 0;i < out.size();++i)
        std::cout<<out[i]<<", ";
    std::cout<<"\n";
}

void rmDuplicatesNLgN(const std::vector<int> & in, std::vector<int> & out)
{
    out.clear();
    std::set<int> s;
    for(size_t i = 0;i < in.size();++i)
        if(!s.count(in[i])){
            out.push_back(in[i]);
            s.insert(in[i]);
        }

    for(size_t i = 0;i < out.size();++i)
        std::cout<<out[i]<<", ";
    std::cout<<"\n";
}

//or O(N) using hash table

int main()
{
    const int vec[] = {2, 3, 1, 4, 2, 1, 3 ,4};
    std::vector<int> v(vec, vec + sizeof vec / sizeof vec[0]);
    std::vector<int> r;
    rmDuplicatesN2(v, r);
    rmDuplicatesNLgN(v, r);
}
