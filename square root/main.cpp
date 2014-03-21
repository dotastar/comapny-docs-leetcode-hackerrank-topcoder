#include <iostream>

double my_sqrt(double v)
{
    double r = 1;
    for(double rr = v;;){
        double e = (r > rr ? r - rr : rr - r);
        if(e < 0.0001)
            break;
        rr = r;
        r = (r + v / r) / 2;    //sqrt is between r and v/r
    }
    return r;
}

int main()
{
    std::cout<<my_sqrt(5)<<"\n";
    std::cout<<my_sqrt(.5)<<"\n";
    std::cout<<my_sqrt(1)<<"\n";
    std::cout<<my_sqrt(1.001)<<"\n";
}