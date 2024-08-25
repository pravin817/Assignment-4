#include "stdafx.h"

#include "Interface.h"
#include "Util.h"


//-----------------------------------------------------------------------------
// Function for getting the name of the student from the user
//-----------------------------------------------------------------------------

void Interface::GetNameOfStudentFromUser(std::string &nameOfStudent)
{
	std :: cin.ignore();
	std::cout<<"Please enter the name of the student : ";
	getline(std::cin,nameOfStudent);
}

//-----------------------------------------------------------------------------
// Function for getting the roll number of student from user
//-----------------------------------------------------------------------------
void Interface::GetRollNumberFromUser(int &rollNo)
{
	std::cout << "Enter the roll number of the student: ";
	std::cin >> rollNo;

	// Roll number must be greater than 1
	while (rollNo <= 0) {
		std::cout << "Invalid roll number. "
			<< "Please enter a roll number of student greater than 0 : ";
		std::cin >> rollNo;
	}
}

//-----------------------------------------------------------------------------
// Function for getting the marks obtained by student
//-----------------------------------------------------------------------------
void Interface::GetMarksFromUser(int &marksOfMarathi, 
	int &marksOfEnglish, 
	int &marksOfPhysics, 
	int &marksOfChemistry, 
	int &marksOfBiology, 
	int &marksOfMathematics)
{
	std::cout<<"Please enter the marks out of 100 for each subject : "
			 <<std::endl;

	std::cout << "Enter the marks of Marathi out of (100) : ";
	Util::ValidateMarks(marksOfMarathi);

	std::cout << "Enter the marks of English out of (100) : ";
	Util::ValidateMarks(marksOfEnglish);

	std::cout << "Enter the marks of Physics out of (100) : ";
	Util::ValidateMarks(marksOfPhysics);

	std::cout << "Enter the marks of Chemistry out of (100) : ";
	Util::ValidateMarks(marksOfChemistry);

	std::cout << "Enter the marks of Biology out of (100) : ";
	Util::ValidateMarks(marksOfBiology);

	std::cout << "Enter the marks of Mathematics out of (100) : ";
	Util::ValidateMarks(marksOfMathematics);
}