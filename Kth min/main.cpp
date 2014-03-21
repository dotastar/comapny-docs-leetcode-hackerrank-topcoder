#include <vector>
#include <cassert>
#include <algorithm>
#include <iostream>

static void nextIdx(const std::vector<int> & r1,
             const std::vector<int> & r2,
             const std::vector<int> & idx1,
             const std::vector<int> & idx2,
             int & i,
             int & j,
             int min_i,
             int min_j)
{
    if(j > 0){
        int rr = r1[i] + r2[j];
        for(int ii = min_i;ii < int(r1.size());++ii){
            int jj = idx1[ii] + 1;
            if(jj < j && rr > r1[ii] + r2[jj]){
                i = ii;
                j = jj;
                rr = r1[i] + r2[j];
            }
            if(!jj)
                break;
        }
    }
    if(i > 0){
        int rr = r1[i] + r2[j];
        for(int jj = min_j;jj < int(r2.size());++jj){
            int ii = idx2[jj] + 1;
            if(ii < i && rr > r1[ii] + r2[jj]){
                i = ii;
                j = jj;
                rr = r1[i] + r2[j];
            }
            if(!ii)
                break;
        }
    }
}

//O(N)
int kthMin(const std::vector<int> & r1, const std::vector<int> & r2, int k)
{
    assert(1 <= k && k <= int(r1.size() * r2.size()));
    assert(!r1.empty() && !r2.empty());
    std::vector<int> idx1(r1.size(), -1);
    std::vector<int> idx2(r2.size(), -1);
    int ret;
    for(int i = 0, j = 0, n = 1;i < int(r1.size()) && j < int(r2.size());++n){
        ret = r1[i] + r2[j];
        if(n == k)
            break;
        idx1[i] = j;
        idx2[j] = i;
        if(i == r1.size() - 1){
            assert(j < int(r2.size()) - 1);
            i = idx2[++j] + 1;
            if(i > 0)
                nextIdx(r1, r2, idx1, idx2, i, j, r1.size(), j + 1);
        }else if(j == r2.size() - 1){
            assert(i < int(r1.size()) - 1);
            j = idx1[++i] + 1;
            if(j > 0)
                nextIdx(r1, r2, idx1, idx2, i, j, i + 1, r2.size());
        }else if(r1[i + 1] < r2[j + 1]){
            int jj = j;
            j = idx1[++i] + 1;
            nextIdx(r1, r2, idx1, idx2, i, j, i + 1, jj + 1);
        }else{
            int ii = i;
            i = idx2[++j] + 1;
            nextIdx(r1, r2, idx1, idx2, i, j, ii + 1, j + 1);
        }
    }
    return ret;
}

//O(N * N)
int kthMinSlow(const std::vector<int> & r1, const std::vector<int> & r2, int k)
{
    assert(1 <= k && k <= int(r1.size() * r2.size()));
    std::vector<int> v;
    for(int i = 0;i < k && i < int(r1.size());++i)
        for(int j = 0;j < k && j < int(r2.size());++j)
            v.push_back(r1[i] + r2[j]);
    std::sort(v.begin(), v.end());
    assert(int(v.size()) >= k);
    return v[k - 1];
}


void test(const int v1[], const int v2[], int N)
{
    assert(N > 0);
    std::vector<int> r1(v1, v1 + N);
    std::vector<int> r2(v2, v2 + N);
    //test
    std::vector<int> t1;
    for(int k = 1;k <= int(r1.size() * r2.size());++k){
        t1.push_back(kthMinSlow(r1, r2, k));
        //std::cout<<t1.back()<<", ";
    }
    //std::cout<<"\n";

    std::vector<int> t2;
    for(int k = 1;k <= int(r1.size() * r2.size());++k){
        t2.push_back(kthMin(r1, r2, k));
        //std::cout<<t2.back()<<", ";
    }
    //std::cout<<"\n";
    if(t1 != t2)
        std::cerr<<"test FAILED\n";
}

int main()
{
    {
        const int v1[] = {0, 1, 3, 5};
        const int v2[] = {1, 2, 4, 7};
        test(v1, v2, sizeof v1 / sizeof v1[0]);
    }{
        const int v1[] = {1, 2, 3,4,5,7,8,9,10,11};
        const int v2[] = {1,20,30,40,50,60,70,80,90,100};
        test(v1, v2, sizeof v1 / sizeof v1[0]);
    }{
        const int v1[] = {1, 30, 35};
        const int v2[] = {5,6,50};
        test(v1, v2, sizeof v1 / sizeof v1[0]);
    }{
        const int v1[] = {1, 6, 7, 9, 10, 14};
        const int v2[] = {2, 3, 5, 8, 11, 16};
        test(v1, v2, sizeof v1 / sizeof v1[0]);
    }{
        const int v1[] = {1, 2, 2, 2};
        const int v2[] = {1, 2, 3, 4};
        test(v1, v2, sizeof v1 / sizeof v1[0]);
    }{
        const int v1[] = {1, 3, 4, 10};
        const int v2[] = {2, 3, 8, 9};
        test(v1, v2, sizeof v1 / sizeof v1[0]);
    }{
        const int v1[] = {1,   50,  100, 1000, 6000, 6002, 6004, 6006, 6008, 6010};
        const int v2[] = {100,  200,  300, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
        test(v1, v2, sizeof v1 / sizeof v1[0]);
    }{
        const int v1[] = {1, 5, 6, 7, 8, 20, 21, 22};
        const int v2[] = {1, 4, 5, 10, 15, 16, 17, 18};
        test(v1, v2, sizeof v1 / sizeof v1[0]);
    }{
        const int v1[] = {100,200,300,400};
        const int v2[] = {1,2,3,4};
        test(v1, v2, sizeof v1 / sizeof v1[0]);
    }{
        const int v1[] = {1, 2, 3};
        const int v2[] = {1, 4, 7};
        test(v1, v2, sizeof v1 / sizeof v1[0]);
    }{
        const int v1[] = {1,   50,  100, 1000, 6000, 6002, 6004, 6006, 6008, 6010};
        const int v2[] = {100,  200,  300, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
        test(v1, v2, sizeof v1 / sizeof v1[0]);
    }{
        const int v1[] = {3,4,5,6,13,19};
        const int v2[] = {1,2,5,9,10,11};
        test(v1, v2, sizeof v1 / sizeof v1[0]);
    }
}