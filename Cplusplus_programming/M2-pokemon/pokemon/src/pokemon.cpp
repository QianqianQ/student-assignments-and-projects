#include<list>
#include<string>
#include<utility>
#include<algorithm>
#include "pokemon.hpp"

void addPokemon(std::list<std::pair<std::string, size_t>>& collection, std::string const& name, size_t id)
{
    std::pair<std::string, size_t> new_Pokemon = std::pair<std::string,size_t>(name,id);
    collection.push_back(new_Pokemon);
}

bool removePokemon(std::list<std::pair<std::string, size_t>>& collection, std::string const& name, size_t id)
{
    std::pair<std::string,size_t> p = std::make_pair(name,id);
    auto it = find_if(collection.begin(),collection.end(),
                      [name](std::pair<std::string, size_t> element){
                          return element.first==name;});
    if(it!=collection.end())
    {
        collection.erase(it);
        return true;

    }

    else
        return false;
}

void printCollection(std::list<std::pair<std::string, size_t>>::const_iterator begin, std::list<std::pair<std::string, size_t>>::const_iterator end)
{
        while(begin!=end)
        {
            std::cout<<"id: "<<begin->second<<", "<<"name: "<<begin->first<<std::endl;
            begin++;
        }
}

void sortCollection(std::list<std::pair<std::string, size_t>>& collection, size_t sortType)
{
     if (sortType == 0)
    {
        std::string temp_s;
        size_t temp_id;
        for(auto i=collection.begin();i!=collection.end();i++)
            for(auto j=i;j!=collection.end();j++)
        {
            if(i->second > j->second)
            {
                temp_s= i->first;
                temp_id= i->second;
                i->first=j->first;
                i->second=j->second;
                j->first=temp_s;
                j->second=temp_id;
            }
            if(i->second == j->second && i!=j)
            {
                if(i->first > j->first)
                {
                temp_s= i->first;
                temp_id= i->second;
                i->first=j->first;
                i->second=j->second;
                j->first=temp_s;
                j->second=temp_id;
                }
            }
        }
    }
   if (sortType == 1)
    {
        std::string temp_s;
        size_t temp_id;
        for(auto i=collection.begin();i!=collection.end();i++)
            for(auto j=i;j!=collection.end();j++)
        {
            if(i->first > j->first)
            {
                temp_s= i->first;
                temp_id= i->second;
                i->first=j->first;
                i->second=j->second;
                j->first=temp_s;
                j->second=temp_id;
            }
            if(i->first == j->first && i!=j)
            {
                if(i->second > j->second)
                {
                temp_s= i->first;
                temp_id= i->second;
                i->first=j->first;
                i->second=j->second;
                j->first=temp_s;
                j->second=temp_id;
                }
            }
        }
    }

}

std::list<std::pair<std::string, size_t>> mergeCollections(std::list<std::pair<std::string, size_t>> const& c1, std::list<std::pair<std::string, size_t>> const& c2)
{
    std::list<std::pair<std::string, size_t>> new_collection;
    std::copy(c1.begin(),c1.end(),back_inserter(new_collection));
    std::copy(c2.begin(),c2.end(),back_inserter(new_collection));
    sortCollection(new_collection,0);
    new_collection.unique();
    return new_collection;
}

