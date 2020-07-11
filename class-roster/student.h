#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student
{
public:
	Student(string ID, string firstName, string lastName, string emailAddress, int age,int daysToCompletion[], degree degreeProgram);
	void print();

#pragma region  Accessors
	const char * GetStudentID()
	{
		return this->studentID;
	}
	const string GetFirstName()
	{
		return this->firstName;
	}
	const string GetLastName()
	{
		return this->lastName;
	}
	const string GetEmailAddress()
	{
		return this->emailAddress;
	}
	const int GetAge()
	{
		return this->age;
	}
	const int * GetDaysToCourseCompletion()
	{
		return this->daysToCourseCompletion;
	}
	const degree GetDegreeProgram()
	{
		return this->degreeProgram;
	}
#pragma endregion

#pragma region Mutators
	void SetStudentID(int index, char value)
	{
		this->studentID[index] = value;
		return;
	}
	void SetFirstName(string value)
	{
		this->firstName = value;
		return;
	}
	void SetLastName(string value)
	{
		this->lastName = value;
		return;
	}
	void SetEmailAddress(string value)
	{
		this->emailAddress = value;
		return;
	}
	void SetAge(int value)
	{
		this->age = value;
		return;
	}
	void SetDaysToCourseCompletion(int index, int value)
	{
		this->daysToCourseCompletion[index] = value;
		return;
	}
	void SetDegreeProgram(degree value)
	{
		this->degreeProgram = value;
		return;
	}
#pragma endregion


private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToCourseCompletion[3] = {-1, -1, -1};
	degree degreeProgram;
};

