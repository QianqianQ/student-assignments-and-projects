#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "../src/transcript.hpp"

TEST(test_transcript, test_add) {
    std::string s = "Transcript of student_123456";
    std::string id = "123456";
    std::list<std::pair<std::string, size_t>> grades;
    grades.emplace_back("C++ programming", 2);
    grades.emplace_back("Basic Course in C programming", 4);
    grades.emplace_back("Computer Graphics", 5);
    grades.emplace_back("Programming 1", 3);
    Transcript t;
    t.name = s;
    t.student_id = id;
    t.grades = grades;

    std::string s2 = "Transcript of student_347657";
    std::string id2 = "347657";
    std::list<std::pair<std::string, size_t>> grades2;
    grades2.emplace_back("C++ programming", 5);
    grades2.emplace_back("Basic Course in C programming", 2);
    grades2.emplace_back("Basic Course in Mathematics S1", 3);
    grades2.emplace_back("Circuit Analysis 1", 4);
    Transcript t2;
    t2.name = s2;
    t2.student_id = id2;
    t2.grades = grades2;

    std::string s3 = "Transcript of student_092854";
    std::string id3 = "092854";
    std::list<std::pair<std::string, size_t>> grades3;
    grades3.emplace_back("Embedded Systems Development", 5);
    grades3.emplace_back("Switched-Mode Power Supplies", 3);
    grades3.emplace_back("Design of Electrical Machines", 4);
    grades3.emplace_back("Converter Techniques", 4);
    grades3.emplace_back("C++ programming", 4);
    Transcript t3;
    t3.name = s3;
    t3.student_id = id3;
    t3.grades = grades3;


    std::list<Transcript> reg;
    
    addTranscript(reg, t3); 
    addTranscript(reg, t2); 
    addTranscript(reg, t);

    EXPECT_EQ(t3.name, reg.begin()->name);
    EXPECT_EQ(t3.student_id, reg.begin()->student_id);
    EXPECT_EQ(*t3.grades.begin(), *(reg.begin()->grades.begin()));
    EXPECT_EQ(*(std::next(t3.grades.begin(),1)), *(std::next(reg.begin()->grades.begin(), 1)));
    EXPECT_EQ(*(std::next(t3.grades.begin(),2)), *(std::next(reg.begin()->grades.begin(), 2)));
    EXPECT_EQ(*(std::next(t3.grades.begin(),3)), *(std::next(reg.begin()->grades.begin(), 3)));

    EXPECT_EQ(t2.name, (++reg.begin())->name);
    EXPECT_EQ(t2.student_id, (++reg.begin())->student_id);
    EXPECT_EQ(*t2.grades.begin(), *((std::next(reg.begin(), 1))->grades.begin()));
    EXPECT_EQ(*(std::next(t2.grades.begin(),1)), *(std::next(std::next(reg.begin(),1)->grades.begin(), 1)));
    EXPECT_EQ(*(std::next(t2.grades.begin(),2)), *(std::next(std::next(reg.begin(),1)->grades.begin(), 2)));
    EXPECT_EQ(*(std::next(t2.grades.begin(),3)), *(std::next(std::next(reg.begin(),1)->grades.begin(), 3)));

    EXPECT_EQ(t.name, (std::next(reg.begin(), 2))->name);
    EXPECT_EQ(t.student_id, (std::next(reg.begin(), 2))->student_id);
    EXPECT_EQ(*t.grades.begin(), *((std::next(reg.begin(), 2))->grades.begin()));
    EXPECT_EQ(*(std::next(t.grades.begin(),1)), *(std::next(std::next(reg.begin(),2)->grades.begin(), 1)));
    EXPECT_EQ(*(std::next(t.grades.begin(),2)), *(std::next(std::next(reg.begin(),2)->grades.begin(), 2)));
    EXPECT_EQ(*(std::next(t.grades.begin(),3)), *(std::next(std::next(reg.begin(),2)->grades.begin(), 3)));
    
}

