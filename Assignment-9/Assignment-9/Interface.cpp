#include "stdafx.h"
#include "Interface.h"
#include <iostream>
#include <limits>

//-------------------------------------------------------------------------
// Function for getting the choice from the user
void Interface::GetChoiceFromUser(int &choice)
{
    std::cout << "Enter your choice: ";
    while (!(std::cin >> choice) || choice < 1)
    {
        std::cout << "Invalid input. Please enter a positive integer: ";
        std::cin.clear(); // clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }
}

//-------------------------------------------------------------------------
// Function that takes the attributes of the product from the user
void Interface::GetProductAttributesFromUser(std::string &productName, 
    float &productPrice, 
    std::string &productCategory, 
    std::string &productManufacturer, 
    int &maxProductHoldingCapacity,
    int &productQuantity, 
    std::string &unitOfMeasure, 
    int &minimumThreshold)
{
    std::cout << "Enter product name: ";
    std::cin.ignore(); // to ignore any remaining newline character from previous input
    std::getline(std::cin, productName);

    std::cout << "Enter product price: ";
    while (!(std::cin >> productPrice) || productPrice < 0)
    {
        std::cout << "Invalid price. Please enter a positive number: ";
        std::cin.clear(); // clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }

    std::cout << "Enter product category: ";
    std::cin.ignore();
    std::getline(std::cin, productCategory);

    std::cout << "Enter product manufacturer: ";
    std::getline(std::cin, productManufacturer);

    std::cout << "Enter max product holding capacity: ";
    while (!(std::cin >> maxProductHoldingCapacity) || maxProductHoldingCapacity < 0)
    {
        std::cout << "Invalid capacity. Please enter a positive integer: ";
        std::cin.clear(); // clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }

    std::cout << "Enter product quantity: ";
    while (!(std::cin >> productQuantity) || productQuantity < 0)
    {
        std::cout << "Invalid quantity. Please enter a positive integer: ";
        std::cin.clear(); // clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }

    std::cout << "Enter unit of measure: ";
    std::cin.ignore();
    std::getline(std::cin, unitOfMeasure);

    std::cout << "Enter minimum threshold: ";
    while (!(std::cin >> minimumThreshold) || minimumThreshold < 0)
    {
        std::cout << "Invalid threshold. Please enter a positive integer: ";
        std::cin.clear(); // clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }
}

//-------------------------------------------------------------------------
// Overloaded function that takes the attributes of the product from the user
void Interface::GetProductAttributesFromUser(std::string &productName, 
    float &productPrice, 
    std::string &productCategory, 
    std::string &productManufacturer, 
    int &productQuantity, 
    std::string &unitOfMeasure, 
    int &minimumOrder)
{
    std::cout << "Enter product name: ";
    std::cin.ignore();
    std::getline(std::cin, productName);

    std::cout << "Enter product price: ";
    while (!(std::cin >> productPrice) || productPrice < 0)
    {
        std::cout << "Invalid price. Please enter a positive number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter product category: ";
    std::cin.ignore();
    std::getline(std::cin, productCategory);

    std::cout << "Enter product manufacturer: ";
    std::getline(std::cin, productManufacturer);

    std::cout << "Enter product quantity: ";
    while (!(std::cin >> productQuantity) || productQuantity < 0)
    {
        std::cout << "Invalid quantity. Please enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter unit of measure: ";
    std::cin.ignore();
    std::getline(std::cin, unitOfMeasure);

    std::cout << "Enter minimum order: ";
    while (!(std::cin >> minimumOrder) || minimumOrder < 0)
    {
        std::cout << "Invalid minimum order. Please enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
