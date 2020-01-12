#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "oodi.h"
int init_record(struct oodi *or, const char *p_student, const char *p_course,unsigned char p_grade, struct date p_compdate)
{
    if(strlen(p_student)<=6)
    {
        or->course=malloc(strlen(p_course)+1);
        if(or->course==NULL)
        {
            return 0;
        }
        else
        {
            strcpy(or->course,p_course);
        }
        strcpy(or->student,p_student);
        or->grade=p_grade;
        or->compdate=p_compdate;
        return 1;
    }
    else
    {
        return 0;
    }

}
struct oodi *add_record(struct oodi *array, unsigned int size, struct oodi newrec)
{
    if(strlen(newrec.student)>6)
    {
        return NULL;
    }
    else
    {
        struct oodi *temp=NULL;
        temp=realloc(array,(size+1)*sizeof(struct oodi));
        if(temp==NULL)
        {
            free(array);
            return NULL;
        }
        else
        {
            array=temp;
            array[size].course = malloc(strlen(newrec.course) + 1);
            strcpy(array[size].course, newrec.course);
            strcpy(array[size].student,newrec.student);
            array[size].grade=newrec.grade;
            array[size].compdate=newrec.compdate;
            return array;
        }

    }

};
int change_grade(struct oodi *array, unsigned int size, const char *p_student,const char *p_course, unsigned char newgrade, struct date newdate)
{
    int i=0;
    int j=0;
    for(i=0;i<size;i++)
    {
        if(strcmp(array[i].student,p_student)==0 && strcmp(array[i].course,p_course)==0)
        {
            array[i].grade=newgrade;
            array[i].compdate=newdate;
            j=1;

        }
        continue;
    }
        if(j==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
}
int delete_array(struct oodi *array, unsigned int size)
{
    int i=0;
    for(i=0;i<size+1;i++)
    {
        free(array[i].course);
    }
    free(array);
    return 0;
}
int main()
{
    /* Feel free to modify
     * for example function for printing the current array content is useful */

    struct oodi antti;
    struct date anttidate = {24, 1, 2015};
    if (init_record(&antti, "123456", "ELEC-A7100", 4, anttidate )) {
        printf("Initialization succeeded\n");
    } else {
        printf("Initialization failed\n");
    }

    struct oodi students[] = {
        { "123456", "ELEC-A7110", 0, {1,1,2015} },
        { "555666", "ELEC-A7110", 2, {3,4,2015} },
        { "773466", "A little bit longer course name", 3, {31, 12, 2014} },
        { "234567", "Short", 5, {31, 12, 2014} }
    };

    struct oodi *array = NULL;
    unsigned int len = 0;
    for (unsigned int i = 0; i < sizeof(students) / sizeof(struct oodi); i++) {
        struct oodi *newarray = add_record(array, len, students[i]);
        if (!newarray) {
            delete_array(array, len);
            exit(EXIT_FAILURE);
        }
        len++;
        array = newarray;
    }

    struct date day1 = {20, 1, 2015};
    struct date day2 = {23, 2, 2016};
    if (!change_grade(array, len, "555666", "ELEC-A7110", 4, day1))
        printf("failed '555666'\n");
    if (!change_grade(array, len, "234567", "Short", 3, day2))
        printf("failed '234567'\n");
    if (!change_grade(array, len, "111111", "ELEC-A7110", 3, day2))
        printf("failed '111111'\n");
    if (!change_grade(array, len, "234567", "no course", 3, day2))
        printf("failed '234567', no course\n");

    delete_array(array, len);
    return 0;
}
