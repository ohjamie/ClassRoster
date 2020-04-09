#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include <vector>
#include "student.h"
#include "degree.h"
using namespace std;

const int numStudents = 5;

const string studentData[numStudents] = {
    "A1, John, Smith,John1989@gm ail.com, 20, 30, 35, 40,SECURITY",
    "A2, Suzan, Erickson,Erickson_1990@gmailcom, 19, 50, 30, 40,NETWORK",
    "A3, Jack, Napoli,The_lawyer99yahoo.com, 19, 20, 40, 33,SOFTWARE",
    "A4, Erin, Black,Erin.black@comcast.net, 22, 50, 58, 40,SECURITY",
    "A5, Jameelah, Okada,jokada@wgu.edu, 23, 30, 50, 60,SOFTWARE"
};

class Roster {
	
public:
    Roster();

	// holds data provided in student data table
	Student *classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};

    // sets instance variables from part D1 and updates the roster
	void add(string studentID,
             string firstName,
             string lastName,
             string email,
             int age,
             int daysToComplete1,
             int daysToComplete2,
             int daysToComplete3,
             Degree degreeType);

	// removes students from roster by student ID
	// if student ID does not exist, print error "Student not found"
	void remove (string studentID);

	void printAll();

	// print student's avg # of days in 3 courses, identified by student ID
	void printDaysInCourse(string studentID);

	// verifies student email addresses
	// print invalid email addresses to the user
	void printInvalidEmails();

	// print student info for degree program specified by enum type
	void printByDegreeProgram(Degree);
    
    ~Roster();
};

#endif
