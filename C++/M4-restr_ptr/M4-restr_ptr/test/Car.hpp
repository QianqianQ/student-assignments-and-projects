#include <string>

/*
 * This is just a test dummy class to test 
 * that the restrictedPtr also works with classes.
 */
class Car
{
public:
	Car(unsigned int w_score, const std::string& w_name) : 
		score(w_score),
		name(w_name)
		{}
	std::string getName()
	{
		return name;
	}

	unsigned int score;
private:
	std::string name;
};
