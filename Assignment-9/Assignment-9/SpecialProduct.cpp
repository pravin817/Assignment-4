#include "stdafx.h"
#include "SpecialProduct.h"
#include "Util.h"
#include <iostream>
#include <sstream>
#include <iomanip>

//-----------------------------------------------------------------------------
// Special Product constructor
//-----------------------------------------------------------------------------

SpecialProduct::SpecialProduct(std::string const &productID, 
                               std::string const &productName, 
                               float const &productPrice, 
                               std::string const &productCategory, 
                               std::string const &productManufacturer, 
                               int const &currentQuantity,
                               std::string const &unitOfMeasure,
                               int const &minimumOrderQuantity,
							   int const &maxHoldingCapacity)
    : Product(productID,
              productName,
              productPrice,
              productCategory,
              productManufacturer,
              currentQuantity,
              unitOfMeasure,
			  maxHoldingCapacity),
      m_minimumOrderQuantity(minimumOrderQuantity)
{}

//-----------------------------------------------------------------------------
// Function that sets the minimum order quantity for the product
//-----------------------------------------------------------------------------

void SpecialProduct::SetMinimumOrderQuantity(int minimumOrderQuantity)
{
    m_minimumOrderQuantity = minimumOrderQuantity;
}

//-----------------------------------------------------------------------------
// Function that returns the minimum order quantity
//-----------------------------------------------------------------------------

const int& SpecialProduct::GetMinimumOrderQuantity() const
{
    return m_minimumOrderQuantity;
}

//-----------------------------------------------------------------------------
// Function to restore stock for the special product
//-----------------------------------------------------------------------------

void SpecialProduct::RestoreStockProduct() const
{
    std::cout << "I am from the special product" << std::endl;
}

//-----------------------------------------------------------------------------
// Function that returns the product order type (e.g., Special)
//-----------------------------------------------------------------------------

const std::string& SpecialProduct::GetOrderType() const
{
    static const std::string typeOfProduct = "Special Order Product";
    return typeOfProduct;
}

//-----------------------------------------------------------------------------
// Function that displays the product details
//-----------------------------------------------------------------------------

void SpecialProduct::Display() const
{
    std::cout << "Special Display Called" << std::endl;
}

//-----------------------------------------------------------------------------
// Function that returns the product in string format for console printing
//-----------------------------------------------------------------------------

std::string SpecialProduct::GetDetailsInStringFormatForPrintingOnConsole() const
{
    const int width = 15;

    std::ostringstream oss;

    oss << "| " << Util::AlignTextAtCenterOfTable(GetProductID(), width)
        << " | " << Util::AlignTextAtCenterOfTable("Special Product", width)
        << " | " << Util::AlignTextAtCenterOfTable(GetProductName(), width)
        << " | " << Util::AlignTextAtCenterOfTable(Util::DoubleToString(GetProductPrice()), width)
        << " | " << Util::AlignTextAtCenterOfTable(GetProductCategory(), width)
        //<< " | " << Util::AlignTextAtCenterOfTable(GetproductManufacturer(), width)
        << " | " << Util::AlignTextAtCenterOfTable(std::to_string(static_cast<long long>(GetCurrentProductQuantity())), width)
        << " | " << Util::AlignTextAtCenterOfTable(GetUnitOfMeasure(), width)
        << " | " << Util::AlignTextAtCenterOfTable("-", width)
        << " | " << Util::AlignTextAtCenterOfTable(std::to_string(static_cast<long long>(GetMinimumOrderQuantity())), width)
        << " |";

    return oss.str();
}

//-----------------------------------------------------------------------------
// Function that returns the product in string format for file writing
//-----------------------------------------------------------------------------

std::string SpecialProduct::GetDetailsInStringFormatForWritingInFile() const
{
    return GetProductID() + "," 
         + GetProductName() + "," 
         + Util::DoubleToString(GetProductPrice()) + "," 
         + GetProductCategory() + "," 
         //+ GetproductManufacturer() + "," 
         + std::to_string(static_cast<long long>(GetCurrentProductQuantity())) + "," 
         + GetUnitOfMeasure() + "," 
         + std::to_string(static_cast<long long>(GetMinimumOrderQuantity()));
}

//-----------------------------------------------------------------------------
// Special Product destructor
//-----------------------------------------------------------------------------

SpecialProduct::~SpecialProduct()
{
    std::cout << "The Special Product destructor called" << std::endl;
}
