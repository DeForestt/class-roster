#include "roster.h"
#include <string>
#include<algorithm>
#include<iostream>
#include<cstring>

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

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string lastName = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string emailAddress = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int age = stoi(studentData[i].substr(lhs, rhs - lhs));

		int daysToCompletion[3];
		for (int x = 0; x < 3; x++)
		{
			lhs = rhs + 1;
			rhs = studentData[i].find(",", lhs);
			daysToCompletion[x] = stoi(studentData[i].substr(lhs, rhs - lhs));
		}


		degree degreeField = (degree)0;
		lhs = rhs + 1;
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

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degree degreeProgram)
{
	//Scroll through the list of pointers filling the first instance of a nullptr with the new student;
	for (int i = 0; i < 5; i++)
	{
		if (this->classRosterArray[i] == nullptr)
		{
			int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3};
			this->classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
			cout << "New Student Added!!!" << endl;
			return;
		}
	}
	return;
}

void Roster::printAll()
{
	for (size_t i = 0; i < 5; i++)
	{
		if (this->classRosterArray[i] !=  nullptr)
		this->classRosterArray[i]->print();
	}
}

void Roster::remove(string ID)
{
	try
	{
		for (size_t i = 0; i < 6; i++)
		{
			if (i == 5)
			{
				throw 50;
				break;
			}
			else if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->GetStudentID() == ID)
			{
				this->classRosterArray[i] = nullptr;
				break;
			}
		}
	}
	catch(int e)
	{
		cout << "No student with the id " << ID << endl;
	}
	return;
}

void Roster::printAverageDaysInCourse(string ID)
{
	try
	{
		for (size_t i = 0; i < 6; i++)
		{
			if (i == 5)
			{
				throw 50;
				break;
			}
			else if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->GetStudentID() == ID)
			{
				double sum = 0.0;
				for (size_t i = 0; i < 3; i++)
				{
					sum += this->classRosterArray[i]->GetDaysToCourseCompletion()[i];
				}
				double avg = sum / 3;
				cout << "AVG time in course: " << avg << endl;
				break;
			}
		}
	}
	catch (int e)
	{
		if (e == 50)
		{
			cout << "No student with the id " << ID << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	for (size_t i = 0; i < 5; i++)
	{
		char atSymbol = '@';
		char dotSymbol = '.';
		char space = ' ';
		if (this->classRosterArray[i] != nullptr)
		{
			const char* checkAt = nullptr;
			const char* checkDot = nullptr;
			const char* checkSpace = nullptr;
			string emailAddress = this->classRosterArray[i]->GetEmailAddress();

			emailAddress.c_str();

			checkAt = strchr(emailAddress.c_str(), atSymbol);
			checkSpace = strchr(emailAddress.c_str(), space);
			checkDot = strchr(emailAddress.c_str(), dotSymbol);

			if (checkAt == nullptr || checkDot == nullptr || checkSpace != nullptr)
			{
				cout << emailAddress;
			}
		}
	}
}