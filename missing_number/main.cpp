#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main()
{
    int len;
    std::string line;
    std::cout<<"Enter the length:";
    std::cin>>len;
    if(len < 3){
        std::cerr<<"error: length < 3\n";
        return 1;
    }
    std::cout<<"Enter the sequence:";
    std::getline(std::cin, line);
    std::getline(std::cin, line);
    std::vector<int> vec;
    std::istringstream iss(line);
    for(int i;(iss>>i);)
        vec.push_back(i);
    if(len != int(vec.size())){
        std::cerr<<"error: sequence length is not "<<len<<"\n";
        return 1;
    }
    int sum = (vec.front() + vec.back()) * (len + 1) / 2;
    for(size_t i = 0;i < vec.size();++i)
        sum -= vec[i];
    std::cout<<"missing "<<sum<<"\n";
    return 0;
}
