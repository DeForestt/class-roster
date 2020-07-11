#include "Student.h"
#include <iostream>

Student::Student(string ID, string firstName, string lastName, string emailAddress, int age, int daysToCompletion[], degree degreeProgram)
{	
	for (int i = 0; i < 3; ++i)
		this->daysToCourseCompletion[i] = daysToCompletion[i];
	
	this->studentID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->degreeProgram = degreeProgram;
	return;
}

void Student::print() 
{
	cout << "Student ID: " << this->studentID << " | Fist Name: " << this->firstName << " | Last Name: " << this->lastName;
	cout << " | Email Address: " << this->emailAddress << " | Age: " << this->age << " | Days to complete course: ";
	for (int i = 0; i < 3; ++i)
	{
		cout << this->daysToCourseCompletion[i];
		if (i < 2) cout << ", ";
	}
	cout << " | Degree Program: " << degreeFields[(int)this->degreeProgram];
	return;
}