#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include "student.h"
#include "degree.h"

class NetworkStudent : public Student {

public:
	// each subclass should override the virtual getDegreeProgram()
	Degree getDegreeProgram();
	using Student::Student;

protected:
	Degree degreeType = NETWORK;
};

#endif
