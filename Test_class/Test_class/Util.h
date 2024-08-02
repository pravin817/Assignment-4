#ifndef UTIL_H
#define UTIL_H

// Precomipled Header files
#include "stdafx.h"

// Corresponding header file
#include "Point2D.h"


// Standard Header files
#include <cmath>


class Util{

public:

	// Get the distance between the two points
	static double GetDistanceBetweenTwoPoints(Point2D p1, Point2D p2);

	// Functuion for the getting the power of the number
	static double powerOfNumber(double base , int exponent);

	// Function for the getting the coordinate of the point from the user
	static void GetTheCoordinatesFromUser(Point2D &p);

	// Function for the printing the coordinates of the point
	static void PrintPointEachCoordinates(Point2D &p);

	// Function for the printing the all coordinates of the triangle
	static void PrintAllCoordinates(Point2D &p1, Point2D &p2, Point2D &p3);


	// Function for the calculation of the sides of the triangle
	static void CalculateSidesOfTriangle(Point2D &p1, Point2D &p2, Point2D &p3);



};


#endif // UTIL_H