#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include "student.h"
#include "degree.h"

class SecurityStudent : public Student {

public:
	// each subclass should override the virtual getDegreeProgram()
	Degree getDegreeProgram();
	using Student::Student;

protected:
	Degree degreeType = SECURITY;
};

#endif
