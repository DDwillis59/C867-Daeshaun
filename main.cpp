#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {

    std::cout <<"Course: C867 Scripting and Programming - Applications \n" << "Programming Language: C++ \n" << "ID: 012399678 \n" << "Name: Daeshaun Willis"  << std::endl;

    Roster classRoster;
    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Daeshaun,Willis,dwill196@wgu.edu,20,30,30,30,SOFTWARE"};
    for(int i =0;i < 5;i++) classRoster.parse(studentData[i]);


    classRoster.printAll();
    classRoster.printInvalidEmails();

    for(int i = 0; i < 5; i++){
        classRoster.printCourseDayAverage(classRoster.classRosterArray[i]->getStudentId());
    }

    classRoster.printByDegree(SOFTWARE);
    classRoster.removeStudent("A3");
    classRoster.printAll();
    classRoster.removeStudent("A3");



    return 0;
}
