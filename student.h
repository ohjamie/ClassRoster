#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <vector>
#include "degree.h"
using namespace std;

class Student {

protected:
	string studentID;
    string firstName;
    string lastName;
	string email;
	int age;
	int* daysToComplete;
	Degree degreeType;

public:
    const int numStudents = 5;
    
    //constructors
	Student();
	Student(string ID, string firstName, string lastName, string email, int age, int daysToComplete[], Degree degreeType);

	//mutators, setters 8.4

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToComplete(int daysToComplete[]); 
	void setDegreeProgram(Degree degreeType);

	//accessors, getters 8.4

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToComplete();
    virtual Degree getDegreeProgram() = 0; // leave empty

	// to print specific student data
	virtual void print();

	// destructor
	~Student();

};

#endif
