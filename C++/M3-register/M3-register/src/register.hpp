#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <cstdlib>
class Vehicle {
public:
	explicit Vehicle(std::string w_regNum, std::string w_owner);
	virtual ~Vehicle();

	// simple getter, returns this instance's register number
	std::string getRegNum() const;

	// simple getter, returns this instance's owner
	std::string getOwner() const;

	// pure virtual functions, you should implement these in the child classes!
	virtual void regWriter(std::ofstream& w_outStream) = 0;

	// this function should print out the instance to the standard output (cout)
	// The format should be exactly the same as in the file read/write serialization.
	virtual void printVehicle() = 0;
private:
	std::string m_regNum;
	std::string m_owner;
}; // end class Vehicle


// this class is just a simple container for an array (vector) of Vehicle instances
class Register {
public:
	Register();
	~Register();

	// adds an vehicle to the register. Takes a pointer to a dynamically allocated instance as param
	void addVehicle(Vehicle* v);

	// serializes the register instances into a file
	void outputAll(const std::string& w_filename) const;

	// this function is called per line in the file that is being read
	bool readOneLine(std::istream& w_inStream);

	// opens a file and handles IO operations, calls readOneLine for every line read from the file
	int readToRegister(const std::string& w_filename);

	// prints the register to standard output
	// CAUTION: you should use the same formatting here as when writing to
	// the text file.
	void printRegister();

	// returns the register size
	size_t size() const;
private:
	// this container only sees that Vehicle instances are stored. Actually these instances are boats, cars...
	std::vector<Vehicle *> m_vehicles;
}; // end class Register


/*
 * Implement here classes Aircraft, Car and Boat
 * All of these classes should inherit from Vehicle.
 */
class Car: public Vehicle{
public:
    Car(std::string w_regNum, std::string w_owner,std::string imaker,unsigned int r,bool i):Vehicle(w_regNum,w_owner){
        maker = imaker;
        range = r;
        inspection = i;
}
    void regWriter(std::ofstream& w_outStream)
    {


            w_outStream<<"C;"<<getRegNum()<<";"<<getOwner()<<";"
           <<maker<<";"<<range<<";"<<std::noboolalpha<<inspection<<std::endl;
    }
    void printVehicle()
    {

            std::cout<<"C;"<<getRegNum()<<";"<<getOwner()<<";"
           <<maker<<";"<<range<<";"<<std::noboolalpha<<inspection<<std::endl;
    }
    static Car* readRest(std::istream& w_inStream)
    {
        std::string str;
        std::getline(w_inStream,str);
        size_t pos=0;
        std::string delim = ";";
        std::string token;
        pos = str.find(delim);
        std::string p1=str.substr(0,pos);
        str.erase(0,pos+delim.length());
        pos = str.find(delim);
        std::string p2=str.substr(0,pos);
        str.erase(0,pos+delim.length());
        pos = str.find(delim);
        std::string p3=str.substr(0,pos);
        str.erase(0,pos+delim.length());
        pos = str.find(delim);
        std::string p4=str.substr(0,pos);
        str.erase(0,pos+delim.length());
        std::string p5 = str;
        unsigned int r;
        std::istringstream(p4)>>r;
        bool i ;
        if(p5=="1")
           i = 1;
        else
            i = 0;
        Car *read_car = new Car(p1,p2,p3,r,i);
        return read_car;
    }
private:
    std::string maker;
    unsigned int range;
    bool inspection;
};

class Boat: public Vehicle{
public:
    Boat(std::string w_regNum, std::string w_owner,std::string n,double d,double p):Vehicle(w_regNum,w_owner){
        name = n;
        draft = d;
        power = p;
}
    void regWriter(std::ofstream& w_outStream)
    {
        w_outStream<<"B;"<<getRegNum()<<";"<<getOwner()<<";"
        <<name<<";"<<draft<<";"<<power<<std::endl;
    }
    void printVehicle()
    {
        std::cout<<"B;"<<getRegNum()<<";"<<getOwner()<<";"
        <<name<<";"<<draft<<";"<<power<<std::endl;
    }
    static Boat* readRest(std::istream& w_inStream)
    {
        std::string str;
        std::getline(w_inStream,str);
        size_t pos=0;
        std::string delim = ";";
        std::string token;
        pos = str.find(delim);
        std::string p1=str.substr(0,pos);
        str.erase(0,pos+delim.length());
        pos = str.find(delim);
        std::string p2=str.substr(0,pos);
        str.erase(0,pos+delim.length());
        pos = str.find(delim);
        std::string p3=str.substr(0,pos);
        str.erase(0,pos+delim.length());
        pos = str.find(delim);
        std::string p4=str.substr(0,pos);
        str.erase(0,pos+delim.length());
        std::string p5 = str;
        double d;
        std::istringstream(p4)>>d;
        double p;
        std::istringstream(p5)>>p;
        Boat *read_Boat = new Boat(p1,p2,p3,d,p);
        return read_Boat;
    }
private:
    std::string name;
    double draft;
    double power;
};

class Aircraft: public Vehicle{
public:
    Aircraft(std::string w_regNum, std::string w_owner,std::string m,double s,unsigned int p):Vehicle(w_regNum,w_owner){
        model = m;
        span = s;
        speed = p;
}
    void regWriter(std::ofstream& w_outStream)
    {
        w_outStream<<"A;"<<getRegNum()<<";"<<getOwner()<<";"
        <<model<<";"<<span<<";"<<speed<<std::endl;
    }
    void printVehicle()
    {
        std::cout<<"A;"<<getRegNum()<<";"<<getOwner()<<";"
        <<model<<";"<<span<<";"<<speed<<std::endl;
    }
    static Aircraft* readRest(std::istream& w_inStream)
    {
        std::string str;
        std::getline(w_inStream,str);
        size_t pos=0;
        std::string delim = ";";
        std::string token;
        pos = str.find(delim);
        std::string p1=str.substr(0,pos);
        str.erase(0,pos+delim.length());
        pos = str.find(delim);
        std::string p2=str.substr(0,pos);
        str.erase(0,pos+delim.length());
        pos = str.find(delim);
        std::string p3=str.substr(0,pos);
        str.erase(0,pos+delim.length());
        pos = str.find(delim);
        std::string p4=str.substr(0,pos);
        str.erase(0,pos+delim.length());
        std::string p5 = str;
        double s;
        std::istringstream(p4)>>s;
        unsigned int p;
        std::istringstream(p5)>>p;
        Aircraft *read_Aircraft = new Aircraft(p1,p2,p3,s,p);
        return read_Aircraft;
    }
private:
    std::string model;
    double span;
    unsigned int speed;
};

