#include "bird.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>


void Aviary::addBird(Bird *b)
{
    list.push_back(b);
}

Bird* Aviary::operator[](size_t j)
{
    return list[j];
}

Bird* Aviary::operator[](int i) const
{
    return list[i];
}

void Aviary::speakAll(std::ostream &os) const
{
    unsigned int i;
    for(i=0;i<list.size();i++)
    {
        list[i]->speak(os);
    }
}

size_t Aviary::size() const
{
    return list.size();
}


