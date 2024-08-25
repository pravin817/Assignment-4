#ifndef CALCULATION_H
#define CALCULATION_H

#include "Student.h"

class Calculation
{
public:

	// Function to get the total marks of the student
	static int CalculateTotalMarks(Student const *currentStudent);

	// Function to calculate the percentage of the student
	static float CalculatePercentage(int totalMarks, int totalSubjects);

	// Function to determine the grade for the student
	static char CalculateGrade(float percentage);

};

#endif  // CALCULATION_H