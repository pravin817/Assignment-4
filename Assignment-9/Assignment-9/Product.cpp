#include "stdafx.h"
#include "Product.h"

#include <iostream>

//------------------------------------------------------------------------------
// Product constructor
//------------------------------------------------------------------------------
Product::Product(std::string const &productID, std::string const &productName, 
                 float const &productPrice, std::string const &productCategory, 
                 std::string const &productManufacturer, 
                 int const &currentQuantity, std::string const &unitOfMeasure, 
                 int maxProductHoldingCapacity)
    : m_productID(productID), m_productName(productName),
      m_productPrice(productPrice), m_productCategory(productCategory),
      m_productManufacturer(productManufacturer), m_currentQuantity(currentQuantity),
      m_unitOfMeasure(unitOfMeasure), 
	  m_maxProductHoldingCapacity(maxProductHoldingCapacity)
{}

//------------------------------------------------------------------------------
// Setter Methods
//------------------------------------------------------------------------------

// Function to set the product name
void Product::SetProductName(std::string const &productName)
{
    m_productName = productName;
}

// Function to set the product price
void Product::SetProductPrice(float const &productPrice)
{
    m_productPrice = productPrice;
}

// Function to set the product category
void Product::SetProductCategory(std::string const &productCategory)
{
    m_productCategory = productCategory;
}

// Function to set the product manufacturer
void Product::SetProductManufacturer(std::string const &productManufacturer)
{
    m_productManufacturer = productManufacturer;
}

// Function to set the current product quantity
void Product::SetCurrentProductQuantity(int quantity)
{
    m_currentQuantity = quantity;
}

// Function to set the unit of measure
void Product::SetUnitOfMeasure(std::string const &unitOfMeasure)
{
    m_unitOfMeasure = unitOfMeasure;
}

// Function to set the maximum product holding capacity
void Product::SetMaximumProductHoldingCapacity(int maxProductHoldingCapacity)
{
    m_maxProductHoldingCapacity = maxProductHoldingCapacity;
}

//------------------------------------------------------------------------------
// Getter Methods
//------------------------------------------------------------------------------

// Function that returns the product ID
const std::string& Product::GetProductID() const
{
    return m_productID;
}

// Function that returns the product name
const std::string& Product::GetProductName() const
{
    return m_productName;
}

// Function that returns the product price
const float& Product::GetProductPrice() const
{
    return m_productPrice;
}

// Function that returns the product category
const std::string& Product::GetProductCategory() const
{
    return m_productCategory;
}

// Function that returns the product manufacturer
const std::string& Product::GetProductManufacturer() const
{
    return m_productManufacturer;
}

// Function that returns the current product quantity
const int& Product::GetCurrentProductQuantity() const
{
    return m_currentQuantity;
}

// Function that returns the unit of measure for the product
const std::string& Product::GetUnitOfMeasure() const
{
    return m_unitOfMeasure;
}

// Function that returns the maximum product holding capacity
const int& Product::GetMaximumProductHoldingCapacity() const
{
    return m_maxProductHoldingCapacity;
}

//------------------------------------------------------------------------------
// Product Destructor
//------------------------------------------------------------------------------
Product::~Product()
{
    std::cout << "The Product destructor is called" << std::endl;
}
