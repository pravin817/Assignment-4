#ifndef ORDER_H
#define ORDER_H

#include "ProductPresenter.h"
#include <string>

class Order : public ProductPresenter
{
private:
    std::string m_orderID;
    std::string m_productID;
    int m_quantity;
    float m_totalPrice;
    std::string m_orderStatus;

public:
    // Constructors
    Order();
    Order(std::string const &orderID, 
          std::string const &productID, 
          int quantity, 
          float totalPrice = -1.0, 
          std::string orderStatus = "Pending");

    // Setter Methods
    void SetOrderID(std::string const &orderID);
    void SetProductID(std::string const &productID);
    void SetOrderQuantity(int const &quantity);
    void SetTotalPrice(float price);

    // Getter Methods
    const std::string& GetOrderID() const;
    const std::string& GetProductID() const;
    const int& GetOrderQuantity() const;
    const float& GetTotalOrderPrice() const;
	const std::string& GetOrderStatus()const;

    // Override the functions from the base class
    // Function that displays the individual order
    void Display() const override;

    // Returns the order in a string format suitable for writing to a file
    std::string GetDetailsInStringFormatForWritingInFile() const override;

    // Returns the order in a string format suitable for printing on console
    std::string GetDetailsInStringFormatForPrintingOnConsole() const override;

    // Destructor
    ~Order();
};

#endif // ORDER_H
