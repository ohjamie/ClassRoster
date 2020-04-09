#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "degree.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"
using namespace std;

int main() {

	// 1. via functions declared, print out your course title, 
	// programming language used, your student ID, and your name
	cout << "Greetings! C867 Scripting and Programming - Applications" << endl;
	cout << "Programming language used: C++" << endl;
	cout << "Project by Jameelah Okada, student ID #687956" << endl;
	cout << endl;

	// 2. create an instance of the roster class called classRoster
	Roster classRoster;

	// 3. add each student to classRoster
    int i = 0;
    for (i = 0; i < numStudents; i++){
        string line;
        string token;
        string temp[9];
        
        line = studentData[i];
        stringstream ss(line);
        
        int x = 0;
         while (getline(ss, token, ',')) {          // use comma as delimiter
            temp[x] = token;                        // store in temp
            ++x;
         }
         Degree studentMajor;
         if (temp[8] == "NETWORK") {
            studentMajor = Degree::NETWORK;
         }
         else if (temp[8] == "SECURITY") {
            studentMajor = Degree::SECURITY;
         }
         else {
             studentMajor = Degree::SOFTWARE;
         }
        
         classRoster.add(temp[0], temp[1], temp[2], temp[3], 
                         stoi(temp[4]), stoi(temp[5]), stoi(temp[6]), stoi(temp[7]), studentMajor);

    }

	// 4. Covert the following pseudo code to complete
    cout << left << setw(5) << "ID#";
    cout << left << setw(22) << " NAME";
    cout << left << setw(26) << "E-MAIL";
    cout << left << setw(7) << "AGE";
    cout << left << setw(21) << "DAYS IN COURSES";
    cout << left << setw(10) << "DEGREE" << endl;
    classRoster.printAll();
    cout << endl;
    
    cout << "Invalid e-mails:" << endl;
	classRoster.printInvalidEmails();
    cout << endl;

 	// loop through classRosterArray and for each element:
    // then calculate average number of days in course
    cout << "Students' average number of days for three courses:" << endl;
    for (int i = 0; i < numStudents; i++) {
        string studentID = classRoster.classRosterArray[i]->getStudentID();
        classRoster.printDaysInCourse(studentID);
    }
    cout << endl;
    
    cout << "Print student by degree program: SOFTWARE" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    
    cout << "Removing Student #A3... " << endl;
 	classRoster.remove("A3");
    classRoster.printAll();
    cout << endl;
    
    cout << "Removing Student #A3 (again)... " << endl;
    classRoster.remove("A3");
    cout << endl;
    // expected: the above line should print a message saying
	// such a student with this ID was not found.
    
	// 5. Call the destructor!!!!
    classRoster.~Roster();
    
return 0;
}

// defining functions

Roster::Roster() {}

// sets the instance variables and updates the roster

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, Degree degreeType) {
    
    int daysToComplete[3] = { daysToComplete1, daysToComplete2, daysToComplete3 };
    
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i] == nullptr) {
            if (degreeType == Degree::NETWORK) {
                classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, email, age, daysToComplete, degreeType);
            }
            else if (degreeType == Degree::SECURITY) {
                classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, email, age, daysToComplete, degreeType);
            }
            else if (degreeType == Degree::SOFTWARE) {
                classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, email, age, daysToComplete, degreeType);
            }
            break;
        }
    }
}

// removes students from roster by student ID
// if student ID does not exist, print error "Student not  found"
void Roster::remove(string studentID) {
    bool removeStudent = false;
    
    for (int i = 0; i < numStudents; i++) {
        if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getStudentID() == studentID)) {
            classRosterArray[i] = nullptr;
            removeStudent = true;
            break;
        }
    }
    
    if (removeStudent == false) {
        cout << "Student #" << studentID << " not found." << endl;
    }
}


void Roster::printAll() {
    int i = 0;
    for (i = 0; i < numStudents; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
        else if (classRosterArray[i] == nullptr) {                          // if index is null
            classRosterArray[i] = classRosterArray[numStudents - 1];        // replace with last index
            int x = 0;
            for(x = i; x < numStudents - 3; x++) {
                classRosterArray[x]->print();                               // do not print last student
            }
        }
    }
}

// print student's avg # of days in 3 courses, identified by student ID
void Roster::printDaysInCourse(string studentID) {
    int x = 0; // average number of days
    int y = 3; // max
    int i = 0; // loop through students
    for (i = 0; i < numStudents; i++) {
        if(classRosterArray[i]->getStudentID() == studentID) {
            int* daysToComplete = classRosterArray[i]->getDaysToComplete();
            int z = 0;
            for (z = 0; z < y; z++) {
                x += daysToComplete[z];
            }
            cout << classRosterArray[i]->getStudentID() << " = " << (x/y) << endl;
            break;
        }
    }
}

// verifies student email addresses
// print invalid email addresses to the user
void Roster::printInvalidEmails() {
    int i = 0;
    for (i = 0; i < numStudents; i++) {
        
        string email = classRosterArray[i]->getEmail();
        bool validEmail = false;
        size_t found;
        
        found = email.find('@');
        if (found != string::npos) {
            validEmail = true;
            found = email.find('.');
            if (found != string::npos) {
                validEmail = true;
        }
        else {
            validEmail = false;
            }
        }
        
        found = email.find(' ');
        if (found != string::npos) {
            validEmail = false;
        }
        
        if (validEmail != true) {
            cout << email << " is not a valid email address." << endl;
        }
    }
}

// print student info for degree program specified by enum type
void Roster::printByDegreeProgram(Degree degreeType) {
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeType) {
            classRosterArray[i]->print();
        }
    }
}

Roster::~Roster() {}
