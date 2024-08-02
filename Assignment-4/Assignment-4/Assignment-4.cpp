/*
	Assignment : 
		1) Find the centroid, incircle center and radius, circumcircle center 
		and radius of triangle - manual input, manual verification
	Additional Inputs:
		1. Write functions to find the centroid, incircle center and radius, 
			circumcircle center and radius of a triangle given in form of x,y 
			coordinates of three vertices.
		2. Take the three vertices of triangle as input and print the centroid, 
			incircle and circumcirle information.
	Author : Pravin Mhaske
	Date : 23/07/2024
*/

//Find the 
// 1) centroid, 
// 2) incircle center and radius, 
// 3) circumcircle center and radius of triangle - manual input, 
//    manual verification

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <vector>

// Function for the 2D
//-----------------------------------------------------------------------------
// Function for the getting the vertices of the triangle
void get2DTriangleVertices(std::vector<double>&verticesOfTriangle){
	double x1 = 0,
		y1 = 0,
		x2 = 0,
		y2 = 0,
		x3 = 0,
		y3 = 0;

	std::cout<<"Enter the X Co-ordinate of 1st vertex : ";
	std::cin>>x1;
	std::cout<<"Enter the Y Co-ordinate of 1st vertex : ";
	std::cin>>y1;

	std::cout<<"Enter the X Co-ordinate of 2nd vertex : ";
	std::cin>>x2;
	std::cout<<"Enter the Y Co-ordinate of 2nd vertex : ";
	std::cin>>y2;

	std::cout<<"Enter the X Co-ordinate of 3rd vertex : ";
	std::cin>>x3;
	std::cout<<"Enter the Y Co-ordinate of 3rd vertex : ";
	std::cin>>y3;

	// Push the vertices into the vertices vector
	verticesOfTriangle.push_back(x1);
	verticesOfTriangle.push_back(y1);
	verticesOfTriangle.push_back(x2);
	verticesOfTriangle.push_back(y2);
	verticesOfTriangle.push_back(x3);
	verticesOfTriangle.push_back(y3);
}

//-----------------------------------------------------------------------------
// Function for finding the distance between two points using distance formula
double distanceBetweenTwoPoints2D(double x1, double y1, double x2, double y2){

	// Formula :
	// D = √ (x2-x1)^2 + (y2-y1)^2 

	double firstTerm = pow((x2-x1),2);
	double secondTerm = pow((y2-y1),2);

	double term = firstTerm + secondTerm;

	double distance = sqrt(term);

	return distance;
}

//-----------------------------------------------------------------------------
// Function for calculating the sides of the triangle by using the distance formula
void calculateSidesOfTriangle2D(std::vector<double>v,
	std::vector<double>&sidesOfTriangle2D){

		// Sides of traingle 
		// Let the ▲ ABC then side a,b,c 
		// AB - c 
		// BC - a 
		// AC - b   

		double a = distanceBetweenTwoPoints2D(v[2],v[3],v[4],v[5]);

		double b = distanceBetweenTwoPoints2D(v[4],v[5],v[0],v[1]);

		double c = distanceBetweenTwoPoints2D(v[0], v[1],v[2],v[3]);

		// Insert the sides into the sidesOfTriangle
		sidesOfTriangle2D.push_back(a);
		sidesOfTriangle2D.push_back(b);
		sidesOfTriangle2D.push_back(c);
}

//-----------------------------------------------------------------------------
// Function for finding the area of the triangle 
double areaOfTriangle(std::vector<double>vertices){

	// Take out the vertices of triangle
	double x1 = vertices[0];
	double y1 = vertices[1];
	double x2 = vertices[2];
	double y2 = vertices[3];
	double x3 = vertices[4];
	double y3 = vertices[5];

	// Formula 
	// A = 1/2 [x1(y2-y3) + x2(y3-y1) + x3(y1-y2)]

	double area = 0.5 * fabs( (x1*(y2-y3)) + (x2*(y3-y1)) + (x3*(y1-y2)) );

	return area;
}

//-----------------------------------------------------------------------------
// Function for the finding the semi perimeter of the triangle
double perimeterOfTriangle(std::vector<double>&sides){

	// Take out the all sides of the triangle 
	double a = sides[0];
	double b = sides[1];
	double c = sides[2];

	double perimeter = a+b+c;

	return perimeter;
}

