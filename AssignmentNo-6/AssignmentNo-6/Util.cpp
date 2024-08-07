
#include "stdafx.h"

#include "Util.h"

#include <string>
#include <iostream>
#include <vector>

//-----------------------------------------------------------------------------
// Function for the getting the input from the user
void Util::GetInputFromUser(std::vector<char>&input)
{

	// *****************************************************************
	// Question : As we know that we need the initialisesed the variable when we declare it.
	// but in this case all the charactersa are validmeans they can be the part of the string.

	//std::cin.clear();
	//std::cin.ignore();


	char ch = ' ';
	
	
	//// cin function ignore the white space character hence not recommended to use this in this senario
	//std::cin.get(ch);

	std::cin.get(ch);

	// Take the input until we hit the new line character
	while(ch!='\n')
	{
		input.push_back(ch);
		
		// cin.get(ch) reads exactly one character, even if it's whitespace. 
		// It's useful when you need to capture all characters, 
		// including spaces and newline characters.
		std::cin.get(ch);
	}
}

//-----------------------------------------------------------------------------
// Function used for the printing the input entered by the user (Test Program);
void Util::PrintUserInput(const std::vector<char>&input)
{
	int stringLength = input.size();

	std::cout<<"Printing the string entered by user: ";
	
	for(int i = 0; i< stringLength ; ++i){
		std::cout<<input[i];
	}

	std::cout<<std::endl;
}

//-----------------------------------------------------------------------------
// Function for the getting the valid interger input
void Util::getValidIntegerInput(int &number)
{
	std::string input;
	while (true)
	{
		getline(std::cin, input); // Read the entire input line
		bool isValid = true;

		int inputLength = input.length();
		// Check if the input consists only of digits
		for (int i = 0; i < inputLength; ++i)
		{
			if (!isdigit(input[i])) 
			{
				isValid = false;
				break;
			}
		}

		// Check if input is valid and convert to number
		// Now convert the string to the valid number.
		// 1. String must contains atleast one digit. means the string must not be empty
		// 2. String must be valid means it doesn't contains any character other than numberic character.

		if (isValid && !input.empty())
		{
			// While converting the string to the number if it gets the expections handle it.
			try
			{
				number = stoi(input);
				break;
			}
			catch (const std::out_of_range& e)
			{
				std::cout << "Input is too large. Please enter a valid number: ";
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << "Invalid input. Please enter a valid number: ";
			}
		}
		else
		{
			std::cout << "Invalid input. Please enter a valid integer number: ";
		}
	}
}
