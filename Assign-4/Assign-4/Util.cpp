#include "stdafx.h"
#include "Util.h"
#include "Point2D.h"
#include "Point3D.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

//-----------------------------------------------------------------------------
// Function used for the finding the power of the number
double Util::powerOfNumber(double base , int exponent)
{
	double result = 1;

	// Check the exponent for the negative values
	bool isExponentNegative = false;

	// Check if the expoent is negative 
	if(exponent < 0){
		isExponentNegative = true;
		exponent = -1 * exponent;
	}

	// We know that the power of number whose index is zero(0) is always 1.0
	if(exponent == 0)
		return 1.0;

	for(int i = 0; i < exponent; ++i){
		result *= base;
	}

	// return the value of the power based 
	// on the exponent which is positive or negative
	if(isExponentNegative){
		return 1/result;
	}else{
		return result;
	}
}

//-----------------------------------------------------------------------------
// Function for the finding the distance between two points (2D)
double Util::GetDistanceBetweenTwoPoints(Point2D p1, Point2D p2)
{
	double distance = 0;

	// The distance between two point is given by using the distance formula
	// d =  Under root of [(X2 - X1)^2 + (Y2-Y1)^2]

	double firstTerm = powerOfNumber((p2.GetX()-p1.GetX()),2);
	double secondTerm = powerOfNumber((p2.GetY()-p1.GetY()),2);

	double term = firstTerm + secondTerm;

	distance = sqrt(term);

	return distance;
}

//-----------------------------------------------------------------------------
// Function for the finding the distance between two points (3D)
double Util::GetDistanceBetweenTwoPoints(Point3D p1, Point3D p2)
{
	double distance = 0;

	// The distance between two point is given by using the distance formula
	// d =  Under root of [(X2 - X1)^2 + (Y2-Y1)^2 + (Z2-Z1)^2]

	double firstTerm = powerOfNumber((p2.GetX()-p1.GetX()),2);
	double secondTerm = powerOfNumber((p2.GetY()-p1.GetY()),2);
	double thirdTerm = powerOfNumber((p2.GetZ()-p1.GetZ()),2);

	double term = firstTerm + secondTerm + thirdTerm;

	distance = sqrt(term);

	return distance;
}

//-----------------------------------------------------------------------------
// Function for the geting the input from the user (2D)
void Util::GetTheCoordinatesFromUser(Point2D &pt)
{
	double x = 0;
	double y = 0;

	std::cout<<"Enter the X - coordinate of the vertices : ";
	std::cin>>x;

	std::cout<<"Enter the Y - coordinate of the vertices : ";
	std::cin>>y;

	// change the value inside the object
	pt.SetX(x);
	pt.SetY(y);
}

//-----------------------------------------------------------------------------
// Function for the geting the input from the user (3D)
void Util::GetTheCoordinatesFromUser(Point3D &pt)
{
	double x = 0;
	double y = 0;
	double z = 0;

	std::cout<<"Enter the X - coordinate of the vertices : ";
	std::cin>>x;

	std::cout<<"Enter the Y - coordinate of the vertices : ";
	std::cin>>y;

	std::cout<<"Enter the Z - coordinate of the vertices : ";
	std::cin>>z;

	// Set the values of x,y,z
	pt.SetX(x);
	pt.SetY(y);
	pt.SetZ(z);
}

//-----------------------------------------------------------------------------
// Function for the printing the coordinates of the point (2D)
void Util::PrintCoordinateOfOneVertex(Point2D const &pt)
{
	std::cout<<" ( "<<pt.GetX()<<" , "<<pt.GetY()<<" ) "<<std::endl;
}

//-----------------------------------------------------------------------------
// Function for the printing the coordinates of the point (3D)
void Util::PrintCoordinateOfOneVertex(Point3D const &pt)
{
	std::cout<<" ( "<<
					pt.GetX()<<" , "<<
					pt.GetY()<<" , "<<
					pt.GetZ()<<" )"<<std::endl;
}

//-----------------------------------------------------------------------------
// Function for the printing the all coordinates of the triangle (2D)
void Util::PrintAllCoordinates(Point2D const &p1, 
							   Point2D const &p2, 
							   Point2D const &p3)
{
	std::cout<<"Printing the all three vertices of the triangle : "<<std::endl;
	PrintCoordinateOfOneVertex(p1);
	PrintCoordinateOfOneVertex(p2);
	PrintCoordinateOfOneVertex(p3);
}

//-----------------------------------------------------------------------------
// Function for the printing the all coordinates of the triangle (3D)
void Util::PrintAllCoordinates(Point3D const &p1, 
							   Point3D const &p2, 
							   Point3D const &p3)
{
	std::cout<<"Printing the all three vertices of the triangle : "<<std::endl;
	PrintCoordinateOfOneVertex(p1);
	PrintCoordinateOfOneVertex(p2);
	PrintCoordinateOfOneVertex(p3);
}

//-----------------------------------------------------------------------------
// Function for the calculating the sides of the triangle
void Util::CalculateSidesOfTriangle(Point2D &p1, Point2D &p2, Point2D &p3)
{

	// The sides of the triangle can be easy calculated 
	// by using the distance between two point formula

	double s1 = GetDistanceBetweenTwoPoints(p2,p3);
	double s2 = GetDistanceBetweenTwoPoints(p1,p3);
	double s3 = GetDistanceBetweenTwoPoints(p1,p2);
}

