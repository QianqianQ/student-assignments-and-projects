#include "dragon.hpp"

#include <string>
#include <list>
#include <iostream>

DragonCave::DragonCave() { }

DragonCave::~DragonCave()
{
  for (std::list<Dragon*>::iterator it = dragons.begin(); it != dragons.end(); it++)
    delete *it;
}
const std::list<Dragon*>& DragonCave::getDragons() const
{
        return dragons;
}

ChineseDragon::ChineseDragon(std::string const& name, size_t age, size_t size):Dragon(name,age,size){}

void ChineseDragon::eat(std::list<Food>& food)
{
   for (std::list<Food>::iterator it = food.begin(); it != food.end();)
    if (it->type == Herbs || it->type == PeopleFood)
    {
      std::cout << "Chinese dragon ate: " << it->name << std::endl;
      it = food.erase(it);
      size++;
    } else it++;
}

void ChineseDragon::hoard(std::list<Treasure>& t)
{
    for (std::list<Treasure>::iterator it = t.begin(); it != t.end();)
    if (it->type == Wisdom)
    {
      std::cout << "Chinese dragon received: " << it->name << std::endl;
      this->treasures.push_back(*it);
      it = t.erase(it);
    } else it++;
}


FantasyDragon::FantasyDragon(std::string const& name, size_t age, size_t size):Dragon(name,age,size){}
void FantasyDragon::eat(std::list<Food>& food)
{

   for (std::list<Food>::iterator it = food.begin(); it != food.end();)
    if (it->type == People || it->type == PeopleFood)
    {
      std::cout << "Fantasy dragon ate: " << it->name << std::endl;
      it = food.erase(it);
      size++;
    } else it++;
}

void FantasyDragon::hoard(std::list<Treasure>& t)
{
    for (std::list<Treasure>::iterator it = t.begin(); it != t.end();)
    if (it->type == Jewellery)
    {
      std::cout << "Fantasy dragon received: " << it->name << std::endl;
      this->treasures.push_back(*it);
      it = t.erase(it);
    } else it++;
}

MagicDragon::MagicDragon(std::string const& name, size_t age, size_t size) : Dragon(name, age, size) { }

void MagicDragon::eat(std::list<Food>& food)
{
 for (std::list<Food>::iterator it = food.begin(); it != food.end();)
    if (it->type == Herbs)
    {
      std::cout << "Magic dragon ate: " << it->name << std::endl;
      it = food.erase(it);
      size++;
    } else it++;
}

void MagicDragon::hoard(std::list<Treasure>& t)
{
for (std::list<Treasure>::iterator it = t.begin(); it != t.end();)
    if (it->type == Potions)
    {
      std::cout << "Magic dragon received: " << it->name << std::endl;
      this->treasures.push_back(*it);
      it = t.erase(it);
    } else it++;
}
std::ostream& operator<<(std::ostream& os, Dragon const& dragon)
{
    os<<"Dragon named: "<<dragon.getName()<<", age: "<<dragon.getAge()<<", size: "<<dragon.getSize()<<std::endl;
    os<<"Treasures:"<<std::endl;
    for(auto i=dragon.getTreasures().begin();i!=dragon.getTreasures().end();i++)
    {
        os<<(i->name)<<std::endl;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, DragonCave const& cave)
{
    os<<"DragonCave dwellers:"<<std::endl;
    os<<std::endl;
    std::list<Dragon*>::const_iterator i;
    for(i=cave.getDragons().begin(); i!=cave.getDragons().end();i++)
    {
        os<<**i;
        os<<std::endl;
    }
    return os;
}
