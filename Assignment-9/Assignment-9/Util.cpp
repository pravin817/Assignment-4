#include "stdafx.h"
#include "Util.h"
#include "Validations.h"
#include "ProductPresenter.h"

#include <iostream>
#include <sstream>

//-----------------------------------------------------------------------------
// Function for printing the main menu
//-----------------------------------------------------------------------------
void Util::PrintMainMenu()
{
    std::cout << "\n----------------- Main Menu ------------------------" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. ADD Product" << std::endl;
    std::cout << "3. Issue product from store against requisition (Sell the product)" << std::endl;
    std::cout << "4. Receive purchased goods " << std::endl;
    std::cout << "5. Generate stock report" << std::endl;
    std::cout << "6. Generate purchase order report" << std::endl;
    std::cout << "7. Save & Restore " << std::endl;
    std::cout << "8. Display all products in the store " << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
}

//-----------------------------------------------------------------------------
// Function showing the Add Product choice
//-----------------------------------------------------------------------------
void Util::GetAddProductChoiceFromUser(int &choice)
{
    std::cout << "0. Exit from add product." << std::endl;
    std::cout << "1. Add Bulk order Product." << std::endl;
    std::cout << "2. Add Special Order Product." << std::endl;
    std::cout << "Please enter your choice: ";
    Validations::ValidateIntegerInput(choice);
}

//-----------------------------------------------------------------------------
// Function for converting double to string
//-----------------------------------------------------------------------------
std::string Util::DoubleToString(double value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

//-----------------------------------------------------------------------------
// Function for printing the table header
//-----------------------------------------------------------------------------
void Util::PrintTableHeader()
{
    std::cout << "+-------------------+-----------------+-----------------+-------------------+-------------------+----------------------+--------------------+-------------------+-----------------------+----------------------+" << std::endl;
    std::cout << "|     Product ID    |  Product Type   |  Product Name   |   Product Price   |  Product Category | Product Manufacturer |  Product Quantity  |  Unit Of Measure  |  Max product Capacity | Minimum Threshold    | " << std::endl;
    std::cout << "+-------------------+-----------------+-----------------+-------------------+-------------------+----------------------+--------------------+-------------------+-----------------------+----------------------+" << std::endl;
}

//-----------------------------------------------------------------------------
// Function for printing the table footer
//-----------------------------------------------------------------------------
void Util::PrintTableFooter()
{
    std::cout << "+-------------------+-----------------+-----------------+-------------------+-------------------+----------------------+--------------------+-------------------+-----------------------+----------------------+" << std::endl;
}

//-----------------------------------------------------------------------------
// Function for printing the table header (Orders)
//-----------------------------------------------------------------------------
void Util::PrintTableHeaderForOrder()
{
    std::cout << "+-------------------+-----------------+--------------------+----------------------+-------------------+" << std::endl;
    std::cout << "|     Order ID      |    Product ID   |  Product Quantity  |  Total Order Price   |  Order Status     |" << std::endl;
    std::cout << "+-------------------+-----------------+--------------------+----------------------+-------------------+" << std::endl;
}

//-----------------------------------------------------------------------------
// Function for printing the table footer (Orders)
//-----------------------------------------------------------------------------
void Util::PrintTableFooterForOrder()
{
    std::cout << "+-------------------+-----------------+--------------------+----------------------+-------------------+" << std::endl;
}

//-----------------------------------------------------------------------------
// Function for aligning text at the center of a table column
//-----------------------------------------------------------------------------
std::string Util::AlignTextAtCenterOfTable(const std::string& text, int width)
{
    int padding = width - text.size();
    if (padding <= 0) 
        return text; // No need to pad if the text is longer than the width

    int padLeft = padding / 2;
    int padRight = padding - padLeft;

    return std::string(padLeft, ' ') + text + std::string(padRight, ' ');
}

//-----------------------------------------------------------------------------
// Function that prints the single product details
//-----------------------------------------------------------------------------
void Util::PrintProductDetails(const Product* currentProduct)
{
    // 1. Table Header
    Util::PrintTableHeader();

    // 2. Table Data
    ProductPresenter const* productPresenter = dynamic_cast<ProductPresenter const*>(currentProduct);

    if (productPresenter != nullptr)
    {
        std::cout << productPresenter->GetDetailsInStringFormatForPrintingOnConsole() << std::endl;
    }

    // 3. Table Footer
    Util::PrintTableFooter();
}
