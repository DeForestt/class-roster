#pragma once
#include "student.h"
class Roster
{
public:
	Roster(const string studentData[]);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degree degreeprogram);
	void remove(string ID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(degree degreeProgram);
private:
	Student* classRosterArray[5];
};

