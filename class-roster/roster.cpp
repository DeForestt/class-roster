#include "roster.h"
#include <string>
#include<algorithm>

Roster::Roster(const string studentData[])
{
	//initialize the class roster Array with nullptr
	for (int i = 0; i < 5; i++)
	{
		this->classRosterArray[i] = nullptr;
	}
	//Parse the pointer datta
	for (int i = 0; i < 5; i++)
	{
#pragma region Parse Data



		size_t rhs = studentData[i].find(",");
		string ID = studentData[i].substr(0, rhs);
		
		size_t lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string firstName = studentData[i].substr(lhs, rhs - lhs);

		size_t lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string lastName = studentData[i].substr(lhs, rhs - lhs);

		size_t lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string emailAddress = studentData[i].substr(lhs, rhs - lhs);

		size_t lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int age = stoi(studentData[i].substr(lhs, rhs - lhs));

		int daysToCompletion[3];
		for (int x = 0; x < 3; x++)
		{
			size_t lhs = rhs + 1;
			rhs = studentData[i].find(",", lhs);
			daysToCompletion[x] = stoi(studentData[i].substr(lhs, rhs - lhs));
		}


		degree degreeField = (degree)0;
		size_t lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string unparsedDegree = studentData[i].substr(lhs, rhs - lhs);
		for (int x = 0; x < 3; x++)
		{
			if (degreeFields[x] == unparsedDegree)
			{
				degreeField = degree(x);
			}
		}
#pragma endregion
		this->add(ID, firstName, lastName, emailAddress, age, daysToCompletion[0], daysToCompletion[1], daysToCompletion[2], degreeField);
	}
	return;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degree degreeprogram)
{
	//Scroll through the list of pointers filling the first instance of a nullptr with the new student;
	for (int i = 0; i < 5; i++)
	{

	}
}