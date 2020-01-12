#include <gtest/gtest.h>
#include "../src/dragon.hpp"

#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

std::list<Treasure> createRandomTreasures(size_t howMany)
{
    using namespace std;
    list<Treasure> treasures;

    // Jewellery
    vector<string> j_names = {"Ruby", "Gold bar", "Agate", "Amber", "Silver coins", "Jade stone", "Bag of pearls", "Topaz", "Sapphire dust"};
    // Wisdom
    vector<string> w_names = {"Scroll of infinite wisdom", "Sun Tzu's Art of War", "Biographia literaria", "MAOL", "Gabriel's Wing", "Critique of pure reason", "The C++ standard", "The Symposium", "Thus Spoke Zarathustra"};
    // Potions
    vector<string> p_names = {"Cough syrup", "Liquid luck", "Stoneskin potion", "Blemish blitzer", "Elixir of euphoria", "Garroting gas", "Essence of insanity", "Gin tonic", "Truth serum"};

    vector<vector<string>> names = {j_names, w_names, p_names};

    for (size_t i = 0; i < howMany; i++)
    {
        size_t type = rand()%3;
        Treasure t = {((TreasureType)type), names[type][rand()%(names[type].size())]};
        treasures.push_back(t);
    }

    return treasures;
}

std::list<Food> createRandomFood(size_t howMany)
{
    using namespace std;
    list<Food> food;

    // PeopleFood
    vector<string> pf_names = {"Tenderloin steak", "Carnivore pizza", "Beef chuck", "Pork ribs", "Cornered beef", "Flank steak", "Pork rack", "Half of a pork's ass", "Horse (salami)"};
    // People
    vector<string> p_names = {"Raimo", "Petteri", "Joonas", "Konsta", "Jack Sparrow", "John Smith", "Random crusader", "Barack Obama", "The Pope"};
    // Herbs
    vector<string> h_names = {"Arrowroot", "Bay leaves", "Hawthorn", "Hypericum perforatum", "Poppy seeds", "Magic mushrooms", "Salvia divinorum", "Salvia officinalis", "Peppermint root"};

    vector<vector<string>> names = {pf_names, p_names, h_names};

    for (size_t i = 0; i < howMany; i++)
    {
        size_t type = rand()%3;
        Food f = {((FoodType)type), names[type][rand()%(names[type].size())]};
        food.push_back(f);
    }

    return food;
}

void putListIntoFile2(std::list<Food> list, FoodType type, FoodType type2, std::ofstream& out, std::string s) {
    for (std::list<Food>::iterator it = list.begin(); it != list.end(); it++)
        if (it->type == type || it->type == type2)
            out << s << it->name << std::endl;
}

void putListIntoFile3(std::list<Food> list, FoodType type, std::ofstream& out, std::string s) {
    for (std::list<Food>::iterator it = list.begin(); it != list.end(); it++)
        if (it->type == type)
            out << s << it->name << std::endl;
}

void putListIntoFile(std::list<Treasure> list, TreasureType type, std::ofstream& out, std::string s) {
    for (std::list<Treasure>::iterator it = list.begin(); it != list.end(); it++)
        if (it->type == type)
            out << s << it->name << std::endl;
}


TEST(test_dragon, test_create)
{
    using namespace std;

    MagicDragon* mdragon = new MagicDragon("Puff", 976, 20);
    int a1 = (rand()%10000)+900;
    int a2 = (rand()%500)+100;
    int s1 = (rand()%10)+1;
    int s2 = (rand()%15)+1;
    FantasyDragon* fdragon = new FantasyDragon("Bahamut", a1, s1);
    ChineseDragon* cdragon = new ChineseDragon("Haku", a2, s2);

    EXPECT_EQ("Puff", mdragon->getName());
    EXPECT_EQ(976, mdragon->getAge());
    EXPECT_EQ(20, mdragon->getSize());

    EXPECT_EQ("Bahamut", fdragon->getName());
    EXPECT_EQ(a1, fdragon->getAge());
    EXPECT_EQ(s1, fdragon->getSize());

    EXPECT_EQ("Haku", cdragon->getName());
    EXPECT_EQ(a2, cdragon->getAge());
    EXPECT_EQ(s2, cdragon->getSize());

    delete cdragon;
    delete fdragon;
    delete mdragon;
}

