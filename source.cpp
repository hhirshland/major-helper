
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
#include "simpio.h"
#include "vector.h"
#include "queue.h"
#include "strlib.h"

#include "error.h"
#include "map.h"
#include "basicgraph.h"
#include "graph.h"


#include "course.h"

using namespace std;

static void manualReadInCourseData(ifstream &infile, Map<string, Course> &stanfordCourses, Vector<string> &courseTitles);
static void manualReadInTakenClasses(Map<string, Course> &stanfordCourses, Grid<Vector<Course> > &fourYearSchedule, Vector<Course> &coursesTaken);
static void outputFourYearPlan(Grid<Vector<Course> > &fourYearSchedule);
static void outputGersNeeded(Vector<Course> coursesTaken);

int main() {
    /*
     * LAYOUT:
     * 1. Read in data: read in a data file of all classes available at stanford
     * store the courses in a data structure (FIGURE OUT WHAT KIND -- maybe a map?)
     * when reading in... if terms aren't given this year, move on to the next...
     *
     * 2. Read in data: read in data file with all info regarding majors and their requirements
     * Store them in a data structure (maybe a vector or something?)
     *
     * 3. **MIGHT WANT TO MAKE CLASS FOR STUDENT**
     * get all relevant user information to make new instance of student class for them
     * name, year, major?, classes taken?,
     *
     * 4. Output data: start by laying out a schedule of their 4 year plan, with the classes they have
     * already taken filled into that schedule.  Next, lay out list of all the required courses in the
     *  major they chose (highlighting the ones they have already taken vs. need to take still).
     *
     * 5. Let them fill in the rest of the requirements into their schedule, and/or auto-generate a
     * full 4 year plan that will fullful the major requirements... (maybe ask them to choose when there
     * are multiple options for a specific requirement?
     */


    //DEMO (figuring out stuff
    //READING IN FILES!

    /* Data structure used to store all available Stanford courses */
    Map<string,Course> stanfordCourses;

    /* Data structure used to store the course titles that provide the
     * keys to the map of Courses */
    Vector<string> courseTitles;
    Vector<Course> coursesTaken;
    Grid<Vector<Course> > fourYearSchedule(4,4);
    /* Reads in the file that contains the courses*/
    ifstream infile;
    infile.open("StanfordCourseList.txt");
    manualReadInCourseData(infile, stanfordCourses, courseTitles);
    infile.close();
    manualReadInTakenClasses(stanfordCourses, fourYearSchedule, coursesTaken);
    outputFourYearPlan(fourYearSchedule);
    outputGersNeeded(coursesTaken);
    return 0;


}

static void outputGersNeeded(Vector<Course> coursesTaken) {
    Map<string, bool> gersCompleted;
    gersCompleted.put("WAY-A-II", false);
    gersCompleted.put("WAY-AQR", false);
    gersCompleted.put("WAY-CE", false);
    gersCompleted.put("WAY-ED", false);
    gersCompleted.put("WAY-ER", false);
    gersCompleted.put("WAY-FR", false);
    gersCompleted.put("WAY-SI", false);
    gersCompleted.put("WAY-SMA", false);


    for(int h = 0; h < coursesTaken.size(); h++) {

        /* Set of each course takens GERs */
        Vector<string> courseGers = coursesTaken[h].getCourseGers();

        //cout << courseGers << endl;

        for(int w = 0; w < courseGers.size(); w++) {
            //cout << courseGers[w] << endl;
            //cout << "WAY-FR" << endl;
            gersCompleted.put(courseGers[w], true);
            //cout << boolToString(gersCompleted["WAY-FR"]) << endl;
            //if("WAY-FR" == courseGers[w]) cout << "ok" << endl;

            //if(gersCompleted.containsKey(courseGers[w])) {
                //if(gersCompleted[courseGers[w]]) {
                //cout << courseGers[w] << "WTF" << endl;
                //}
            //}
        }




    }
    cout << "GERs Remaining:" << endl;

    //cout << boolToString(gersCompleted["WAY-FR"]) << endl;
    if(!gersCompleted.get("WAY-A-II")) {
        cout << "WAY-A-II" << endl;
    }

    if(!gersCompleted.get("WAY-AQR")) {
        cout << "WAY-AQR" << endl;
    }
    if(!gersCompleted.get("WAY-CE")) {
        cout << "WAY-CE" << endl;
    }
    if(!gersCompleted.get("WAY-ED")) {
        cout << "WAY-ED" << endl;
    }
    if(!gersCompleted.get("WAY-ER")) {
        cout << "WAY-ER" << endl;
    }
    if(!gersCompleted["WAY-FR"]) {
        cout << "WAY-FR" << endl;
    }
    if(!gersCompleted.get("WAY-SI")) {
        cout << "WAY-SI" << endl;
    }
    if(!gersCompleted.get("WAY-SMA")) {
        cout << "WAY-SMA" << endl;
    }

//    Vector<string> stanfordGers;
//    stanfordGers.add("WAY-AII");
//    stanfordGers.add("WAY-AQR");
//    stanfordGers.add("WAY-CE");
//    stanfordGers.add("WAY-ED");
//    stanfordGers.add("WAY-ER");
//    stanfordGers.add("WAY-FR");
//    stanfordGers.add("WAY-SI");
//    stanfordGers.add("WAY-SMA");


}

