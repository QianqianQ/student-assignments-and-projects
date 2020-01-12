#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "../src/tostring.hpp"

TEST(test_tostring, test_container) {
    std::vector<int> v;
    std::set<int> s;
    
    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = rand() / (RAND_MAX / 10);
    double b = rand() / (RAND_MAX / 10000);
    for(int i=0; i<25; i++){
        v.push_back(a);
        s.insert(b);
        a = rand() / (RAND_MAX / 10);
        b = rand() / (RAND_MAX / 10000);
    }
    
    std::string correct = "{ ";
    for(auto& i: v)
        correct+= std::to_string(i)+", ";
    correct.pop_back();
    correct.pop_back();
    correct+=" }";
    EXPECT_EQ(toString(v), correct);

    correct.erase(correct.begin(), correct.end());
    correct = "{ ";
    for(auto& i: s)
        correct+= std::to_string(i)+", ";
    correct.pop_back();
    correct.pop_back();
    correct+=" }";
    EXPECT_EQ(toString(s), correct);
}

TEST(test_tostring, test_iterators) {
    std::vector<int> v;
    std::set<int> s;
    std::string str("This is a very nice test string!");
    
    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = rand() / (RAND_MAX / 10);
    double b = rand() / (RAND_MAX / 10000);
    for(int i=0; i<25; i++){
        v.push_back(a);
        s.insert(b);
        a = rand() / (RAND_MAX / 10);
        b = rand() / (RAND_MAX / 10000);
    }
    
    std::string correct = "{ ";
    for(auto& i: v)
        correct+= std::to_string(i)+", ";
    correct.pop_back();
    correct.pop_back();
    correct+=" }";
    EXPECT_EQ(toString(v.begin(), v.end()), correct);

    correct.erase(correct.begin(), correct.end());
    correct = "{ ";
    for(auto& i: s)
        correct+= std::to_string(i)+", ";
    correct.pop_back();
    correct.pop_back();
    correct+=" }";
    EXPECT_EQ(toString(s.begin(), s.end()), correct);
    
    correct.erase(correct.begin(), correct.end());
    correct = "{ ";
    for(size_t i=0; i<str.length(); ++i){
        correct+=str[i];
        correct+=", ";
    }
    correct.pop_back();
    correct.pop_back();
    correct+=" }";
    EXPECT_EQ(toString(str.begin(), str.end()), correct);
}

TEST(test_tostring, test_string) {
    std::string s;
    
    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = (rand() / (RAND_MAX / 70)+48);
    for(int i=0; i<25; i++){
        s.push_back(a);
        a = (rand() / (RAND_MAX / 70)+48);
    }
    std::string correct = "\"";
    correct+=s;
    correct+="\"";
    EXPECT_EQ(toString(s), correct);
}

