#include "stdafx.h"
#include "Util.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Triangle.h"
#include "Triangle3D.h"
#include<iostream>
#include <vector>

void calculationsFor2DTriangle();
void calculationsFor2DTriangle(std::vector<double>v);

//-----------------------------------------------------------------------------
// Function for the displaying the operation that can be performed on triangle
int triangleOperationMenu()
{
	int choice = -1;

	std::cout<<"1. Find the Centroid of Triangle "<<std::endl;
	std::cout<<"2. Find the Incircle center of Triangle "<<std::endl;
	std::cout<<"3. Find the Circum center of Triangle "<<std::endl;
	std::cout<<"4. Find the area of Triangle"<<std::endl;

	std::cout<<"Please select the operation that you wnat to perform : ";
	std::cin>>choice;

	return choice;
}

//-----------------------------------------------------------------------------
// Functuion that select the triangle type
int selectTriangleType()
{
	int triangleType = 0;

	std::cout<<"1. 2D Triangle"<<std::endl;
	std::cout<<"2. 3D Triangle"<<std::endl;

	std::cout<<"Please select the triangle type from the above : ";
	std::cin>>triangleType;

	return triangleType;
}

//-----------------------------------------------------------------------------
// Function that shows the main Menu
int mainMenu()
{
	int mainMenuChoice = 0;

	std::cout<<"--------------------- MENU ------------------- "<<std::endl;
	std::cout<<" 1. Take Input from the console."<<std::endl;
	std::cout<<" 2. Take Input from the file."<<std::endl;
	std::cout<<" 3. Exit."<<std::endl;

	std::cout<<"Please select the choice : ";
	std::cin>>mainMenuChoice;

	return mainMenuChoice;
}

//-----------------------------------------------------------------------------
void takeInputFromConsole()
{
	int choice;
	std::cout<<"--------------------- MENU ------------------- "<<std::endl;
	std::cout<<" 1. Take Input from the console."<<std::endl;
	std::cout<<" 2. Take Input from the file."<<std::endl;
	std::cout<<" 3. Exit."<<std::endl;

	std::cout<<"Please select the choice : ";
	std::cin>>choice;
}

// Console Input
//-----------------------------------------------------------------------------
void calculationsFor2DTriangle()
{
	Point2D p1;
	Point2D p2;
	Point2D p3;

	double side1 = 0;
	double side2 = 0;
	double side3 = 0; 

	// get the coordinates of the vertices from the user
	Util::GetTheCoordinatesFromUser(p1);
	Util::GetTheCoordinatesFromUser(p2);
	Util::GetTheCoordinatesFromUser(p3);

	Util::PrintAllCoordinates(p1,p2,p3);

	// Calculate the sides of the triangle
	side1 = Util::GetDistanceBetweenTwoPoints(p2, p3);
	side2 = Util::GetDistanceBetweenTwoPoints(p1, p3);
	side3 = Util::GetDistanceBetweenTwoPoints(p1, p2);

	// Print the side of the triangle
	Util::PrintSidesOfTriangle(side1, side2, side3);

	// Check if the vertices can formed the valid triangle
	bool isTriangle = Util::isVerticesFormedValidTriangle(side1, side2, side3);

	if(!isTriangle)
	{
		std::cout<<"No "<<std::endl;
	}
	else
	{
		// Create the object of the Triangle
		Triangle t1(p1,p2,p3,side1, side2, side3);

		// 1. Find the centroid 
		Point2D centroid = t1.GetCentroidOfTriangle();
		std::cout<<"The centroid of the Triangle is : ";
		Util::PrintCoordinateOfOneVertex(centroid);

		// 2. Incircle center of the triangle
		Point2D incenterOfTriangle = t1.GetIncenterOfTriangle();
		std::cout<<"The Incenter of the Triangle is : ";
		Util::PrintCoordinateOfOneVertex(incenterOfTriangle);

		// 3. Circum Center of Triangle
		Point2D circumCenter = t1.GetCircumCenterOfTriangle();
		std::cout<<"The Circum center of the Triangle is : ";
		Util::PrintCoordinateOfOneVertex(circumCenter);

		// 4 Area of the Triangle
		double areaOfTriangle = t1.AreaOfTriangle();
		std::cout<<"The Area of the Triangle is : "<<areaOfTriangle<<std::endl;

		std::cout<<"Exiting"<<std::endl;
	}
}


