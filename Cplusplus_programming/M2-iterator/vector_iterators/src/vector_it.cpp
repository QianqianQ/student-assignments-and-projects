#include <iostream>
#include <vector>
#include<cctype>
#include "vector_it.hpp"

std::vector<int> readVector() {
    std::vector<int> v;
    while(1)
    {
        int i;
        std::cin>>i;
        if(!std::cin.fail())
        {
            v.push_back(i);
            continue;
        }
        else
            break;
    }
    return v;
}

void printSum1(std::vector<int>& v) {
    std::vector<int> sum;
    for(auto i=v.begin();i!=(v.end()-1);i++)
    {
        int j = *i +*(i+1);
        sum.push_back(j);
    }
    for (auto k:sum)
    {
        std::cout<<k<<' ';
    }
    std::cout<<std::endl;
}

void printSum2(std::vector<int>& v) {
    std::vector<int> sum;
    auto size = v.size();
    auto i=v.begin();
    auto j=v.end()-1;
    if (size % 2 == 0)
    {
        while((i-1)!=j)
    {
        int s= *i+*j;
        sum.push_back(s);
        i++;
        j--;
    }
    }
    else
    {
         while(i!=j)
    {
        int s= *i+*j;
        sum.push_back(s);
        i++;
        j--;
    }

    }

    for(auto k:sum)
    {
        std::cout<<k<<' ';
    }
    std::cout<<std::endl;

}
