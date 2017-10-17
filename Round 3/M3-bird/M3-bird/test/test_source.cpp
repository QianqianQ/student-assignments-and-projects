#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "../src/bird.hpp"

TEST(test_bird, test_add) {
    Aviary a;
    a.addBird(new Duck("Esko")); 
    a.addBird(new Owl("Orly"));
    a.addBird(new Duck("Alfred"));

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    for(size_t i=0; i<a.size(); i++)
        std::cout << a[i]->getName() << std::endl;

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
    c << "Orly";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Alfred";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
}

TEST(test_bird, test_speak_all) {
    Aviary a;
    a.addBird(new Duck("Esko")); 
    a.addBird(new Owl("Orly"));
    a.addBird(new Duck("Alfred"));

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    a.speakAll(std::cout);

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "Esko: QUACK";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Orly: WHUU";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Alfred: QUACK";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
}

TEST(test_bird, test_fly) {
    Aviary a;
    a.addBird(new Duck("Esko")); 
    a.addBird(new Owl("Orly"));
    a.addBird(new Duck("Alfred"));

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    for(size_t i=0; i<a.size(); i++)
        a[i]->fly(std::cout);

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "Esko flies!";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Orly flies!";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Alfred flies!";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
}

void constTest(Aviary const & a) {
    for(size_t i=0; i<a.size(); i++)
        a[i]->speak(std::cout);
}

TEST(test_bird, test_const) {
    Aviary a;
    a.addBird(new Duck("Esko")); 
    a.addBird(new Owl("Orly"));
    a.addBird(new Duck("Alfred"));

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    constTest(a);
 
    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "Esko: QUACK";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Orly: WHUU";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Alfred: QUACK";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
}
