#include "restrictedPtrEx.hpp"
#include "restrictedInterface.hpp"
#include <iostream>


int main(void)
{
	int* tester = new int;

	*tester = 6;

	WeirdMemoryAllocator::restrictedPtr<int> testiPtr = makeRestricted(tester);

	WeirdMemoryAllocator::restrictedPtr<int> testi2Ptr = copyRestricted(testiPtr);

	std::cout << testi2Ptr.getData() << std::endl;

	WeirdMemoryAllocator::restrictedPtr<int> testi3Ptr = copyRestricted(testiPtr);

	std::cout << "next should fail and print out:\nrestrictedptr instance: Too many copies of restrictedPtr!" << std::endl;

	WeirdMemoryAllocator::restrictedPtr<int> testi4Ptr = copyRestricted(testiPtr);

	// calling getData with this nullPtr instance should throw a
	// restrictedNullException
	WeirdMemoryAllocator::restrictedPtr<int> nullPtr(nullptr, "nullptr instance");

	std::cout << "This should print out :\nnullptr instance: nullptr exception!" << std::endl;

	printRestricted(nullPtr);

	return 0;
}