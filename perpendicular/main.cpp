#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

void minDistance(const std::vector<std::pair<double, double> > & coordins)
{
    double X = 0, Y = 0, X2 = 0, Y2 = 0, XY = 0;
    for(size_t i = 0;i < coordins.size();++i){
        X += coordins[i].first;
        Y += coordins[i].second;
        X2 += coordins[i].first * coordins[i].first;
        Y2 += coordins[i].second * coordins[i].second;
        XY += coordins[i].first * coordins[i].second;
    }
    double a = XY * Y - Y2 * X;
    double b = XY * X - X2 * Y;
    double c = XY * XY - X2 * Y2;
    std::cout<<"Line: "<<a<<"x + "<<b<<"y = "<<c;
    double dis = 0;
    for(size_t i = 0;i < coordins.size();++i)
        dis += fabs(a * coordins[i].first + b * coordins[i].second - c);
    dis /= sqrt(a * a + b * b);
    std::cout<<", distance: "<<dis<<"\n";
}

int main()
{
    const double coord[][2] = {
        {23, 54},
        {14, 45},
        {87, 67},
        {34, 64},
    };
    std::vector<std::pair<double, double> > c;
    for(size_t i = 0;i < sizeof coord / sizeof coord[0];++i)
        c.push_back(std::make_pair(coord[i][0], coord[i][1]));
    minDistance(c);
}
