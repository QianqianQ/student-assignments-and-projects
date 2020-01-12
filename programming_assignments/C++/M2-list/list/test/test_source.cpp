#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "../src/list.hpp"

TEST(test_list, test_read) {
    std::list<std::string> list;
    std::ifstream f("teapot.ply");

    getLines(f, list);

    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = (rand()) / (RAND_MAX / 3000);
    int b = (rand()) / (RAND_MAX / 3000);

    auto it = list.begin();
    std::advance(it, a);

    std::ifstream t("teapot.ply");
    std::string line;
    for (int l = 0; std::getline(t, line) && l < a; l++);
    
    EXPECT_EQ(line, *it);
 
    auto it2 = list.begin();
    std::advance(it2, b);

    std::ifstream t2("teapot.ply");
    for (int l = 0; std::getline(t2, line) && l < b; l++);

   EXPECT_EQ(line, *it2);
}

TEST(test_list, test_print) {
    std::list<std::string> list;
    std::ifstream f("teapot.ply");

    getLines(f, list);

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    print(list);

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = (rand()) / (RAND_MAX / 3000);
    int b = (rand()) / (RAND_MAX / 3000);

    //read output from function
    std::ifstream o("out.txt");
    std::string check;
    for (int l = 0; std::getline(o, check) && l < a; l++);
    
    std::ifstream t("teapot.ply");
    std::string line;
    for (int l = 0; std::getline(t, line) && l < a; l++);
    
    EXPECT_EQ(line, check);
    
    std::ifstream o2("out.txt");
    std::string check2;
    for (int l = 0; std::getline(o2, check2) && l < b; l++);

    std::ifstream t2("teapot.ply");
    std::string line2;
    for (int l = 0; std::getline(t2, line2) && l < b; l++);
    
    EXPECT_EQ(line2, check2);
}

TEST(test_list, test_sort_and_unique) {
    std::list<std::string> list;
    std::ifstream f("teapot.ply");

    getLines(f, list);

    sortAndUnique(list);

    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = (rand()) / (RAND_MAX / 3000);
    int b = (rand()) / (RAND_MAX / 3000);

    auto it = list.begin();
    std::advance(it, a);

    std::ifstream t("teapot.ply");
    std::string line;
    std::vector<std::string> v;
    for (int l = 0; l < 3443; l++){
        std::getline(t, line);
        v.push_back(line);
    }

    std::sort(v.begin(), v.end());
    std::unique(v.begin(), v.end());

    EXPECT_EQ(v[a], *it);
 
    auto it2 = list.begin();
    std::advance(it2, b);

    EXPECT_EQ(v[b], *it2);
}
