#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "triple.hpp"

int main()
{
    // Seed the random
    srand(time(0));

    std::vector<std::string> strings = {"Templates", "are", "fun", "reb00t", "coffee"};
    // Test constructor, copy, assignment, and accessors
 {
    // Test the constructor
    std::cout << "*** Creating different kind of triples.." << std::endl;
    Triple<int, int, int> t1(rand()%5, rand()%5, rand()%5);
    const Triple<int, int, int>& rt1 = t1;

    Triple<int, int, int> t2(rand()%5, rand()%5, rand()%5);
    const Triple<int, int, int>& rt2 = t2;

    Triple<int, double, char> t3(rand()%5, ((double)((rand()%100)+10))/17.2, (char)((rand()%91)+33));
    const Triple<int, double, char>& rt3 = t3;

    // Test the accessors
    std::cout << "*** Testing the accessors (first, second, and third).." << std::endl;
    std::cout << "F: " << rt1.first() << " S: " << rt1.second() << " T: " << rt1.third() << std::endl;
    std::cout << "F: " << rt2.first() << " S: " << rt2.second() << " T: " << rt2.third() << std::endl;
    std::cout << "F: " << rt3.first() << " S: " << rt3.second() << " T: " << rt3.third() << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;

    // Test the copy constructor
    std::cout << "*** Testing the copy constructor.." << std::endl;
    Triple<int, int, int> ct1(rt1);
    Triple<int, int, int> ct2(rt2);
    Triple<int, double, char> ct3(rt3);

    std::cout << "F: " << ct1.first() << " S: " << ct1.second() << " T: " << ct1.third() << std::endl;
    std::cout << "F: " << ct2.first() << " S: " << ct2.second() << " T: " << ct2.third() << std::endl;
    std::cout << "F: " << ct3.first() << " S: " << ct3.second() << " T: " << ct3.third() << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;

    // Test the assignment operator
    std::cout << "*** Testing the assignment, = -operator.." << std::endl;
    Triple<int, int, int> at1 = rt1;
    t2 = t2; // Self assignment
    Triple<int, double, char> at3 = rt3;

    std::cout << "F: " << at1.first() << " S: " << at1.second() << " T: " << at1.third() << std::endl;
    std::cout << "F: " << t2.first() << " S: " << t2.second() << " T: " << t2.third() << std::endl;
    std::cout << "F: " << at3.first() << " S: " << at3.second() << " T: " << at3.third() << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;
}
    // Test the makeTriple, and isHomogenous functions
 {
    // Test the makeTriple function
    std::cout << "*** Testing your makeTriple function.." << std::endl;
    Triple<int, int, int> t1 = makeTriple(rand()%5, rand()%5, rand()%5);
    const Triple<int, int, int>& rt1 = t1;

    Triple<int, int, int> t2 = makeTriple(rand()%5, rand()%5, rand()%5);
    const Triple<int, int, int>& rt2 = t2;

    Triple<int, double, char> t3 = makeTriple(rand()%5, ((double)((rand()%100)+10))/17.2, (char)((rand()%91)+33));
    const Triple<int, double, char>& rt3 = t3;

    std::cout << "*** Printing the results.." << std::endl;
    std::cout << "F: " << rt1.first() << " S: " << rt1.second() << " T: " << rt1.third() << std::endl;
    std::cout << "F: " << rt2.first() << " S: " << rt2.second() << " T: " << rt2.third() << std::endl;
    std::cout << "F: " << rt3.first() << " S: " << rt3.second() << " T: " << rt3.third() << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;

    // Test the isHomogenous function
    std::cout << "*** Testing your isHomogenous function.." << std::endl;
    std::cout << "The isHomogenous function returned: " << (isHomogenous(rt1) ? "yes" : "no") << std::endl;
    std::cout << "The isHomogenous function returned: " << (isHomogenous(rt2) ? "yes" : "no") << std::endl;
    std::cout << "The isHomogenous function returned: " << (isHomogenous(rt3) ? "yes" : "no") << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;
}

 {
    // Test the ==, !=, and << -operators
    std::cout << "*** Creating different kind of triples.." << std::endl;
    Triple<int, int, int> t1(rand()%5, rand()%5, rand()%5);
    const Triple<int, int, int>& rt1 = t1;

    Triple<int, int, int> t2(rand()%5, rand()%5, rand()%5);
    const Triple<int, int, int>& rt2 = t2;

    Triple<int, double, char> t3(rand()%5, ((double)((rand()%100)+10))/17.2, (char)((rand()%91)+33));
    const Triple<int, double, char>& rt3 = t3;
    Triple<int, double, char> t4(rand()%5, ((double)((rand()%100)+10))/17.2, (char)((rand()%91)+33));
    const Triple<int, double, char>& rt4 = t4;

    // Test the << -operator
    std::cout << "*** Printing the triples, using the << -operator.." << std::endl;
    std::cout << rt1 << std::endl;
    std::cout << rt2 << std::endl;
    std::cout << rt3 << std::endl;
    std::cout << rt4 << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;

    // Test the == -operator
    std::cout << "*** Testing the == -operator, comparing triples.." << std::endl;
    std::cout << "Are the triples equal: " << (rt1==rt2 ? "yes" : "no") << std::endl;
    std::cout << "Are the triples equal: " << (rt3==rt4 ? "yes" : "no") << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;

    // Test the != -operator
    std::cout << "*** Testing the != -operator, comparing triples.." << std::endl;
    std::cout << "Are the triples inequal: " << (rt1!=rt2 ? "yes" : "no") << std::endl;
    std::cout << "Are the triples inequal: " << (rt3!=rt4 ? "yes" : "no") << std::endl;
    std::cout << "*** END OF READ ***" << std::endl;
}

    std::cout << "*** All done, exiting.." << std::endl;

    return 0;
}
