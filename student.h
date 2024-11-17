#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>


class Student {
public:
    Student();
    Student(std::string id, std::string first, std::string last, std::string email, int ageValue, int course[], DegreeProgram degreeProgram);

    std::string getFirstName();
    std::string getLastName();
    std::string getStudentId();
    std::string getEmailAddress();
    int getAge();
    int* getDays();
    DegreeProgram getDegreeProgram();

    void setStudentID(std::string id);
    void setFirstName(std::string first);
    void setLastName(std::string last);
    void setEmailAddress(std::string email);
    void setAge(int ageValue);
    void setDegreeProgram(DegreeProgram degreeProgram);
    ~Student();





    void print();



private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

};

#endif
