#ifndef UTIL_H
#define UTIL_H

#include "stdafx.h"
#include "Point2D.h"
#include "Point3D.h"
#include <cmath>
#include <vector>

class Util
{
public:

	// Independent Function

	// Function for the getting the power of the number
	static double powerOfNumber(double base , int exponent);

	// Function for getting the distance between two points
	static double GetDistanceBetweenTwoPoints(Point2D p1, Point2D p2);
	static double GetDistanceBetweenTwoPoints(Point3D p1, Point3D p2);

	// Function for getting the coordinates of the point from the user
	static void GetTheCoordinatesFromUser(Point2D &p);
	static void GetTheCoordinatesFromUser(Point3D &p);

	// Function for the printing coordinates of one point
	static void PrintCoordinateOfOneVertex(Point2D const &p);
	static void PrintCoordinateOfOneVertex(Point3D const &p);

	// Function for the printing the all coordinates of the triangle
	static void PrintAllCoordinates(Point2D const &p1, 
									Point2D const &p2, 
									Point2D const &p3);
	static void PrintAllCoordinates(Point3D const &p1, 
									Point3D const &p2, 
									Point3D const &p3);

	// Function for calculation of sides of triangle
	static void CalculateSidesOfTriangle(Point2D &p1, 
										 Point2D &p2, 
										 Point2D &p3);

	// Function to check if the vertices can formed the valid triangle
	static bool isVerticesFormedValidTriangle(double s1, double s2, double s3);

	// Function for the printing the sides of the triangle
	static void PrintSidesOfTriangle(double s1, double s2, double s3);

	// Function for the processing the input string 
	// and converting it into the vertices of the triangle
	static void processString(std::string &input, char delimiter, 
							  std::vector<double>&vertices);
	
	// Function for the reading data from the file
	static void GetInputFromFile(std::string fileName, 
								 std::vector<double>&vertices);

	// Function for writting the calculations to file
	static void WriteToFile(std::string fileName,
							Point2D &centroid, 
							Point2D &incircleCenter, 
							Point2D &circumCenter, double area);

	static void WriteToFile(std::string fileName,
							Point3D &centroid, 
							Point3D &incircleCenter, 
							Point3D &circumCenter, double area);

	// Function for the printing the vertices of triangle
	static void PrintVerticesOfTriangle(std::vector<double>&vertices);
};



#endif // UTIL_H