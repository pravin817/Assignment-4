#include "stdafx.h"
#include "Sell.h"
#include <iostream>
#include <numeric>

//-----------------------------------------------------------------------------
// Default Constructor
//-----------------------------------------------------------------------------
Sell::Sell() : m_sellID(""), totalPrice(0) {}

//-----------------------------------------------------------------------------
// Parameterized Constructor
//-----------------------------------------------------------------------------
Sell::Sell(std::string const &sellID, std::vector<std::map<std::string, int>> const &newSell)
    : m_sellID(sellID), m_sellList(newSell), totalPrice(0) {}

//-----------------------------------------------------------------------------
// Method to add a product to the sell list
//-----------------------------------------------------------------------------
void Sell::SellProduct(std::map<std::string, int> const &newSell)
{
    m_sellList.push_back(newSell);
    CalculateTotalPrice(); // Update total price after adding new sale
}

//-----------------------------------------------------------------------------
// Method to calculate the total price of all sold products
//-----------------------------------------------------------------------------
void Sell::CalculateTotalPrice()
{
    totalPrice = 0;

	int totalSoldToParticularUser = m_sellList.size();


	for(int iSell = 0; iSell < totalSoldToParticularUser; ++iSell)
	{
		std::map<std::string,int>oneSell;

		oneSell = m_sellList[iSell];

		int price = 100;
	}


}

//-----------------------------------------------------------------------------
// Getter for total price
//-----------------------------------------------------------------------------
int Sell::GetTotalPrice() const
{
    return totalPrice;
}

//-----------------------------------------------------------------------------
// Getter for sell list
//-----------------------------------------------------------------------------
std::vector<std::map<std::string, int>> Sell::GetSellList() const
{
    return m_sellList;
}

//-----------------------------------------------------------------------------
// Destructor
//-----------------------------------------------------------------------------
Sell::~Sell()
{
    std::cout << "The Sell destructor called" << std::endl;
}