//loops through the 4 year schedule, outpitting all the inputted classes
static void outputFourYearPlan(Grid<Vector<Course> > &fourYearSchedule) {
    for (int y = 0; y <= 3; y++) {
        if (y == 0) cout << "Freshman Year: " << endl;
        if (y == 1) cout << "Sophomore Year: " << endl;
        if (y == 2) cout << "Junior Year: " << endl;
        if (y == 3) cout << "Senior Year: " << endl;
        //cout << "Year: " << y << endl;
        for (int x = 0; x <= 3; x++) {
            if (x == 0) cout << "Autumn Quarter: " << endl;
            if (x == 1) cout << "Winter Quarter: " << endl;
            if (x == 2) cout << "Spring Quarter: " << endl;
            if (x == 3) cout << "Summer Quarter: " << endl;
            //cout << "Quarter: " << x << endl;
            Vector<Course> temp;
            temp = fourYearSchedule[y][x];
            for(int i= 0; i < temp.size(); i++) {
                cout << temp[i].getCourseName() << endl;
                cout << temp[i].getCourseGers() << endl;
            }
        }
        cout << "" << endl;
    }
}


static void manualReadInTakenClasses(Map<string, Course> &stanfordCourses, Grid<Vector<Course> > &fourYearSchedule, Vector<Course> &coursesTaken) {
    string newLine;
    int year;
    int quarter;
    Course currentCourse;
    Vector<Course> currentVector;
    while(true) {
        Vector<Course> oldVector;
        newLine = getLine("Enter Course taken: ");
        if(newLine == "") break;
        newLine = toUpperCase(newLine);
        currentCourse = stanfordCourses[newLine];
        year = getInteger("Enter the school year you took this course (0-3): ");
        quarter = getInteger("Enter the quarter you took this course: ");
        coursesTaken.add(currentCourse);
        oldVector = fourYearSchedule[year][quarter];
        oldVector.add(currentCourse);
        cout << year << quarter << endl;
        (fourYearSchedule[year][quarter]);
        fourYearSchedule.set(year, quarter, oldVector);
    }


    for(int i = 0; i < coursesTaken.size(); i++) {
        //setConsoleFont("Sans-Bold-24");
        cout << "Course: " << coursesTaken[i].getCourseName() << endl;
        cout << "Short Desc: " << coursesTaken[i].getCourseShortDesc() << endl;
        setConsoleFont("Sans-14");
        cout << "Description: " << coursesTaken[i].getCourseDesc() << endl;
        cout << "Number of units: " << coursesTaken[i].getCourseNumUnits() << endl;
        cout << "Proffesor(s): " << coursesTaken[i].getCourseProf() << endl;
        cout << "Quarters offered: " << coursesTaken[i].getQuartersOffered() << endl;
        cout << "" << endl;
        cout << "" << endl;

    }
}