//-----------------------------------------------------------------------------
// Function for the checking if the triangle is valid or not.
bool isTriangleValid(std::vector<double>&sides){

	// Formula for checking if the ▲ is valid or not .
	// If the sum of any two sides of triangle must be greater than the 
	// third side of the triangle then it is valid triangle else 
	// it is not valid triangle

	// If the sum of two sides of the triangle is equal to the third side 
	// then the points are collinear

	// Take out the sides from the sides vector
	double a = sides[0];
	double b = sides[1];
	double c = sides[2];

	// Check the valid triangle condition

	if( ((a+b) > c) && ((b+c) > c) && ((c+a) > b)){
		return true;
	}

	return false;
}

//-----------------------------------------------------------------------------
// Function for the printing the vertices of the triangle
void print(std::vector<double>&v){
	int length = v.size();
	for(int i = 0; i <length; ++i){
		std::cout<<v[i]<<" ";
	}
	std::cout<<std::endl;
}

//-----------------------------------------------------------------------------
// Function for the finding the centroid of the triangle
std::pair<double, double> centroidOfTriangle(std::vector<double> vertices){

	std::pair<double,double>centroid;

	double x1 = vertices[0];
	double y1 = vertices[1];
	double x2 = vertices[2];
	double y2 = vertices[3];
	double x3 = vertices[4];
	double y3 = vertices[5];

	double centroidX = (x1+x2+x3)/3.0;
	double centroidY = (y1+y2+y3)/3.0;

	centroid.first = centroidX;
	centroid.second = centroidY;

	return centroid;
}

//-----------------------------------------------------------------------------
// Function for finding the incircle center of the triangle and radius.
void findInCircleCenterAndRadius(std::vector<double>vertices, 
	std::vector<double>&sidesOfTriangle,
	std::pair<double,double>&inCircleCenter,
	double &inCircleRadius){

		// Take out the values 
		// Vertices of the triangle
		double x1 = vertices[0];
		double y1 = vertices[1];
		double x2 = vertices[2];
		double y2 = vertices[3];
		double x3 = vertices[4];
		double y3 = vertices[5];

		// Sides of triangle
		double a = sidesOfTriangle[0];
		double b = sidesOfTriangle[1];
		double c = sidesOfTriangle[2];

		// Incenter of the triangle by using the three vertices and the three 
		// side of the triangle ,Formula 
		// [ (z*x1 + b*x2 + c*x3)/(a+b+c), (a*y1 + b*y2 + c*y3)/(a+b+c)]

		double Ix = (a*x1 + b*x2 + c*x3) / (a+b+c);
		double Iy = (a*y1 + b*y2 + c*y3) / (a+b+c);

		// Now find the radius of the incircle center, Which can be find by 
		// calculating the distance between the incircle center and any midpoint
		// if the triangle is equilateral triangle.
		// General Formula :
		// r = A / S, 
		// Where A is the area of the triangle and S is the semiperimeter of the triangle.
		// S = (a+b+c)/2
		// A = 1/2 [x1(y2-y3) + x2(y3-y1) + x3(y1-y2)]
		// take the mod because the area never be negative.

		// Area of the Triangle 
		double Area = areaOfTriangle(vertices);

		// Semiperimeter of Triangle
		double semiPerimeter = perimeterOfTriangle(sidesOfTriangle)/2.0;

		double inRadius = Area / semiPerimeter;

		// Now push these values into the vector.
		inCircleCenter.first = Ix;
		inCircleCenter.second = Iy;
		inCircleRadius = inRadius;
}

