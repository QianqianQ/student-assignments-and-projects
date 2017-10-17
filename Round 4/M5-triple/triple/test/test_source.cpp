#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdexcept>
#include "../src/triple.hpp"

TEST(test_triple, test_construct_copy_assignment_access) {
    // Seed the random
    srand(time(0));

    std::vector<std::string> strings = {"Templates", "are", "fun", "reb00t", "coffee"};

    // Test the constructor
    int i1=rand()%5;
    int i2=rand()%5;
    int i3=rand()%5;
    int i4=rand()%5;
    int i5=rand()%5;
    int i6=rand()%5;
    int i7=rand()%5;
    int d1=((double)((rand()%100)+10))/17.2;
    int c1=(char)((rand()%91)+33);
    Triple<int, int, int> t1(i1, i2, i3);
    const Triple<int, int, int>& rt1 = t1;

    Triple<int, int, int> t2(i4, i5, i6);
    const Triple<int, int, int>& rt2 = t2;

    Triple<int, double, char> t3(i7, d1, c1);
    const Triple<int, double, char>& rt3 = t3;


    // Test the accessors
    EXPECT_EQ(i1, rt1.first());
    EXPECT_EQ(i2, rt1.second());
    EXPECT_EQ(i3, rt1.third());
    EXPECT_EQ(i4, rt2.first());
    EXPECT_EQ(i5, rt2.second());
    EXPECT_EQ(i6, rt2.third());
    EXPECT_EQ(i7, rt3.first());
    EXPECT_EQ(d1, rt3.second());
    EXPECT_EQ(c1, rt3.third());

    // Test the copy constructor
    Triple<int, int, int> ct1(rt1);
    Triple<int, int, int> ct2(rt2);
    Triple<int, double, char> ct3(rt3);

    EXPECT_EQ(i1, ct1.first());
    EXPECT_EQ(i2, ct1.second());
    EXPECT_EQ(i3, ct1.third());
    EXPECT_EQ(i4, ct2.first());
    EXPECT_EQ(i5, ct2.second());
    EXPECT_EQ(i6, ct2.third());
    EXPECT_EQ(i7, ct3.first());
    EXPECT_EQ(d1, ct3.second());
    EXPECT_EQ(c1, ct3.third());

    // Test the assignment operator
    Triple<int, int, int> at1 = rt1;
    t2 = t2; // Self assignment
    Triple<int, double, char> at3 = rt3;

    EXPECT_EQ(i1, at1.first());
    EXPECT_EQ(i2, at1.second());
    EXPECT_EQ(i3, at1.third());
    EXPECT_EQ(i7, at3.first());
    EXPECT_EQ(d1, at3.second());
    EXPECT_EQ(c1, at3.third());
}

TEST(test_triple2, test_maketriple_ishomogenous) {
    // Seed the random
    srand(time(0));

    std::vector<std::string> strings = {"Templates", "are", "fun", "reb00t", "coffee"};

    int i1=rand()%5;
    int i2=rand()%5;
    int i3=rand()%5;
    int i4=rand()%5;
    int i5=rand()%5;
    int i6=rand()%5;
    int i7=rand()%5;
    int d1=((double)((rand()%100)+10))/17.2;
    int c1=(char)((rand()%91)+33);
    Triple<int, int, int> t1(i1, i2, i3);
    const Triple<int, int, int>& rt1 = t1;

    Triple<int, int, int> t2(i4, i5, i6);
    const Triple<int, int, int>& rt2 = t2;

    Triple<int, double, char> t3(i7, d1, c1);
    const Triple<int, double, char>& rt3 = t3;


    EXPECT_EQ(i1, rt1.first());
    EXPECT_EQ(i2, rt1.second());
    EXPECT_EQ(i3, rt1.third());
    EXPECT_EQ(i4, rt2.first());
    EXPECT_EQ(i5, rt2.second());
    EXPECT_EQ(i6, rt2.third());
    EXPECT_EQ(i7, rt3.first());
    EXPECT_EQ(d1, rt3.second());
    EXPECT_EQ(c1, rt3.third());

    // Test the isHomogenous function
    EXPECT_TRUE(isHomogenous(rt1));
    EXPECT_TRUE(isHomogenous(rt2));
    EXPECT_FALSE(isHomogenous(rt3));

}

TEST(test_triple3, test_eq_neq_print) {
    // Seed the random
    srand(time(0));

    std::vector<std::string> strings = {"Templates", "are", "fun", "reb00t", "coffee"};

    // Test the ==, !=, and << -operators
    int i1=rand()%5;
    int i2=rand()%6;
    int i3=rand()%7;
    int i4=rand()%8;
    int i5=rand()%9;
    int i6=rand()%10;
    int i7=rand()%11;
    int i11=rand()%12;
    int d1=((double)((rand()%100)+10))/17.2;
    int d2=((double)((rand()%100)+10))/18.2;
    int c1=(char)((rand()%91)+34);
    int c2=(char)((rand()%91)+33);
    Triple<int, int, int> t1(i1, i2, i3);
    const Triple<int, int, int>& rt1 = t1;

    Triple<int, int, int> t2(i4, i5, i6);
    const Triple<int, int, int>& rt2 = t2;

    Triple<int, double, char> t3(i7, d1, c1);
    const Triple<int, double, char>& rt3 = t3;

    Triple<int, double, char> t4(i11, d2, c2);
    const Triple<int, double, char>& rt4 = t4;


    // Test the << -operator
    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    std::cout << rt1 << std::endl;
    std::cout << rt2 << std::endl;
    std::cout << rt3 << std::endl;
    std::cout << rt4 << std::endl;

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "[" << i1 << ", " << i2 << ", " << i3 << "]";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    c << "[" << i4 << ", " << i5 << ", " << i6 << "]";
    correct = c.str();
    std::getline(test, checkstr);
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    c << "[" << i7 << ", " << d1 << ", " << (char)c1 << "]";
    correct = c.str();
    std::getline(test, checkstr);
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    c << "[" << i11 << ", " << d2 << ", " << (char)c2 << "]";
    correct = c.str();
    std::getline(test, checkstr);
    EXPECT_EQ(correct, checkstr);


    // Test the == -operator
    EXPECT_FALSE(rt1==rt2);
    EXPECT_FALSE(rt3==rt4);

    // Test the != -operator
    EXPECT_TRUE(rt1!=rt2);
    EXPECT_TRUE(rt3!=rt4);
}

