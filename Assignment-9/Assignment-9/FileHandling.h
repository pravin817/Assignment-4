#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include "Product.h"
#include "Order.h"
#include "Sell.h"

#include <string>
#include <vector>
#include <map>

class FileHandling
{
public:

	//-------------------------------------------------------------------------
    // Function that reads from the files
    static bool LoadProductsDataFromFile(std::string const &fileName, 
        std::vector<Product*> &listOfProducts,
        std::map<std::string, Product*> &ProductIDToProductMap, 
        std::map<std::string, int>& counter);

    // Function that reads the Order data from the file
    static bool LoadOrdersDataFromFile(std::string const &fileName, 
        std::vector<Order*> &listOfOrders, 
        std::map<std::string, Order*> &OrderIDToOrderMap, 
        std::map<std::string, int>& counter);

    // Function that loads the sells data from the file into the system
    static bool LoadSellsDataFromFile(std::string const &fileName, 
        std::vector<Sell*> &listOfSells, 
        std::map<std::string, Sell*> &SellIDToSellMap, 
        std::map<std::string, int>& counter);

    // Function that adds the product to the product file
    static bool AddProductToFile(std::string const &fileName, 
		const Product const *product);

    // Function that adds the orders to the order file
    static bool AddOrderToFile(std::string const &fileName, 
		Order const &order);

    // Function that saves the data in the file (By writing the complete data)
    static bool WriteDataToProductFile(std::string const &fileName, 
		std::vector<std::vector<std::string>> const &productsData);

    static bool WriteDataToOrdersFile(std::string const &fileName, 
		std::vector<std::vector<std::string>> const &ordersData);

    static bool WriteDataToSellsFile(std::string const &fileName, 
		std::vector<std::vector<std::string>> const &sellsData);
};

#endif // FILEHANDLING_H
