#include "stdafx.h"
#include "Validations.h"

#include <iostream>

//-----------------------------------------------------------------------------
// Function for validating integer input.
//-----------------------------------------------------------------------------
void Validations::ValidateIntegerInput(int &inputValue)
{
    while (true)
    {
        std::cin >> inputValue;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer: ";
        }
        else
        {
            break;
        }
    }
}

//-----------------------------------------------------------------------------
// Function for validating double input.
//-----------------------------------------------------------------------------
void Validations::ValidateDoubleInput(float &inputValue)
{
    while (true)
    {
        std::cin >> inputValue;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number: ";
        }
        else
        {
            break;
        }
    }
}
