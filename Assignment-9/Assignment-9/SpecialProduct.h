#ifndef SPECIALPRODUCT_H
#define SPECIALPRODUCT_H

#include "Product.h"
#include "ProductPresenter.h"
#include <string>

class SpecialProduct : public Product, public ProductPresenter
{
private:
    int m_minimumOrderQuantity;    // Minimum order quantity for the special product

public:
    // Constructor
    SpecialProduct();
    SpecialProduct(std::string const &productID, std::string const &productName, 
                   float const &productPrice, std::string const &productCategory, 
                   std::string const &productManufacturer, 
                   int const &currentQuantity,
                   std::string const &unitOfMeasure,
                   int const &minimumOrderQuantity,
				   int const &maxHoldingCapacity = 0
				   );

    // Function to restore stock for the special product
    void RestoreStockProduct() const override;

    // Function to get the order type (e.g., Special, Bulk)
    const std::string& GetOrderType() const override;

    // Function to display the individual product
    void Display() const override;

    // Function to return product details as a string for file writing
    std::string GetDetailsInStringFormatForWritingInFile() const override;

    // Function to return product details as a string for console printing
    std::string GetDetailsInStringFormatForPrintingOnConsole() const override;

    // Setter for minimum order quantity
    void SetMinimumOrderQuantity(int minimumOrderQuantity);

    // Getter for minimum order quantity
    const int& GetMinimumOrderQuantity() const;

    // Destructor
    ~SpecialProduct();
};

#endif // SPECIALPRODUCT_H
