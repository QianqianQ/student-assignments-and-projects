#include "vector.hpp"
#include <vector>

int getMin(std::vector<int> v)
{
    int min=v[0];
    for(unsigned int i=1;i<v.size();i++){
        if(v[i]<min)
            min=v[i];
    }
    return min;
}

int getMax(std::vector<int> v)
{
    int max=v[0];
    for(unsigned int i=1;i<v.size();i++){
        if(v[i]>max)
            max=v[i];
    }
    return max;
}

double getAvg(std::vector<int> v)
{
    double sum=0;
    for(unsigned int i=0;i<v.size();i++){
        sum+=(double)v[i];
    }
    double avg=sum/v.size();
    return avg;
}