TEST(test_dragon, test_hoard)
{
    using namespace std;

    srand(time(0));
    // Random treasures
    list<Treasure> treasures = createRandomTreasures((rand()%20)+15);

    ofstream tr;
    std::string s = "Magic dragon received: ";
    tr.open("treasures.txt");
    if(tr.is_open()){
        putListIntoFile(treasures, Potions, tr, s);
        tr.close();
        tr.clear();
    }

    MagicDragon* mdragon = new MagicDragon("Puff", 976, 20);

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    mdragon->hoard(treasures);

    std::cout.rdbuf(coutbuf); //reset to standard output again
    out.close();
    out.clear();

    //read output from function
    std::string checkstr;
    std::string correct;
    std::ifstream test("out.txt");
    std::ifstream corr("treasures.txt");
    while(std::getline(test, checkstr) && std::getline(corr, correct)) {
        EXPECT_EQ(correct, checkstr);
    }
    test.close();
    test.clear();
    corr.close();
    corr.clear();

    if(remove("treasures.txt")!=0)
        std::cout << "Error!" << std::endl;
    if(remove("out.txt")!=0)
        std::cout << "Error!" << std::endl;

    s = "Fantasy dragon received: ";
    tr.open("treasures.txt");
    if(tr.is_open()){
        putListIntoFile(treasures, Jewellery, tr, s);
        tr.close();
    }
    else std::cout << "failed to open treasures.txt" << std::endl;

    FantasyDragon* fdragon = new FantasyDragon("Bahamut", (rand()%10000)+900, (rand()%10)+1);

    //use file out.txt as standard output
    out.open("out.txt", std::ofstream::trunc);
    coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    fdragon->hoard(treasures);

    std::cout.rdbuf(coutbuf); //reset to standard output again
    out.close();
    out.clear();

    test.open("out.txt");
    corr.open("treasures.txt");

    //read output from function
    while(std::getline(test, checkstr) && std::getline(corr, correct)) {
        EXPECT_EQ(correct, checkstr);
    }
    test.close();
    test.clear();
    corr.close();
    corr.clear();

    if(remove("treasures.txt")!=0)
        std::cout << "Error!" << std::endl;
    if(remove("out.txt")!=0)
        std::cout << "Error!" << std::endl;

    s = "Chinese dragon received: ";
    tr.open("treasures.txt");
    if(tr.is_open()){
        putListIntoFile(treasures, Wisdom, tr, s);
        tr.close();
    }
    else std::cout << "failed to open treasures.txt" << std::endl;

    ChineseDragon* cdragon = new ChineseDragon("Haku", (rand()%500)+100, (rand()%15)+1);

    //use file out.txt as standard output
    out.open("out.txt", std::ofstream::trunc);
    coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    cdragon->hoard(treasures);

    std::cout.rdbuf(coutbuf); //reset to standard output again
    out.close();
    out.clear();

    test.open("out.txt");
    corr.open("treasures.txt");

    //read output from function
    while(std::getline(test, checkstr) && std::getline(corr, correct)) {
        EXPECT_EQ(correct, checkstr);
    }
    test.close();
    test.clear();
    corr.close();
    corr.clear();

    if(remove("treasures.txt")!=0)
        std::cout << "Error!" << std::endl;
    
    delete cdragon;
    delete fdragon;
    delete mdragon;
}

