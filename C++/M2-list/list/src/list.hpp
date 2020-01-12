#ifndef AALTO_ELEC_CPP_LIST
#define AALTO_ELEC_CPP_LIST

#include <iostream>
#include <list>
#include <string>

/** Read all lines from the stream into the list. Newline characters are not
 * stored in the list. Returns the stream. **/
std::istream& getLines(std::istream& is, std::list<std::string>& list);

/** Print the list, with a newline after each entry. **/
void print(std::list<std::string> const& list);

/** Sort the list and remove all duplicate entries. **/
void sortAndUnique(std::list<std::string>& list);

#endif
