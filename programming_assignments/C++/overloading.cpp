#include <string>
#include <vector>
#include <iostream>

class Creature {
public:
	Creature(const std::string& n, const std::string& t, int h) :
	name(n), type(t), hitpoints(h) { }

	const std::string& getName() const { return name; }
	const std::string& getType() const { return type; }
	int getHP() const { return hitpoints; }

private:
	std::string name;
	const std::string type;
	int hitpoints;
};

class Troll : public Creature {
public:
    Troll(const std::string& n, int hp) : Creature(n, "Troll", hp) { }
    friend std::ostream &operator<<(std::ostream &out, const Troll& b){
    	out<<"Troll "<<b.getName()<<" with "<<b.getHP()<<" HP";
    	return out;
    }
};


class Dragon : public Creature {
public:
    Dragon(const std::string& n, int hp) : Creature(n, "Dragon", hp) { }
    friend std::ostream &operator<<(std::ostream &out, const Dragon& b){
    	out<<"Dragon "<<b.getName()<<" with "<<b.getHP()<<" HP";
    	return out;
    }
};

int main()
{
    Troll tr("Diiba", 10), tr2("Urkki", 15);
    Dragon dr("Rhaegal", 50), dr2("Viserion", 55);

    std::cout << "Trolls are: " << tr << " and " << tr2 << std::endl;
    std::cout << "Dragons are: " << dr << " and " << dr2 << std::endl;
}