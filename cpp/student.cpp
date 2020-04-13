#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "student.h"
#include "degree.h"

using namespace std;

// constructor

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 1;
	this->daysToComplete = new int[numStudents];
    for(int i = 0; i < numStudents; i++) {
        this->daysToComplete[i] = 0;
    }
}

Student::Student(string ID, string firstName, string lastName, string email, int age, int daysToComplete[], Degree degreeType) {
	this->studentID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->daysToComplete = new int[numStudents]; // dynamically create new array, destructor MUST dispose of it
	for(int i = 0; i < numStudents; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
    this->degreeType = degreeType;
}

//mutators

void Student::setStudentID(string ID) {
	studentID = ID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmail(string email) {
 	this->email = email;
 }

void Student::setAge(int age) {
	this->age = age;
}

// to be safe, start with fresh array

void Student::setDaysToComplete(int daysToComplete[]) {

	if(this->daysToComplete != nullptr){ // if daysToComplete is pointing to something,
        delete[] this->daysToComplete;   // delete whatever it is
		this->daysToComplete = nullptr;  // then set it to nullptr
	}
	this->daysToComplete = new int[numStudents];
	for(int i = 0; i < numStudents; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}

}

//accessors

string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}
	
string Student::getLastName() {
	return lastName;
}
	
string Student::getEmail() {
	return email;
}

int Student::getAge() {
	return age;
}

int* Student::getDaysToComplete() {
	return daysToComplete;
}

void Student::print() {
    cout << left << setw(5) << studentID;
    cout << left << setw(10) << firstName;
    cout << left << setw(12) << lastName;
    cout << left << setw(26) << email;
    cout << left << setw(7) << age;
    cout << left << setw(7) << daysToComplete[0];
    cout << left << setw(7) << daysToComplete[1];
    cout << left << setw(7) << daysToComplete[2];
    if(degreeType == Degree::NETWORK) {
        cout << left << setw(10) << "NETWORK" << endl;
    }
    else if(degreeType == Degree::SECURITY) {
        cout << left << setw(10) << "SECURITY" << endl;
    }
    else if(degreeType == Degree::SOFTWARE) {
        cout << left << setw(10) << "SOFTWARE" << endl;
    }
}

// destructor
Student::~Student() {

	if (daysToComplete != nullptr) {
		delete[] daysToComplete;
		daysToComplete = nullptr;
    }

}
