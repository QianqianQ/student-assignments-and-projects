#include <string.h>
#include <stdlib.h>
#include "oodi.h"


int init_record(struct oodi *or, const char *p_student, const char *p_course,
        unsigned char p_grade, struct date p_date)
{
    if (strlen(p_student) > 6)
        return 0;

    strncpy(or->student, p_student, 6);
    or->student[6] = 0;
    or->course = malloc(strlen(p_course) + 1);
    strcpy(or->course, p_course);
    or->grade = p_grade;
    or->compdate = p_date;
    return 1;
}

struct oodi *add_record(struct oodi *array, unsigned int length, struct oodi newrec)
{
    array = realloc(array, (length + 1) * sizeof(struct oodi));
    init_record(&array[length], newrec.student, newrec.course,
            newrec.grade, newrec.compdate);
    return array;
}

int change_grade(struct oodi *array, unsigned int size, const char *p_student,
        const char *p_course, unsigned char newgrade, struct date newdate)
{
    for (unsigned int i = 0; i < size; i++) {
        if (!strcmp(array[i].student, p_student) && !strcmp(array[i].course, p_course)) {
            array[i].grade = newgrade;
            array[i].compdate = newdate;
            return 1;
        }
    }
    return 0;
}
