
/*
	Problem Statement:

	1. Assignment:
		Write a simple String class to do following operations:
			• Concatanation/Addition
			• Subtraction
			• Reversal
			• Search & replace
			• Comparison
	2 Additional Inputs:
		Write a simple String class to perform the operations on two strings.
		Take input strings from user.

	Date : 05/08/2023
	Author : Pravin Mhaske
*/

#include "stdafx.h"
#include "Util.h"
#include "String.h"

#include <iostream>

#include <vector>

void ShowOperationMenu()
{

}


int main()
{

	// Take the input form  the user in vector<char> for the testing purpose
	std::vector<char>input;

	// Get the input from the user
	std::cout<<"Please enter the string on which you want to perform the operations : ";
	Util::GetInputFromUser(input);

	// Print the user input
	Util::PrintUserInput(input);

	// Create the object of the string class
	String str(input);

	// Print the string by using the string object
	//std::cout<<"The string entered by the user from string object : ";
	//str.PrintString();
	//std::cout<<std::endl;

	int choice = -1;

	do{

		//---------------------------------------------------------------------
		std::cout<<"------------------ MENU --------------------"<<std::endl;
		std::cout<<" 0. Exit"<<std::endl;
		std::cout<<" 1. Concatenation of two strings. "<<std::endl;
		std::cout<<" 2. Reverse the string "<<std::endl;
		std::cout<<" 3. Find the string in the string "<<std::endl;
		std::cout<<" 4. Find and replace the string "<<std::endl;
		std::cout<<" 5. Substraction of two strings "<<std::endl;
		std::cout<<" 6. Comparison of two strings "<<std::endl;
		std::cout<<" 7. Length of the string"<<std::endl;
		std::cout<<" 8. Print the string."<<std::endl;
		std::cout<<"-------------------------------------------"<<std::endl;

		std::cout<<" Please select the proper operation : ";
		Util::getValidIntegerInput(choice);

		switch(choice)
		{

		case 0:
			{
				std::cout<<"Exiting...."<<std::endl;
				break;
			}

		case 1:
			{
				std::vector<char>input2;

				std::cout<<"Enter the string that you want to concatenate / Add : ";
				Util::GetInputFromUser(input2);

				// Create the string
				String str2(input2);

				// Now save the result of the concatenation in third string
				String str3 = str+str2;

				// Now print the string
				std::cout<<"The string after the addition of '";
				str.PrintString();
				std::cout<<"' and '";
				str2.PrintString();
				std::cout<<"' is '";
				str3.PrintString();
				std::cout<<"' ."<<std::endl;
				break;
			}

		case 2:
			{
				std::cout<<" 2. Reverse the string "<<std::endl;
				std::cout<<"The string before the reverse operation : ";
				str.PrintString();
				std::cout<<std::endl;

				str.Reverse();

				std::cout<<"The string after the reverse operation : ";
				str.PrintString();
				std::cout<<std::endl;
				break;
			}

		case 3:
			{
				std::cout<<" 3. Find the string in the string "<<std::endl;
				break;
			}

		case 4:
			{
				std::cout<<" 4. Find and replace the string "<<std::endl;
				break;
			}

		case 5:
			{
				std::cout<<" 5. Substraction of two strings "<<std::endl;
				break;
			}

		case 6:
			{
				std::cout<<" 5. Comparsion of two strings "<<std::endl;
				break;
			}

		case 7:
			{
				int lengthOfString = str.GetLength();
				std::cout<<"The length of the string '";

				// Call the function for the printing the string
				str.PrintString();

				std::cout<<"' is : "<<lengthOfString<<std::endl;
				break;
			}

		case 8:
			{
				std::cout<<"The string is : ";
				str.PrintString();
				std::cout<<std::endl;
				break;
			}

		default:
			{
				std::cout<<"Please enter the proper operation number from the above"<<std::endl;
			}
		}


	}while(choice!=0);


	return 0;
}