//-----------------------------------------------------------------------------
// Function for the finding the circum center of the trinagle
void circumCenterOfTriangle(std::vector<double>&vertices, 
	std::pair<double,double>&circumCircleCenter,
	double &circumCircleRadius){

		// Take out the values 
		// Vertices of the triangle
		double x1 = vertices[0];
		double y1 = vertices[1];
		double x2 = vertices[2];
		double y2 = vertices[3];
		double x3 = vertices[4];
		double y3 = vertices[5];

		// Calculation for the circum center of the triangle 

		// Formula : 


		// The formula goes here 

		double numeratorX = (( pow(x1,2) + pow(y1,2)) * (y2-y3) + 
			( pow(x2,2) + pow(y2,2)) * (y3-y1) + 
			( pow(x3,2) + pow(y3,2)) * (y1-y2));

		double numeratorY = (( pow(x1,2) + pow(y1,2)) * (x3-x2) +
			( pow(x2,2) + pow(y2,2)) * (x1-x3) + 
			( pow(x3,2) + pow(y3,2)) * (x2-x1));

		double denominator = 2*((x1-x2) * (y2-y3) - (x2-x3) * (y1-y2));

		// Handle the exception if the denominator is zero (0)
		if(denominator == 0){
			circumCircleCenter.first = 9.122001;
			circumCircleCenter.second = 9.122001;
		}

		double circumcenterX = numeratorX / denominator;
		double circumcenterY = numeratorY / denominator;

		// Now find the radius of the circumcenter of the triangle 
		// Which is eqaul to the distance bwteen the circumcenter and 
		// the one of the vertices of the triangle
		double circumcenterRadius = distanceBetweenTwoPoints2D(circumcenterX,
			circumcenterY,x1,y1);

		// Now push the result into the vector.
		circumCircleCenter.first = circumcenterX;
		circumCircleCenter.first = circumcenterY;
		circumCircleRadius = circumcenterRadius;
}

// Function for the 3D
//-----------------------------------------------------------------------------
// Function for the getting the vertices of the triangle
void get3DTriangleVertices(std::vector<double>&verticesOf3DTriangle){

	double x1 = 0,
		y1 = 0,
		z1 = 0,

		x2 = 0,
		y2 = 0,
		z2 = 0,

		x3 = 0,
		y3 = 0,
		z3 = 0;

	// First vertices
	std::cout<<"Enter the X - co-ordinate of the 1st vertices : ";
	std::cin>>x1;

	std::cout<<"Enter the Y - co-ordinate of the 1st vertices : ";
	std::cin>>y1;


	std::cout<<"Enter the Z - co-ordinate of the 1st vertices : ";
	std::cin>>z1;

	// Second vertices
	std::cout<<"Enter the X - co-ordinate of the 2nd vertices : ";
	std::cin>>x2;

	std::cout<<"Enter the y - co-ordinate of the 2nd vertices : ";
	std::cin>>y2;

	std::cout<<"Enter the z - co-ordinate of the 2nd vertices : ";
	std::cin>>z2;

	// Third vertices
	std::cout<<"Enter the x - co-ordinate of the 3rd vertices : ";
	std::cin>>x3;

	std::cout<<"Enter the y - co-ordinate of the 3rd vertices : ";
	std::cin>>y3;

	std::cout<<"Enter the z - co-ordinate of the 3rd vertices : ";
	std::cin>>z3;

	// Insert the three vertices into the vector in order
	// (x,y,z) from 1st to 3rd

	verticesOf3DTriangle.push_back(x1);
	verticesOf3DTriangle.push_back(y1);
	verticesOf3DTriangle.push_back(z1);
	verticesOf3DTriangle.push_back(x2);
	verticesOf3DTriangle.push_back(y2);
	verticesOf3DTriangle.push_back(z2);
	verticesOf3DTriangle.push_back(x3);
	verticesOf3DTriangle.push_back(y3);
	verticesOf3DTriangle.push_back(z3);
}

// Function for finding the distance between two points using distance formula
// for the 3D triangle
double distanceBetweenTwoPoints3D(double x1, double y1, double z1, 
	double x2, double y2, double z2){

		// Formula :
		// D = √ (x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2

		double firstTerm = pow((x2-x1),2);
		double secondTerm = pow((y2-y1),2);
		double thirdTerm = pow((z2-z1),2);

		double term = firstTerm + secondTerm + thirdTerm;

		double distance = sqrt(term);

		return distance;
}

//-----------------------------------------------------------------------------
// Function for calculating the sides of the triangle by using 
// the distance formula
void calculateSidesOf3DTriangle(std::vector<double>v,
	std::vector<double>&sidesOfTriangle3D){


		// Sides of traingle 
		// Let the ▲ ABC then side a,b,c 
		// AB - c 
		// BC - a 
		// AC - b   

		double a = distanceBetweenTwoPoints3D(v[3],v[4],v[5],v[6],v[7],v[8]);

		double b = distanceBetweenTwoPoints3D(v[0],v[1],v[2],v[6],v[7],v[8]);

		double c = distanceBetweenTwoPoints3D(v[0],v[1],v[2],v[3],v[4],v[5]);

		// Insert the sides into the sidesOfTriangle
		sidesOfTriangle3D.push_back(a);
		sidesOfTriangle3D.push_back(b);
		sidesOfTriangle3D.push_back(c);
}

