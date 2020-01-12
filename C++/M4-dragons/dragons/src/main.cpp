#include "dragon.hpp"

#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>

std::list<Treasure> createRandomTreasures(size_t howMany)
{
    using namespace std;
    list<Treasure> treasures;

    // Jewellery
    vector<string> j_names = {"Ruby", "Gold bar"};
    // Wisdom
    vector<string> w_names = {"Scroll of infinite wisdom", "Sun Tzu's Art of War"};
    // Potions
    vector<string> p_names = {"Cough syrup", "Liquid luck", "Stoneskin potion"};

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
    vector<string> pf_names = {"Tenderloin steak", "Carnivore pizza"};
    // People
    vector<string> p_names = {"Raimo", "Petteri"};
    // Herbs
    vector<string> h_names = {"Arrowroot", "Bay leaves"};

    vector<vector<string>> names = {pf_names, p_names, h_names};

    for (size_t i = 0; i < howMany; i++)
    {
        size_t type = rand()%3;
        Food f = {((FoodType)type), names[type][rand()%(names[type].size())]};
        food.push_back(f);
    }

    return food;
}

int main()
{
    using namespace std;

    // Seed the random
    srand(123);

    // Random treasures
    list<Treasure> treasures = createRandomTreasures(rand()%10);
    // Random food
    list<Food> food = createRandomFood(rand()%10);

    cout << "*** Creating a set of different Dragons.." << endl;
    MagicDragon* mdragon = new MagicDragon("Puff", 976, 20);
    mdragon->hoard(treasures);
    FantasyDragon* fdragon = new FantasyDragon("Bahamut", (rand()%10000)+900, (rand()%10)+1);
    fdragon->hoard(treasures);

    ChineseDragon* cdragon = new ChineseDragon("Haku", (rand()%500)+100, (rand()%15)+1);
    cdragon->hoard(treasures);

    cout << "*** END OF READ ***" << endl;

    cout << "*** The dragons need beachside housing, creating a new DragonCave.." << endl;
    DragonCave* cave = new DragonCave();

    cout << "*** Accommodating the different Dragons to the cave.." << endl;
    cave->accommodateDragon(mdragon);
    cave->accommodateDragon(fdragon);
    cave->accommodateDragon(cdragon);

    cout << "*** Printing out the cave dwellers.." << endl;
    cout << *cave;
    cout << "*** END OF READ ***" << endl;

    cout << "*** Evicting a few dragons for various reasons.." << endl;
    size_t m_evicted = 0;

    if (rand()%2)
    {
        m_evicted = 1;
        cout << mdragon->getName() << " the MagicDragon broke the cave's rules and was evicted.." << endl;
        cave->evictDragon(mdragon->getName());
        delete mdragon;
    }

    if (rand()%2)
    {
        cout << fdragon->getName() << " the FantasyDragon broke the cave's rules and was evicted.." << endl;
        cave->evictDragon(fdragon->getName());
        delete fdragon;
    }

    if (rand()%2 && !m_evicted)
    {
        cout << cdragon->getName() << " the ChineseDragon framed " << mdragon->getName() << " the MagicDragon who was evicted.." << endl;
        cave->evictDragon(mdragon->getName());
        delete mdragon;
    }

    if (rand()%2)
    {
        cout << cdragon->getName() << " the ChineseDragon failed to pay the rent and was evicted.." << endl;
        cave->evictDragon(cdragon->getName());
        delete cdragon;
    }

    cout << "*** END OF READ ***" << endl;

    cout << "*** Printing out the new list of cave dwellers.." << endl;
    cout << *cave;
    cout << "*** END OF READ ***" << endl;

    cout << "*** The cave spontaneously collapsed, killing all the remaining cave dwellers (deleted).." << endl;
    delete cave;

    cout << "*** Test complete, exiting.." << endl;

    return 0;
}
