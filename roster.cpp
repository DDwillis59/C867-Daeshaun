#include "roster.h"

#include <iostream>
#include <string>


void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degreeProgram){
  int daysArray[3] = {days1, days2, days3};

  classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);

}

void Roster::printAll(){
  for (int i =0; i <= lastIndex; i++){
    Roster::classRosterArray[i]->print();
  }
}

void Roster::printByDegree(DegreeProgram degreeProgram){
  for (int i =0; i <= lastIndex ; i++){
    if(classRosterArray[i]->getDegreeProgram() == degreeProgram){
      classRosterArray[i]->print();
    }
  }
}

void Roster::printInvalidEmails(){
  bool any = false;

  for (int i =0; i <= lastIndex; i++){

    std::string email = (classRosterArray[i]->getEmailAddress());
    if(email.find("@") == std::string::npos || email.find(" ") != std::string::npos || email.find(".") == std::string::npos){
      any = true;
      std::cout << email << "\t" << classRosterArray[i]->getFirstName() << "\n";
    }
  }

  if(!any){
    std::cout << "NO INVALID EMAILS" << "\n";
  }
}

void Roster::printCourseDayAverage(std::string studentID){
  for(int i = 0; i <= lastIndex; i++){
    if(classRosterArray[i]->getStudentId() == studentID){
      std::cout << studentID  << ":" ;
      std::cout << (classRosterArray[i]->getDays()[0]+classRosterArray[i]->getDays()[1]+classRosterArray[i]->getDays()[2])/3;
      std::cout << "\n";
    }
  }
}

bool Roster::removeStudent(std::string studentID){
  bool success = false;

  for(int i =0; i <= lastIndex; i++){
    if(classRosterArray[i]->getStudentId() == studentID){
      success = true;
      if(i < 4){
        Student* temp = classRosterArray[i];
        classRosterArray[i] = classRosterArray[4];
        classRosterArray[4] = temp;
      }
      lastIndex--;
    }
  }

  if(success){
    std::cout << "removed from roster." << "\n";
    this->printAll();
  }
  else std::cout << "not found." << "\n";;
  return 0;
  
}

void Roster::parse(std::string row){

  int right = row.find(',');
  std::string sID = row.substr(0,right);

  int left = right + 1;
  right = row.find(',',left);
  std::string studentFName = row.substr(left, right - left);

  left = right + 1;
  right = row.find(',', left);
  std::string studentLName = row.substr(left, right - left);
  
  left = right + 1; 
  right = row.find(",", left);
  std::string studentEmail = row.substr(left, right -left);
  
  left = right + 1;
  right = row.find(",", left);
  int studentAge = stoi(row.substr(left, right -left));
  
  left = right + 1;
  right = row.find(",", left);
  int d1 = stod(row.substr(left, right-left));
  
  left = right + 1;
  right = row.find(",", left);
  int d2 = stod(row.substr(left, right-left));
  
  left = right + 1;
  right = row.find(",", left);
  int d3 = stod(row.substr(left, right-left));
  
  left = right + 1;
  right = row.find(",", left);

  DegreeProgram degreeProgram  = SECURITY;
  
  if (row.at(left) == 'S' && row.at(left + 1) == 'E') degreeProgram = SECURITY;
  else if (row.at(left) == 'S' && row.at(left + 1) == 'O') degreeProgram = SOFTWARE;
  else if (row.at(left) == 'N') degreeProgram = NETWORK;
  
  add(sID, studentFName, studentLName, studentEmail, studentAge, d1, d2, d3, degreeProgram);
}

Roster::~Roster(){
  for (int i=0;i<studentData;i++){
    delete classRosterArray[i];
    classRosterArray[i] = nullptr;
  }
}