//-----------------------------------------------------------------------------
// Function for finding the area of the 3D triangle 
double areaOf3DTriangle(std::vector<double>sidesOf3DTriangle){

	// Take out the sides of the 3D triangle
	double a = sidesOf3DTriangle[0];
	double b = sidesOf3DTriangle[1];
	double c = sidesOf3DTriangle[2];

	// Formula for the finding the area of the triangle by using the 
	// Hero's formula
	// A = √ s(s-a)(s-b)(s-c) 

	double s = (a+b+c)/2.0;
	double term = s*(s-a)*(s-b)*(s-c);
	double area = sqrt(term);

	return area;
}

//-----------------------------------------------------------------------------
// Function for the finding the centroid of the 3D triangle
void calculateCentroidOf3DTriangle(std::vector<double>verticesOf3DTriangle, std::vector<double>&centroidOf3DTriangle){

	double x1 = verticesOf3DTriangle[0];
	double y1 = verticesOf3DTriangle[1];
	double z1 = verticesOf3DTriangle[2];

	double x2 = verticesOf3DTriangle[3];
	double y2 = verticesOf3DTriangle[4];
	double z2 = verticesOf3DTriangle[5];

	double x3 = verticesOf3DTriangle[6];
	double y3 = verticesOf3DTriangle[7];
	double z3 = verticesOf3DTriangle[8];

	double Gx = (x1+x2+x3)/3.0;

	double Gy = (y1+y2+y3)/3.0;

	double Gz = (z1+z2+z3)/3.0;

	centroidOf3DTriangle.push_back(Gx);
	centroidOf3DTriangle.push_back(Gy);
	centroidOf3DTriangle.push_back(Gz);
}

