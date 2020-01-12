title: Pokemon
task_id: M2-POKEMON
points: 2


**Objective:** Practice use of algorithms together with a list
  container.

Pokemon is an information entity with a name (string) and an
identifier. Therefore the **pair** type can be used to store one such
element. This exercise operates on lists that consist of (string,
unsigned integer) pairs. The function definitions in **pokemon.hpp**
include the exact definition of the container, along with the detailed
descriptions of the functions. You should review the function
interfaces and respective descriptions there.

You will need to implement the following functions:

  * **addPokemon(collection, name, id)** that adds a new Pokemon with
    given name/id pair at the end of list **collection**.

  * **removePokemon(collection, name, id)** that removes the first
    Pokemon with matching name and id.

  * **printCollection(begin, end)** that prints the Pokemons between
    iterators **begin** and **end**. The Pokemon at iterator **begin**
    is printed, but **end** is not included in the printout. See the
    example in **pokemon.hpp** for the required print format.

  * **sortCollection(collection, sortType)** that sorts the Pokemon
    collection either by the name, or by the ID. The sortType argument
    specifies which element in the pair specifies the more significant
    sorting order.

  * **mergeCollections(c1, c2)** that merges the contents of the two
    collections. The merged collection is ordered with ID being the
    most significant order, and duplicate elements must be removed.

You will gain one point for succesful implementation of
**addPokemon**, **removePokemon** and **printCollection**, and other
point for implementing **sortCollection** and
**mergeCollection**. Especially for the last two functions it is
recommended that you familiarize yourself with the algorithms and
functions available for list container (such as **sort** and
**unique**).
