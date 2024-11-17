#include "student.h"
#include <string>
#include <iostream>

Student::~Student() {};


Student::Student()//parameterless constructor - sets to default values
{
    //(pointer_name)->(variable_name)
    this->studentID = "";//an empty string is not null
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < 3; i++) this->daysInCourse[i] = 0;//loops over array and sets default price to 0
    this->degreeProgram = DegreeProgram::SECURITY;//sets default degree type to software using value created in Degree.h
}

Student::Student(std::string id, std::string first, std::string last, std::string email, int ageValue, int course[],DegreeProgram degreeProgram) {
    this->studentID = id;
    this->firstName = first;
    this->lastName = last;
    this->emailAddress = email;
    this->age = ageValue;
    for (int i = 0; i < 3; i++){
        this->daysInCourse[i] = course[i];
    }
    this->degreeProgram = degreeProgram;

}

std::string Student::getFirstName() {
    return this->firstName;
}

std::string Student::getLastName() {
    return this->lastName;
}

std::string Student::getStudentId() {
    return this->studentID;
}

std::string Student::getEmailAddress() {
    return this->emailAddress;
}

int Student::getAge() {
    return this->age;
}

int* Student::getDays(){
    return this->daysInCourse;
}

DegreeProgram Student::getDegreeProgram(){
    return this->degreeProgram;
}



void Student::print(){
    std::cout << getStudentId() << "\t";
    std::cout << "First Name: " << firstName << "\t";
    std::cout << "Last Name: " << lastName << "\t";
    std::cout << "Age: " << age << "\t";
    std::cout << "Days in Course: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "} " << "\t";
    std::cout << "Degree Program: " << (degreeProgram == SECURITY ? "Security" : degreeProgram == NETWORK ? "Network" : "Software") << "\t" << "\n";
    
}


void Student::setStudentID(std::string id){
    studentID = id;
}

void Student::setFirstName(std::string first){
    firstName = first;
}

void Student::setLastName(std::string last){
    lastName = last;
}

void Student::setEmailAddress(std::string email){
    emailAddress = email;
}

void Student::setAge(int ageValue){
    age = ageValue;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram){
    this->degreeProgram = degreeProgram;
}