void calculationsFor3DTriangle()
{
	// Let's us consider the triangle ABC
	// Create the object of the class 
	Point3D p1;
	Point3D p2;
	Point3D p3;

	double side1 = 0;
	double side2 = 0;
	double side3 = 0; 

	// get the coordinates of the vertices from the user
	Util::GetTheCoordinatesFromUser(p1);
	Util::GetTheCoordinatesFromUser(p2);
	Util::GetTheCoordinatesFromUser(p3);

	Util::PrintAllCoordinates(p1,p2,p3);

	// Calculate the sides of the triangle
	side1 = Util::GetDistanceBetweenTwoPoints(p2, p3);
	side2 = Util::GetDistanceBetweenTwoPoints(p1, p3);
	side3 = Util::GetDistanceBetweenTwoPoints(p1, p2);

	// Print the side of the triangle
	Util::PrintSidesOfTriangle(side1, side2, side3);

	// Check if the vertices can formed the valid triangle
	bool isTriangle = Util::isVerticesFormedValidTriangle(side1, side2, side3);

	if(!isTriangle)
	{
		std::cout<<"No "<<std::endl;
	}
	else
	{
		// Create the object of the Triangle
		Triangle3D t1(p1,p2,p3,side1, side2, side3);

		// 1. Find the centroid 
		Point3D centroid = t1.GetCentroidOfTriangle();
		std::cout<<"The centroid of the Triangle is : ";
		Util::PrintCoordinateOfOneVertex(centroid);

		// 2. Incircle center of the triangle
		Point3D incenterOfTriangle = t1.GetIncenterOfTriangle();
		std::cout<<"The Incenter of the Triangle is : ";
		Util::PrintCoordinateOfOneVertex(incenterOfTriangle);

		// 3. Circum Center of Triangle
		Point3D circumCenter = t1.GetCircumCenterOfTriangle();
		std::cout<<"The Circum center of the Triangle is : ";
		Util::PrintCoordinateOfOneVertex(circumCenter);

		// 4 Area of the Triangle
		double areaOfTriangle = t1.AreaOfTriangle();
		std::cout<<"The Area of the Triangle is : "<<areaOfTriangle<<std::endl;
	}
}

// 2D triangle using the file
void calculationsFor2DTriangle(std::vector<double>v){

	// Check if we the vertices of the triangle, if we don't get then show the warning message

	int verticesSize = v.size();

	std::string fileName = "Output2D.txt";

	if(verticesSize !=6)
	{
		std::cout<<"Warning : Proper input not get from the file"<<std::endl;
		return;
	}

	Point2D p1(v[0],v[1]);
	Point2D p2(v[2],v[3]);
	Point2D p3(v[4],v[5]);

	double side1 = 0;
	double side2 = 0;
	double side3 = 0; 

	// get the coordinates of the vertices from the user
	//Util::GetTheCoordinatesFromUser(p1);
	//Util::GetTheCoordinatesFromUser(p2);
	//Util::GetTheCoordinatesFromUser(p3);

	Util::PrintAllCoordinates(p1,p2,p3);

	// Calculate the sides of the triangle
	side1 = Util::GetDistanceBetweenTwoPoints(p2, p3);
	side2 = Util::GetDistanceBetweenTwoPoints(p1, p3);
	side3 = Util::GetDistanceBetweenTwoPoints(p1, p2);

	// Print the side of the triangle
	Util::PrintSidesOfTriangle(side1, side2, side3);

	// Check if the vertices can formed the valid triangle
	bool isTriangle = Util::isVerticesFormedValidTriangle(side1, side2, side3);

	if(!isTriangle)
	{
		std::cout<<"The entered vertices can't formed the valid triangle "<<std::endl;
	}
	else
	{
		Triangle t1(p1,p2,p3,side1, side2, side3);

		// 1. Find the centroid 
		Point2D centroid = t1.GetCentroidOfTriangle();

		// 2. Incircle center of the triangle
		Point2D incenterOfTriangle = t1.GetIncenterOfTriangle();

		// 3. Circum Center of Triangle
		Point2D circumCenter = t1.GetCircumCenterOfTriangle();

		// 4 Area of the Triangle
		double areaOfTriangle = t1.AreaOfTriangle();

		Util::WriteToFile(fileName,centroid, incenterOfTriangle, circumCenter, areaOfTriangle);
	}
}

