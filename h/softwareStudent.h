#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include "student.h"
#include "degree.h"

class SoftwareStudent : public Student {

public:
	// each subclass should override the virtual getDegreeProgram()
	Degree getDegreeProgram();
	using Student::Student;

protected:
	Degree degreeType = SOFTWARE;
	
};

#endif
