#include "course.h"

Course::Course() {
    courseName = "";
    courseNumUnits = 0;
    courseProf = "";
    courseDesc ="";
}

/* Instantiates a new course, offered all 4 quarters */
Course::Course(string cName, int numUnits, string prof, string desc,
               string q1, string q2, string q3, string q4) {
    courseName = cName;
    courseNumUnits = numUnits;
    courseProf = prof;
    courseDesc = desc;
    quartersOffered.add(q1);
    quartersOffered.add(q2);
    quartersOffered.add(q3);
    quartersOffered.add(q4);

}

/* Instantiates a new course, offered 3 quarters */
Course::Course(string cName, int numUnits, string prof, string desc,
               string q1, string q2, string q3) {
    courseName = cName;
    courseNumUnits = numUnits;
    courseProf = prof;
    courseDesc = desc;
    quartersOffered.add(q1);
    quartersOffered.add(q2);
    quartersOffered.add(q3);

}

/* Instantiates a new course, offered 2 quarter */
Course::Course(string cName, int numUnits, string prof, string desc,
               string q1, string q2) {
    courseName = cName;
    courseNumUnits = numUnits;
    courseProf = prof;
    courseDesc = desc;
    quartersOffered.add(q1);
    quartersOffered.add(q2);


}

/* Instantiates a new course, offered 1 quarter */
Course::Course(string cName, int numUnits, string prof, string desc, string q1) {
    courseName = cName;
    courseNumUnits = numUnits;
    courseProf = prof;
    courseDesc = desc;
    quartersOffered.add(q1);

}

/* Returns the course units */
int Course::getCourseNumUnits() {
    return courseNumUnits;
}

/* Returns the name of the course */
string Course::getCourseName() {
    return courseName;
}

/*Returns the name of the course's proffesor */
string Course::getCourseProf() {
    return courseProf;
}

/* Returns the course's description */
string Course::getCourseDesc() {
    return courseDesc;
}

string Course::getCourseShortDesc() {
    return shortDesc;
}

/*Returns the quarters the course is offered */

Set<string> Course::getQuartersOffered() {
    return quartersOffered;
}

void Course::setCourseShortDesc(string s) {
    shortDesc = s;
}

void Course::setCourseNumUnits(int u) {
    courseNumUnits = u;
}

void Course::setCourseName(string c) {
    courseName = c;
}

void Course::setCourseProf(string p) {
    courseProf = p;
}

void Course::setCourseDesc(string d) {
    courseDesc += d;
}

void Course::setQuartersOffered(string q) {
    quartersOffered.add(q);
}
