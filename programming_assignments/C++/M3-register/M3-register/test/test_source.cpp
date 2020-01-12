#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "../src/register.hpp"

TEST(test_register, test_read_correctness)
{
    Register r;
    int ret;

    if((ret = r.readToRegister("nonexistent")) != -1)
    {
        FAIL() << "When opening a file that does not exist, readToRegister should return -1. You returned " << ret;
    }

    if((ret = r.readToRegister("empty.txt")) != 0)
    {
        FAIL() << "When opening a empty file, readToRegister should return 0. You returned " << ret;
    }
    
    if((ret = r.readToRegister("readtester1.txt")) != 5)
    {
        FAIL() << "Reading a file should return the amount of read Vehicles. You returned " << ret << ", should have been 5.";
    }
}


TEST(test_register, test_read_register1)
{

    /*
     * FIRST TEST WITH TEXTFILE INCLUDING 5 VEHICLES
     */
    Register r;

    r.readToRegister("readtester1.txt");

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    EXPECT_EQ(r.size(), 5);

    r.printRegister();

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "A;G_BOAC;British Airways;Concorde SST;80.8;2000";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "C;YUU-123;Teemu Teekkari;Volkswagen Polo;800;1";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "A;RU-123;Russian Federation;MiG-21;80.8;1600";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "C;EES-321;Nikola;Tesla;600;0";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "B;FI123;Pekka Purjehtija;Mariella;1.8;0";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
}


TEST(test_register, test_output_register1)
{

    /*
     * TEST OUTPUT WITH A REGISTER OF 5 VEHICLES
     */
    Register r;

    r.addVehicle(new Aircraft("G_BOAC", "British Airways", "Concorde SST", 80.8, 2000));
    r.addVehicle(new Car("YUU-123", "Teemu Teekkari", "Volkswagen Polo", 800, true));
    r.addVehicle(new Aircraft("RU-123", "Russian Federation", "MiG-21", 80.8, 1600));
    r.addVehicle(new Car("EES-321", "Nikola", "Tesla", 600, false));
    r.addVehicle(new Boat("FI123", "Pekka Purjehtija", "Mariella", 1.8, 0));

    r.outputAll("outfile1.txt");

    std::string checkstr;
    std::ifstream test("outfile1.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "A;G_BOAC;British Airways;Concorde SST;80.8;2000";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "C;YUU-123;Teemu Teekkari;Volkswagen Polo;800;1";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "A;RU-123;Russian Federation;MiG-21;80.8;1600";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "C;EES-321;Nikola;Tesla;600;0";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "B;FI123;Pekka Purjehtija;Mariella;1.8;0";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
}
