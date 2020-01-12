#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include "../src/bank_account.hpp"

TEST(test_bank_account, test_constructor) {
    BankAccount("Roope Rikas", "12345", 100.0);
    BankAccount("Kaisa Köyhä", "53457");
}

TEST(test_bank_account, test_getOwner) {
    auto a = BankAccount("Roope Rikas", "12345", 100.0);
    auto b = BankAccount("Kaisa Köyhä", "53457");
    
    EXPECT_EQ("Roope Rikas", a.getOwner());
    EXPECT_EQ("Kaisa Köyhä", b.getOwner());
}

TEST(test_bank_account, test_getNumber) {
    srand(time(0));
    std::string number1 = std::to_string(static_cast<long int> (rand() / (RAND_MAX)));
    std::string number2 = std::to_string(static_cast<long int> (rand() / (RAND_MAX)));
    auto a = BankAccount("Roope Rikas", number1, 100.0);
    auto b = BankAccount("Kaisa Köyhä", number2);
    
    EXPECT_EQ(number1, a.getNumber());
    EXPECT_EQ(number2, b.getNumber());
}

TEST(test_bank_account, test_getBalance) {
    srand(time(0));
    auto amount1 = rand() / (RAND_MAX / 100.0);
    auto amount2 = rand() / (RAND_MAX / 100.0);
    auto a = BankAccount("Roope Rikas", "12345", amount1);
    auto b = BankAccount("Kaisa Köyhä", "53457", amount2);
    
    EXPECT_EQ(amount1, a.getBalance());
    EXPECT_EQ(amount2, b.getBalance());
}

TEST(test_bank_account, test_deposit) {
    srand(time(0));
    auto amount1 = rand() / (RAND_MAX / 100.0);
    auto amount2 = rand() / (RAND_MAX / 100.0);
    auto a = BankAccount("Roope Rikas", "12345", amount1);
    auto b = BankAccount("Kaisa Köyhä", "53457", amount2);

    auto deposit1 = rand() / (RAND_MAX / 100.0);
    auto deposit2 = rand() / (RAND_MAX / 100.0);

    a.deposit(deposit1);
    b.deposit(deposit2);

    EXPECT_EQ(amount1+deposit1, a.getBalance());
    EXPECT_EQ(amount2+deposit2, b.getBalance());
}

TEST(test_bank_account, test_withdraw) {
    srand(time(0));
    auto amount1 = rand() / (RAND_MAX / 100.0);
    auto amount2 = rand() / (RAND_MAX / 100.0);
    auto a = BankAccount("Roope Rikas", "12345", amount1);
    auto b = BankAccount("Kaisa Köyhä", "53457", amount2);

    auto withdraw1 = rand() / (RAND_MAX / 100.0);
    while(withdraw1 >= amount1)
        withdraw1 = rand() / (RAND_MAX / 100.0);
 
    auto withdraw2 = rand() / (RAND_MAX / 100.0);
    while(withdraw2 >= amount2)
        withdraw2 = rand() / (RAND_MAX / 100.0);
    

    a.withdraw(withdraw1);
    b.withdraw(withdraw2);

    EXPECT_EQ(amount1-withdraw1, a.getBalance());
    EXPECT_EQ(amount2-withdraw2, b.getBalance());

    a.withdraw(a.getBalance()+100.0);
    EXPECT_EQ(amount1-withdraw1, a.getBalance());
}

TEST(test_bank_account2, test_transfer) {
    srand(time(0));
    auto amount1 = rand() / (RAND_MAX / 100.0);
    auto amount2 = rand() / (RAND_MAX / 100.0);
    auto a = BankAccount("Roope Rikas", "12345", amount1);
    auto b = BankAccount("Kaisa Köyhä", "53457", amount2);

    auto withdraw = rand() / (RAND_MAX / 100.0);
    while(withdraw >= amount1)
        withdraw = rand() / (RAND_MAX / 100.0);

    transfer(a, b, withdraw);

    EXPECT_EQ(amount1-withdraw, a.getBalance());
    EXPECT_EQ(amount2+withdraw, b.getBalance());

    transfer(a, b, a.getBalance()+100.0);
    EXPECT_EQ(amount1-withdraw, a.getBalance());
    EXPECT_EQ(amount2+withdraw, b.getBalance());
}

TEST(test_bank_account2, test_print) {
    //create two random numbers
    srand(time(0));
    auto amount1 = rand() / (RAND_MAX / 100.0);
    auto amount2 = rand() / (RAND_MAX / 100.0);
    auto a = BankAccount("Roope Rikas", "12345", amount1);
    auto b = BankAccount("Kaisa Köyhä", "53457", amount2);

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    a.print();
    b.print();

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::cout << "Testing output" << std::endl;
    std::ostringstream c;
    c << "Account num: 12345, owned by: Roope Rikas, balance: " << amount1 << " eur.";
    std::string correct = c.str();

    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "Account num: 53457, owned by: Kaisa Köyhä, balance: " << amount2 << " eur.";
    correct = c.str();
    std::cout << checkstr << std::endl;
    EXPECT_EQ(correct, checkstr);
} 
