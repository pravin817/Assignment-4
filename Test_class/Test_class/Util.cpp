
#include "stdafx.h"

#include "Util.h"
#include "Point2D.h"

#include <iostream>


// Function used for the finding the power of the number
double Util::powerOfNumber(double base , int exponent){
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

// Function for the finding the distance between two points
double Util::GetDistanceBetweenTwoPoints(Point2D p1, Point2D p2){
	double distance = 0;

	// The distance between two point is given by using the distance formula

	// d = √[(X2 - X1)^2 + (Y2-Y1)^2]

	double firstTerm = powerOfNumber((p2.GetX()-p1.GetX()),2);
	double secondTerm = powerOfNumber((p2.GetY()-p1.GetY()),2);

	double term = firstTerm + secondTerm;

	distance = sqrt(term);

	return distance;
}

// Function for the geting the input from the user
void Util::GetTheCoordinatesFromUser(Point2D &pt){

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

// Function for the printing the coordinates of the point
void Util::PrintPointEachCoordinates(Point2D &pt){
	std::cout<<" ( "<<pt.GetX()<<" , "<<pt.GetY()<<" ) "<<std::endl;
}

// Function for the printing the all coordinates of the triangle
void Util::PrintAllCoordinates(Point2D &p1, Point2D &p2, Point2D &p3){
	std::cout<<"Printing the all three vertices of the triangle : ";
	PrintPointEachCoordinates(p1);
	PrintPointEachCoordinates(p2);
	PrintPointEachCoordinates(p3);
}

// Function for the calculating the sides of the triangle
void Util::CalculateSidesOfTriangle(Point2D &p1, Point2D &p2, Point2D &p3){

	// The sides of the triangle can be easy calculated by using the distance between two point formula
	double s1 = GetDistanceBetweenTwoPoints(p2,p3);
	double s2 = GetDistanceBetweenTwoPoints(p1,p3);
	double s3 = GetDistanceBetweenTwoPoints(p1,p2);

	// Set the values for the sides in the triangle

}