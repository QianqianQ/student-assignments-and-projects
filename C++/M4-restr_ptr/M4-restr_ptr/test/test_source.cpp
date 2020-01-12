#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "../src/restrictedPtr.hpp"
#include "Car.hpp"

TEST(test_restricted, test_restricted_assign_value)
{
    restrictedPtr<int> testInt(new int);
    if(testInt.getPointer() == nullptr)
    {
        FAIL() << "After initialization of a restricted pointer, your raw pointer was NULL.";
    }
    testInt.getData() = 5;
    if(testInt.getData() != 5)
    {
        FAIL() << "After setting a value with getData, expected output with getData is 5, you gave " << testInt.getData();
    }

    testInt.getData() = 13;
    if(testInt.getData() != 13)
    {
        FAIL() << "After setting a value with getData, expected output with getData is 13, you gave " << testInt.getData();
    }

    restrictedPtr<Car> testCar(new Car(2, "Tesla"));
    testCar.getData().score = 1;
    if(testCar.getData().score != 1)
    {
        FAIL() << "After setting a value with getData, expected value to be 1, you had " << testCar.getData().score;
    }

}

TEST(test_restricted, test_restricted_copy)
{
    restrictedPtr<int> testInt(new int);
    testInt.getData() = 6;
    restrictedPtr<int> intCopy1(testInt);
    if(testInt.getPointer() != intCopy1.getPointer() && testInt.getPointer() != nullptr)
    {
        FAIL() << "After assigning a value, the raw pointers should match. Your first restricted had: " << testInt.getPointer() << " and the copy constructed had " << intCopy1.getPointer();
    }
    if(testInt.getData() != intCopy1.getData() && testInt.getData() != 6)
    {
        FAIL() << "getData() should return 6. Your first restricted ptr returned " << testInt.getData() << " and copy constructed returned " << intCopy1.getData();
    }
    restrictedPtr<int> intCopy2;
    intCopy2 = intCopy1;

    if(testInt.getPointer() != intCopy2.getPointer() && testInt.getPointer() != nullptr)
    {
        FAIL() << "After assigning a value, the raw pointers should match. Your first restricted had: " << testInt.getPointer() << " and the copy assigned had " << intCopy2.getPointer();
    }
    if(intCopy1.getData() != intCopy2.getData() && intCopy1.getData() != 6)
    {
        FAIL() << "getData() should return 6. Your first restricted ptr returned " << testInt.getData() << " and copy assigned returned " << intCopy2.getData();
    }

    restrictedPtr<Car> testCar(new Car(2, "Tesla"));
    testCar.getData().score = 1;
    if(testCar.getData().score != 1)
    {
        FAIL() << "After setting a value with getData, expected value to be 1, you had " << testCar.getData().score;
    }
}

TEST(test_restricted, test_restricted_restrictness)
{
    restrictedPtr<int> testInt(new int);
    testInt.getData() = 1;
    restrictedPtr<int> intCopy1(testInt);
    restrictedPtr<int> intCopy2 = intCopy1;

    // this should fail
    restrictedPtr<int> intCopy3 = intCopy2;
    if(intCopy3.getPointer() != nullptr)
    {
        FAIL() << "After reference count exceeds 3, the new restricted ptr's raw pointer should be NULL, you had " << intCopy3.getPointer();
    }

    // this should be ok though
    restrictedPtr<int> testInt2(new int);
    if(testInt2.getPointer() == nullptr)
    {
        FAIL() << "Creating a new first reference to a new pointer should never fail. However your restricted pointer had a null raw pointer.";
    }
}