#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "../src/pokemon.hpp"

TEST(test_pokemon, test_addPokemon) {
    std::list<std::pair<std::string, size_t>> collection = {std::pair<std::string, size_t>("Pikachu", 25), std::pair<std::string, size_t>("Bulbasaur", 1)};
    addPokemon(collection, "Meowth", 52);
    addPokemon(collection, "Diglett", 50);
    
    auto it = collection.begin();
    std::advance(it, 2);
    EXPECT_EQ("Meowth", (*it).first);
    EXPECT_EQ(52, (*it).second);
    std::advance(it, 1);
    EXPECT_EQ("Diglett", (*it).first);
    EXPECT_EQ(50, (*it).second);
}

TEST(test_pokemon, test_printCollection) {
    std::list<std::pair<std::string, size_t>> collection = {std::pair<std::string, size_t>("Pikachu", 25), std::pair<std::string, size_t>("Raticate", 20), std::pair<std::string, size_t>("Raticate", 20), std::pair<std::string, size_t>("Bulbasaur", 1), std::pair<std::string, size_t>("Pikachu", 25), std::pair<std::string, size_t>("Diglett", 50)};
    
    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    printCollection(collection.begin(), collection.end());

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "id: 25, name: Pikachu";
    std::string correct = c.str();

    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 20, name: Raticate";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 20, name: Raticate";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 1, name: Bulbasaur";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 25, name: Pikachu";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 50, name: Diglett";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
}

TEST(test_pokemon, test_printCollection2) {
    std::list<std::pair<std::string, size_t>> collection = {std::pair<std::string, size_t>("Pikachu", 25), std::pair<std::string, size_t>("Raticate", 20), std::pair<std::string, size_t>("Raticate", 20), std::pair<std::string, size_t>("Bulbasaur", 1), std::pair<std::string, size_t>("Pikachu", 25), std::pair<std::string, size_t>("Diglett", 50)};
    
    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    auto it1 = collection.begin();
    std::advance(it1, 2);
    auto it2 = collection.begin();
    std::advance(it2, 5);
    printCollection(it1, it2);

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "id: 20, name: Raticate";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 1, name: Bulbasaur";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 25, name: Pikachu";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
}

TEST(test_pokemon, test_removePokemon) {
    std::list<std::pair<std::string, size_t>> collection = {std::pair<std::string, size_t>("Pikachu", 25), std::pair<std::string, size_t>("Raticate", 20), std::pair<std::string, size_t>("Raticate", 20), std::pair<std::string, size_t>("Bulbasaur", 1), std::pair<std::string, size_t>("Pikachu", 25), std::pair<std::string, size_t>("Diglett", 50)};
    
    bool t = removePokemon(collection, "Raticate", 20);
    EXPECT_TRUE(t);
    t = removePokemon(collection, "Oddish", 43);
    EXPECT_FALSE(t);
    t = removePokemon(collection, "Raticate", 20);
    EXPECT_TRUE(t);
    t = removePokemon(collection, "Raticate", 20);
    EXPECT_FALSE(t);
    t = removePokemon(collection, "Bulbasaur", 1);
    EXPECT_TRUE(t);
}


TEST(test_pokemon2, test_sortCollection) {
    std::list<std::pair<std::string, size_t>> collection = {std::pair<std::string, size_t>("Pikachu", 25), std::pair<std::string, size_t>("Raticate", 20), std::pair<std::string, size_t>("Raticate", 20), std::pair<std::string, size_t>("Bulbasaur", 1), std::pair<std::string, size_t>("Pikachu", 25), std::pair<std::string, size_t>("Diglett", 50)};
    addPokemon(collection, "Meowth", 52);
    addPokemon(collection, "Arcanine", 59);
    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    sortCollection(collection, 1);
    printCollection(collection.begin(), collection.end());

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "id: 59, name: Arcanine";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 1, name: Bulbasaur";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 50, name: Diglett";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 52, name: Meowth";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 25, name: Pikachu";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 25, name: Pikachu";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 20, name: Raticate";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 20, name: Raticate";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
}

TEST(test_pokemon2, test_sortCollection2) {
    std::list<std::pair<std::string, size_t>> collection = {std::pair<std::string, size_t>("Pikachu", 25), std::pair<std::string, size_t>("Raticate", 20), std::pair<std::string, size_t>("Raticate", 20), std::pair<std::string, size_t>("Bulbasaur", 1), std::pair<std::string, size_t>("Pikachu", 25), std::pair<std::string, size_t>("Diglett", 50)};
    addPokemon(collection, "Meowth", 52);
    addPokemon(collection, "Arcanine", 59);
    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    sortCollection(collection, 0);
    printCollection(collection.begin(), collection.end());

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "id: 1, name: Bulbasaur";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 20, name: Raticate";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();
    
    std::getline(test, checkstr);
    c << "id: 20, name: Raticate";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 25, name: Pikachu";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 25, name: Pikachu";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 50, name: Diglett";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 52, name: Meowth";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();    
    
    std::getline(test, checkstr);
    c << "id: 59, name: Arcanine";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
}

TEST(test_pokemon2, test_mergeCollection) {
    std::list<std::pair<std::string, size_t>> collection1 = {std::pair<std::string, size_t>("Pikachu", 25), std::pair<std::string, size_t>("Raticate", 20), std::pair<std::string, size_t>("Raticate", 20), std::pair<std::string, size_t>("Bulbasaur", 1), std::pair<std::string, size_t>("Pikachu", 25), std::pair<std::string, size_t>("Diglett", 50)};
    std::list<std::pair<std::string, size_t>> collection2 = {std::pair<std::string, size_t>("Venomoth", 49), std::pair<std::string, size_t>("Oddish", 43)};
    addPokemon(collection2, "Meowth", 52);
    addPokemon(collection2, "Arcanine", 59);
    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    sortCollection(collection1, 1);
    sortCollection(collection2, 1);
    auto merged = mergeCollections(collection1, collection2);
    printCollection(merged.begin(), merged.end());

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "id: 1, name: Bulbasaur";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 20, name: Raticate";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();
    
    std::getline(test, checkstr);
    c << "id: 25, name: Pikachu";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 43, name: Oddish";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
    
    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 49, name: Venomoth";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 50, name: Diglett";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "id: 52, name: Meowth";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();    
    
    std::getline(test, checkstr);
    c << "id: 59, name: Arcanine";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
}
