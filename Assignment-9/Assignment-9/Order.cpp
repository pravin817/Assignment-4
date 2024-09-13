#include "stdafx.h"
#include "Order.h"
#include "Util.h"
#include <iostream>
#include <sstream>

//-----------------------------------------------------------------------------
// Default Constructor
//-----------------------------------------------------------------------------
Order::Order()
    : m_orderID(""), m_productID(""), m_quantity(0), m_totalPrice(-1.0), m_orderStatus("Pending") {}

//-----------------------------------------------------------------------------
// Parameterized Constructor
//-----------------------------------------------------------------------------
Order::Order(std::string const &orderID, 
             std::string const &productID, 
             int quantity, 
             float totalPrice, 
             std::string orderStatus)
    : m_orderID(orderID), 
      m_productID(productID), 
      m_quantity(quantity), 
      m_totalPrice(totalPrice), 
      m_orderStatus(orderStatus) {}

//-----------------------------------------------------------------------------
// Setter Methods
//-----------------------------------------------------------------------------
void Order::SetOrderID(std::string const &orderID)
{
    m_orderID = orderID;
}

void Order::SetProductID(std::string const &productID)
{
    m_productID = productID;
}

void Order::SetOrderQuantity(int const &quantity)
{
    m_quantity = quantity;
}

void Order::SetTotalPrice(float price)
{
    m_totalPrice = price;
}

//-----------------------------------------------------------------------------
// Getter Methods
//-----------------------------------------------------------------------------
const std::string& Order::GetOrderID() const
{
    return m_orderID;
}

const std::string& Order::GetProductID() const
{
    return m_productID;
}

const int& Order::GetOrderQuantity() const
{
    return m_quantity;
}

const float& Order::GetTotalOrderPrice() const
{
    return m_totalPrice;
}

const std::string& Order::GetOrderStatus()const
{
	return m_orderStatus;
}

//-----------------------------------------------------------------------------
// Function that displays the individual order
//-----------------------------------------------------------------------------
void Order::Display() const
{
    std::cout << "Order ID: " << m_orderID << std::endl;
    std::cout << "Product ID: " << m_productID << std::endl;
    std::cout << "Quantity: " << m_quantity << std::endl;
    std::cout << "Total Price: " << m_totalPrice << std::endl;
    std::cout << "Order Status: " << m_orderStatus << std::endl;
}

//-----------------------------------------------------------------------------
// Function that returns the order in a string format suitable for writing to a file
//-----------------------------------------------------------------------------
std::string Order::GetDetailsInStringFormatForWritingInFile() const
{
    std::ostringstream oss;
    oss << m_orderID << ","
        << m_productID << ","
        << m_quantity << ","
        << m_totalPrice << ","
        << m_orderStatus;
    return oss.str();
}

//-----------------------------------------------------------------------------
// Function that returns the order in a string format suitable for printing on console
//-----------------------------------------------------------------------------
std::string Order::GetDetailsInStringFormatForPrintingOnConsole() const
{
    std::ostringstream oss;
    oss << "Order ID: " << m_orderID << " | "
        << "Product ID: " << m_productID << " | "
        << "Quantity: " << m_quantity << " | "
        << "Total Price: " << m_totalPrice << " | "
        << "Order Status: " << m_orderStatus;
    return oss.str();
}

//-----------------------------------------------------------------------------
// Destructor
//-----------------------------------------------------------------------------
Order::~Order()
{
    std::cout << "The Order destructor called" << std::endl;
}
