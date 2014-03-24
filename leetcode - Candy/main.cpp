#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int c = 1, r = c;
        int t = 0, i = 1;
        for(;i < int(ratings.size());++i){
            if(ratings[i - 1] < ratings[i]){        //��ǰrate����
                if(c > 1 && t < i - 1){     //���彵��[t, i-1]���˵�����
                    r -= (c - 1) * (i - t - 1);
                    c = 1;
                }
                r += ++c;
                t = i;
            }else if(ratings[i - 1] == ratings[i]){ //rateһ��
                if(c > 1 && t < i - 1)       //���彵��[t, i-1]���˵�����
                    r -= (c - 1) * (i - t - 1);
                t = i;
                c = 1;
                ++r;
            }else{      //��ǰrate����
                if(c > 1){
                    r += --c;   //�ݼ���ǰ�������������п��ܵ�ʱ�������彵��
                }else
                    r += 1 + i - t; //���ǰһ���Ѿ���1������������[t, i]���˵�����
            }
        }
        if(c > 1 && t < i - 1)     //���彵��[t, end]���˵�����
            r -= (c - 1) * (i - t - 1);
        return r;
    }
};

int main()
{
}