TEST(test_dragon, test_eat)
{
    using namespace std;

    srand(time(0));
    // Random food
    list<Food> food = createRandomFood((rand()%20)+10);

    ofstream fd;
    std::string s = "Magic dragon ate: ";
    fd.open("food.txt");
    if(fd.is_open()){
        putListIntoFile3(food, Herbs, fd, s);
        fd.close();
        fd.clear();
    }

    MagicDragon* mdragon = new MagicDragon("Puff", 976, 20);

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    mdragon->eat(food);

    std::cout.rdbuf(coutbuf); //reset to standard output again
    out.close();
    out.clear();

    //read output from function
    std::string checkstr;
    std::string correct;
    std::ifstream test("out.txt");
    std::ifstream corr("food.txt");
    while(std::getline(test, checkstr) && std::getline(corr, correct)) {
        EXPECT_EQ(correct, checkstr);
    }
    test.close();
    test.clear();
    corr.close();
    corr.clear();

    if(remove("food.txt")!=0)
        std::cout << "Error!" << std::endl;
    if(remove("out.txt")!=0)
        std::cout << "Error!" << std::endl;

    s = "Fantasy dragon ate: ";
    fd.open("food.txt");
    if(fd.is_open()){
        putListIntoFile2(food, People, PeopleFood, fd, s);
        fd.close();
    }
    else std::cout << "failed to open food.txt" << std::endl;

    FantasyDragon* fdragon = new FantasyDragon("Bahamut", (rand()%10000)+900, (rand()%10)+1);

    //use file out.txt as standard output
    out.open("out.txt", std::ofstream::trunc);
    coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    fdragon->eat(food);

    std::cout.rdbuf(coutbuf); //reset to standard output again
    out.close();
    out.clear();

    test.open("out.txt");
    corr.open("food.txt");

    //read output from function
    while(std::getline(test, checkstr) && std::getline(corr, correct)) {
        EXPECT_EQ(correct, checkstr);
    }
    test.close();
    test.clear();
    corr.close();
    corr.clear();

    if(remove("food.txt")!=0)
        std::cout << "Error!" << std::endl;
    if(remove("out.txt")!=0)
        std::cout << "Error!" << std::endl;

    s = "Chinese dragon ate: ";
    fd.open("food.txt");
    if(fd.is_open()){
        putListIntoFile2(food, PeopleFood, Herbs, fd, s);
        fd.close();
    }
    else std::cout << "failed to open food.txt" << std::endl;

    ChineseDragon* cdragon = new ChineseDragon("Haku", (rand()%500)+100, (rand()%15)+1);

    //use file out.txt as standard output
    out.open("out.txt", std::ofstream::trunc);
    coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    cdragon->eat(food);

    std::cout.rdbuf(coutbuf); //reset to standard output again
    out.close();
    out.clear();

    test.open("out.txt");
    corr.open("food.txt");

    //read output from function
    while(std::getline(test, checkstr) && std::getline(corr, correct)) {
        EXPECT_EQ(correct, checkstr);
    }
    test.close();
    test.clear();
    corr.close();
    corr.clear();

    if(remove("food.txt")!=0)
        std::cout << "Error!" << std::endl;
    
    delete cdragon;
    delete fdragon;
    delete mdragon;
}

TEST(test_dragon2, test_print)
{
    using namespace std;

    srand(time(0));
    // Random treasures
    list<Treasure> treasures = createRandomTreasures((rand()%20)+15);
    // Random food
    list<Food> food = createRandomFood((rand()%20)+10);

    MagicDragon* mdragon = new MagicDragon("Puff", 976, 20);

    //use file tmp.txt as standard output
    std::ofstream tmp("tmp.txt");
    std::streambuf *outbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(tmp.rdbuf()); //redirect std::cout to out.txt!

    mdragon->hoard(treasures);

    int a1=(rand()%10000)+900, a2=(rand()%500)+100;
    int s1=(rand()%10)+1, s2=(rand()%15)+1;
    FantasyDragon* fdragon = new FantasyDragon("Bahamut", a1, s1);
    fdragon->hoard(treasures);

    ChineseDragon* cdragon = new ChineseDragon("Haku", a2, s2);
    cdragon->hoard(treasures);
    
    std::cout.rdbuf(outbuf); //reset to standard output again
    tmp.close();
    remove("tmp.txt");

    std::ofstream out("out.txt");
    out << *cdragon; 

    out.close();
    out.clear();

    std::string checkstr;
    std::string correct;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);
    correct="Dragon named: Haku, age: " + to_string(a2) + ", size: " + to_string(s2);
    EXPECT_EQ(correct, checkstr);
    std::getline(test, checkstr);
    correct="Treasures:";
    EXPECT_EQ(correct, checkstr);
    for(auto& tr: cdragon->getTreasures()) {
        std::getline(test, checkstr);
        EXPECT_EQ(tr.name, checkstr);
    }
    test.close();
    test.clear();
    
    out.open("out.txt");
    out << *fdragon; 

    out.close();
    out.clear();

    test.open("out.txt");
    std::getline(test, checkstr);
    correct="Dragon named: Bahamut, age: " + to_string(a1) + ", size: " + to_string(s1);
    EXPECT_EQ(correct, checkstr);
    std::getline(test, checkstr);
    correct="Treasures:";
    EXPECT_EQ(correct, checkstr);
    for(auto& tr: fdragon->getTreasures()) {
        std::getline(test, checkstr);
        EXPECT_EQ(tr.name, checkstr);
    }

    test.close();
    test.clear();
    
    out.open("out.txt");
    out << *mdragon; 

    out.close();
    out.clear();

    test.open("out.txt");
    std::getline(test, checkstr);
    correct="Dragon named: Puff, age: 976, size: 20";
    EXPECT_EQ(correct, checkstr);
    std::getline(test, checkstr);
    correct="Treasures:";
    EXPECT_EQ(correct, checkstr);
    for(auto& tr: mdragon->getTreasures()) {
        std::getline(test, checkstr);
        EXPECT_EQ(tr.name, checkstr);
    }
    
    delete cdragon;
    delete fdragon;
    delete mdragon;
}

