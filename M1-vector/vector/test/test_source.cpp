#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../src/vector.hpp"

TEST(test_vector, test_1) {
    
    std::vector<int> v;

    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = (rand()) / (RAND_MAX / 100);
    for(int i=0; i<10; i++){
        v.push_back(a);
        a = (rand()) / (RAND_MAX / 100);
    }

    EXPECT_EQ(*std::min_element(v.begin(), v.end()), getMin(v));
    EXPECT_EQ(*std::max_element(v.begin(), v.end()), getMax(v));
    EXPECT_EQ((double)std::accumulate(v.begin(), v.end(), 0)/v.size(), getAvg(v));
}
