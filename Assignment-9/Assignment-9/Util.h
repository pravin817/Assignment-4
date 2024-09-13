#ifndef UTIL_H
#define UTIL_H

#include "Product.h"
#include <iostream>
#include <string>

class Util
{
public:

    // Print the Main Menu
    static void PrintMainMenu();

    // Function that shows the add product menu
    static void GetAddProductChoiceFromUser(int &choice);

    // Convert a double to a string.
    static std::string DoubleToString(double value);

    // Print table headers and footers.
    static void PrintTableHeader();
    static void PrintTableFooter();

    static void PrintTableHeaderForOrder();
    static void PrintTableFooterForOrder();

    // Center text in a table.
    static std::string AlignTextAtCenterOfTable(const std::string& text, int width);

    // Print the product details
    static void PrintProductDetails(const Product const *product);
};

#endif // UTIL_H
