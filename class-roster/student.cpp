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
	cout << this->studentID << "\t" << "Fist Name: " << this->firstName << "\tLast Name: " << this->lastName;
	cout << "\tEmail Address: " << this->emailAddress << "\tAge: " << this->age << "\tDays to complete course: {";
	for (int i = 0; i < 3; ++i)
	{
		cout << this->daysToCourseCompletion[i];
		if (i < 2) cout << ", ";
	}
	cout << "} \tDegree Program: " << degreeFields[(int)this->degreeProgram] << endl;
	return;
}