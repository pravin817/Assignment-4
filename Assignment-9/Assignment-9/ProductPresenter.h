#ifndef PRODUCTPRSENTER_H
#define PRODUCTPRSENTER_H

#include <string>

class ProductPresenter
{
public:

	// Displays the product details
	virtual void Display() const = 0;

	// Returns the product in a string format suitable for writing to a file
	virtual std::string GetDetailsInStringFormatForWritingInFile() const = 0;

	// Returns the product in a string format suitable for printing on console
	virtual std::string GetDetailsInStringFormatForPrintingOnConsole() const = 0;

	// Virtual destructor to ensure derived class destructors are called
	virtual ~ProductPresenter();
	
};




#endif //PRODUCTPRSENTER_H