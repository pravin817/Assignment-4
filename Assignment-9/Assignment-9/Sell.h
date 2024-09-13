#ifndef SELL_H
#define SELL_H

#include <string>
#include <vector>
#include <map>

class Sell
{
private:
    std::string m_sellID;
    std::vector<std::map<std::string, int>> m_sellList; // List of products sold with quantities
    int totalPrice; // Total price of all sold products

public:
    // Constructors
    Sell();
    Sell(std::string const &sellID, std::vector<std::map<std::string, int>> const &newSell);

    // Method to sell a product to the user
    void SellProduct(std::map<std::string, int> const &newSell);

    // Method to calculate the total price of sold products
    void CalculateTotalPrice();

    // Getter for total price
    int GetTotalPrice() const;

    // Getter for sell list
    std::vector<std::map<std::string, int>> GetSellList() const;

    // Destructor
    ~Sell();
};

#endif // SELL_H
