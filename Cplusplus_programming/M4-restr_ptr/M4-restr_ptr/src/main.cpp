#include "restrictedPtr.hpp"
#include "Car.hpp"
#include <iostream>

int main(void)
{
	restrictedPtr<Car> newCar(new Car(0, "Ferrari"));

	// should print "Ferrari"
	std::cout << newCar.getPointer()->getName() << std::endl;

	// should also print "Ferrari"
	std::cout << newCar.getData().getName() << std::endl;

	newCar.getData().score = 50;

	// should printf "50", as it was just assigned before
	std::cout << newCar.getPointer()->score << std::endl;

	// make some copies
	restrictedPtr<Car> copyOfnewCar = newCar;
	restrictedPtr<Car> copyOfnewCar2 = newCar;

	// this copy should fail
	restrictedPtr<Car> copyOfnewCar3 = newCar;

	// should be nullptr
	std::cout << copyOfnewCar3.getPointer() << std::endl;

	// should be something other than 0 and equal
	std::cout << "copy2 pointer: " << copyOfnewCar2.getPointer() << " copy1 pointer: " << copyOfnewCar.getPointer() << std::endl;
	copyOfnewCar2.getData().score = 40;

	// should be 40 now
	std::cout << newCar.getPointer()->score << std::endl;
	restrictedPtr<Car> copyOfnewCar4(newCar);

	// should be nullptr
	std::cout << copyOfnewCar4.getPointer() << std::endl;
}
