#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "../src/poly.hpp"

TEST(test_poly, test_modify) {
    std::vector<int> v, v2;
    
    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = -(rand()) / (RAND_MAX / 10);
    int b = -(rand()) / (RAND_MAX / 10);
    for(int i=0; i<4; i++){
        v.push_back(a);
        v2.push_back(b);
        a = (rand()) / (RAND_MAX / 10);
        a *= pow(-1, i);
        b = (rand()) / (RAND_MAX / 10);
        b *= pow(-1, i);
    }

    Poly p1, p2; 
    for(int i=0; i<4; i++){
        p1[i] = v[i];
        p2[i] = v2[i];
    }
    EXPECT_EQ(v[0], p1[0]);
    EXPECT_EQ(v[1], p1[1]);
    EXPECT_EQ(v[2], p1[2]);
    EXPECT_EQ(v[3], p1[3]);

    EXPECT_EQ(p2[0], v2[0]);
    EXPECT_EQ(p2[1], v2[1]);
    EXPECT_EQ(p2[2], v2[2]);
    EXPECT_EQ(p2[3], v2[3]);
}

TEST(test_poly, test_iterators) {
    std::vector<int> v, v2;
    
    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = -(rand()) / (RAND_MAX / 10);
    int b = -(rand()) / (RAND_MAX / 10);
    for(int i=0; i<4; i++){
        v.push_back(a);
        v2.push_back(b);
        a = (rand()) / (RAND_MAX / 10);
        a *= pow(-1, i);
        b = (rand()) / (RAND_MAX / 10);
        b *= pow(-1, i);
    }

    Poly p1, p2; 
    for(int i=0; i<4; i++){
        p1[i] = v[i];
        p2[i] = v2[i];
    }

    auto it = std::next(p1.begin(), 2);
    EXPECT_EQ(v[1], it->second);
    EXPECT_EQ(v2[3], p2.begin()->second);
    Poly const& p = p1;
    Poly const& pp = p2;
    auto it2 = std::next(pp.begin(), 1);
    EXPECT_EQ(v[3], p.begin()->second);
    EXPECT_EQ(v2[2], it2->second);
}

TEST(test_poly, test_access) {
    std::vector<int> v, v2;
    
    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = -(rand()) / (RAND_MAX / 10);
    int b = -(rand()) / (RAND_MAX / 10);
    for(int i=0; i<4; i++){
        v.push_back(a);
        v2.push_back(b);
        a = (rand()) / (RAND_MAX / 10);
        a *= pow(-1, i);
        b = (rand()) / (RAND_MAX / 10);
        b *= pow(-1, i);
    }

    Poly p1, p2; 
    for(int i=0; i<4; i++){
        p1[i] = v[i];
        p2[i] = v2[i];
    }
    Poly const& p = p1;
    Poly const& pp = p2;
    EXPECT_EQ(p[0], v[0]);
    EXPECT_EQ(p[1], v[1]);
    EXPECT_EQ(pp[2], v2[2]);
    EXPECT_EQ(pp[3], v2[3]);
}

TEST(test_poly, test_negate) {
    std::vector<int> v, v2;
    
    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = -(rand()) / (RAND_MAX / 10);
    int b = -(rand()) / (RAND_MAX / 10);
    for(int i=0; i<4; i++){
        v.push_back(a);
        v2.push_back(b);
        a = (rand()) / (RAND_MAX / 10);
        a *= pow(-1, i);
        b = (rand()) / (RAND_MAX / 10);
        b *= pow(-1, i);
    }

    Poly p1, p2; 
    for(int i=0; i<4; i++){
        p1[i] = v[i];
        p2[i] = v2[i];
    }
    Poly const& p = -p1;
    Poly const& pp = -p2;
    EXPECT_EQ(p[0], -v[0]);
    EXPECT_EQ(p[1], -v[1]);
    EXPECT_EQ(pp[2], -v2[2]);
    EXPECT_EQ(pp[3], -v2[3]);
}

