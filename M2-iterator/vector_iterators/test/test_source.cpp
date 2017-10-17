#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "../src/vector_it.hpp"

TEST(test_vector_it, test_read) {
    std::string input;

    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = (rand()) / (RAND_MAX / 100);
    for(int i=0; i<50; i++){
        input += std::to_string(a) + " ";
        a = (rand()) / (RAND_MAX / 100);
    }

    input += std::to_string(a) + " ";
    input += "!";

    //write to file
    std::ofstream file("in.txt");
    file << input;
    file.close();

    //use file in.txt as standard input
    std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    std::vector<int> v = readVector(); 

    std::cin.rdbuf(cinbuf); //reset to standard input again

    //read output from function
    std::string temp;
    std::ifstream test("in.txt");
    std::getline(test, temp);

    std::istringstream iss(temp);
    std::vector<int> c;

    while(1){
        int n;
        iss >> n;
        if(!iss)
            break;
        c.push_back(n);
    }

    for(int i=0; i<=50; i++)
        EXPECT_EQ(c[i], v[i]);
}

TEST(test_vector_it, test_sum1) {
    std::string input;
    std::string output;

    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = (rand()) / (RAND_MAX / 100), b=0;
    for(int i=0; i<50; i++){
        input += std::to_string(a) + " ";
        b = a;
        a = (rand()) / (RAND_MAX / 100);
        output += std::to_string(a+b) + " ";
    }

    input += std::to_string(a) + " ";
    input += "!";

    //write to file
    std::ofstream file("in.txt");
    file << input;
    file.close();

    //use file in.txt as standard input
    std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    std::vector<int> v = readVector();
    printSum1(v);

    std::cin.rdbuf(cinbuf); //reset to standard input again
    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    EXPECT_EQ(output, checkstr);
}

TEST(test_vector_it, test_sum2) {
    std::string input;

    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = (rand()) / (RAND_MAX / 100);
    for(int i=0; i<50; i++){
        input += std::to_string(a) + " ";
        a = (rand()) / (RAND_MAX / 100);
    }

    input += std::to_string(a) + " ";
    input += "!";

    //write to file
    std::ofstream file("in.txt");
    file << input;
    file.close();

    //use file in.txt as standard input
    std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    std::vector<int> v = readVector();
    printSum2(v);

    std::cin.rdbuf(cinbuf); //reset to standard input again
    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::string t;
    std::ifstream temp("in.txt");
    std::getline(temp, t);

    std::reverse(t.begin(), t.end());
    size_t s = 0, i = 0;
    while(i < t.length())
    {
        if(t[i] == ' ')
        {
            std::reverse(t.begin() + s, t.begin() + i);
            s = i + 1;
        }
        i++;
    }
    if(t[t.length() - 1] != ' ')  
    {
        std::reverse(t.begin() + s, t.end());           
    }

    std::istringstream iiss(input);
    std::istringstream itss(t);

    std::string output;
    std::string tt;
    itss >> tt;

    i=0;
    while(i<50/2){
        int n=0, m=0;
        iiss >> n;
        itss >> m;
        output += std::to_string(n+m) + " ";
        i++;
    }

    EXPECT_EQ(output, checkstr);
}

