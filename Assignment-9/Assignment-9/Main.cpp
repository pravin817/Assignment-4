/* 
* 2.Write a store management program,to maintain inventory of various products.
* There are different ordering strategies for different products. 
* For Bulk ordering products a minimum quantity is maintained in the store. 
* Whenever the quantity goes below this, 
* order is generated using the bulk order quantity. 
* For special products, ordering is done only when there is a requirement, 
* the order being placed for actual quantity or the minimum ordering quantity. 

* The program should provide following options: 
* 1. Add product (with appropriate options) 
* 2. Issue product from store against requisition (sell product)
* 3. Receive purchased goods (Order recieved)
* 4. Generate stock report (report of products in stock, with quantity) 
* 5. Generate purchase order report 
* 6. Save & Restore

Author : Pravin Mhaske
Date : 09/09/2024

*/




/*
				    Product  (ProductID)                   ProductPresenter     
					
					  |												|
														String (Console, File, Display)
   Special Product         Bulk Product                          



   Special Order	(ORDERID)					Order : Order (Automatic)
	

   Sell : SellID 


   Issue :-> customer , product , quantity





*/ 
#include "stdafx.h"
#include "Util.h"
#include "Interface.h"
#include "Product.h"
#include "BulkProduct.h"
#include "SpecialProduct.h"
#include "IDGenerator.h"
#include "StoreManager.h"

#include <iostream>

int main()
{
	std::cout <<"Keep learning, Keep Growing !!!!!"<<std::endl;



	/**************************************************************************
		We need 3 seperate files for the storing the details about the 
		1) Products
		2) Orders
		3) Sell Products details
	**************************************************************************/
	
	std::string productFileName = "products.csv";  // File containing product details
	std::string orderFileName = "orders.csv";      // File containing order details
	std::string sellFileName = "sales.csv";        // File containing sell details

	// Example usage
	std::cout << "Product File: " << productFileName << std::endl;
	std::cout << "Order File: " << orderFileName << std::endl;
	std::cout << "Sell File: " << sellFileName << std::endl;
	StoreManager storeManager;
	int choice = -1;

	do
	{

		Util::PrintMainMenu();
		Interface::GetChoiceFromUser(choice);

		switch(choice)
		{
		case 0:
			{
				std::cout << "Exiting...."<<std::endl;
				break;
			}

		case 1:
			{
				std::cout << "|-> Add Product "<<std::endl;

				int addProductChoice = -1;
				bool flag = true;

				while(flag)
				{
					Util::GetAddProductChoiceFromUser(addProductChoice);

					switch(addProductChoice)
					{
					case 0:
						{
							std::cout << "Exiting from the add product to the store."<<std::endl;
							flag = false;
							break;
						}

					case 1:
						{
							std::cout << "|-> Add Bulk Product"<<std::endl;

							// 1. Define the required variables to store the data
							std::string productName = "";
							float productPrice = 0.0;
							std::string productCategory = "";
							std::string productManufacturer = "";
							int productQuantity = 0;
							std::string unitOfMeasure = "";

							int minimumReorderQuantity = 0;      // minimum reorder quantity of the product
							int maxProductHoldingCapacity = 0;
							int minimumThreshold = 0;

							// 2. Get the product details from the user
							Interface::GetProductAttributesFromUser(productName, productPrice,productCategory,productManufacturer,maxProductHoldingCapacity,productQuantity,unitOfMeasure,minimumThreshold);

							// 3. Generate the unique productID for each product

							int count = storeManager.GetCount("BULK");
							std::string productID = IDGenerator::GenerateProductID("BULK",++count);

							// 4. Create the product
							Product *newProduct = nullptr;
							newProduct = new BulkProduct(productID,productName, productPrice,productCategory, productManufacturer,productQuantity,unitOfMeasure,minimumReorderQuantity,maxProductHoldingCapacity,minimumThreshold);

							// 5. Add the product to the store
							bool addProductStatus = storeManager.AddProductToStore(newProduct);

							// 6. Print the product add msg
							if(addProductStatus)
							{
								std::cout << "The product added successfully to the store with the PRODUCT ID : "<<productID<<std::endl;
							}
							else
							{
								std::cout << "WANRING : We are unable to add the product to the store."<<std::endl;
							}

							break;
						}

					case 2:
						{
							std::cout << "|-> Add Special Product"<<std::endl;

							// 1. Define the required variables to store the data
							std::string productName = "";
							float productPrice = 0.0;
							std::string productCategory = "";
							std::string productManufacturer = "";
							int productQuantity = 0;
							std::string unitOfMeasure = "";

							int minimumOrder = 0;

							// 2. Get the product details from the user
							Interface::GetProductAttributesFromUser(productName, productPrice,productCategory,productManufacturer,productQuantity,unitOfMeasure,minimumOrder);

							// 3. Generate the unique productID for each product
							int count = storeManager.GetCount("SPECIAL");
							std::string productID = IDGenerator::GenerateProductID("SPECIAL",++count);

							// 4. Create the product
							Product *newProduct = nullptr;
							newProduct = new SpecialProduct(productID,productName, productPrice,productCategory, productManufacturer,productQuantity,unitOfMeasure,minimumOrder);

							// 5. Add the product to the store
							bool addProductStatus = storeManager.AddProductToStore(newProduct);

							// 6. Print the product add msg
							if(addProductStatus)
							{
								std::cout << "The product added successfully to the store with the PRODUCT ID : "<<productID<<std::endl;
							}
							else
							{
								std::cout << "WANRING : We are unable to add the product to the store."<<std::endl;
							}

							break;
						}

					default:
						{
							std::cout << "Please enter valid choice"<<std::endl;
							break;
						}
					}		
				}	
				
				// Break the add product case
				break;
			}

		case 2:
			{

				// OPTINONAL
				std::cout << "2. Update Product Details " <<std::endl;
				break;
			}

		case 3:
			{
				std::cout << "3. Issue product from store against requisition (Sell the product)" << std::endl;

				
				storeManager.IssueProductToCustomer();




				break;
			}

		case 4:
			{

				std::cout << "4. Receive purchased goods " << std::endl;

				break;
			}

		case 5:
			{
				std::cout << "5. Generate stock report" << std::endl;

				break;
			}

		case 6:
			{
				std::cout << "6. Generate purchase order report"<<std::endl;

				break;
			}


		case 7:
			{

				std::cout << "7. Save & Restore "<<std::endl;

				break;
			}
		case 8:
			{
				std::cout << "8. Show all products details"<<std::endl;

				storeManager.PrintAllProducts();
				break;
			}

		}


	}while(choice != 0);


	return 0;
}