//-----------------------------------------------------------------------------
// Function for finding the incircle center of the triangle and radius of 3D.
void findInCircleCenterAndRadiusOf3DTriangle(
	std::vector<double>verticesOf3DTriangle, 
	std::vector<double>&sidesOfTriangle3DTriangle,
	std::vector<double>&inCircleCenterOf3DTriangle,
	double &inCircleRadiusOf3DTriangle){

		// Take out the values 
		// Vertices of the triangle
		double x1 = verticesOf3DTriangle[0];
		double y1 = verticesOf3DTriangle[1];
		double z1 = verticesOf3DTriangle[2];

		double x2 = verticesOf3DTriangle[3];
		double y2 = verticesOf3DTriangle[4];
		double z2 = verticesOf3DTriangle[5];

		double x3 = verticesOf3DTriangle[6];
		double y3 = verticesOf3DTriangle[7];
		double z3 = verticesOf3DTriangle[8];

		// Sides of triangle
		double a = sidesOfTriangle3DTriangle[0];
		double b = sidesOfTriangle3DTriangle[1];
		double c = sidesOfTriangle3DTriangle[2];

		// Incenter of the triangle by using the three vertices and the three 
		// side of the triangle ,Formula 
		// [ (z*x1 + b*x2 + c*x3)/(a+b+c), 
		//	 (a*y1 + b*y2 + c*y3)/(a+b+c), 
		//	 (a*z1 + b*z2 + c*z3)/(a+b+c) ]

		double Ix = (a*x1 + b*x2 + c*x3) / (a+b+c);
		double Iy = (a*y1 + b*y2 + c*y3) / (a+b+c);
		double Iz = (a*z1 + b*z2 + c*z3) / (a+b+c);

		// Now find the radius of the incircle center, Which can be find by 
		// calculating the distance between the incircle center and any midpoint
		// if the triangle is equilateral triangle.
		// General Formula :
		// r = A / S, 
		// Where A is the area of the triangle and S is the semiperimeter of the triangle.
		// S = (a+b+c)/2
		// Formula for the finding the area of the triangle by using the 
		// Hero's formula
		// A = √ s(s-a)(s-b)(s-c) 
		// take the mod because the area never be negative.

		// Find the semi perimeter 
		double perimeter = perimeterOfTriangle(sidesOfTriangle3DTriangle);

		// Semiperimeter of the triangle
		double S = perimeter / 2.0;

		// Area of the Triangle 
		double Area = areaOf3DTriangle(sidesOfTriangle3DTriangle);

		// Inradius of the triangle
		double inRadius = Area / S;

		// Now push these values into the vector.
		inCircleCenterOf3DTriangle.push_back(Ix);
		inCircleCenterOf3DTriangle.push_back(Iy);
		inCircleCenterOf3DTriangle.push_back(Iz);

		inCircleRadiusOf3DTriangle = inRadius;
}
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
int main(){

	int choice;

	do{

		std::cout<<"---------------------------- MENU --------------------------"<<std::endl;
		std::cout<<"1. Find the centroid, incircle center and radius, circumcenter and radius of the 2D triangle. "<<std::endl;
		std::cout<<"2. Find the centroid, incircle center and radius, circumcenter and radius of the 3D triangle. "<<std::endl;
		std::cout<<"3. Exit."<<std::endl;
		std::cout<<"Enter your choice : "<<std::endl;
		std::cin>>choice;

		switch(choice){

		case 1:{
			std::cout<<"--------------------------------------------------"<<std::endl;
			std::cout<<"                2D Triangle Program               "<<std::endl;
			std::cout<<"--------------------------------------------------\n\n"<<std::endl;

			std::vector<double>verticesOfTriangle;
			std::pair<double, double>centroid;
			std::pair<double, double>inCircleCenter;
			std::pair<double, double>circumCircleCenter;

			double inCircleRadius = 0.0;
			double circumCircleRadius = 0.0;

			// Take the input from the user - The vertices of the triangle
			get2DTriangleVertices(verticesOfTriangle);

			// Print the vertices of the triangle in the order : 
			// (x1,y1) (x2,y2) and (x3,y3)

			std::cout<<"\nPrinting the vertices of triangle : "<<std::endl;
			std::cout<<"--------------------------------------------------"<<std::endl;


			// Print the vertices of the triangle
			print(verticesOfTriangle);

			// Store the sides of the triangle
			std::vector<double>sidesOfTriangle2D;

			// calculate the sides of the triangle
			calculateSidesOfTriangle2D(verticesOfTriangle,sidesOfTriangle2D);

			std::cout<<"\nPrinting the sides of triangle : "<<std::endl;
			std::cout<<"--------------------------------------------------"<<std::endl;
			print(sidesOfTriangle2D);

			// Check if the triangle is valid or not.
			if(isTriangleValid(sidesOfTriangle2D)){
				std::cout<<"\n--------------------------------------------"<<std::endl;
				std::cout<<"The triangle formed from the vertices of the triangle " <<
					"is valid triangle. " 
					<<"Hence we can perform the different opertation on the triangle"<<std::endl;
			}else{
				std::cout<<"Sorry !!! we can't form the triangle from this vertices. Invalid Triangle."<<std::endl;
				return -1;
			}

			// 1. Centroid of the 2D triangle 
			centroid = centroidOfTriangle(verticesOfTriangle);

			std::cout<<"\n------------------------------------------------"<<std::endl;
			std::cout<<"The centoid of the triangle in the form (Cx,Cy) : "<<std::endl;
			std::cout<<" ( "<<centroid.first<<" , "<<centroid.second<<" ) "<<std::endl;
			std::cout<<"\n------------------------------------------------"<<std::endl;			

			// 2. incircle Center of 2D triangle and radius of circle.

			int radius = 0;
			std::pair<double, double>incircleCenter;

			findInCircleCenterAndRadius(verticesOfTriangle, 
				sidesOfTriangle2D,
				inCircleCenter,inCircleRadius);

			std::cout<<"--------------------------------------------------"<<std::endl;
			std::cout<<"The incircle center of triangle in the form (Ix, Iy) : "<<std::endl;
			std::cout<<"Incircle coordinates : "<<inCircleCenter.first<<" , " << 
				inCircleCenter.second<<std::endl;
			std::cout<<"The incenter radius is : "<<inCircleRadius<<std::endl;

			std::cout<<"--------------------------------------------------"<<std::endl;
			// 3. circumcircle center and radius of 2D triangle

			std::vector<double>circumCenterAndRadius;

			circumCenterOfTriangle(verticesOfTriangle,circumCircleCenter,circumCircleRadius);

			std::cout<<"--------------------------------------------------"<<std::endl;
			std::cout<<"The Circum center of triangle in the form of : (Cx,Cy) : "<<std::endl;
			std::cout<<"Circum center Co-ordinates : "<<circumCircleCenter.first<<
				" , "<<circumCircleCenter.second<<std::endl;
			std::cout<<"The circum radius is : "<<circumCircleRadius<<std::endl;
			std::cout<<"--------------------------------------------------"<<std::endl;

			break;
			   }

		case 2:
			{
				std::cout<<"--------------------------------------------------"<<std::endl;
				std::cout<<"                3D Triangle Program               "<<std::endl;
				std::cout<<"--------------------------------------------------\n\n"<<std::endl;

				std::vector<double>verticesOf3DTriangle;
				std::vector<double>centroidOf3DTriangle;
				std::vector<double>incircleCenterOf3DTriangle;
				std::pair<double, double>circumCircleCenter;

				double inCircleRadiusOf3DTriangle = 0.0;
				double circumCircleRadiusOf3DTriangle = 0.0;

				// Take the input from the user - The vertices of the triangle
				get3DTriangleVertices(verticesOf3DTriangle);

				// Print the vertices of the triangle in the order : 
				// (x1,y1,z1) (x2,y2,z2) and (x3,y3,z3)

				std::cout<<"\nPrinting the vertices of triangle : "<<std::endl;
				std::cout<<"--------------------------------------------------"<<std::endl;

				// Print the vertices of the triangle
				print(verticesOf3DTriangle);

				// Store the sides of the triangle
				std::vector<double>sidesOf3DTriangle;

				// calculate the sides of the triangle
				calculateSidesOf3DTriangle(verticesOf3DTriangle,sidesOf3DTriangle);

				std::cout<<"\nPrinting the sides of triangle : "<<std::endl;
				std::cout<<"--------------------------------------------------"<<std::endl;
				print(sidesOf3DTriangle);

				// Check if the triangle is valid or not.
				if(isTriangleValid(sidesOf3DTriangle)){
					std::cout<<"\n--------------------------------------------"<<std::endl;
					std::cout<<"The triangle formed from the vertices of the triangle " <<
						"is valid triangle. " 
						<<"Hence we can perform the different opertation on the triangle"<<std::endl;
				}else{
					std::cout<<"Sorry !!! we can't form the triangle from this vertices. Invalid Triangle."<<std::endl;
					return -1;
				}

				// 1. Centroid of the triangle 
				calculateCentroidOf3DTriangle(verticesOf3DTriangle,centroidOf3DTriangle);

				std::cout<<"\n------------------------------------------------"<<std::endl;
				std::cout<<"The centoid of the triangle in the form (Gx,Gy,Gz) : "<<std::endl;
				std::cout<<" ( "<<centroidOf3DTriangle[0] <<" , "<<centroidOf3DTriangle[1] <<" , "<<centroidOf3DTriangle[2]<<" )"<<std::endl;
				std::cout<<"\n------------------------------------------------"<<std::endl;			

				// 2. incircle Center of triangle and radius of circle.

				int radius = 0;

				findInCircleCenterAndRadiusOf3DTriangle(verticesOf3DTriangle, 
					sidesOf3DTriangle,
					incircleCenterOf3DTriangle,inCircleRadiusOf3DTriangle);

				std::cout<<"--------------------------------------------------"<<std::endl;
				std::cout<<"The incircle center of triangle in the form (Ix, Iy, Iz) : "<<std::endl;
				std::cout<<"Incircle coordinates : "<<incircleCenterOf3DTriangle[0]<<" , " << 
					incircleCenterOf3DTriangle[1]<<" , "<<incircleCenterOf3DTriangle[2]<<std::endl;
				std::cout<<"The incenter radius is : "<<inCircleRadiusOf3DTriangle<<std::endl;

				std::cout<<"--------------------------------------------------"<<std::endl;
				// 3. circumcircle center and radius of triangle

				std::vector<double>circumCenterAndRadius;

				circumCenterOfTriangle(verticesOf3DTriangle,circumCircleCenter,circumCircleRadiusOf3DTriangle);

				std::cout<<"--------------------------------------------------"<<std::endl;
				std::cout<<"The Circum center of triangle in the form of : (Cx,Cy) : "<<std::endl;
				std::cout<<"Circum center Co-ordinates : "<<circumCircleCenter.first<<
					" , "<<circumCircleCenter.second<<std::endl;
				std::cout<<"The circum radius is : "<<circumCircleRadiusOf3DTriangle<<std::endl;
				std::cout<<"--------------------------------------------------"<<std::endl;
				break;
			}

		case 3:{
			std::cout<<"Exiting..."<<std::endl;
			break;

			   }

		default:{
			std::cout<<"Please enter the correct choice."<<std::endl;
				}
		}

	}while(choice!=3);

	return 0;
}