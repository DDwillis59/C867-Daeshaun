#ifndef ROSTER_H
#define ROSTER_H

#include <string>

#include "student.h"


class Roster{
    public:
        int lastIndex = -1;
        const static int studentData = 5;
        void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degreeProgram);
        void remove(std::string studenID);
        ~Roster();

        void parse(std::string row);
        void printAll();
        void printByDegree(DegreeProgram degreeProgram);
        void printInvalidEmails();
        void printCourseDayAverage(std::string studentID);
        bool removeStudent(std::string studentID);


    public:
        Student* classRosterArray[studentData];
        

};

#endif