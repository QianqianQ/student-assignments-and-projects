#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "../src/vector_strings.hpp"

TEST(test_vector_strings, test_reader) {

    //write to file
    std::string input = "QUIT";
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

    cmdReader();

    std::cin.rdbuf(cinbuf); //reset to standard input again
    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "Commands: ADD, PRINT, REMOVE, QUIT";
    std::string correct = c.str();

    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Enter command:";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
}

TEST(test_vector_strings, test_add) {
    std::vector<std::string> v;

    //write to file
    std::string input = "Esko";
    std::ofstream file("in.txt");
    file << input << std::endl;
    file.close();

    //use file in.txt as standard input
    std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    adder(v);

    std::cin.rdbuf(cinbuf); //reset to standard input again
    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "Enter a name:";
    std::string correct = c.str();

    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Number of names in the vector:";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "1";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    EXPECT_EQ("Esko", v[0]);
}

TEST(test_vector_strings, test_remove){
    std::vector<std::string> v;

    //write to file
    std::string input = "Esko";
    std::ofstream file("in.txt");
    file << input << std::endl;
    input = "Eero";
    file << input << std::endl;
    input = "Franz";
    file << input << std::endl;
    file.close();

    //use file in.txt as standard input
    std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    //use ss as standard output
    std::stringstream ss;
    std::streambuf *outbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(ss.rdbuf()); //redirect std::cout to out.txt!

    adder(v);
    adder(v);
    adder(v);

    std::cout.rdbuf(outbuf); //reset to standard output again
    
    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    remover(v);

    std::cin.rdbuf(cinbuf); //reset to standard input again
    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "Removing the last element:";
    std::string correct = c.str();

    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Franz";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    EXPECT_EQ("Esko", v[0]);
    EXPECT_EQ("Eero", v[1]);
}

TEST(test_vector_strings, test_print){
    std::vector<std::string> v;

    //write to file
    std::string input = "Esko";
    std::ofstream file("in.txt");
    file << input << std::endl;
    input = "Eero";
    file << input << std::endl;
    input = "Franz";
    file << input << std::endl;
    file.close();

    //use file in.txt as standard input
    std::ifstream in("in.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    //use ss as standard output
    std::stringstream ss;
    std::streambuf *outbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(ss.rdbuf()); //redirect std::cout to out.txt!

    adder(v);
    adder(v);
    adder(v);

    std::cout.rdbuf(outbuf); //reset to standard output again
    
    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    printer(v);

    std::cin.rdbuf(cinbuf); //reset to standard input again
    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "Esko";
    std::string correct = c.str();

    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Eero";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Franz";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    EXPECT_EQ("Esko", v[0]);
    EXPECT_EQ("Eero", v[1]);
    EXPECT_EQ("Franz", v[2]);
}
