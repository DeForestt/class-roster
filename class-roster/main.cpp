// class-roster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"

using namespace std;

const string studentData[] = { "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,DeForestt,Thompson,dtho607@wgu.edu],22, 10,20,14,SOFTWARE" };

int main()
{
    cout << "\t\t\t\tDeForestt Thompson\tWGU\t##########";
    Roster* classRoster = new Roster(studentData);
    classRoster->printAll();
    classRoster->printInvalidEmails();

    for (size_t i = 0; i < 5; i++)
    {
        string id = "A";
        id.append(to_string(i));
        classRoster->printAverageDaysInCourse(id);
    }

    classRoster->printByDegreeProgram(degree::SOFTWARE);

    classRoster->remove("A3");

    classRoster->printAll();

    classRoster->remove("A3");

    delete classRoster;
    return 0;
}