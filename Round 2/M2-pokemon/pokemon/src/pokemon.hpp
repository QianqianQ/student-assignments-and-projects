#ifndef AALTO_ELEC_CPP_POKEMON
#define AALTO_ELEC_CPP_POKEMON

#include <iostream>
#include <string>
#include <list>
#include <utility>

/* DESCRIPTION:
 * -------------
 * Creates and adds a new pokemon to the back of the list.
 *
 * PARAMETERS:
 * -------------
 * collection: a list of pokemon elements
 * name: name of the new pokemon
 * id: the id of the new pokemon
 *
 * RETURNS:
 * -------------
 * Nothing.
 *
 */
void addPokemon(std::list<std::pair<std::string, size_t>>& collection, std::string const& name, size_t id);

/* DESCRIPTION:
 * -------------
 * Removes the first pokemon found matching the parameter name and id.
 *
 * PARAMETERS:
 * -------------
 * collection: a list of pokemon elements
 * name: the name of the pokemon to be found
 * id: the id of the pokemon to be found
 *
 * RETURNS:
 * -------------
 * true: if the pokemon was found and removed
 * false: if there was no such pokemon to be removed from the collection
 *
 */
bool removePokemon(std::list<std::pair<std::string, size_t>>& collection, std::string const& name, size_t id);

/* DESCRIPTION:
 * -------------
 * Prints out the collection from range [begin, last) (i.e. last element not included) to the standard
 * output stream. The format of the print should be as below:
 * id: <id>, name: <name>\n
 * id: <id>, name: <name>\n
 *
 * e.g.
 *
 * id: 25, name: Pikachu\n
 * id: 1, name: Bulbasaur\n
 *
 * PARAMETERS:
 * -------------
 * begin: an iterator pointing to the beginning of the printable area
 * end: an iterator pointing to the end of the printable area
 *
 * RETURNS:
 * -------------
 * Nothing.
 *
 */
void printCollection(std::list<std::pair<std::string, size_t>>::const_iterator begin, std::list<std::pair<std::string, size_t>>::const_iterator end);

/* DESCRIPTION:
 * -------------
 * Sorts the parameter collection according to parameter sort type.
 *
 * If the parameter sortType is 0 the collection is sorted first by id,
 * in case the ids are equal then by name.
 *
 * If the parameter sortType is 1 the collection is sorted first by name then by id,
 * in case the names are equal then by id.
 *
 * Hint: A list only has bidirectional iterators, which might narrow your sorting solutions down a bit.
 *       However a valid and easy solution does exist!
 *
 * PARAMETERS:
 * -------------
 * collection: the collection to be sorted
 * sortType: specifies the desired order
 *
 * RETURNS:
 * -------------
 * Nothing.
 *
 */
void sortCollection(std::list<std::pair<std::string, size_t>>& collection, size_t sortType);

/* DESCRIPTION:
 * -------------
 * Merges the two parameter collections into one new collection. The new collection doesn't contain any duplicates and is
 * sorted first by id, if the ids are equal then by name.
 *
 * Note: you can assume that the parameter collections are already sorted first by name then by id.
 *
 * PARAMETERS:
 * -------------
 * c1: first of the collections to be merged
 * c2: second of the collections to be merged
 *
 * RETURNS:
 * -------------
 * A new collection containing no duplicates and ordered as specified.
 *
 */
std::list<std::pair<std::string, size_t>> mergeCollections(std::list<std::pair<std::string, size_t>> const& c1, std::list<std::pair<std::string, size_t>> const& c2);

#endif
