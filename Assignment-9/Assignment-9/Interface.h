#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>

class Interface
{
public:
    //------------------------------------------------------------------------
    // Function for getting the choice from the user
    static void GetChoiceFromUser(int &choice);

    // Function that takes the attributes of the product from the user
    static void GetProductAttributesFromUser(std::string &productName, 
        float &productPrice, 
        std::string &productCategory, 
        std::string &productManufacturer, 
        int &maxProductHoldingCapacity,
        int &productQuantity, 
        std::string &unitOfMeasure, 
        int &minimumThreshold);

    // Overloaded function that takes the attributes of the product from the user
    static void GetProductAttributesFromUser(std::string &productName, 
        float &productPrice, 
        std::string &productCategory, 
        std::string &productManufacturer, 
        int &productQuantity, 
        std::string &unitOfMeasure, 
        int &minimumOrder);
};

#endif // INTERFACE_H
