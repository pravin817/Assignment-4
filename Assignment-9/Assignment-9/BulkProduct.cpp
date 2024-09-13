#include "stdafx.h"
#include "BulkProduct.h"
#include "Util.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

//-----------------------------------------------------------------------------
// BulkProduct Constructor
//-----------------------------------------------------------------------------

BulkProduct::BulkProduct(std::string const &productID, std::string const &productName, 
                         float const &productPrice, std::string const &productCategory, 
                         std::string const &productManufacturer, 
                         int const &currentQuantity, std::string const &unitOfMeasure,
                         int const &maxProductHoldingCapacity,
                         int const &minimumReorderQuantity,
                         int const &minimumThreshold)
    : Product(productID, productName, productPrice, productCategory, 
              productManufacturer, currentQuantity, unitOfMeasure, maxProductHoldingCapacity),
      m_maxProductHoldingCapacity(maxProductHoldingCapacity),
      m_minimumReorderQuantity(minimumReorderQuantity),
      m_minimumThreshold(minimumThreshold) {}

//-----------------------------------------------------------------------------
// Function to set the minimum threshold for the bulk product
//-----------------------------------------------------------------------------

void BulkProduct::SetMinimumThreshold(int minimumThreshold)
{
    m_minimumThreshold = minimumThreshold;
}

//-----------------------------------------------------------------------------
// Function to set the maximum number of a particular product that can be stored
// in the store
//-----------------------------------------------------------------------------

void BulkProduct::SetMaximumProductHoldingCapacity(int maximumProductHoldingCapacity)
{
    m_maxProductHoldingCapacity = maximumProductHoldingCapacity;
}

//-----------------------------------------------------------------------------
// Function to return the minimum threshold
//-----------------------------------------------------------------------------

const int& BulkProduct::GetMinimumThreshold() const
{
    return m_minimumThreshold;
}

//-----------------------------------------------------------------------------
// Function to return the maximum number of a particular product that can be stored
// in the store
//-----------------------------------------------------------------------------

const int& BulkProduct::GetMaximumProductHoldingCapacity() const
{
    return m_maxProductHoldingCapacity;
}

//-----------------------------------------------------------------------------
// Function to return the minimum reorder quantity of the product
//-----------------------------------------------------------------------------

const int& BulkProduct::GetMinimumReorderQuantity() const
{
    return m_minimumReorderQuantity;
}

//-----------------------------------------------------------------------------
// Function to restore stock for the bulk product
//-----------------------------------------------------------------------------

void BulkProduct::RestoreStockProduct() const
{
    std::cout << "Restocking the bulk product..." << std::endl;
}

//-----------------------------------------------------------------------------
// Function to get the order type (e.g., Bulk, Special)
//-----------------------------------------------------------------------------

const std::string& BulkProduct::GetOrderType() const
{
    static const std::string typeOfProduct = "Bulk Order Product";
    return typeOfProduct;
}

//-----------------------------------------------------------------------------
// Function to display the product details
//-----------------------------------------------------------------------------

void BulkProduct::Display() const
{
    // 1. Table Header
    Util::PrintTableHeader();

    // 2. Table Data
    std::cout << GetDetailsInStringFormatForPrintingOnConsole() << std::endl;

    // 3. Table Footer
    Util::PrintTableFooter();
}

//-----------------------------------------------------------------------------
// Function to return the product details in a string format for console output
//-----------------------------------------------------------------------------

std::string BulkProduct::GetDetailsInStringFormatForPrintingOnConsole() const
{
    const int width = 15;

    std::ostringstream oss;

    oss << "| " << Util::AlignTextAtCenterOfTable(GetProductID(), width)
        << " | " << Util::AlignTextAtCenterOfTable("Bulk Product", width)
        << " | " << Util::AlignTextAtCenterOfTable(GetProductName(), width)
        << " | " << Util::AlignTextAtCenterOfTable(Util::DoubleToString(GetProductPrice()), width + 2)
        << " | " << Util::AlignTextAtCenterOfTable(GetProductCategory(), width + 2)
        << " | " << Util::AlignTextAtCenterOfTable(GetProductManufacturer(), width + 5)
        << " | " << Util::AlignTextAtCenterOfTable(std::to_string(static_cast<long long>(GetCurrentProductQuantity())), width + 3)
        << " | " << Util::AlignTextAtCenterOfTable(GetUnitOfMeasure(), width + 2)
        << " | " << Util::AlignTextAtCenterOfTable(std::to_string(static_cast<long long>(GetMaximumProductHoldingCapacity())), width + 6)
        << " | " << Util::AlignTextAtCenterOfTable(std::to_string(static_cast<long long>(GetMinimumThreshold())), width + 5)
        << " |";

    return oss.str();
}

//-----------------------------------------------------------------------------
// Function to return the product details in a string format for file writing
//-----------------------------------------------------------------------------
std::string BulkProduct::GetDetailsInStringFormatForWritingInFile() const
{
    return GetProductID() + "," 
         + GetProductName() + "," 
         + Util::DoubleToString(GetProductPrice()) + "," 
         + GetProductCategory() + "," 
         + GetProductManufacturer() + "," 
         + std::to_string(static_cast<long long>(GetCurrentProductQuantity())) + "," 
         + GetUnitOfMeasure() + "," 
         + std::to_string(static_cast<long long>(GetMaximumProductHoldingCapacity())) + "," 
         + std::to_string(static_cast<long long>(GetMinimumReorderQuantity())) + "," 
         + std::to_string(static_cast<long long>(GetMinimumThreshold()));
}

//-----------------------------------------------------------------------------
// BulkProduct Destructor
//-----------------------------------------------------------------------------

BulkProduct::~BulkProduct()
{
    std::cout << "The Bulk Product destructor called" << std::endl;
}
