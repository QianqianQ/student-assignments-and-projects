#ifndef ELEC_AS_CPP_DRAGON_HH
#define ELEC_AS_CPP_DRAGON_HH

#include <string>
#include <list>
#include <iostream>

/* Enumeration types for the different treasures */
enum TreasureType
{
  Jewellery,
  Wisdom,
  Potions
};

/* Implementation of Treasure */
struct Treasure
{
  TreasureType type;
  std::string name;
};

/* Enumeration types for the different foods */
enum FoodType
{
  PeopleFood,
  People,
  Herbs
};

/* Implementation of Food */
struct Food
{
  FoodType type;
  std::string name;
};

class Dragon
{
public:
    Dragon(std::string const& iname, size_t iage, size_t isize):name(iname),age(iage),size(isize){}
    virtual ~Dragon(){};
    std::string const& getName() const
    {
        return name;
    }
    size_t getAge() const
    {
        return age;
    }
    size_t getSize() const
    {
        return size;
    }
   const std::list<Treasure>& getTreasures() const
   {
       return treasures;
   }
   virtual void eat(std::list<Food>&){};
   virtual void hoard(std::list<Treasure>&){};
   protected:
        std::string name;
        size_t age;
        size_t size;
        std::list<Treasure> treasures;
};


std::ostream& operator<<(std::ostream& os, Dragon const& dragon);

class DragonCave
{
    public:
    explicit DragonCave();
    virtual ~DragonCave();
    const std::list<Dragon*>& getDragons() const;

    void accommodateDragon(Dragon *d)
    {
        dragons.push_back(d);
    }

    void evictDragon(std::string const& name)
    {

        for(auto i = this->dragons.begin();i!=this->dragons.end();i++)
        {
            if((*i)->getName()==name)
            {
                dragons.erase(i);
                break;
            }
        }
    }
    private:
    std::list<Dragon*> dragons;

};


std::ostream& operator<<(std::ostream& os, DragonCave const& cave);



class ChineseDragon : public Dragon
{
  public:
    ChineseDragon(std::string const& name, size_t age, size_t size);
    virtual ~ChineseDragon(){};
    void eat(std::list<Food>& food);
    void hoard(std::list<Treasure>& t);
};



class FantasyDragon : public Dragon
{
  public:
    FantasyDragon(std::string const& name, size_t age, size_t size);
    virtual ~FantasyDragon(){};
    void eat(std::list<Food>& food);
    void hoard(std::list<Treasure>& t);
};



class MagicDragon : public Dragon
{
  public:
    MagicDragon(std::string const& name, size_t age, size_t size);
    virtual ~MagicDragon(){};

    void eat(std::list<Food>& food);
    void hoard(std::list<Treasure>& t);
};

#endif
