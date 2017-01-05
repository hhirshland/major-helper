#ifndef COURSE_H
#define COURSE_H

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "simpio.h"

#include "lexicon.h"
#include "vector.h"
#include "shuffle.h"
#include "random.h"
#include "strlib.h"
#include "foreach.h"

using namespace std;

class Course
{
public:
    Course();

    /* Instantiates a new course, offered all 4 quarters */
    Course(string cName, int numUnits, string prof, string desc,
           string q1, string q2, string q3, string q4);

    /* Instantiates a new course, offered 3 quarters */
    Course(string cName, int numUnits, string prof, string desc,
           string q1, string q2, string q3);

    /* Instantiates a new course, offered 2 quarter */
    Course(string cName, int numUnits, string prof, string desc,
           string q1, string q2);

    /* Instantiates a new course, offered 1 quarter */
    Course(string cName, int numUnits, string prof, string desc,
           string q1);

    /* Returns the course units */
    int getCourseNumUnits();

    /* Returns the name of the course */
    string getCourseName();

    /*Returns the name of the course's proffesor */
    string getCourseProf();

    /* Returns the course's description */
    string getCourseDesc();

    /*Returns the quarters the course is offered */
    Set<string> getQuartersOffered();

    string getCourseShortDesc();

    void setCourseNumUnits(int u);
    void setCourseName(string c);
    void setCourseProf(string p);
    void setCourseDesc(string d);
    void setQuartersOffered(string q);
    void setCourseShortDesc(string s);

private:
    int courseNumUnits;
    string shortDesc;
    string courseName;
    string courseProf;
    string courseDesc;
    Set<string> quartersOffered;
};

#endif // COURSE_H
