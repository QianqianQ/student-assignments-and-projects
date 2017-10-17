#ifndef ELEC_AS_CPP_POLY
#define ELEC_AS_CPP_POLY

#include <iosfwd>
#include <map>

/* Polynomial is a mathematical expression consisting of terms summed to each-other.
 * In this exercise you will implement class Poly, holding a single polynomial
 * where each term is of form <mul>x<exp>.
 * For example, the parabola 4x²+2x+7 would be stored in the Poly object as
 * std::map<int, int> of pairs of exponent and multiplier: (2, 4), (1, 2), (0, 7).
 *
 * Before starting, make yourself familiar with operator overloading.
 * Then implement for your class the following accessors and operators,
 * and test your implementation with the given main.
 *
 * Implement:
 *
 * begin and end functions that return iterators for traversing the map.
 * These must work with const and non-const Poly objects, permitting modifications on the latter.
 * The iteration order must descending (*poly.begin() is the term with the highest exponent).
 * The iterator value type is the same as the std::map's.
 *
 * Negation operator (unary operator-) that changes the sign of the multiplier of each term.
 *
 * Binary (two-operand) operators +, -, += and -= that do the corresponding mathematical operations
 * (adding/subtracting the multipliers of termwise)
 *
 * Indexing with poly[exponent], accessing the associated multiplier.
 * Zero is returned if the exponent didn't exist.
 * Notice that const and non-const versions need to be implemented differently.
 *
 * operator<<, using the format described below.
 *
 * Additionally you will need public typedefs iterator and const_iterator for the iterator types used.
 * Do not implement your own iterator types but instead use existing ones for the typedefs.
 * It is OK for the iterators to also return terms with zero multipliers.
 *
 * A few operators have been implemented for you in poly.cpp.
 * Add the missing operators but do not modify the existing ones.
 *
 *
 * Stream I/O format
 *
 * A simplified format where each term is of format <mul>x<exp> is used.
 * Between each term there must be a plus or a minus sign depending on the sign of the multiplier of the next term.
 * For example, 4x²+2x+7 would be written 4x2+2x1+7x0 and -7x^-2 would be written as -7x-2.
 *
 * The output operator must normalize the output by printing the terms with descending order (highest exponent first)
 * and by omitting all terms where the multiplier is zero.
 * Nothing is printed if there are no non-zero terms in the polynomial.
 *
 * Ordering
 *
 * In this exercise the degree (the exponent of the first non-zero term) of the polynomial alone determines the order for the comparison operators.
 * Multipliers or other terms have no effect. E.g. 3x² is considered equal to 1000x²+123x and x³ is considered greater than any of the two others.
 * An empty polynomial is less than any non-empty polynomial.
 */

/* TODO: recommended order for implementing:
 * 1. Indexing operator for modifying
 * 2. Iterators
 * 3. Indexing operator for accessing (cnost!)
 * 4. Unary operator-
 * 5. Binary operators: operator+= & operator+
 * 6. operator-= & operator-
 * 7. Operators for comparisons.
 */


class Poly {
    typedef std::map<int, int> Values;
    Values m_values;
    public:
    typedef Values::const_reverse_iterator const_iterator;
    typedef Values::reverse_iterator iterator;
    const int& operator[](const int exp) const;
    int& operator[](const int exp);
    Poly& operator+=(Poly const& b);
    Poly& operator-=(Poly const& b);
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

std::istream& operator>>(std::istream& is, Poly& p);
std::ostream& operator<<(std::ostream& os, Poly const& p);
Poly operator+(Poly const& a, Poly const& b);
Poly operator-(Poly const& a, Poly const& b);
Poly operator-(Poly const& p);

bool operator<(Poly const& a, Poly const& b);
bool operator==(Poly const& a, Poly const& b);
bool operator>(Poly const& a, Poly const& b);
bool operator!=(Poly const& a, Poly const& b);

#endif