TEST(test_poly2, test_add) {
    std::vector<int> v, v2, v3;
    
    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = -(rand()) / (RAND_MAX / 10);
    int b = -(rand()) / (RAND_MAX / 10);
    int c = -(rand()) / (RAND_MAX / 10);
    for(int i=0; i<4; i++){
        v.push_back(a);
        v2.push_back(b);
        v3.push_back(c);
        a = (rand()) / (RAND_MAX / 10);
        a *= pow(-1, i);
        b = (rand()) / (RAND_MAX / 10);
        b *= pow(-1, i);
        c = (rand()) / (RAND_MAX / 10);
        c *= pow(-1, i);

    }

    Poly p1, p2, p3; 
    for(int i=0; i<4; i++){
        p1[i] = v[i];
        p2[i] = v2[i];
        p3[i] = v3[i];
    }
    Poly const& pp = p2;
    Poly const& ppp = p3;

    p1+=pp;
    Poly t = ppp+pp;
    EXPECT_EQ(p1[0], v[0]+v2[0]);
    EXPECT_EQ(p1[2], v[2]+v2[2]);
    EXPECT_EQ(p1[3], v[3]+v2[3]);
    EXPECT_EQ(t[1], v2[1]+v3[1]);
    EXPECT_EQ(t[0], v2[0]+v3[0]);
    EXPECT_EQ(t[3], v2[3]+v3[3]);
}

TEST(test_poly2, test_substract) {
    std::vector<int> v, v2, v3;
    
    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = -(rand()) / (RAND_MAX / 10);
    int b = -(rand()) / (RAND_MAX / 10);
    int c = -(rand()) / (RAND_MAX / 10);
    for(int i=0; i<4; i++){
        v.push_back(a);
        v2.push_back(b);
        v3.push_back(c);
        a = (rand()) / (RAND_MAX / 10);
        a *= pow(-1, i);
        b = (rand()) / (RAND_MAX / 10);
        b *= pow(-1, i);
        c = (rand()) / (RAND_MAX / 10);
        c *= pow(-1, i);

    }

    Poly p1, p2, p3; 
    for(int i=0; i<4; i++){
        p1[i] = v[i];
        p2[i] = v2[i];
        p3[i] = v3[i];
    }
    Poly const& pp = p2;
    Poly const& ppp = p3;

    p1-=pp;
    Poly t = pp-ppp;
    EXPECT_EQ(p1[0], v[0]-v2[0]);
    EXPECT_EQ(p1[2], v[2]-v2[2]);
    EXPECT_EQ(p1[3], v[3]-v2[3]);
    EXPECT_EQ(t[1], v2[1]-v3[1]);
    EXPECT_EQ(t[0], v2[0]-v3[0]);
    EXPECT_EQ(t[3], v2[3]-v3[3]);
}

TEST(test_poly3, test_equal) {
    Poly p1, p2, p3;
    std::istringstream iss("1x2+3x4-5x2 4x6+2x2-5x3");
    std::istringstream iss2("1x2+3x4-5x2");
    iss >> p1 >> p2;
    iss2 >> p3;

    Poly const& t=p1;
    Poly const& t2=p2;
    Poly const& t3=p3;
    EXPECT_FALSE(t==t2);
    EXPECT_TRUE(t==t3);
}

TEST(test_poly3, test_not_equal) {
    Poly p1, p2, p3;
    std::istringstream iss("1x2+3x4-5x2 4x6+2x2-5x3");
    std::istringstream iss2("1x2+3x4-5x2");
    iss >> p1 >> p2;
    iss2 >> p3;

    Poly const& t=p1;
    Poly const& t2=p2;
    Poly const& t3=p3;
    EXPECT_TRUE(t!=t2);
    EXPECT_FALSE(t!=t3);
}

TEST(test_poly3, test_smaller) {
    Poly p1, p2, p3;
    std::istringstream iss("1x2+3x4-5x2 4x6+2x2-5x3");
    std::istringstream iss2("4x5+3x4-5x2");
    iss >> p1 >> p2;
    iss2 >> p3;

    Poly const& t=p1;
    Poly const& t2=p2;
    Poly const& t3=p3;
    EXPECT_FALSE(t3<t);
    EXPECT_TRUE(t3<t2);
}

TEST(test_poly3, test_bigger) {
    Poly p1, p2, p3;
    std::istringstream iss("1x2+3x4-5x2 4x6+2x2-5x3");
    std::istringstream iss2("4x5+3x4-5x2");
    iss >> p1 >> p2;
    iss2 >> p3;

    Poly const& t=p1;
    Poly const& t2=p2;
    Poly const& t3=p3;
    EXPECT_FALSE(t>t2);
    EXPECT_TRUE(t2>t3);
}
