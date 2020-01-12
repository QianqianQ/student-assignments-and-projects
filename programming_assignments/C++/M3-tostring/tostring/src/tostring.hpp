#ifndef CONVERT_HH

#define CONVERT_HH



#include <sstream>

#include <string>

using namespace std;

/* As an introduction to templates you will write and specialize a template function

 * for formatting the contents of a container (string, vector, list, ...) into a string,

 * assuming that the elements of the container are printable (with the << operator).

 *

 * This function is called toString and it returns the container contents in the following format

 * (assuming a container of strings with three elements: "foo", "bar" and "baz"):

{ foo, bar, baz }

 * When passed a std::string, the function should, instead of returning a list of characters { f, o, o, b, a, r },

 * just put double quotes around the string:

"foobar"

 * Additionally, overload the function with a version that, instead of a container,

 * takes begin and end iterators, and formats the contents in the format specified above for containers

 * (no special handling for string iterators).

 *

 * Notes:

 * You may assume that std::strings have their regular interface.

 * For other containers, only use the iterator interface (begin and end functions).

 * Your functions must work with at least bidirectional iterators. Note that such iterators do not have operators + and -

 * If you'd really want to provide printing support for containers,

 * you should write operator<< for them instead of a toString function.

 * This would allow printing containers that contain other containers, etc.

 */




template<class Container>

string toString(Container& c)

 {

     string s;

     s.append("{ ");

    for(auto i = c.begin();i!=c.end();i++)

    {

        s.append(to_string(*i));

        s.append(", ");

    }

    s.pop_back();

    s.pop_back();

    s.append(" }");

    return s;

 }

template<>
string toString<string>(string& s)

{
    string str = "\"";
    str+=s;
    str+="\"";

    return str;

}




template<typename Iter>

string toString(Iter begin,Iter end)

 {

     string str;

     str.append("{ ");


     while(begin!=end)

     {
        str.append(to_string(*begin));

        str.append(", ");

        begin++;

     }

     str.pop_back();

     str.pop_back();

     str.append(" }");

     return str;

 }
template<>

string toString(string::iterator begin,string::iterator end)

 {

     string str;

     str.append("{ ");


     while(begin!=end)

     {
        str.push_back(*begin);

        str.append(", ");

        begin++;

     }

     str.pop_back();

     str.pop_back();

     str.append(" }");

     return str;

 }






#endif

