#ifndef UTIL_H
#define UTIL_H

#include <vector>

class Util{

public:

	// Function for the getting the input from the user
	static void GetInputFromUser(std::vector<char>&ch);

	// Function for the printing the user input
	static void PrintUserInput(const std::vector<char>&ch);

	// Function for the validation of the integer input
	static void getValidIntegerInput(int &number);
};


#endif //UTIL_H