// 3D Triangle By using the file Handling
void calculationsFor3DTriangle(std::vector<double>v){

	int verticesSize = v.size();

	std::string fileName = "Output3D.txt";

	// Check if we get the 9 point of the triangle for the 3D triangle
	if(verticesSize !=9)
	{
		std::cout<<"Warning : Proper input not get from the file"<<std::endl;
		return;
	}

	Point3D p1(v[0],v[1],v[2]);
	Point3D p2(v[3],v[4],v[5]);
	Point3D p3(v[6],v[7],v[8]);

	double side1 = 0;
	double side2 = 0;
	double side3 = 0; 

	// Print the vertices of the triangle
	Util::PrintAllCoordinates(p1,p2,p3);

	// Calculate the sides of the triangle
	side1 = Util::GetDistanceBetweenTwoPoints(p2, p3);
	side2 = Util::GetDistanceBetweenTwoPoints(p1, p3);
	side3 = Util::GetDistanceBetweenTwoPoints(p1, p2);

	// Print the side of the triangle
	Util::PrintSidesOfTriangle(side1, side2, side3);

	// Check if the vertices can formed the valid triangle
	bool isTriangle = Util::isVerticesFormedValidTriangle(side1, side2, side3);

	if(!isTriangle)
	{
		std::cout<<"Warning : We can't fromed the valid triangle from the vertices of the triangle."<<std::endl;
	}
	else
	{
		// Create the object of the Triangle
		Triangle3D t1(p1,p2,p3,side1, side2, side3);

		// 1. Find the centroid 
		Point3D centroid = t1.GetCentroidOfTriangle();

		// 2. Incircle center of the triangle
		Point3D incenterOfTriangle = t1.GetIncenterOfTriangle();

		// 3. Circum Center of Triangle
		Point3D circumCenter = t1.GetCircumCenterOfTriangle();

		// 4 Area of the Triangle
		double areaOfTriangle = t1.AreaOfTriangle();

		Util::WriteToFile(fileName,centroid, incenterOfTriangle, circumCenter, areaOfTriangle);
	}
}