TEST(test_dragoncave, test_accomodate)
{
    using namespace std;

    srand(time(0));
    // Random treasures
    list<Treasure> treasures = createRandomTreasures((rand()%20)+15);
    // Random food
    list<Food> food = createRandomFood((rand()%20)+10);

    MagicDragon* mdragon = new MagicDragon("Puff", 976, 20);
    int a1 = (rand()%10000)+900;
    int a2 = (rand()%500)+100;
    int s1 = (rand()%10)+1;
    int s2 = (rand()%15)+1;
    FantasyDragon* fdragon = new FantasyDragon("Bahamut", a1, s1);
    ChineseDragon* cdragon = new ChineseDragon("Haku", a2, s2);

    //use file tmp.txt as standard output
    std::ofstream tmp("tmp.txt");
    std::streambuf *outbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(tmp.rdbuf()); //redirect std::cout to out.txt!

    mdragon->hoard(treasures);
    fdragon->hoard(treasures);
    cdragon->hoard(treasures);
    
    std::cout.rdbuf(outbuf); //reset to standard output again
    tmp.close();
    remove("tmp.txt");
    
    DragonCave* cave = new DragonCave();

    cave->accommodateDragon(mdragon);
    cave->accommodateDragon(fdragon);
    cave->accommodateDragon(cdragon);

    auto it = cave->getDragons().begin();

    EXPECT_EQ("Puff", (*it)->getName());
    EXPECT_EQ(976, (*it)->getAge());
    EXPECT_EQ(20, (*it)->getSize());
    it++;

    EXPECT_EQ("Bahamut", (*it)->getName());
    EXPECT_EQ(a1, (*it)->getAge());
    EXPECT_EQ(s1, (*it)->getSize());
    it++;

    EXPECT_EQ("Haku", (*it)->getName());
    EXPECT_EQ(a2, (*it)->getAge());
    EXPECT_EQ(s2, (*it)->getSize());

    delete cave;
}

TEST(test_dragoncave, test_evict)
{
    using namespace std;

    srand(time(0));
    // Random treasures
    list<Treasure> treasures = createRandomTreasures((rand()%20)+15);
    // Random food
    list<Food> food = createRandomFood((rand()%20)+10);

    MagicDragon* mdragon = new MagicDragon("Puff", 976, 20);
    int a1 = (rand()%10000)+900;
    int a2 = (rand()%500)+100;
    int a3 = (rand()%1000)+500;
    int s1 = (rand()%10)+1;
    int s2 = (rand()%15)+1;
    int s3 = (rand()%20)+1;
    FantasyDragon* fdragon = new FantasyDragon("Bahamut", a1, s1);
    ChineseDragon* cdragon = new ChineseDragon("Haku", a2, s2);
    MagicDragon* mdragon2 = new MagicDragon("Drogon", a3, s3);

    //use file tmp.txt as standard output
    std::ofstream tmp("tmp.txt");
    std::streambuf *outbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(tmp.rdbuf()); //redirect std::cout to out.txt!

    mdragon2->hoard(treasures);
    fdragon->hoard(treasures);
    cdragon->hoard(treasures);
    
    std::cout.rdbuf(outbuf); //reset to standard output again
    tmp.close();
    remove("tmp.txt");
    
    DragonCave* cave = new DragonCave();

    cave->accommodateDragon(mdragon);
    cave->accommodateDragon(fdragon);
    cave->accommodateDragon(cdragon);
    cave->accommodateDragon(mdragon2);

    auto it = cave->getDragons().begin();

    EXPECT_EQ("Puff", (*it)->getName());
    EXPECT_EQ(976, (*it)->getAge());
    EXPECT_EQ(20, (*it)->getSize());
    it++;

    EXPECT_EQ("Bahamut", (*it)->getName());
    EXPECT_EQ(a1, (*it)->getAge());
    EXPECT_EQ(s1, (*it)->getSize());
    it++;

    EXPECT_EQ("Haku", (*it)->getName());
    EXPECT_EQ(a2, (*it)->getAge());
    EXPECT_EQ(s2, (*it)->getSize());
    it++;

    EXPECT_EQ("Drogon", (*it)->getName());
    EXPECT_EQ(a3, (*it)->getAge());
    EXPECT_EQ(s3, (*it)->getSize());

    cave->evictDragon("Puff");

    auto it2 = cave->getDragons().begin();

    EXPECT_EQ("Bahamut", (*it2)->getName());
    EXPECT_EQ(a1, (*it2)->getAge());
    EXPECT_EQ(s1, (*it2)->getSize());
    it2++;

    EXPECT_EQ("Haku", (*it2)->getName());
    EXPECT_EQ(a2, (*it2)->getAge());
    EXPECT_EQ(s2, (*it2)->getSize());
    it2++;

    EXPECT_EQ("Drogon", (*it2)->getName());
    EXPECT_EQ(a3, (*it2)->getAge());
    EXPECT_EQ(s3, (*it2)->getSize());

    delete mdragon;
    delete cave;
}

