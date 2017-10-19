#ifndef ELEC_CPP_PRINTERS_HH
#define ELEC_CPP_PRINTERS_HH

#include <string>
#include <map>
#include <iostream>


/* Implement the abstract base class StringPrinter here
 *
 * The class has a constructor that takes one parameter:
 *    std::ostream& with the default value std::cout
 *
 * The class contains the following pure virtual member functions:
 *  - A clone() function that copies the object and returns StringPrinter*
 *
 *  - Function call operator overload, i.e. this base class is a function object.
 *    - Takes one std::string argument (the string should not be modified).
 *    - Returns a reference to the StringPrinter object meaning that this
 *      function call operation can be "chained", e.g.
 *      object("First")("Second")("Third");
 *
 * The base class contains the following protected member:
 *  An std::ostream reference which is the output stream
 *
 * Implement the class accordingly and do not forget the virtual destructor..
 */
class StringPrinter
{
public:
    StringPrinter(std::ostream& os=std::cout);
    virtual ~StringPrinter(){};
    virtual StringPrinter* clone() const =0;
    virtual StringPrinter& operator()(const std::string&)=0;
protected:
    std::ostream& os;

};

/* Class StandardPrinter
 * A minimal StringPrinter implementation with no special functionality
 *  apart from the std::ostream& stream parameter
 * Note:
 *  The Constructor
 *  The implementation of clone()
*/
class StandardPrinter : public StringPrinter
{
public:
    /* Construct a new object - pass the std::ostream& to the base class */
    StandardPrinter(std::ostream &os = std::cout) : StringPrinter(os)
    { }
    /* Copy this object */
    StandardPrinter* clone() const
    {
        return new StandardPrinter(os);
    }
    virtual StringPrinter& operator()(const std::string& str)
    {
        /* os is a protected member of the base class */
	os << str << std::endl;
        return *this;
    }
private:
};


/* Implement the class DiagonalPrinter here
 * The class inherits (public inheritance) class StringPrinter
 *
 * DiagonalPrinter prints a string diagonally
 * l        -
 *  i       -
 *   k      -
 *    e     -
 *          -
 *      t   -
 *       h  -
 *        i -
 *         s-
 * Where the dash (-) indicates a newline character.
 * Additionally and optionally, this printer can print a special first and
 *  last line for its output. This functionality is disabled by default.
 *
 * The DiagonalPrinter is constructed with three parameters
 *  The first line - "" by default, i.e. it is not printed at all
 *  The last line  - "" by default, i.e. it is not printed at all either
 *  The output stream
 *
 * Note that the default print functionality does not suffice for this class
 *  and you will have to implement the print overload yourself.
 *
 * Implement the class accordingly.
 */
class DiagonalPrinter: public StringPrinter
{
public:
    DiagonalPrinter(std::ostream& os = std::cout) : StringPrinter(os)
    {
        first_line ="";
        last_line = "";
    }
    DiagonalPrinter(std::string first,std::string last,std::ostream& os=std::cout):StringPrinter(os)
    {
        first_line = first;
        last_line = last;
    }

    DiagonalPrinter* clone() const;
    DiagonalPrinter& operator()(const std::string& str);
private:
    std::string first_line;
    std::string last_line;
};

/* Class Printers
 * A storage for StringPrinters pointers - has ownership of the objects
 * Maintains an association of name to StringPrinter pointer
 * Note:
 *  Some functions can throw exceptions - this is specified for each function
 */
class Printers
{
public:
    /* Construct an empty Printers object */
    Printers();

    /* Copy construct a Printers object */
    Printers(const Printers&);

    /* Free all memory associated with the Printers object */
    ~Printers(){};

    /* Adds a new StringPrinter to the Printers object
     * Creates the association of name to StringPrinter*
     * Throws:
     *  std::invalid_argument if an association for the name already exists ("Duplicate index")
     *  std::invalid_argument if the pointer is null ("Invalid printer")
     * Note: THe Printers object takes ownership of the pointer and is
     *  therefore responsible for eventually calling delete on the pointer
     */
    void add(const std::string&, StringPrinter*);

    /* Retrieves a StringPrinter from the Printers object
     * The StringPrinter is obtained based on the association on the name
     * Returns:
     *  a reference to the StringPrinter object
     * Throws:
     *  std::invalid_argument if an association does not exist ("Unknown index")
     */
    StringPrinter& operator[](const std::string&);

    /* Assign a Printers object */
    Printers& operator=(const Printers&);

    const std::map<std::string,StringPrinter*>& get_index() const;

private:
    /* Internal representation of Printers
     * Associates std::string to StringPrinter*
     * Note: Due to the pointer content, this does not copy nicely
     */
    std::map<std::string, StringPrinter*> index;
};

#endif

