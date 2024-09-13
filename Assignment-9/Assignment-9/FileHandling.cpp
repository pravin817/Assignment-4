#include "stdafx.h"
#include "FileHandling.h"
#include "Product.h"
#include "SpecialProduct.h"
#include "BulkProduct.h"
#include "Order.h"
#include "Sell.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

//-----------------------------------------------------------------------------
// Function that reads the products data from the file and loads to the system.
//-----------------------------------------------------------------------------
bool FileHandling::LoadProductsDataFromFile(std::string const &fileName, 
    std::vector<Product*> &listOfProducts,
    std::map<std::string, Product*> &ProductIDToProductMap, 
    std::map<std::string, int>& counter)
{
    std::ifstream fin(fileName);

    if (fin.is_open())
    {
        std::string line;

        // Ignore the header line
        std::getline(fin, line); 

        std::string productData;

        while (std::getline(fin, productData))
        {
            std::stringstream ss(productData);
            std::string item = "";

            std::getline(ss, item, ','); // ProductID
            std::string productID = item;
            std::string typeOfProduct = productID.substr(0, 4);

            std::getline(ss, item, ','); // ProductName
            std::string productName = item;
            std::getline(ss, item, ','); // ProductPrice
            float productPrice = std::stof(item);
            std::getline(ss, item, ','); // ProductCategory
            std::string productCategory = item;
            std::getline(ss, item, ','); // ProductManufacturer
            std::string productManufacturer = item;
            std::getline(ss, item, ','); // ProductQuantity
            int productQuantity = std::stoi(item);
            std::getline(ss, item, ','); // UnitOfMeasure
            std::string unitOfMeasure = item;

            Product *newProduct = nullptr;
            if (typeOfProduct == "SPEC")
            {
                std::getline(ss, item, ','); // MinimumOrder
                int minimumOrder = std::stoi(item);

                newProduct = new SpecialProduct(productID,
                    productName,
                    productPrice,
                    productCategory,
                    productManufacturer,
                    productQuantity,
                    unitOfMeasure,
                    minimumOrder);
            }
            else
            {
                std::getline(ss, item, ','); // MaxHoldingCapacity
                int maxHoldingCapacity = std::stoi(item);

                std::getline(ss, item, ','); // MinimumReorderQuantity
                int minimumReorderQuantity = std::stoi(item);

                std::getline(ss, item, ','); // MinimumThreshold
                int minimumThreshold = std::stoi(item);

                newProduct = new BulkProduct(productID,
                    productName,
                    productPrice,
                    productCategory,
                    productManufacturer,
                    productQuantity,
                    unitOfMeasure,
                    maxHoldingCapacity,
                    minimumReorderQuantity,
                    minimumThreshold);
            }

            if (newProduct != nullptr)
            {
                listOfProducts.push_back(newProduct);
                ProductIDToProductMap[productID] = newProduct;

                if (typeOfProduct == "SPEC")
                {
                    counter["SPECIAL"]++;
                }
                else 
                {            
                    counter["BULK"]++;
                }
            }
        }

        fin.close();
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------------------------------------------------------
// Function that reads the orders data from the file and loads to the system.
//-----------------------------------------------------------------------------
bool FileHandling::LoadOrdersDataFromFile(std::string const &fileName, 
    std::vector<Order*> &listOfOrders, 
    std::map<std::string, Order*> &OrderIDToOrderMap, 
    std::map<std::string, int>& counter)
{
    std::ifstream fin(fileName);

    if (fin.is_open())
    {
        std::string line;

        // Ignore the header line
        std::getline(fin, line); 

        std::string orderData;

        while (std::getline(fin, orderData))
        {
            std::stringstream ss(orderData);
            std::string item = "";

            std::getline(ss, item, ','); // OrderID
            std::string orderID = item;

            std::getline(ss, item, ','); // ProductID
            std::string productID = item;

            std::getline(ss, item, ','); // Order Quantity
            int orderQuantity = std::stoi(item);

            std::getline(ss, item, ','); // OrderPrice
            float totalOrderPrice = std::stof(item);

            std::getline(ss, item, ','); // OrderStatus
            std::string orderStatus = item;

            Order *newOrder = new Order(orderID, productID, orderQuantity, totalOrderPrice, orderStatus);

            if (newOrder != nullptr)
            {
                listOfOrders.push_back(newOrder);
                OrderIDToOrderMap[orderID] = newOrder;
                counter["ORDER"]++;
            }
        }

        fin.close();
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------------------------------------------------------
// Function that reads the sells data from the file and loads to the system.
//-----------------------------------------------------------------------------
//bool FileHandling::LoadSellsDataFromFile(std::string const &fileName, 
//    std::vector<Sell*> &listOfSells, 
//    std::map<std::string, Sell*> &SellIDToSellMap, 
//    std::map<std::string, int>& counter)
//{
//    std::ifstream fin(fileName);
//
//    if (fin.is_open())
//    {
//        std::string line;
//
//        // Ignore the header line
//        std::getline(fin, line); 
//
//        std::string sellsData;
//
//        while (std::getline(fin, sellsData))
//        {
//            std::stringstream ss(sellsData);
//            std::string item = "";
//
//            std::getline(ss, item, ','); // ProductID
//            std::string productID = item;
//
//            std::getline(ss, item, ','); // ProductName
//            std::string productName = item;
//
//            std::getline(ss, item, ','); // ProductPrice
//            float productPrice = std::stof(item);
//
//            std::getline(ss, item, ','); // ProductCategory
//            std::string productCategory = item;
//
//            std::getline(ss, item, ','); // ProductManufacturer
//            std::string productManufacturer = item;
//
//            std::getline(ss, item, ','); // ProductQuantity
//            int productQuantity = std::stoi(item);
//
//            std::getline(ss, item, ','); // UnitOfMeasure
//            std::string unitOfMeasure = item;
//
//			std::string sellID = "SELLL1234";
//            Sell *newSell = new Sell(productID, productName, productPrice, productCategory, productManufacturer, productQuantity, unitOfMeasure);
//            Sell *newSell = new Sell(sellID,newSell);
//
//
//            if (newSell != nullptr)
//            {
//                listOfSells.push_back(newSell);
//                SellIDToSellMap[productID] = newSell;
//                counter["SELL"]++;
//            }
//        }
//
//        fin.close();
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

//-----------------------------------------------------------------------------
// Function that appends the product to the file
//-----------------------------------------------------------------------------
bool FileHandling::AddProductToFile(std::string const &fileName, 
    const Product const *newProduct)
{
    std::ofstream fout(fileName, std::ios::app);

    if (fout.is_open())
    {
        ProductPresenter const *productPresenter = 
            dynamic_cast<ProductPresenter const*>(newProduct);

        if (productPresenter != nullptr)
        {
            fout << productPresenter->GetDetailsInStringFormatForWritingInFile()<<std::endl;         
        }

        fout.close();
        return true;
    }
    else
    {
        std::cout << "WARNING: The file is not opened for the writing operation. Add Product to file" << std::endl;
        return false;
    }
}

//-----------------------------------------------------------------------------
// Function that appends the order to the file
//-----------------------------------------------------------------------------
bool FileHandling::AddOrderToFile(std::string const &fileName, 
    Order const &order)
{
    std::ofstream fout(fileName, std::ios::app);

    if (fout.is_open())
    {
        fout << order.GetOrderID() << ','
             << order.GetProductID() << ','
             << order.GetOrderQuantity() << ','
             << order.GetTotalOrderPrice() << ','
             << order.GetOrderStatus() << std::endl;

        fout.close();
        return true;
    }
    else
    {
        std::cout << "WARNING: The file is not opened for the writing operation. Add Order to file" << std::endl;
        return false;
    }
}

//-----------------------------------------------------------------------------
// Function that writes data to the product file
//-----------------------------------------------------------------------------
bool FileHandling::WriteDataToProductFile(std::string const &fileName, 
    std::vector<std::vector<std::string>> const &productsData)
{
    std::ofstream fout(fileName);

    if (fout.is_open())
    {
        fout << "ProductID,ProductName,ProductPrice,ProductCategory,ProductManufacturer,ProductQuantity,UnitOfMeasure" << std::endl;

        /*for (auto const &productData : productsData)
        {
            for (auto const &field : productData)
            {
                fout << field << ',';
            }
            fout << std::endl;
        }*/

        fout.close();
        return true;
    }
    else
    {
        std::cout << "WARNING: The file is not opened for the writing operation. Write Data to Product File" << std::endl;
        return false;
    }
}

//-----------------------------------------------------------------------------
// Function that writes data to the orders file
//-----------------------------------------------------------------------------
bool FileHandling::WriteDataToOrdersFile(std::string const &fileName, 
    std::vector<std::vector<std::string>> const &ordersData)
{
    std::ofstream fout(fileName);

    if (fout.is_open())
    {
        fout << "OrderID,ProductID,OrderQuantity,TotalOrderPrice,OrderStatus" << std::endl;

       /* for (auto const &orderData : ordersData)
        {
            for (auto const &field : orderData)
            {
                fout << field << ',';
            }
            fout << std::endl;
        }*/

        fout.close();
        return true;
    }
    else
    {
        std::cout << "WARNING: The file is not opened for the writing operation. Write Data to Orders File" << std::endl;
        return false;
    }
}

//-----------------------------------------------------------------------------
// Function that writes data to the sells file
//-----------------------------------------------------------------------------
bool FileHandling::WriteDataToSellsFile(std::string const &fileName, 
    std::vector<std::vector<std::string>> const &sellsData)
{
    std::ofstream fout(fileName);

    if (fout.is_open())
    {
        fout << "SellID,ProductID,ProductName,ProductPrice,ProductCategory,ProductManufacturer,ProductQuantity,UnitOfMeasure" << std::endl;

       /* for (auto const &sellData : sellsData)
        {
            for (auto const &field : sellData)
            {
                fout << field << ',';
            }
            fout << std::endl;
        }*/

        fout.close();
        return true;
    }
    else
    {
        std::cout << "WARNING: The file is not opened for the writing operation. Write Data to Sells File" << std::endl;
        return false;
    }
}
