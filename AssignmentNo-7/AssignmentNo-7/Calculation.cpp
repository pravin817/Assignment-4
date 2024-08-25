#include "stdafx.h"

#include "Calculations.h"

#include <iomanip>
#include <cmath>  

//-----------------------------------------------------------------------------
// Function for the calculation of the total marks of a student.
//-----------------------------------------------------------------------------
int Calculation::CalculateTotalMarks(Student const *currentStudent)
{
	return currentStudent->GetMarksOfMarathi() 
		+ currentStudent->GetMarksOfEnglish()
		+ currentStudent->GetMarksOfPhysics()
		+ currentStudent->GetMarksOfChemistry()
		+ currentStudent->GetMarksOfBiology()
		+ currentStudent->GetMarksOfMathematics();
}

//-----------------------------------------------------------------------------
// Function for the calculation of the percentage of the student.
//-----------------------------------------------------------------------------
float Calculation::CalculatePercentage(int totalMarks, int totalSubjects)
{
	float percentageObtainedByStudent = 
		(static_cast<float>(totalMarks) / totalSubjects);

	// Return the result rounded to two decimal places
	return std::ceilf(percentageObtainedByStudent * 100) / 100;
}

//-----------------------------------------------------------------------------
// Function for the calculation of the grade based on the percentage.
//-----------------------------------------------------------------------------
char Calculation::CalculateGrade(float percentage)
{
	if (percentage >= 80 && percentage <= 100)
		return 'O';
	else if (percentage >= 70)
		return 'A';
	else if (percentage >= 60)
		return 'B';
	else if (percentage >= 55)
		return 'C';
	else if (percentage >= 50)
		return 'D';
	else if (percentage >= 40)
		return 'E';
	else if (percentage >= 0)
		return 'F';
	else 
		return 'Z'; // Handling any invalid percentage
}