TEST(test_dragoncave2, test_print)
{
    using namespace std;

    srand(time(0));
    // Random treasures
    list<Treasure> treasures = createRandomTreasures((rand()%20)+15);
    // Random food
    list<Food> food = createRandomFood((rand()%20)+10);

    MagicDragon* mdragon = new MagicDragon("Puff", 976, 20);

    //use file tmp.txt as standard output
    std::ofstream tmp("tmp.txt");
    std::streambuf *outbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(tmp.rdbuf()); //redirect std::cout to out.txt!

    mdragon->hoard(treasures);

    int a1=(rand()%10000)+900, a2=(rand()%500)+100;
    int s1=(rand()%10)+1, s2=(rand()%15)+1;
    FantasyDragon* fdragon = new FantasyDragon("Bahamut", a1, s1);
    fdragon->hoard(treasures);

    ChineseDragon* cdragon = new ChineseDragon("Haku", a2, s2);
    cdragon->hoard(treasures);
    
    std::cout.rdbuf(outbuf); //reset to standard output again
    tmp.close();
    remove("tmp.txt");

    DragonCave* cave = new DragonCave();

    cave->accommodateDragon(cdragon);
    cave->accommodateDragon(fdragon);
    cave->accommodateDragon(mdragon);
    
    std::ofstream out("out.txt");
    out << *cave; 
    out.close();

    std::string checkstr;
    std::string correct;
    std::ifstream test("out.txt");
    
    std::getline(test, checkstr);
    correct="DragonCave dwellers:";
    EXPECT_EQ(correct, checkstr);

    std::getline(test, checkstr);
    EXPECT_EQ("", checkstr);
    std::getline(test, checkstr);
    correct="Dragon named: Haku, age: " + to_string(a2) + ", size: " + to_string(s2);
    EXPECT_EQ(correct, checkstr);
    std::getline(test, checkstr);
    correct="Treasures:";
    EXPECT_EQ(correct, checkstr);
    for(auto& tr: cdragon->getTreasures()) {
        std::getline(test, checkstr);
        EXPECT_EQ(tr.name, checkstr);
    }

    std::getline(test, checkstr);
    EXPECT_EQ("", checkstr);
    std::getline(test, checkstr);
    correct="Dragon named: Bahamut, age: " + to_string(a1) + ", size: " + to_string(s1);
    EXPECT_EQ(correct, checkstr);
    std::getline(test, checkstr);
    correct="Treasures:";
    EXPECT_EQ(correct, checkstr);
    for(auto& tr: fdragon->getTreasures()) {
        std::getline(test, checkstr);
        EXPECT_EQ(tr.name, checkstr);
    }

    std::getline(test, checkstr);
    EXPECT_EQ("", checkstr);
    std::getline(test, checkstr);
    correct="Dragon named: Puff, age: 976, size: 20";
    EXPECT_EQ(correct, checkstr);
    std::getline(test, checkstr);
    correct="Treasures:";
    EXPECT_EQ(correct, checkstr);
    for(auto& tr: mdragon->getTreasures()) {
        std::getline(test, checkstr);
        EXPECT_EQ(tr.name, checkstr);
    }
    
    delete cave;
}


