#include "../inc.h"

struct CPhoto
{
    int h_, w_, d_;
    CPhoto(){}
    CPhoto(int h, int w, int d):h_(h),w_(w),d_(d){}
    CPhoto(int h, int w):h_(h),w_(w),d_(h * w - 1){}
};

//height, width: height and width of the wall
int solve(int height, int width, const vector<CPhoto> & photos)
{
    assert(0 < height && 0 < width);
    if(photos.empty())
        return 0;
    //step 1
    vector<vector<int> > profit(height, vector<int>(width));
    //step 2
    for(int k = 0;k < photos.size();++k)
        for(int i = photos[k].h_ - 1;i < height;++i)
            for(int j = photos[k].w_ - 1;j < width;++j)
                profit[i][j] = max(profit[i][j], photos[k].d_);
    cout<<"step 2:\n";
    print(profit);
    //step 3
    for(int i = 0;i < height;++i)
        for(int j = 0;j < width;++j){
            for(int k = 0;k < (i + 1) / 2;++k)
                profit[i][j] = max(profit[k][j] + profit[i - k - 1][j], profit[i][j]);
            for(int k = 0;k < (j + 1) / 2;++k)
                profit[i][j] = max(profit[i][k] + profit[i][j - k - 1], profit[i][j]);
        }
    cout<<"step 3:\n";
    print(profit);
    return profit.back().back();
}

int main()
{
    {
        vector<CPhoto> photos;
        photos.push_back(CPhoto(11, 31));
        photos.push_back(CPhoto(13, 29));
        photos.push_back(CPhoto(17, 23));
        photos.push_back(CPhoto(19, 19));
        photos.push_back(CPhoto(23, 17));
        cout<<solve(50, 50, photos)<<endl;
    }
}
