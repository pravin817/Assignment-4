#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>

class Interface
{

public:

	// Function for getting the name of the student from the user
	static void GetNameOfStudentFromUser(std::string &nameOfStudent);

	// Function for getting the rollNumber from the user
	static void GetRollNumberFromUser(int &rollNo);

	// Function for getting the marks obtained by student
	static void GetMarksFromUser(int &marksOfMarathi, 
		int &marksOfEnglish, 
		int &marksOfPhysics, 
		int &marksOfChemistry, 
		int &marksOfBiology, 
		int &marksOfMathematics);
};

#endif  //INTERFACE_H