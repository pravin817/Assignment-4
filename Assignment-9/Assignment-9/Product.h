#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

//------------------------------------------------------------------------------
// Product class - Represents a product in the store with details like ID, name, 
// price, category, manufacturer, quantity, and unit of measure. This is an 
// abstract base class intended to be inherited by specific types of products.
//------------------------------------------------------------------------------
class Product
{
protected:
    std::string m_productID;             // Product ID
    std::string m_productName;           // Name of the product
    float m_productPrice;                // Product price
    std::string m_productCategory;       // Product category
    std::string m_productManufacturer;   // Product manufacturer
    int m_currentQuantity;               // Current quantity of the product
    std::string m_unitOfMeasure;         // Unit of measure for the product (e.g., liters, units)
    int m_maxProductHoldingCapacity;     // Maximum capacity of the product

public:
    // Constructor
    Product();
    Product(std::string const &productID, std::string const &productName, 
            float const &productPrice, std::string const &productCategory, 
            std::string const &productManufacturer, int const &currentQuantity, 
            std::string const &unitOfMeasure, int maxProductHoldingCapacity);

    // Virtual function to restore stock for a particular product
    virtual void RestoreStockProduct() const = 0;

    // Virtual function that returns the order type
    virtual const std::string& GetOrderType() const = 0;

    // Virtual function that displays the individual product
    virtual void Display() const = 0;

    // Setter Methods
    void SetProductName(std::string const &productName);
    void SetProductPrice(float const &productPrice);
    void SetProductCategory(std::string const &productCategory);
    void SetProductManufacturer(std::string const &productManufacturer);
    void SetCurrentProductQuantity(int quantity);
    void SetUnitOfMeasure(std::string const &unitOfMeasure);
    void SetMaximumProductHoldingCapacity(int maxProductHoldingCapacity);

    // Getter Methods
    const std::string& GetProductID() const;
    const std::string& GetProductName() const;
    const float& GetProductPrice() const;
    const std::string& GetProductCategory() const;
    const std::string& GetProductManufacturer() const;
    const int& GetCurrentProductQuantity() const;
    const std::string& GetUnitOfMeasure() const;
    const int& GetMaximumProductHoldingCapacity() const;

    // Destructor
    virtual ~Product();
};

#endif // PRODUCT_H
