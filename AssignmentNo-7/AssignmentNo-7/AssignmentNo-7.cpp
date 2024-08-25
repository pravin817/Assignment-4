/******************************************************************************
	STUDENT ASSIGNMENT
		Assignment 1
			Students results: Read student data from file, find averages of 
			marks and subject wise topper print on screen.

		Additional Inputs
			Create a text file having student data in rows and separated by 
			tabs (Name, subject, mark etc.) as input for this assignment.

		Assignment 2:
			Students results: 
			Search specific student, topper in specific subject etc based on
			menu.

		Additional Inputs
			Extend the assignment 1 to complete this.
			Take command line option from user to do specific tasks 
			(Ex, Find the student, topper etc.).

******************************************************************************/

#include "stdafx.h"

#include "Student.h"
#include "StudentManager.h"
#include "Interface.h"
#include "Util.h"
#include "Calculations.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	int standard = -1;

	std::cout<<" Please select the standard which student you want to manage "
			 <<std::endl;

	std::cout << " For class - 11 press (11) " <<std::endl;
	std::cout << " For class - 12 press (12) " <<std::endl;

	std::cout << "Please select the standard : "<<std::endl;

	std::cin >> standard;

	// Set the Filename 
	if( !(standard == 11 || standard == 12 ))
	{
		std::cout<<" Please select the correct standard."<<std::endl;
		std::cout<<" Exiting......"<<std::endl;
		return -1;
	}

	std::cout<<"The standard selected successfully."<<std::endl;

	StudentManager studentManager(standard);

	// Execute all operations
	studentManager.Execute();

	return 0;
}
