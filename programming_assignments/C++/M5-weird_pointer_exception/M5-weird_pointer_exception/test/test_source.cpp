#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "../src/restrictedPtrEx.hpp"
#include "../src/restrictedInterface.hpp"

template<typename T>
WeirdMemoryAllocator::restrictedPtr<T> makeRestricted(T* ptr);


std::string random_string(std::string::size_type length)
{
    static auto& chrs = "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    thread_local static std::default_random_engine rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

    std::string s;

    s.reserve(length);

    while(length--)
        s += chrs[pick(rg)];

    return s;
}


TEST(test_restrictedex, test_restrictedex_nullinit)
{
    bool catched = false;
    try
    {
        WeirdMemoryAllocator::restrictedPtr<int> testInt(nullptr, "null");
        testInt.getData();
    }
    catch(WeirdMemoryAllocator::restrictedPtrEx& ex)
    {
        catched = true;
    }
    if(!catched)
    {
        FAIL() << "getData() should throw an exception when the raw pointer is NULL.";    
    }
}


TEST(test_restrictedex, test_restrictedex_copy)
{   
    bool falseCatch = false;
    WeirdMemoryAllocator::restrictedPtr<int> testInt(new int, "Just testing storage of integer.");
    try
    {
        WeirdMemoryAllocator::restrictedPtr<int> i2(testInt);

        WeirdMemoryAllocator::restrictedPtr<int> i3;

        i3 = i2;
    }
    catch(WeirdMemoryAllocator::restrictedPtrEx& ex)
    {
        falseCatch = true;
    }

    if(falseCatch)
    {
        FAIL() << "Your class threw an exception where it should have not";
    }

    bool catcher = false;

    try
    {
        WeirdMemoryAllocator::restrictedPtr<int> i2(testInt);

        WeirdMemoryAllocator::restrictedPtr<int> i3;

        i3 = i2;
        WeirdMemoryAllocator::restrictedPtr<int> i4;
        i4 = testInt;
    }
    catch(WeirdMemoryAllocator::restrictedPtrEx& ex)
    {
        catcher = true;
    }

    if(!catcher)
    {
        FAIL() << "Your class didn't throw an exception at 4th copy!";
    }
}

TEST(test_restrictedex, test_restrictedex_correctness)
{
    bool catcher = false;

    std::string expect = random_string(6);

    std::string expectOut = expect + ": Too many copies of restrictedPtr!";

    WeirdMemoryAllocator::restrictedPtr<int> testInt(new int, expect);

    WeirdMemoryAllocator::restrictedPtr<int> i2(testInt);

    WeirdMemoryAllocator::restrictedPtr<int> i3;

    i3 = i2;

    try
    {
        WeirdMemoryAllocator::restrictedPtr<int> i4(i3);
    }
    catch(WeirdMemoryAllocator::restrictedPtrEx& ex)
    {
        catcher = true;
        std::string ret = ex.getError();
        if(ret != expectOut)
        {
            FAIL() << "getError return was not as expected.\n You returned " << ret << "\nexpected: " << expectOut;
        }
    }

    if(!catcher)
    {
        FAIL() << "Your implementation did not throw!";
    }

}

TEST(test_restrictedex, test_make_restricted)
{
    int* tester = new int;

    *tester = 6;

    WeirdMemoryAllocator::restrictedPtr<int> testiPtr = makeRestricted(tester);

    if(testiPtr.getData() != 6)
    {
        FAIL() << "after makeRestricted the stored data is wrong. Expected 6, was " << testiPtr.getData();
    }

    std::string* another = new std::string;

    *another = "test string" + random_string(3);

    std::string expectString = *another;

    WeirdMemoryAllocator::restrictedPtr<std::string> testi2Ptr = makeRestricted(another);

    if(testi2Ptr.getData() != expectString)
    {
        FAIL() << "after makeRestricted the stored data is wrong. Expected " << expectString << ", was " << testi2Ptr.getData();
    }
}

TEST(test_restrictedex, test_copy_restricted)
{
    int* tester = new int;

    *tester = 6;

    WeirdMemoryAllocator::restrictedPtr<int> testiPtr = makeRestricted(tester);

    WeirdMemoryAllocator::restrictedPtr<int> testiPtr2 = copyRestricted(testiPtr);

    if(!(testiPtr.getPointer() == testiPtr2.getPointer() && testiPtr.getPointer() == tester))
    {
        FAIL() << "After copyRestricted the raw pointers do not match!";
    }

    // test that the 4th copy fails
    WeirdMemoryAllocator::restrictedPtr<int> testiPtr3 = copyRestricted(testiPtr);

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    WeirdMemoryAllocator::restrictedPtr<int> testiPtr4 = copyRestricted(testiPtr);

    std::cout.rdbuf(coutbuf); //reset to standard output again

    out.close();

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::string correct = "restrictedptr instance: Too many copies of restrictedPtr!";

    EXPECT_EQ(correct, checkstr);

}

TEST(test_restrictedex, test_print_restricted)
{
    int* tester = new int;

    *tester = 6;

    WeirdMemoryAllocator::restrictedPtr<int> testiPtr = makeRestricted(tester);

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    printRestricted(testiPtr);

    WeirdMemoryAllocator::restrictedPtr<int> nullPtr;

    printRestricted(nullPtr);

    std::cout.rdbuf(coutbuf); //reset to standard output again

    out.close();

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::string correct = "6";

    EXPECT_EQ(correct, checkstr);

    correct = "nullptr: nullptr exception!";

    std::getline(test, checkstr);

    EXPECT_EQ(correct, checkstr);



}