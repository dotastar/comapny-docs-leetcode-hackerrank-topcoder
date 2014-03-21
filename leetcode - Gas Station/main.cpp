#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0;
        size_t m = 0;
        for(size_t i = 0;i < gas.size();++i){
            gas[i] -= cost[i];
            sum += gas[i];
            if(gas[i] < gas[m])
                m = i;
        }
        if(sum < 0)
            return -1;
        for(size_t i = m + 1;;++i){
            if(i >= gas.size())
                i -= gas.size();
            if(m == i)
                return i;
            if(gas[i] < 0)
                continue;
            sum = gas[i];
            for(size_t j = i + 1;;++j){
                if(j >= gas.size())
                    j -= gas.size();
                if(j == i)
                    return i;
                sum += gas[j];
                if(sum < 0)
                    break;
            }
        }
        return -1;
    }
    int canCompleteCircuit2(vector<int> &gas, vector<int> &cost) {
        if(gas.empty())
            return -1;
        int sum = 0;
        int worst = 0;
        int idx;
        for(size_t i = 0;i < gas.size();++i){
            sum += gas[i] - cost[i];
            if(sum < worst){
                worst = sum;
                idx = i + 1;    //next station is the most difficult to reach
            }
        }
        return (sum < 0 ? -1 : idx % gas.size());
    }
};

int main()
{
}