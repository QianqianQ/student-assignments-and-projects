#include <list>
#include <utility>
#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>

#include "transcript.hpp"

void addTranscript(std::list<Transcript>& registry, const Transcript& t) {
    registry.push_back(t);
}

void removeTranscript(std::list<Transcript>& registry, const std::string& student_id) {
    auto i = std::find_if(registry.begin(),registry.end(),[student_id](Transcript& it)->
                 bool{return (student_id==it.student_id);});
    if(i!=registry.end())
    {
        registry.erase(i);
    }

}

std::list<Transcript>::const_iterator findTranscript(const std::list<Transcript>& registry, const std::string& student_id) {
    auto i = find_if(registry.begin(),registry.end(),[student_id](const Transcript& it)->bool{return (it.student_id==student_id);});
    return i; // replace this
}

std::list<std::pair<std::string, size_t>> findCourseResults(const std::list<Transcript>& registry, const std::string& course) {
    std::list<std::pair<std::string, size_t>> grade_list;
    for(auto i=registry.begin();i!=registry.end();i++)
    {
        auto j = std::find_if(i->grades.begin(),i->grades.end(),
                      [course](const std::pair<std::string, size_t>& a)->bool{return a.first==course;});
        if(j!=i->grades.end())
        {
            std::pair<std::string,size_t> a = std::make_pair(i->student_id,j->second);
            grade_list.push_back(a);
        }

    }
    return grade_list;

 // replace this
}

