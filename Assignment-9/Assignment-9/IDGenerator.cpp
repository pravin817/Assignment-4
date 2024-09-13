#include "stdafx.h"
#include "IDGenerator.h"

#include <sstream>
#include <iomanip>
#include <ctime>


//-----------------------------------------------------------------------------
// Function that generates the ID
//-----------------------------------------------------------------------------
std::string IDGenerator::GenerateID(const std::string& prefix, int sequentialNumber)
{
	std::ostringstream idStream;
	idStream << prefix;
	idStream << GetCurrentDate();
	//idStream << "-";
	idStream << std::setw(5) << std::setfill('0') << sequentialNumber;
	return idStream.str();
}


//-----------------------------------------------------------------------------
// Function that gets the current date
//-----------------------------------------------------------------------------
std::string IDGenerator::GetCurrentDate()
{
	std::time_t now = std::time(nullptr);
	std::tm* tmNow = std::localtime(&now);
	std::ostringstream dateStream;
	dateStream << std::put_time(tmNow, "%Y%m%d");
	return dateStream.str();
}


//-----------------------------------------------------------------------------
// Function that generate the productID 
//-----------------------------------------------------------------------------
std::string IDGenerator::GenerateProductID(std::string const &productType, 
	int sequentialNumber)
{
	if(productType == "SPECIAL")
	{
		return GenerateID("SPEC", sequentialNumber);
	}

	return GenerateID("BULK", sequentialNumber);
}


//-----------------------------------------------------------------------------
// Function that generate the OrderID 
//-----------------------------------------------------------------------------
std::string IDGenerator:: GenerateOrderID(int sequentialNumber) 
{
	return GenerateID("ORDE", sequentialNumber);
}


//-----------------------------------------------------------------------------
// Function that generate the SellID 
//-----------------------------------------------------------------------------
std::string IDGenerator:: GenerateSellID(int sequentialNumber)
{
	return GenerateID("SELL", sequentialNumber);
}