#include <iostream>
#include <vector>
#include <string>
#include "degree.h"
#include "student.h"
#include "securityStudent.h"
using namespace std;

Degree SecurityStudent::getDegreeProgram() {
	return degreeType;
}
