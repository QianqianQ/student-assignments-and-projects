#include "pokemon.hpp"

#include <vector>

int main()
{
    using namespace std;

    /* A collections of few pokemons */
    list<pair<string, size_t>> collection = {pair<string, size_t>("Pikachu", 25), pair<string, size_t>("Raticate", 20), pair<string, size_t>("Raticate", 20), pair<string, size_t>("Bulbasaur", 1), pair<string, size_t>("Pikachu", 25), pair<string, size_t>("Diglett", 50)};

    list<pair<string, size_t>> collection2 = {pair<string, size_t>("Venomoth", 49), pair<string, size_t>("Oddish", 43)};

    cout << "*** Test printCollection.." << endl;
    printCollection(collection.begin(), collection.end());

    cout << "*** Test addPokemon.." << endl;
    addPokemon(collection, "Meowth", 52);
    addPokemon(collection, "Arcanine", 59);
    printCollection(collection.begin(), collection.end());

    cout << "*** Test removePokemon.." << endl;
    bool ret;

    ret = removePokemon(collection, "Raticate", 20);
    cout << (ret ? "Remove returned true. CORRECT!" : "Remove returned false. FAILED!") << endl;;

    ret = removePokemon(collection, "Ivysaur", 2);
    cout << (ret ? "Remove returned true. FAILED!" : "Remove returned false. CORRECT!") << endl;

    cout << "*** Test sortCollection by name, id.." << endl;
    sortCollection(collection, 1);
    printCollection(collection.begin(), collection.end());

    cout << "*** Test sortCollection by id, name.." << endl;
    sortCollection(collection, 0);
    printCollection(collection.begin(), collection.end());

    cout << "*** Test mergeCollections.." << endl;

    sortCollection(collection, 1);
    sortCollection(collection2, 1);

    cout << "*** Collection 1:" << endl;
    printCollection(collection.begin(), collection.end());

    cout << "*** Collection 2:" << endl;
    printCollection(collection2.begin(), collection2.end());

    list<pair<string, size_t>> merged = mergeCollections(collection, collection2);

    cout << "*** Merged collection:" << endl;
    printCollection(merged.begin(), merged.end());

    return 0;
}
