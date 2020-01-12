void sortCollection(std::list<std::pair<std::string, size_t>>& collection, size_t sortType)
{
     if (sortType == 1)
    {
        std::sort(collection.begin(),collection.end(),
                  [](const std::pair<std::string,size_t>& one,
                     const std::pair<std::string,size_t>& two)->bool{
                    if(one.first == two.first)
                        return one.second<two.second;
                        return one.first<two.first;});
    }
    if (sortType == 0)
    {
        std::sort(collection.begin(),collection.end(),
                  [](const std::pair<std::string,size_t>& one,
                     const std::pair<std::string,size_t>& two){
                    if(one.second==two.second)
                        return one.first<two.first;
                        return one.second<two.second;});
    }

}

    for(auto i=c1.begin();i!=c1.end();i++)
    {
        new_collection.push_back(*i);
    }
    for(auto j=c2.begin();j!=c2.end();j++)
    {
        new_collection.push_back(*j);
    }
