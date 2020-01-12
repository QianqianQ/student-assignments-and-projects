#include <cstddef>
#include <iostream>
#include "bank_account.hpp"

int main(void) {
    auto b = BankAccount("Rasse Rikas", "21345");
    std::cout << "Owner: " <<  b.getOwner() << std::endl;
    std::cout << "Number: " << b.getNumber() << std::endl;
    std::cout << "Balance: " << b.getBalance() << std::endl;
    
    std::cout << "Depositing 100 to account." << std::endl;
    b.deposit(100.0);
    std::cout << "Balance: " << b.getBalance() << std::endl;

    std::cout << "Withdrawing 50 from account." << std::endl;
    b.withdraw(50.0);
    std::cout << "Balance: " << b.getBalance() << std::endl;

    std::cout << "Trying to withdraw 100." << std::endl;
    b.withdraw(100.0); //should do nothing!
    std::cout << "Balance: " << b.getBalance() << std::endl;

    auto b2 = BankAccount("Kaisa Kroisos", "43662", 1000.0);
    b2.print();

    std::cout << "Transfering 100.0 from " << b2.getOwner() << " to " << b.getOwner() << "." << std::endl;
    bool t = transfer(b2, b, 100.0);
    std::cout << "Transfer " << (t ? "succesful!" : "failed!") << std::endl;

    std::cout << "Transfering 500.0 from " << b.getOwner() << " to " << b2.getOwner() << "." << std::endl;
    t = transfer(b, b2, 500.0); //should fail!
    std::cout << "Transfer " << (t ? "succesful!" : "failed!") << std::endl;

    return 0;
}