TEST(test_transcript, test_remove) {
    std::string s = "Transcript of student_123456";
    std::string id = "123456";
    std::list<std::pair<std::string, size_t>> grades;
    grades.emplace_back("C++ programming", 2);
    grades.emplace_back("Basic Course in C programming", 4);
    grades.emplace_back("Computer Graphics", 5);
    grades.emplace_back("Programming 1", 3);
    Transcript t;
    t.name = s;
    t.student_id = id;
    t.grades = grades;

    std::string s2 = "Transcript of student_347657";
    std::string id2 = "347657";
    std::list<std::pair<std::string, size_t>> grades2;
    grades2.emplace_back("C++ programming", 5);
    grades2.emplace_back("Basic Course in C programming", 2);
    grades2.emplace_back("Basic Course in Mathematics S1", 3);
    grades2.emplace_back("Circuit Analysis 1", 4);
    Transcript t2;
    t2.name = s2;
    t2.student_id = id2;
    t2.grades = grades2;

    std::string s3 = "Transcript of student_092854";
    std::string id3 = "092854";
    std::list<std::pair<std::string, size_t>> grades3;
    grades3.emplace_back("Embedded Systems Development", 5);
    grades3.emplace_back("Switched-Mode Power Supplies", 3);
    grades3.emplace_back("Design of Electrical Machines", 4);
    grades3.emplace_back("Converter Techniques", 4);
    grades3.emplace_back("C++ programming", 4);
    Transcript t3;
    t3.name = s3;
    t3.student_id = id3;
    t3.grades = grades3;


    std::list<Transcript> reg;
    
    addTranscript(reg, t); 
    addTranscript(reg, t2); 
    addTranscript(reg, t3);

    removeTranscript(reg, t2.student_id);

    EXPECT_EQ(t.name, reg.begin()->name);
    EXPECT_EQ(t.student_id, reg.begin()->student_id);
    EXPECT_EQ(*t.grades.begin(), *(reg.begin()->grades.begin()));
    EXPECT_EQ(*(std::next(t.grades.begin(),1)), *(std::next(reg.begin()->grades.begin(), 1)));
    EXPECT_EQ(*(std::next(t.grades.begin(),2)), *(std::next(reg.begin()->grades.begin(), 2)));
    EXPECT_EQ(*(std::next(t.grades.begin(),3)), *(std::next(reg.begin()->grades.begin(), 3)));

    EXPECT_EQ(t3.name, (++reg.begin())->name);
    EXPECT_EQ(t3.student_id, (++reg.begin())->student_id);
    EXPECT_EQ(*t3.grades.begin(), *((std::next(reg.begin(), 1))->grades.begin()));
    EXPECT_EQ(*(std::next(t3.grades.begin(),1)), *(std::next(std::next(reg.begin(),1)->grades.begin(), 1)));
    EXPECT_EQ(*(std::next(t3.grades.begin(),2)), *(std::next(std::next(reg.begin(),1)->grades.begin(), 2)));
    EXPECT_EQ(*(std::next(t3.grades.begin(),3)), *(std::next(std::next(reg.begin(),1)->grades.begin(), 3)));
}

