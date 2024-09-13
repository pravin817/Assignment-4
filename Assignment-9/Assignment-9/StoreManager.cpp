#include "stdafx.h"
#include "StoreManager.h"
#include "FileHandling.h"
#include "ProductPresenter.h"
#include "SpecialProduct.h"
#include "BulkProduct.h"
#include "IDGenerator.h"
#include "Util.h"

#include <iostream>

//-----------------------------------------------------------------------------
// StoreManager constructor
//-----------------------------------------------------------------------------
StoreManager::StoreManager()
{
    std::cout << "The StoreManager is initialized." << std::endl;
    loadDataFromFile();
}

//-----------------------------------------------------------------------------
// Function that loads data from the file into the program
//-----------------------------------------------------------------------------
void StoreManager::loadDataFromFile()
{
    std::cout << "Loading data from files..." << std::endl;

    // Load products data
    FileHandling::LoadProductsDataFromFile("products.csv", m_listOfProducts, m_productIDToProductMap, m_counters);

    // Load orders data
    FileHandling::LoadOrdersDataFromFile("orders.csv", m_listOfOrders, m_orderIDToOrderMap, m_counters);

    // Load sells data (currently commented out)
    // FileHandling::LoadSellsDataFromFile("sells.csv", m_listOfSells, m_sellIDToSellMap, m_counters);

    // Print counts for debugging
    //for (const auto& entry : m_counters)
    //{
    //    std::cout << entry.first << ": " << entry.second << std::endl;
    //}
}

//-----------------------------------------------------------------------------
// Function that adds a product to the store
//-----------------------------------------------------------------------------
bool StoreManager::AddProductToStore(Product* newProduct)
{
    if (newProduct != nullptr)
    {
        // Add product to the list and map
        m_listOfProducts.push_back(newProduct);
        m_productIDToProductMap[newProduct->GetProductID()] = newProduct;

        // Update the product count
        if (dynamic_cast<SpecialProduct*>(newProduct))
        {
            m_counters["SPECIAL"]++;
        }
        else if (dynamic_cast<BulkProduct*>(newProduct))
        {
            m_counters["BULK"]++;
        }

        // Save product to file
        if (FileHandling::AddProductToFile("products.csv", newProduct))
        {
            return true;
        }
    }
    return false; // Failed to add the product
}

//-----------------------------------------------------------------------------
// Function that issues a product to a customer
//-----------------------------------------------------------------------------
bool StoreManager::IssueProductToCustomer()
{
    bool loopFlag = true;
    std::vector<std::map<std::string, int>> sellOrders;

    while (loopFlag)
    {
        std::string productID;
        int quantityToBeSold = 0;

        std::cout << "Enter the product ID to sell: ";
        std::cin >> productID;

        Product* currentProduct = GetProductByProductID(productID);

        if (currentProduct != nullptr)
        {
            Util::PrintProductDetails(currentProduct);

            std::cout << "Price: " << currentProduct->GetProductPrice() << " per " << currentProduct->GetUnitOfMeasure() << std::endl;

            BulkProduct* bulkProduct = dynamic_cast<BulkProduct*>(currentProduct);
            SpecialProduct* specialProduct = dynamic_cast<SpecialProduct*>(currentProduct);

            if (bulkProduct != nullptr)
            {
                std::cout << "Enter the quantity: ";
                std::cin >> quantityToBeSold;

                int availableQuantity = bulkProduct->GetCurrentProductQuantity();

                if (availableQuantity >= quantityToBeSold)
                {
                    bulkProduct->SetCurrentProductQuantity(availableQuantity - quantityToBeSold);

                    // Record the sale
                    std::map<std::string, int> oneSell;
                    oneSell[productID] = quantityToBeSold;
                    sellOrders.push_back(oneSell);

                    // Check if reorder is needed
                    if (bulkProduct->GetCurrentProductQuantity() < bulkProduct->GetMinimumThreshold())
                    {
                        int quantityToOrder = bulkProduct->GetMaximumProductHoldingCapacity() - bulkProduct->GetCurrentProductQuantity();
                        float totalOrderPrice = quantityToOrder * bulkProduct->GetProductPrice();

                        // Generate an order ID
                        std::string orderID = IDGenerator::GenerateOrderID(++m_counters["ORDER"]);

                        // Create and add a new order
                        Order* newOrder = new Order(orderID, productID, quantityToOrder, totalOrderPrice);
                        m_listOfOrders.push_back(newOrder);
                        m_orderIDToOrderMap[orderID] = newOrder;

                        // Save the order to file (not yet implemented)
                    }
                }
            }
            else
            {
                std::cout << "This is not a bulk product." << std::endl;
            }
        }
        else
        {
            std::cout << "No product found with ID: " << productID << std::endl;
        }
    }
    return true;
}

//-----------------------------------------------------------------------------
// Function to return the count of different products, orders, and sells
//-----------------------------------------------------------------------------
int StoreManager::GetCount(std::string const &name) const
{
    auto it = m_counters.find(name);
    if (it != m_counters.end())
    {
        return it->second;
    }
    return 0; // Default value if not found
}

//-----------------------------------------------------------------------------
// Function to return the count of a product available
//-----------------------------------------------------------------------------
int StoreManager::GetProductCountByProductID(std::string const &productID)
{
    auto it = m_productIDToProductMap.find(productID);
    if (it != m_productIDToProductMap.end())
    {
        return it->second->GetCurrentProductQuantity();
    }
    return -1; // Product not found
}


//-----------------------------------------------------------------------------
// Function to return the price of the product by productID
//-----------------------------------------------------------------------------
int StoreManager::GetProductPriceByProductID(std::string const &productID)
{
    auto it = m_productIDToProductMap.find(productID);
    if (it != m_productIDToProductMap.end())
    {
        return it->second->GetProductPrice();
    }
    return -1; // Product not found
}




//-----------------------------------------------------------------------------
// Function to return the product by productID
//-----------------------------------------------------------------------------
Product* StoreManager::GetProductByProductID(std::string const &productID)
{
    auto it = m_productIDToProductMap.find(productID);
    if (it != m_productIDToProductMap.end())
    {
        return it->second;
    }
    return nullptr; // Product not found
}

//-----------------------------------------------------------------------------
// Function to print all products
//-----------------------------------------------------------------------------
void StoreManager::PrintAllProducts() const
{
    std::cout << "Product List:" << std::endl;

	int totalProductCount = m_listOfProducts.size();
    Util::PrintTableHeader();

    for (int iProduct = 0; iProduct < totalProductCount; ++iProduct)
    {
		Product *currentProduct = m_listOfProducts[iProduct];

        ProductPresenter* presenter = dynamic_cast<ProductPresenter*>(currentProduct);
        if (presenter != nullptr)
        {
            std::cout << presenter->GetDetailsInStringFormatForPrintingOnConsole() << std::endl;
        }
    }

    Util::PrintTableFooter();
}
