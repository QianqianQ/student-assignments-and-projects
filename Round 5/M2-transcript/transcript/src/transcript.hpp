#ifndef AALTO_ELEC_CPP_TRANSCRIPT
#define AALTO_ELEC_CPP_TRANSCRIPT

#include <string>
#include <list>
#include <utility>

typedef struct Transcript_t {
        std::string name; // Name of the transcript
        std::string student_id;
        std::list<std::pair<std::string, size_t>> grades; // List of (course, grade) pairs
} Transcript;

/* Adds a transcript to the end of the registry */
void addTranscript(std::list<Transcript>& registry, const Transcript& t);

/* Removes all transcripts with the given student_id */
void removeTranscript(std::list<Transcript>& registry, const std::string& student_id);

/* Returns an iterator to first transcript with the given student_id
 * If no such transcript is found, the end iterator is returned */
std::list<Transcript>::const_iterator findTranscript(const std::list<Transcript>& registry, const std::string& student_id);

/* Generates a list of results for a course.
 * This is done by collecting all grades for a course from all the transcripts */
std::list<std::pair<std::string, size_t>> findCourseResults(const std::list<Transcript>& registry, const std::string& course);

#endif
