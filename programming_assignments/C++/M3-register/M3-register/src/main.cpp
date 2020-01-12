#include <iostream>
#include "register.hpp"

int main(void)
{
	Register r;
	r.readToRegister("readtester1.txt");
	r.printRegister();
	r.addVehicle(new Aircraft("G_BOAC", "British Airways", "Concorde SST", 80.8, 2000));
	r.addVehicle(new Car("YUU-123", "Teemu Teekkari", "Volkswagen Polo", 800, true));
	r.addVehicle(new Aircraft("RU-123", "Russian Federation", "MiG-21", 80.8, 1600));
	r.addVehicle(new Car("EES-321", "Nikola", "Tesla", 600, false));
	r.addVehicle(new Boat("FI123", "Pekka Purjehtija", "Mariella", 1.8, 0));
	r.outputAll("test2.txt");
	r.printRegister();
}
