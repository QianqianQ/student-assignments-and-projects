#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "../src/dog_class.hpp"

TEST(test_dog_class, test_1) {
    //create random numbers
    srand(static_cast<unsigned> (time(0)));
    int a = (rand()) / (RAND_MAX / 100);
    int b = (rand()) / (RAND_MAX / 100);

    Dog dog(a, "Mr. Wuf");
    EXPECT_EQ(a, dog.getAge());
    EXPECT_EQ("Mr. Wuf", dog.getName());
    dog.setAge(b);
    EXPECT_EQ(b, dog.getAge());
    dog.setName("Doge");
    EXPECT_EQ("Doge", dog.getName());
}
