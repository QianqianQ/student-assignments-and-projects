#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdexcept>
#include "../src/printers.hpp"

class ReversePrinter : public StringPrinter
{
public:
    /* Construct a new object - pass the std::ostream& to the base class */
    ReversePrinter(std::ostream &os = std::cout) : StringPrinter(os)
    { }
    /* Copy this object */
    ReversePrinter* clone() const
    {
        return new ReversePrinter(os);
    }
    virtual StringPrinter& operator()(const std::string& str)
    {
        /* os is a protected member of the base class */
	std::copy(str.rbegin(), str.rend(), std::ostream_iterator<char>(os));
	os << std::endl;
        return *this;
    }
private:
};

TEST(test_printers, test_standard) {
    std::ostringstream oss;
    auto p = new StandardPrinter;
    auto p2 = new StandardPrinter(oss);
    
    Printers ps;
    ps.add("normal1", p);
    ps.add("normal2", p2);

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    ps["normal1"]("Testing the two printers");
    ps["normal2"]("Seems to work");

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "Testing the two printers";
    std::string correct = c.str();

    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    c << "Seems to work" << std::endl;
    correct = c.str();
    EXPECT_EQ(correct, oss.str());
}
    
TEST(test_printers, test_diagonal) {
    std::ostringstream oss;
    auto p = new DiagonalPrinter;
    
    Printers ps;
    ps.add("diag1", p);
    
    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    ps["diag1"]("Testing the printer");

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "T                  ";
    std::string correct = c.str();

    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << " e                 ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "  s                ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);     

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "   t               ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
   
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "    i              ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
   
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "     n             ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
   
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "      g            ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
   
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "                   ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
   
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "        t          ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
      
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "         h         ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
  
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "          e        ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "                   ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "            p      ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "             r     ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "              i    ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
 
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "               n   ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
   
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "                t  ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "                 e ";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "                  r";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
}

TEST(test_printers, test_diagonal2) {
    std::ostringstream oss;
    auto p = new DiagonalPrinter("****", "****", oss);
    
    Printers ps;
    ps.add("diag", p);

    ps["diag"]("Streamversion");

    char* checkstr = (char*)calloc(1, 14);
    std::string t = oss.str();
    std::stringstream test(t);

    std::ostringstream c;
    c << "****";
    test.getline(checkstr,14);
    std::string correct = c.str();

    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    c << "S            ";
    test.getline(checkstr,14);
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    c << " t           ";
    test.getline(checkstr,14);
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    c << "  r          ";
    test.getline(checkstr,14);
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    c.str("");
    c.clear();

    c << "   e         ";
    test.getline(checkstr,14);
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    c.str("");
    c.clear();

    c << "    a        ";
    test.getline(checkstr,14);
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    c.str("");
    c.clear();

    c << "     m       ";
    test.getline(checkstr,14);
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    c.str("");
    c.clear();

    c << "      v      ";
    test.getline(checkstr,14);
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    c.str("");
    c.clear();

    c << "       e     ";
    test.getline(checkstr,14);
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    c.str("");
    c.clear();
    
    c << "        r    ";
    test.getline(checkstr,14);
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    c.str("");
    c.clear();

    c << "         s   ";
    test.getline(checkstr,14);
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    c.str("");
    c.clear();

    c << "          i  ";
    test.getline(checkstr,14);
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    c.str("");
    c.clear();

    c << "           o ";
    test.getline(checkstr,14);
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    c << "            n";
    test.getline(checkstr,14);
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    c << "****";
    test.getline(checkstr,5);
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    free(checkstr);
}

TEST(test_printers, test_reverse) {
    std::ostringstream oss;
    auto p = new ReversePrinter;
    auto p2 = new ReversePrinter(oss);
    
    Printers ps;
    ps.add("r1", p);
    ps.add("r2", p2);

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    ps["r1"]("Testing the two printers");
    ps["r2"]("Seems to work");

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "sretnirp owt eht gnitseT";
    std::string correct = c.str();

    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    c << "krow ot smeeS" << std::endl;
    correct = c.str();
    EXPECT_EQ(correct, oss.str());
}

TEST(test_printers2, test_chain) {
    std::ostringstream oss;
    auto p = new StandardPrinter;
    auto p2 = new ReversePrinter;
    
    Printers ps;
    ps.add("n1", p);
    ps.add("r2", p2);

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    ps["n1"]("Testing the two printers")("With some chaining")("Whoo");
    ps["r2"]("Seems to work")("Yes, pretty well");

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "Testing the two printers";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    c << "With some chaining" ;
    correct = c.str();
    std::getline(test, checkstr);
    EXPECT_EQ(correct, checkstr); 
    
    c.str("");
    c.clear();

    c << "Whoo";
    correct = c.str();
    std::getline(test, checkstr);
    EXPECT_EQ(correct, checkstr);   
    
    c.str("");
    c.clear();

    c << "krow ot smeeS";
    correct = c.str();
    std::getline(test, checkstr);
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    c << "llew ytterp ,seY" ;
    correct = c.str();
    std::getline(test, checkstr);
    EXPECT_EQ(correct, checkstr);

}

TEST(test_printers3, test_copyassign) {
    std::ostringstream oss;
    auto p = new StandardPrinter;
    auto p2 = new ReversePrinter;
    
    Printers ps;
    ps.add("n1", p);
    ps.add("r2", p2);

    Printers ps2(ps);
    Printers ps3(ps);
    ps3 = ps;

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    ps2["n1"]("Testing the two printers");    
    ps2["n1"]("With some chaining")("Whoo");
    ps3["r2"]("Seems to work");
    ps3["r2"]("Yes, pretty well");

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "Testing the two printers";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    c << "With some chaining" ;
    correct = c.str();
    std::getline(test, checkstr);
    EXPECT_EQ(correct, checkstr); 
    
    c.str("");
    c.clear();

    c << "Whoo";
    correct = c.str();
    std::getline(test, checkstr);
    EXPECT_EQ(correct, checkstr);   
    
    c.str("");
    c.clear();

    c << "krow ot smeeS";
    correct = c.str();
    std::getline(test, checkstr);
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    c << "llew ytterp ,seY" ;
    correct = c.str();
    std::getline(test, checkstr);
    EXPECT_EQ(correct, checkstr);
}

TEST(test_printers4, test_exceptions) {
    auto p = new StandardPrinter;
    auto p2 = new ReversePrinter;
    
    Printers ps;
    ps.add("n1", p);
    ps.add("r2", p2);

    try {
        ps.add("n3", (StringPrinter*)0);
    }       
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid printer"));
    }

    try {
        ps["pinkey"]("Hih");    
    }       
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Unknown index"));
    }
    try {
        ps.add("n1", p);
    }       
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Duplicate index"));
    }

}
