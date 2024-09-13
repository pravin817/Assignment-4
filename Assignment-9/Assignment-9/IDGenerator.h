#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <iostream>

class IDGenerator {

private:

	// Function that generate the Unique ID
	static std::string GenerateID(const std::string& prefix, int sequentialNumber);

	//Function that returns the current date
	static std::string GetCurrentDate();

public:

	// Function that generate the unique productID
	static std::string GenerateProductID(std::string const &productType, 
		int sequentialNumber);

	// Function that generate the unique OrderID
	static std::string GenerateOrderID(int sequentialNumber);

	// Function that generate the unique SellID
	static std::string GenerateSellID(int sequentialNumber) ;

};


#endif // IDGENERATOR_H