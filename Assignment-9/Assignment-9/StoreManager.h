#ifndef STOREMANAGER_H
#define STOREMANAGER_H

#include "Product.h"
#include "Order.h"
#include "Sell.h"

#include <string>
#include <vector>
#include <map>

// Forward declarations
class FileHandling;

class StoreManager
{
private:
    // List of all products
    std::vector<Product*> m_listOfProducts;

    // List of all orders
    std::vector<Order*> m_listOfOrders;

    // List of all sales
    std::vector<Sell*> m_listOfSells;

    // For getting the product by productID
    std::map<std::string, Product*> m_productIDToProductMap;

    // For searching for the order based on orderID
    std::map<std::string, Order*> m_orderIDToOrderMap;

    // For searching the sale by saleID
    std::map<std::string, Sell*> m_sellIDToSellMap;

    // Count of all things (like counts of products, orders, sells)
    std::map<std::string, int> m_counters;

    // Load data from files
    void loadDataFromFile();

    // Get the product by productID
    Product* GetProductByProductID(std::string const &productID);

public:
    // Constructor
    StoreManager();

    // Function to add a product to the store
    bool AddProductToStore(Product *newProduct);

    // Function that issues a product from the store
    bool IssueProductToCustomer();

    // Function that adds ordered products to the store
    bool AddOrderedProductToStore();

    // Function for printing all products
    void PrintAllProducts() const;

    // Return the count of different products, orders, and sales
    int GetCount(std::string const &name) const;

    // Check if the product is present in the store or not
    bool IsProductPresent(std::string const &productID) const;

    // Get the count of the product available
    int GetProductCountByProductID(std::string const &productID);

	// Get the price of the product by productID
	int GetProductPriceByProductID(std::string const &productID);

    // Friend class to access private members for file handling
    friend class FileHandling;
};

#endif // STOREMANAGER_H
