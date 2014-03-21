#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

class CPoint
{
public:
    CPoint():x_(0),y_(0),r_(0){}
    CPoint(double x, double y):x_(x),y_(y){
        r_ = std::sqrt(x * x + y * y);
    }
    bool operator <(const CPoint & a) const{
        return r_ < a.r_;
    }
    std::string toString() const{
        std::ostringstream oss;
        oss<<"("<<x_<<","<<y_<<","<<r_<<")";
        return oss.str();
    }
private:
    double x_, y_, r_;
};

void findMin(const std::vector<CPoint> & in, int k, std::vector<CPoint> & out)
{
    out = in;
    if(k >= int(in.size()))
        return;
    std::nth_element(out.begin(), out.begin() + k, out.end());
    out.resize(k);
}

int main()
{
    std::vector<int> a;
    for(int i = 0;i < 50;++i)
        a.push_back(i + 1);
    std::random_shuffle(a.begin(), a.end());

    std::nth_element(a.begin(), a.begin() + 10, a.end());



    std::vector<CPoint> in, out;
    in.push_back(CPoint(45, 23));
    in.push_back(CPoint(23, 54));
    in.push_back(CPoint(22, 38));
    in.push_back(CPoint(25, 47));
    in.push_back(CPoint(52, 35));
    in.push_back(CPoint(38, 25));
    for(size_t i = 0;i < in.size();++i)
        std::cout<<in[i].toString()<<", ";
    std::cout<<"\n";

    findMin(in, 3, out);

    for(size_t i = 0;i < out.size();++i)
        std::cout<<out[i].toString()<<", ";
    std::cout<<"\n";
}