int main()
{

	int choice = -1;

	do{
		std::cout<<"--------------------- Menu ------- "<<std::endl;
		std::cout<<"triangle assignment for using the file handling"<<std::endl;
		std::cout<<" 1. 2D Triangle ."<<std::endl;
		std::cout<<" 2. 3D Traingle ."<<std::endl;
		std::cout<<" 3. Exit "<<std::endl;

		std::cout<<"Please enter the choice : "<<std::endl;
		std::cin>>choice;

		switch(choice){
		case 1:
			{
				// 2D 

				std::vector<double>verticesOfTriangle;

				// util
				std::string fileName = "Input2D.txt";

				Util::GetInputFromFile(fileName,verticesOfTriangle);

				calculationsFor2DTriangle(verticesOfTriangle);

				break;
			}


		case 2:
			{
				//3D 

				std::cout<<"3D File handling"<<std::endl;

				std::vector<double>verticesOfTriangle;

				std::string fileName = "Input3D.txt";

				Util::GetInputFromFile(fileName,verticesOfTriangle);


				// Print the vertices of Triangle
				Util::PrintVerticesOfTriangle(verticesOfTriangle);
				calculationsFor3DTriangle(verticesOfTriangle);

				break;
			}

		case 3:
			{
				std::cout<<"Exiting...."<<std::endl;
				break;
			}

		default:
			{
				std::cout<<"Please select the correct choice"<<std::endl;
			}

		}
	}while(choice!=3);



	//switch(choice)
	//{
	//case 1:
	//	{
	//		// Let's us consider the triangle ABC
	//		// Create the object of the class 
	//		Point2D p1;
	//		Point2D p2;
	//		Point2D p3;

	//		double side1 = 0;
	//		double side2 = 0;
	//		double side3 = 0; 

	//		// get the coordinates of the vertices from the user
	//		Util::GetTheCoordinatesFromUser(p1);
	//		Util::GetTheCoordinatesFromUser(p2);
	//		Util::GetTheCoordinatesFromUser(p3);

	//		Util::PrintAllCoordinates(p1,p2,p3);

	//		// Calculate the sides of the triangle
	//		side1 = Util::GetDistanceBetweenTwoPoints(p2, p3);
	//		side2 = Util::GetDistanceBetweenTwoPoints(p1, p3);
	//		side3 = Util::GetDistanceBetweenTwoPoints(p1, p2);

	//		// Print the side of the triangle
	//		Util::PrintSidesOfTriangle(side1, side2, side3);

	//		// Check if the vertices can formed the valid triangle
	//		bool isTriangle = Util::isVerticesFormedValidTriangle(side1, side2, side3);

	//		if(!isTriangle)
	//		{
	//			std::cout<<"No "<<std::endl;
	//		}
	//		else
	//		{
	//			// Vertices of the triangle formed the valid triangle hence we can perform the different operations on the triangle

	//			// Create the object of the Triangle
	//			Triangle t1(p1,p2,p3,side1, side2, side3);

	//			// 1. Find the centroid 
	//			Point2D centroid = t1.GetCentroidOfTriangle();
	//			std::cout<<"The centroid of the Triangle is : ";
	//			Util::PrintCoordinateOfOneVertex(centroid);

	//			// 2. Incircle center of the triangle
	//			Point2D incenterOfTriangle = t1.GetIncenterOfTriangle();
	//			std::cout<<"The Incenter of the Triangle is : ";
	//			Util::PrintCoordinateOfOneVertex(incenterOfTriangle);

	//			// 3. Circum Center of Triangle
	//			Point2D circumCenter = t1.GetCircumCenterOfTriangle();
	//			std::cout<<"The Circum center of the Triangle is : ";
	//			Util::PrintCoordinateOfOneVertex(circumCenter);

	//			// 4 Area of the Triangle
	//			double areaOfTriangle = t1.AreaOfTriangle();
	//			std::cout<<"The Area of the Triangle is : "<<areaOfTriangle<<std::endl;
	//		}

	//		break;
	//	}

	//case 2:
	//			{
	//		// Let's us consider the triangle ABC
	//		// Create the object of the class 
	//		Point3D p1;
	//		Point3D p2;
	//		Point3D p3;

	//		double side1 = 0;
	//		double side2 = 0;
	//		double side3 = 0; 

	//		// get the coordinates of the vertices from the user
	//		Util::GetTheCoordinatesFromUser(p1);
	//		Util::GetTheCoordinatesFromUser(p2);
	//		Util::GetTheCoordinatesFromUser(p3);

	//		Util::PrintAllCoordinates(p1,p2,p3);

	//		// Calculate the sides of the triangle
	//		side1 = Util::GetDistanceBetweenTwoPoints(p2, p3);
	//		side2 = Util::GetDistanceBetweenTwoPoints(p1, p3);
	//		side3 = Util::GetDistanceBetweenTwoPoints(p1, p2);

	//		// Print the side of the triangle
	//		Util::PrintSidesOfTriangle(side1, side2, side3);

	//		// Check if the vertices can formed the valid triangle
	//		bool isTriangle = Util::isVerticesFormedValidTriangle(side1, side2, side3);

	//		if(!isTriangle)
	//		{
	//			std::cout<<"No "<<std::endl;
	//		}
	//		else
	//		{
	//			// Vertices of the triangle formed the valid triangle hence we can perform the different operations on the triangle

	//			// Create the object of the Triangle
	//			Triangle3D t1(p1,p2,p3,side1, side2, side3);

	//			// 1. Find the centroid 
	//			Point3D centroid = t1.GetCentroidOfTriangle();
	//			std::cout<<"The centroid of the Triangle is : ";
	//			Util::PrintCoordinateOfOneVertex(centroid);

	//			// 2. Incircle center of the triangle
	//			Point3D incenterOfTriangle = t1.GetIncenterOfTriangle();
	//			std::cout<<"The Incenter of the Triangle is : ";
	//			Util::PrintCoordinateOfOneVertex(incenterOfTriangle);

	//			// 3. Circum Center of Triangle
	//			Point3D circumCenter = t1.GetCircumCenterOfTriangle();
	//			std::cout<<"The Circum center of the Triangle is : ";
	//			Util::PrintCoordinateOfOneVertex(circumCenter);

	//			// 4 Area of the Triangle
	//			double areaOfTriangle = t1.AreaOfTriangle();
	//			std::cout<<"The Area of the Triangle is : "<<areaOfTriangle<<std::endl;
	//		}

	//		break;
	//	}
	//}

	return 0;
}