static void manualReadInCourseData(ifstream &infile, Map<string, Course> &stanfordCourses, Vector<string> &courseTitles) {
    string currentLine;
    Vector<string> splitString;
    Queue<string> inputtedData;
    string line;


    while(getline(infile, line)) {
        inputtedData.enqueue(line);
    }



    /* This loop iterates through all of the data that was taken from the text file
 * And stored into the queue, and sorts it into Course data structures, which
 * are then stored in a map. */
    while(!inputtedData.isEmpty()) {
        Course currCourse;
        string desc;

        /* Should be the course title, start by storing title in course structure */
        currentLine = inputtedData.dequeue();
        splitString = stringSplit(currentLine, ": ");


        currCourse.setCourseName(splitString[0]);
        courseTitles.add(splitString[0]);
        currCourse.setCourseShortDesc(splitString[1]);

        /* gets course description and stores it in course structure */
        currentLine =inputtedData.dequeue();

        /* Continues reading in the description until it is done, signaled by endcase.
     * endcase: currentLine will be line starting with Terms:, letting us know
     * to move from storing the description to storing the quarters offered */
        while(!startsWith(currentLine, "Terms: ")) {

            desc += currentLine;
            currentLine = inputtedData.dequeue();
        }
        currCourse.setCourseDesc(desc);

        /* splitString is the one with terms and units */
        splitString = stringSplit(currentLine, "|");

        /* Checks if class satisfies any GER requirements */
        if(stringContains(splitString[2], "GER")) {
            //cout << splitString[2] << endl;



            /* Parsing the GERs into vector gerVector, and adding each GER to the course.  */
            if(stringContains(splitString[2], "GER")) {
                //cout << splitString[2] << endl;
                Vector<string> gerString;
                gerString = stringSplit(splitString[2],":");
                //cout << gerString << endl;
                Vector<string> gerVector;
                gerVector= stringSplit(gerString[2], ", ");
                for(int v = 0; v < gerVector.size(); v++) {
                    //cout << gerVector[v] << endl;
                }
                currCourse.setCourseGER(gerVector);

            }

            //TO IMPLEMENT, check which GERs are satisfied, and if class is taken then change that GER to completed
        }
        /* finding the number of units the course is worth... automatically picks
     * highest possible unit value */
        if(stringContains(splitString[1], "1")) {
            currCourse.setCourseNumUnits(1);
        }
        if(stringContains(splitString[1], "2")) {
            currCourse.setCourseNumUnits(2);
        }
        if(stringContains(splitString[1], "3")) {
            currCourse.setCourseNumUnits(3);
        }
        if(stringContains(splitString[1], "4")) {
            currCourse.setCourseNumUnits(4);
        }
        if(stringContains(splitString[1], "5")) {
            currCourse.setCourseNumUnits(5);
        }


        /* finding the terms offered, adding each to the course data */
        if(stringContains(splitString[0], "not given this year") ||
                !stringContains(splitString[0], "offered occasionally")) {
            stanfordCourses.add(currCourse.getCourseName(), currCourse);
        }
        if(stringContains(splitString[0], "Aut")) {
            currCourse.setQuartersOffered("Aut");
        }
        if(stringContains(splitString[0], "Win")) {
            currCourse.setQuartersOffered("Win");
        }
        if(stringContains(splitString[0], "Spr")) {
            currCourse.setQuartersOffered("Spr");
        }
        if(stringContains(splitString[0], "Sum")) {
            currCourse.setQuartersOffered("Sum");
        }


        /* get instructors of course.  Start by seeing if there is an instructors line
     * If so, add the proffesors from the line into the course data */
        if(stringContains(inputtedData.peek(), "Instructors:")) {
            currentLine = inputtedData.dequeue();
            currCourse.setCourseProf(currentLine.substr(12));
        }

        /* Check to see if there is the extra "schedule" line, if so skip over it before
     * reitering to the next course so the information of next course is properly formatted */
        if(stringContains(inputtedData.peek(), "Schedule for")) {
            currentLine = inputtedData.dequeue();
        }

        /* adds the new course to the map with the key being the course name, and the value
     * being the course structure */
        stanfordCourses.add(currCourse.getCourseName(), currCourse);

    }
}


/* Outputs all the courses, with their descriptions, units, proffesors, and quarters offered */
//    for(int i = 0; i < courseTitles.size(); i++) {
//        //setConsoleFont("Sans-Bold-24");
//        cout << "Course: " << courseTitles[i] << endl;
//        cout << "Short Desc: " << (stanfordCourses.get(courseTitles[i])).getCourseShortDesc() << endl;
//        setConsoleFont("Sans-14");
//        cout << "Description: " << (stanfordCourses.get(courseTitles[i])).getCourseDesc() << endl;
//        cout << "Number of units: " << (stanfordCourses.get(courseTitles[i])).getCourseNumUnits() << endl;
//        cout << "Proffesor(s): " << (stanfordCourses.get(courseTitles[i])).getCourseProf() << endl;
//        cout << "Quarters offered: " << (stanfordCourses.get(courseTitles[i])).getQuartersOffered() << endl;
//        cout << "" << endl;
//        cout << "" << endl;

//    }
