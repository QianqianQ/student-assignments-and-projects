#include "register.hpp"
#include <fstream>
#include <iostream>

/*
 * VEHICLE CLASS FUNCTIONS
 */
Vehicle::Vehicle(std::string w_regNum, std::string w_owner)
	:
	m_regNum(w_regNum),
	m_owner(w_owner)
{
}

Vehicle::~Vehicle() {}

std::string Vehicle::getRegNum() const
{
	return m_regNum;
}

std::string Vehicle::getOwner() const
{
	return m_owner;
}

/*
 * REGISTER CLASS FUNCTIONS
 */
Register::Register() {}

Register::~Register()
{
	for(auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
	{
		delete *i;
	}
}

void Register::addVehicle(Vehicle* v)
{
	m_vehicles.push_back(v);
}

void Register::outputAll(const std::string& w_filename) const
{
	// write here a function that serializes the Vehicle instances in the correct format
	// to output file (filename given as parameter)
	// instances are separated by newline

	// FORMAT :
	// case Aircraft:
	// A;regnum;owner;model;wingspan;cruisespeed
	//
	// case Boat:
	// B;regnum;owner;name;draft;power
	//
	// case Car:
	// C;regnum;owner;maker;range;inspection
	std::ofstream file;
	file.open(w_filename);
    for(auto i=m_vehicles.begin();i!=m_vehicles.end();i++)
    {
            (*i)->regWriter(file);
    }
}

void Register::printRegister()
{
	for(auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
	{
		(*i)->printVehicle();
	}
}

bool Register::readOneLine(std::istream& w_inStream)
{
	// TODO:
	// take the istream from the readToRegister function, and check the
	// current type of vehicle. Call the readRest function with the current istream as parameter, once again
	// (we are learning the iostreams here) of the corresponding
	// vehicle type and add the returned new instance to register.
    if(w_inStream.rdstate()&(w_inStream.failbit | w_inStream.badbit))
    {
        std::cerr<<"Failed!"<<std::endl;
        return false;
    }
    char c;
    w_inStream.get(c);
    if (c=='A')
    {
        w_inStream.get(c);
        Aircraft* a=Aircraft::readRest(w_inStream);
        addVehicle(a);
        return true;
    }
    if (c=='B')
    {
        w_inStream.get(c);
        Boat* b = Boat::readRest(w_inStream);
        addVehicle(b);
        return true;
    }
    if (c=='C')
    {
        w_inStream.get(c);
        Car* c=Car::readRest(w_inStream);
        addVehicle(c);
        return true;
    }
    return false;
}

int Register::readToRegister(const std::string& w_filename)
{
	// TODO:
	// open the file (filename given as param) and read file line by line.
	// give the istream to readOneLine from each line.
	// return: the number of vehicles added. If there was an error reading the file,
	// -1 should be returned.
	unsigned int count = 0;
    std::ifstream f(w_filename);
    if(!f.is_open())
        return -1;
    if(f.peek()==std::ifstream::traits_type::eof())
        return 0;
    if(f.rdstate()&(f.failbit | f.badbit))
    {
        std::cerr<<"Failed!"<<std::endl;
        return -1;
    }
    while(!f.eof())
    {
        std::string line;
        std::getline(f,line);
        std::istringstream os(line);
        readOneLine(os);
        count++;
    }
    std::cout<<count<<std::endl;
    return count;
}

size_t Register::size() const
{
	return m_vehicles.size();
}

/*
 * Implement here classes Aircraft, Car and Boat
 * All of these classes should inherit from Vehicle.
 */