//-----------------------------------------------------------------------------
// Function for the printing the sides of the triangle
void Util::PrintSidesOfTriangle(double s1, double s2, double s3)
{
	std::cout<<"The sides of the triangle are : ";
	std::cout<<s1<<" , "<<s2<<" , "<<s3<<std::endl;
}

//-----------------------------------------------------------------------------
// Function that checks if the vertices can formed the valid triangle or not
bool Util::isVerticesFormedValidTriangle(double s1, double s2, double s3){

	// Check if the vertices can be formed the valid triangle

	if( ( (s1 + s2) > s3) && ((s2+s3) > s1) && ( (s1+s3) > s2 )){
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
// Function for the printing the vertices of triangle
void Util::PrintVerticesOfTriangle(std::vector<double>&vertices)
{
	int verticesLength = vertices.size();
	std::cout<<"Print the vertices of the triangle : ";
	for(int i = 0;i<verticesLength;++i)
	{
		std::cout<<vertices[i]<<" ";
	}
	std::cout<<std::endl;
}

//-----------------------------------------------------------------------------
// Function used for the processing the string 
void Util::processString(std::string &input,char delimiter, 
						 std::vector<double>&vertices)
{    

    std::string token;
    std::stringstream ss(input);
    
    // Now iterate over the input string
    while(getline(ss,token, delimiter)){
        vertices.push_back(stod(token));
    }
}


//-----------------------------------------------------------------------------
// Function for the reading data from the file
void Util::GetInputFromFile(std::string fileName,
							std::vector<double>& vertices)
{
    std::ifstream fin(fileName);
    
    std::vector<std::string> triangleCoordinates;
    char delimiter = ',';

    // Check if the file is opened or not
    if (fin.is_open()) {
        std::cout<<"Congratulations !!! File opened successfully."<<std::endl;
        
        // Read the coordinates of the point from file
        std::string coordinates;
        
        while (std::getline(fin, coordinates)) {
            triangleCoordinates.push_back(coordinates);
        }
        
        // Print the triangle coordinates
        int triangleCount = triangleCoordinates.size();
        for (int i = 0; i < triangleCount; ++i) {
            std::cout<< "[ " << (i + 1) << " ] : " 
					 << triangleCoordinates[i] << std::endl;
        }
        
        // Now take out the coordinates of the point from the string
        int triangleNumber = 0;
        std::cout << "Select the triangle that you want to select: ";
        std::cin >> triangleNumber;

		if(triangleNumber < 1 || triangleNumber > triangleCount)
		{
			std::cout<<"Please select the triangle number from 1 to "
					 <<triangleCount<<std::endl;
			return;
		}
        
        std::string currentTriangleCoordinates = triangleCoordinates[triangleNumber - 1];
        Util::processString(currentTriangleCoordinates, delimiter, vertices);
        
        // Close the file
        fin.close();
		std::cout<<"File closed successfully after the read operation"<<std::endl;
    } else {
        std::cout << "Warning - File is not opened." << std::endl;
    }
}

//-----------------------------------------------------------------------------
// Function for the Writing to the file (2D)
void Util::WriteToFile(std::string fileName,
					   Point2D &centroid, 
					   Point2D &incircleCenter, 
					   Point2D &circumCenter, double area)
{
	std::cout<<"The file writing operation started : "<<std::endl;

	// Open the file for the writing
	std::ofstream fout(fileName, std::ios_base::app);

	// check if the file is opened or not
	if(fout.is_open()){

		std::cout<<"File opened successfully."<<std::endl;

		fout<<"Centroid     : ("<<centroid.GetX()<<", "
			<<centroid.GetY()<<" )"<<std::endl;
		fout<<"Incircle     : ("<<incircleCenter.GetX()
			<<", "<<incircleCenter.GetY()<<" )"<<std::endl;
		fout<<"CircumCircle : ("<<circumCenter.GetX()
			<<", "<<circumCenter.GetY()<<" )"<<std::endl;
		fout<<"Area         :  "<<area<<std::endl;

		std::cout<<"The data saved in Output2D.txt file"<<std::endl;

		// close the file
		fout.close();
		std::cout<<"File close successfully."<<std::endl;
	}else{
		std::cout<<"Warning : The file is not opened ";
		std::cout<<" the write operation is not possible"<<std::endl;
	}
}

//-----------------------------------------------------------------------------
// Function for the Writing to the file (3D)
void Util::WriteToFile(std::string fileName,
					   Point3D &centroid, 
					   Point3D &incircleCenter, 
					   Point3D &circumCenter, double area)
{
	std::cout<<"The file writing operation started : "<<std::endl;

	// Open the file for the writing
	std::ofstream fout(fileName, std::ios_base::app);

	// check if the file is opened or not
	if(fout.is_open()){

		std::cout<<"File opened successfully."<<std::endl;

		fout<<"Centroid     : ("<<centroid.GetX()<<", "<<centroid.GetY()<<" , "<<centroid.GetZ()<<" )"<<std::endl;
		fout<<"Incircle     : ("<<incircleCenter.GetX()<<", "<<incircleCenter.GetY()<<" , "<<incircleCenter.GetZ()<<" )"<<std::endl;
		fout<<"CircumCircle : ("<<circumCenter.GetX()<<", "<<circumCenter.GetY()<<" , "<<circumCenter.GetZ()<<" )"<<std::endl;
		fout<<"Area         :  "<<area<<std::endl;

		std::cout<<"The data saved in "<<fileName<<"file"<<std::endl;

		std::cout<<"File close successfully."<<std::endl;
		// close the file
		fout.close();
	}else{
		std::cout<<"Warning : The file is not opened hence the write operation is not possible"<<std::endl;
	}
}