TEST(test_transcript2, test_find) {
    std::string s = "Transcript of student_123456";
    std::string id = "123456";
    std::list<std::pair<std::string, size_t>> grades;
    grades.emplace_back("C++ programming", 2);
    grades.emplace_back("Basic Course in C programming", 4);
    grades.emplace_back("Computer Graphics", 5);
    grades.emplace_back("Programming 1", 3);
    Transcript t;
    t.name = s;
    t.student_id = id;
    t.grades = grades;

    std::string s2 = "Transcript of student_347657";
    std::string id2 = "347657";
    std::list<std::pair<std::string, size_t>> grades2;
    grades2.emplace_back("C++ programming", 5);
    grades2.emplace_back("Basic Course in C programming", 2);
    grades2.emplace_back("Basic Course in Mathematics S1", 3);
    grades2.emplace_back("Circuit Analysis 1", 4);
    Transcript t2;
    t2.name = s2;
    t2.student_id = id2;
    t2.grades = grades2;

    std::string s3 = "Transcript of student_092854";
    std::string id3 = "092854";
    std::list<std::pair<std::string, size_t>> grades3;
    grades3.emplace_back("Embedded Systems Development", 5);
    grades3.emplace_back("Switched-Mode Power Supplies", 3);
    grades3.emplace_back("Design of Electrical Machines", 4);
    grades3.emplace_back("Converter Techniques", 4);
    grades3.emplace_back("C++ programming", 4);
    Transcript t3;
    t3.name = s3;
    t3.student_id = id3;
    t3.grades = grades3;


    std::list<Transcript> reg;
    
    addTranscript(reg, t); 
    addTranscript(reg, t2); 
    addTranscript(reg, t3);

    auto it = findTranscript(reg, t.student_id);

    EXPECT_EQ(t.name, it->name);
    EXPECT_EQ(t.student_id, it->student_id);
    EXPECT_EQ(*t.grades.begin(), *(it->grades.begin()));
    EXPECT_EQ(*(std::next(t.grades.begin(),1)), *(std::next(it->grades.begin(), 1)));
    EXPECT_EQ(*(std::next(t.grades.begin(),2)), *(std::next(it->grades.begin(), 2)));
    EXPECT_EQ(*(std::next(t.grades.begin(),3)), *(std::next(it->grades.begin(), 3)));

}

TEST(test_transcript2, test_find_course_results) {
    std::string s = "Transcript of student_123456";
    std::string id = "123456";
    std::list<std::pair<std::string, size_t>> grades;
    grades.emplace_back("C++ programming", 2);
    grades.emplace_back("Basic Course in C programming", 4);
    grades.emplace_back("Computer Graphics", 5);
    grades.emplace_back("Programming 1", 3);
    Transcript t;
    t.name = s;
    t.student_id = id;
    t.grades = grades;

    std::string s2 = "Transcript of student_347657";
    std::string id2 = "347657";
    std::list<std::pair<std::string, size_t>> grades2;
    grades2.emplace_back("C++ programming", 5);
    grades2.emplace_back("Basic Course in C programming", 2);
    grades2.emplace_back("Basic Course in Mathematics S1", 3);
    grades2.emplace_back("Circuit Analysis 1", 4);
    Transcript t2;
    t2.name = s2;
    t2.student_id = id2;
    t2.grades = grades2;

    std::string s3 = "Transcript of student_092854";
    std::string id3 = "092854";
    std::list<std::pair<std::string, size_t>> grades3;
    grades3.emplace_back("Embedded Systems Development", 5);
    grades3.emplace_back("Switched-Mode Power Supplies", 3);
    grades3.emplace_back("Design of Electrical Machines", 4);
    grades3.emplace_back("Converter Techniques", 4);
    grades3.emplace_back("C++ programming", 4);
    Transcript t3;
    t3.name = s3;
    t3.student_id = id3;
    t3.grades = grades3;


    std::list<Transcript> reg;
    
    addTranscript(reg, t); 
    addTranscript(reg, t2); 
    addTranscript(reg, t3);

    auto list  = findCourseResults(reg, "C++ programming");

    EXPECT_EQ("123456", (*list.begin()).first);
    EXPECT_EQ("347657", (*std::next(list.begin(), 1)).first);
    EXPECT_EQ("092854", (*std::next(list.begin(), 2)).first);

    EXPECT_EQ(2, (*list.begin()).second);
    EXPECT_EQ(5, (*std::next(list.begin(), 1)).second);
    EXPECT_EQ(4, (*std::next(list.begin(), 2)).second);

}
