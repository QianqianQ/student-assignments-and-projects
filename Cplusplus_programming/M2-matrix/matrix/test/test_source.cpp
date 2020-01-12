#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "../src/matrix.hpp"

TEST(test_matrix, test_read) {
    //write to file
    std::string input = "1 2 3 4 5 6 5 4 3 2 1 2 3 4 5 6 5 4 3 2 1 2 3 4 5";
    std::ofstream file("in.txt");
    file << input;
    file.close();

    //use file in.txt as standard input
    std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    Matrix m = readMatrix(5); 

    std::cin.rdbuf(cinbuf); //reset to standard input again

    Matrix c = {{1, 2, 3, 4, 5}, {6, 5, 4, 3, 2}, {1, 2, 3, 4, 5}, {6, 5, 4, 3, 2}, {1, 2, 3, 4, 5}};

    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            EXPECT_EQ(c[i][j], m[i][j]);
}

TEST(test_matrix, test_rotate) {
    Matrix t = {{1, 2, 3, 4, 5}, {6, 5, 4, 3, 2}, {1, 2, 3, 4, 5}, {6, 5, 4, 3, 2}, {1, 2, 3, 4, 5}};
    Matrix c = {{1, 6, 1, 6, 1}, {2, 5, 2, 5, 2}, {3, 4, 3, 4, 3}, {4, 3, 4, 3, 4}, {5, 2, 5, 2, 5}}; 

    Matrix m = rotate90deg(t); 

    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            EXPECT_EQ(c[i][j], m[i][j]) << " when i=" << i << " j=" << j;
}

TEST(test_matrix, test_print) {
    Matrix m = {{1, 6, 1, 6, 1}, {2, 5, 2, 5, 2}, {3, 4, 3, 4, 3}, {4, 3, 4, 3, 4}, {5, 2, 5, 2, 5}}; 
    
    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    print(m);

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::cout << "Testing output" << std::endl;
    std::ostringstream c;
    c << "Printing out a 5 x 5 matrix:";
    std::string correct = c.str();

    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "1 6 1 6 1 ";
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
 
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "2 5 2 5 2 ";
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "3 4 3 4 3 ";
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "4 3 4 3 4 ";
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "5 2 5 2 5 ";
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
}

