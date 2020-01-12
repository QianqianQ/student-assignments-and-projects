#include <iostream>
#include <vector>
#include "matrix.hpp"

// Remember to use auto and ranged for-loops when they can be used!
// Assumes 'm' is a square matrix
Matrix readMatrix(int n){
    Matrix m;
    int i;
    int j;
    for(i=0;i<n;i++)
    {
        std::vector<int> new_row;
        m.push_back(new_row);
        for(j=0;j<n;j++)
    {
        int in;
        std::cin>>in;
        m.at(i).push_back(in);
    }
    }

    return m;
}

Matrix rotate90deg(Matrix & m) {
    Matrix new_m;
    unsigned int length=m.size();
    for(unsigned int i=0;i<length;i++)
    {
        std::vector<int> new_row;
        new_m.push_back(new_row);
        for(unsigned int j=0;j<length;j++)
        {
            int element = m[j][i];
            new_m.at(i).push_back(element);
        }
    }
    for (unsigned int k=0;k<length;k++)
    {
        for(unsigned int l=0;l<(length/2);l++)
        {
            int temp = new_m[k][l];
            new_m[k][l] = new_m[k][length-1-l];
            new_m[k][length-1-l]=temp;
        }
    }
    return new_m;

}

void print(Matrix & m){
    std::cout << "Printing out a " << m.size() << " x " << m.size() << " matrix:" << std::endl;
    for(unsigned int i=0;i<m.size();i++)
    {
        for(unsigned int j=0;j<m.size();j++)
        {
            std::cout<<m[i][j]<<' ';
        }
        std::cout<<std::endl;
    }

}
