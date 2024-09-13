#ifndef BULKPRODUCT_H
#define BULKPRODUCT_H

#include "Product.h"
#include "ProductPresenter.h"

#include <string>

//------------------------------------------------------------------------------
// Class representing a bulk product that can be stored in larger quantities
//------------------------------------------------------------------------------
class BulkProduct : public Product, public ProductPresenter
{
private:
    int m_maxProductHoldingCapacity;   // Maximum number of particular product that can be stored in the store
    int m_minimumReorderQuantity;      // Minimum reorder quantity of the product
    int m_minimumThreshold;            // Threshold level for triggering reorder

public:
    // Default Constructor
    BulkProduct();

    // Parameterized Constructor
    BulkProduct(std::string const &productID, std::string const &productName, 
                float const &productPrice, std::string const &productCategory, 
                std::string const &productManufacturer, 
                int const &currentQuantity, std::string const &unitOfMeasure,
                int const &maxProductHoldingCapacity,
                int const &minimumReorderQuantity = 0,
                int const &minimumThreshold = 10);

    // Function to restore stock for the particular product
    void RestoreStockProduct() const override;

    // Function to get the order type
    const std::string& GetOrderType() const override;

    // Function to display the individual product details
    void Display() const override;

    // Function to return the product in a string format suitable for writing to a file
    std::string GetDetailsInStringFormatForWritingInFile() const override;

    // Function to return the product in a string format suitable for printing on console
    std::string GetDetailsInStringFormatForPrintingOnConsole() const override;

    // Setter Methods
    void SetMinimumThreshold(int minimumThreshold);
    void SetMaximumProductHoldingCapacity(int maximumProductHoldingCapacity);
    void SetMinimumReorderQuantity(int minimumReorderQuantity);

    // Getter Methods
    const int& GetMinimumThreshold() const;
    const int& GetMaximumProductHoldingCapacity() const;
    const int& GetMinimumReorderQuantity() const;

    // Destructor
    ~BulkProduct();
};

#endif // BULKPRODUCT_H
